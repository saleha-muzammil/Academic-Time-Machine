/*
    C socket server example
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <stdbool.h>
bool IsVowel(char * str){
	int size = strlen(str);
	int i = 0;
	for( i = 0; i< size ; i++){
		if(str[i] == 'a'
		|| str[i] == 'e'
		|| str[i] == 'i'
		|| str[i] == 'o'
		|| str[i] == 'u'){
			return true;
		}
	
	}
	return false;

}
void Invert(char * str){
	int size = strlen(str);
	int i;
	char temp;
	for(i=0; i< size/2 ; i++){
		temp = str[i];
		str[i] = str[size -i -1];
		str[ size -i -1] = temp;
	}
}
void InvertVowels(char * client_message, char * server_message){
	
	const char del[2] = " ";
	char * token;
	bool initial = true;
   	//get the first token 
   	token = strtok(client_message, del);
   	//walk through other tokens 
   	while( token != NULL ) 
   	{
      	
      	if(IsVowel(token)){
      		Invert(token);
      	}
      	if(initial ==true){
      		strcpy(server_message,token);
      		initial = false;
      	}
      	else{
      		server_message[strlen(server_message)] = ' ';
      		strcpy(server_message + strlen(server_message),token);
      	}
      	
      	token = strtok(NULL, del);
   }
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
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    
    char server_message[2000];
    char client_message[2000];
    
    int i=0;
     
    
    	//Create socket
    	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    	if (socket_desc == -1)
    	{
    	    printf("Could not create socket\n");
    	}
    	printf("Socket Created\n");
     
    	//Prepare the sockaddr_in structure
    	server.sin_family = AF_INET;
    	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    	server.sin_port = htons(10001);
     
    	//Bind
    	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    	{
        	//print the error message
        	printf("Bind failed. Error\n");
        	return 1;
    	}
    	printf("Bind Done\n");
    	
    
    	Initialise(client_message,server_message);
    	//Listen
    	listen(socket_desc , 1);
      while(1){
    	//Accept and incoming connection
    	printf("Waiting for incoming connections...\n");
    	c = sizeof(struct sockaddr_in);
     
    	//accept connection from an incoming client
    	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    	if (client_sock < 0)
    	{
        	printf("Accept Failed\n");
        	return 1;
    	}
    	printf("Connection Accepted\n");
     
    	//Receive a message from client
    	if( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    	{
    		//Print client message as it is
    		
			InvertVowels(client_message,server_message);
			
			printf("Server message %s\n",server_message);
			
			
        	//Send the message back to client
        	write(client_sock , server_message , strlen(server_message));
        	
    	}
        
    	if(read_size == 0)
    	{
        	printf("Client disconnected");
    	}
    	else
    	{
        	perror("Recv Failed\n");
    	}
    }
    
    
    return 0;
}
