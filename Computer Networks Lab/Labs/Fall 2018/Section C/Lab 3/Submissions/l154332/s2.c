/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

char* invertArr(char arr[]){
	
	char x[100];
	strcpy(x, arr);
	int i, j;
	j = 0;
	for (i = strlen(arr)-1;i >= 0;i--,j++){

		arr[j] = x[i];
	}
	arr[j] = '\0';
	return arr;
}

int hasVowels(char arr[]){

	int i;
	for (i = 0;i < strlen(arr);i++){

		if (arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U' || 
			arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){

			return 1;
		}
	}
	return 0;
}

int main(void)
{

//	char y[100] = "AEIOU";
//	strcpy(x,invertArr(y));
//	printf("%s\n", x);


/////////////////////////////////////////////////////////////////////////////////
	
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000];

        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Creating Socket
        
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	//loop back address
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        
	while (1){    
		
		if(listen(socket_desc, 1) < 0)
		{
		        printf("Listening Failed. Error!!!!!\n");
		        return -1;
		}
		
		printf("Listening for Incoming Connections.....\n");
		
		//Accept the incoming Connections

	    
		client_size = sizeof(client_addr);
		client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
		
		if (client_sock < 0)
		{
		        printf("Accept Failed. Error!!!!!!\n");
		        return -1;
		}
		
		printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		
		//Receive the message from the client
		

		if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
		{
		        printf("Receive Failed. Error!!!!!\n");
		        return -1;
		}
		
		printf("Client Message: %s\n",client_message);
		
		char str[1000];
		strcpy(str,client_message);
		int firstIsDone = 0;
		server_message[0] = '\0';
	
		int i;	
		for (i = 0; i < strlen(str);i++){

			if (str[i] == ' ' || firstIsDone == 0){
			
				firstIsDone = 1;
				char word[1000];
				int j = i;
				int k = 0;
				while (str[j] == ' '){
			
					j++;		//Ignoring Whitespaces
				}
				for (;str[j] != ' ' && j<strlen(str);j++,k++){
			
					word[k] = str[j];				
				}
				word[k] = '\0';
			
				if (hasVowels(word)){
			
					strcat(server_message, invertArr(word));
					strcat(server_message, " ");
				}
				else{
			
					strcat(server_message, word);
					strcat(server_message, " ");				
				}
			
				i = j-1;
			}
		}
		
		printf("\n%s\n", server_message);
		
		if (send(client_sock, server_message, strlen(server_message),0)<0)
		{
		        printf("Send Failed. Error!!!!!\n");
		        return -1;
		}

		memset(server_message,'\0',sizeof(server_message));
	        memset(client_message,'\0',sizeof(client_message));
        }
      
        //Closing the Socket
        
        close(client_sock);
        close(socket_desc);
        return 0;       
}
