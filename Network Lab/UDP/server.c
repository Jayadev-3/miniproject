#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h> 
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void main(){
int server;

struct sockaddr_in servAddr,client_addr;

char servMsg[2000],cliMsg[2000];

socklen_t client_struct_length=sizeof(client_addr);

server=socket(AF_INET,SOCK_DGRAM,0);

servAddr.sin_family=AF_INET;
servAddr.sin_port=htons(2002);
servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(server,(struct sockaddr*)&servAddr,sizeof(servAddr));

printf("Listening \n");

recvfrom(server,cliMsg,sizeof(cliMsg),0,(struct sockaddr*)&client_addr,&client_struct_length);

printf("Message from client %s",cliMsg);

strcpy(servMsg,cliMsg);

sendto(server,servMsg,sizeof(servMsg),0,(struct sockaddr*)&client_addr,client_struct_length);

close(server);
}
