#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void invert_vowels(char* str){
	int found = 0;
	int j = 0;
	int k;
	int i = 0;
	while (i < strlen(str)){
		if(str[i+1] == 0){
			if (found==1){
				k = i-1;
				while (j < k){
					char temp = str[j];
					str[j] = str[k];
					str[k] = temp;
					k--;
					j++;
				}
				found = 0;
				j = i+1;
			}
			else{
				j = i+1;
				found = 0;
			}
			
		} 
		if(str[i] == ' '){
			if (found==1){
				k = i-1;
				while (j < k){
					char temp = str[j];
					str[j] = str[k];
					str[k] = temp;
					k--;
					j++;
				}
				found = 0;
				j = i+1;
			}
			else{
				j = i+1;
				found = 0;
			}
			
		} 
		if(str[i]=='a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
			found = 1;
		}
		i++;
	}
	
}

int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
        char server_message[2030], client_message[2030];

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
        server_addr.sin_port = htons(2020);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        int loops = 1;
        while (loops){
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
	 	
		//Send the message back to client
		invert_vowels(client_message);
		strcpy(server_message, client_message);
		printf("%s\n", server_message);
		
		if (send(client_sock, server_message, strlen(client_message),0)<0)
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
