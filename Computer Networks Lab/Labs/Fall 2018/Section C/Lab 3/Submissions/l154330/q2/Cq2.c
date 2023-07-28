/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <stdbool.h>

bool IsConsonent(char * str)
{
	int size = strlen(str);
	int i = 0;
	for( i = 0; i< size ; i++){
		if(str[i] == 'a'
		|| str[i] == 'e'
		|| str[i] == 'i'
		|| str[i] == 'o'
		|| str[i] == 'u'){
			return false;
		}
	
	}
	return true;

}
void Invert(char * str)
{
	int size = strlen(str);
	int i;
	char temp;
	for(i=0; i< size/2 ; i++){
		temp = str[i];
		str[i] = str[size -i -1];
		str[ size -i -1] = temp;
	}
}
void InvertNonVowels(char * str)
{
	char Newstr[2000];
	const char del[2] = " ";
	char * token;
	bool initial = true;
   	//get the first token 
   	token = strtok(str, del);
   	//walk through other tokens 
   	while( token != NULL ) 
   	{
      	
      	if(IsConsonent(token)){
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
void Initialise(char * client_message , char * server_message)
{
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
    server.sin_port = htons(5000);
 
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
        
    //printf("Server reply :");
    //printf("%s\n",server_reply);
    
    
    InvertNonVowels(server_reply);
    printf("Server_Reply: %s\n",server_reply); 
    close(sock);
    return 0;
}
