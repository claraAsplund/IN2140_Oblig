#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 9000
#define BUFMAX 256

struct sockaddr_in clientaddr;
struct sockaddr_in serveraddr;

int main(void)
{

    char buffer[BUFMAX] = {0};
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == 0)
    {

        fprintf(stderr, "Failed setting up socket");
        exit(EXIT_FAILURE);
    }

    memset(&clientaddr, 0, sizeof(clientaddr));
    memset(&serveraddr, 0, sizeof(clientaddr));

    serveraddr.sin_family = AF_INET; // Vi trenger ikke å si vår egen addresse.
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY; // bryr ikke seg om hvem den får meldinger fra.

    int bindval = bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)); // Kun en part trenger å binde i utgangspunktet

    if (bindval != 0)
    {

        fprintf(stderr, "Failed setting up bind");
        exit(EXIT_FAILURE);
    }

    socklen_t clientaddr_len = sizeof(struct sockaddr_in);
    recvfrom(sockfd, buffer, BUFMAX, 0, (struct sockaddr *)&clientaddr,
             &clientaddr_len); // Mottar melding fra client, lagrer addressen i clientaddr og lagrer addressen i cleintaddr struct'en

    printf("%s\n", buffer); // Se om vi fikk meldingen.
    return EXIT_SUCCESS;
}