#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h> 
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void main(){
int client;

struct sockaddr_in servAddr;

char servMsg[2000],cliMsg[2000];

int server_struct_length=sizeof(servAddr);

client=socket(AF_INET,SOCK_DGRAM,0);

servAddr.sin_family=AF_INET;
servAddr.sin_port=htons(2002);
servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");


printf("\nEnter message to server  :");
fgets(cliMsg,sizeof(cliMsg),stdin);

/*strcpy(cliMsg,"Im client");*/

sendto(client,cliMsg,sizeof(cliMsg),0,(struct sockaddr*)&servAddr,server_struct_length);

recvfrom(client,servMsg,sizeof(servMsg),0,(struct sockaddr*)&servAddr,&server_struct_length);
printf("Message from server %s",servMsg);

close(client);
}
