/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <stdbool.h>

bool CheckVowel(char *str)

{	int i;
	for( i= 0; i < strlen(str); i++)
	{
		if(str[i] == 'a' || str[i] == 'A' ||
		   str[i] == 'e' || str[i] == 'E' ||
		   str[i] == 'i' || str[i] == 'I' ||
		   str[i] == 'o' || str[i] == 'O' ||
		   str[i] == 'u' || str[i] == 'U')
		{
			return true;
		}
	}
	return false;
}
void Invert(char * str){
	int n = strlen(str);
	int i;
	char c;
	for( i = 0; i < n/2; i++)
	{
		c = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = c;
	}
}

void Invert2(char * str){
	char Newstr[2000];
	const char del[2] = " ";
	char * token;
	bool initial = true;
   	//get the first token 
   	token = strtok(str, del);
   	//walk through other tokens 
   	while( token != NULL ) 
   	{
      	
      	if(!CheckVowel(token)){
      		Invert(token);
      	}
      	if(initial ==true){
      		strcpy(Newstr,token);
      		initial = false;
      	}
      	else{
      		Newstr[strlen(Newstr)] = ' ';
      		strcpy(Newstr + strlen(Newstr),token);
      	}
      	
      	token = strtok(NULL, del);
   }
   strcpy(str, Newstr);
	
}
void Initialise(char * client_message , char * server_message){
	int i;
	for(i = 0 ; i < 2000 ; i++){
        server_message[i] = '\0';
    }
    
    for(i = 0 ; i < 1000 ; i++){
       	client_message[i] = '\0';
    }

}
int main(void)
{
    int sock;
    struct sockaddr_in server;
    char server_reply[2000];
    char message[1000];
    Initialise(message,server_reply);
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket\n");
    }
    printf("Socket created\n");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(10001);
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("Connect failed. Error\n");
        return 1;
    }
     
    printf("Connected\n");
     
    
    
    printf("write message\n");
    gets(message);
    
    printf("Attempting to send message\n");
    //Send some data
    if( send(sock , message , strlen(message) , 0) < 0)
    {
         printf("Send failed\n");
         return 1;
    }
    
    
    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
         puts("recv failed\n");
    }
 
 
    Invert2(server_reply);
    printf("Server_Reply: %s\n",server_reply); 
    close(sock);
    return 0;
}
