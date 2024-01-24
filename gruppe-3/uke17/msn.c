#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <sys/select.h>

#define BUFSIZE 325

void get_string(char buf[], int size){
    char c;

    fgets(buf, size, stdin);
    if( buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;
    else
        while((c = getchar()) != '\n' && c != EOF);
}

void check_error(int res, char *msg){
    if(res == -1){
        perror(msg);
        /*Rydde?*/
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[]){
    int msg_fd, rc;
    fd_set fds;
    struct sockaddr_in friends_addr, my_addr;
    char buf[BUFSIZE];
    struct timeval timeout;

    if(argc < 4){
        printf("usage: ./%s <my port> <friends port> <friends ip>\n", argv[0]);
        return EXIT_SUCCESS;
    }

    msg_fd = socket(AF_INET, SOCK_DGRAM, 0);
    check_error(msg_fd, "socket");

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(argv[1]));
    my_addr.sin_addr.s_addr = INADDR_ANY;

    rc = bind(msg_fd, (struct sockaddr*) &my_addr, sizeof(struct sockaddr_in));
    check_error(rc, "bind");

    friends_addr.sin_family = AF_INET;
    friends_addr.sin_port = htons(atoi(argv[2]));
    rc = inet_pton(AF_INET, argv[3], &friends_addr.sin_addr.s_addr);
    check_error(rc, "inet_pton");
    if(rc == 0){
        fprintf(stderr, "IP address not valid: %s\n", argv[3]);
        /*Rydde?*/
        return EXIT_FAILURE;
    }
    
    /*
        To ting skal skje samtidig:
            - lytte til nettet, kommer det en melding fra friend=
            - lytte til tastaturet, kommer det en melding fra bruker?    
    */
    printf("Welcome to MSN! Type stuff to your anonymous friend: \n");

    buf[0] = 0;
    while(strcmp(buf, "q")){
        // Initialiser fds til en tom mengde / liste.
        FD_ZERO(&fds);

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // sett inn fd i fds
        FD_SET(msg_fd, &fds);
        FD_SET(STDIN_FILENO, &fds);

        printf("[YOU] ");
        fflush(stdout);

        rc = select(FD_SETSIZE, &fds, NULL, NULL, &timeout);
        check_error(rc, "select");

        if(rc == 0){
            printf("\r[BOT]Are you alive? pls show a sign\n");
            continue; //vet at de under kommer til å bli false.
        }

        if (FD_ISSET(msg_fd, &fds)) {
            // En mld fra nettet
                // 1 lese mld inn i et buffer
                // 2 printe bufferet
            rc = read(msg_fd, buf, BUFSIZE - 1);
            check_error(rc, "read");
            buf[rc] = 0;
            printf("\r %45s [ANO]\n", buf);
        }

        if(FD_ISSET(STDIN_FILENO, &fds)) {
            // mld fra tastatur
                // 1 lese mld inn i et buffer
                // 2 sende mld over nett til friend
            get_string(buf, BUFSIZE);
            rc = sendto(msg_fd, buf, strlen(buf), 0, (struct sockaddr*) &friends_addr, sizeof(struct sockaddr_in));
            check_error(rc, "sendto");
        }
    }
    

    close(msg_fd);

    return EXIT_SUCCESS;
}