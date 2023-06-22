#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "header.h"


Bool make_request(Source source) {
    char request[MAX_REQUEST_LEN];
    strcat(request,"GET / HTTP/1.1\r\nHost: ");
    strcat(request,source.host);
    strcat(request,"\r\n\r\n");
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Couldn't create socket\n");
        return False;
    }
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(source.port);
    if (inet_pton(AF_INET, source.host, &(serverAddress.sin_addr)) <= 0) {
        perror("Invalid target-address!\n");
        return False;
    }
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Couldn't connect with target-address!");
        return False;
    }
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Couldn't send request to target-address!");
        return False;
    }
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int bytesRead;
    while ((bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    if (bytesRead < 0) {
        perror("An error occured while receiving response from target-addr!");
        return False;
    }
    close(sockfd);
    return True;
}


int main(int argc, const char **argv) {
    // Sources
    Source dwd;
    strcpy(dwd.name,"Deutscher Wetterdienst");
    strcpy(dwd.host,"141.38.3.62");
    strcpy(dwd.url,"www.dwd.de");
    dwd.port = 80;
    // 
    Bool status = make_request(dwd);
    return 0;
}