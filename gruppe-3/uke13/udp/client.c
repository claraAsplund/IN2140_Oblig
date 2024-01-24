#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

struct sockaddr_in serveraddr;
struct sockaddr_in clientaddr;
char *myMessage = "Hello World";

#define PORT 9000 // 0-2000 opptatt. Bruk 2000 og opp.
#define BUFMAX 256

int main(void)
{

    char buffer[BUFMAX] = {0};
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    // AF_INET = addressefamilie. IPv4
    // SOCK_DGRAM = UDP
    // 0 = default protocol

    if (sockfd == 0)
    {
        fprintf(stderr, "Failed setting up socket");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0,
           sizeof(serveraddr)); // Ønsker å memsette de til 0 for å unngå søppel.
    memset(&clientaddr, 0, sizeof(clientaddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");        // IPv4 Addressen til vår server i network order
    serveraddr.sin_port = htons(PORT); // Port i network order

    strcpy(buffer, myMessage);

    sendto(sockfd, buffer, strlen(buffer), MSG_WAITALL,
           (struct sockaddr *)&serveraddr,
           sizeof(serveraddr)); // Sender til client, ber om å vente på alle
                                // meldinger MSG_WAITALL

    return EXIT_SUCCESS;
}