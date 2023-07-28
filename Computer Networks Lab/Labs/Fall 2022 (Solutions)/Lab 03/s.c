#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
	int socket_desc, client_sock, client_size;
	struct sockaddr_in server_addr, client_addr;
	char server_message[2000], client_message[2000];
	
	memset(server_message, '\0', sizeof(server_message));
	memset(client_message, '\0', sizeof(client_message));
	
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socket_desc < 0)
	{
		printf("Error: Could not create socket\n");
		return -1;
	}
	
	printf("Socket Created\n");
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(2000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if (bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("Error: Bind Failed\n");
		return -1;
	}
	
	printf("Bind Done\n");
	
	while(1)
	{
	
		if(listen(socket_desc, 1) < 0)
		{
			printf("Error: Listening Failed\n");
		}
	
		printf("Listening for Incoming Conversation\n");
	
		client_size = sizeof(client_addr);
	
		client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
	
		if (client_sock < 0)
		{
		    printf("Accept Failed. Error!!!!!!\n");
		    return -1;
		}
		
		printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa				       (client_addr.sin_addr),ntohs(client_addr.sin_port));
		
		if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
		{
		    printf("Receive Failed. Error!!!!!\n");
		    return -1;
		}
		
		printf("Client Message: %s\n",client_message);
		
		//int client_message_length = strlen(client_message) - 1;
		//int client_id = client_message[client_message_length] - 48;
		//char client_id_char = (char)client_id;
		
		//printf("\n\n%c\n\n", client_id_char);

		
		char send_to_client[2000] = "Hello I am server. Your received id is  ";
        send_to_client[strlen(send_to_client) - 1] = client_message[strlen(client_message) - 1];
        //send_to_client[strlen(send_to_client)] = '\0';

        //Send the message back to client
        
        strcpy(server_message, send_to_client);
	
		if (send(client_sock, server_message, strlen(send_to_client),0)<0)
		{
		    printf("Send Failed. Error!!!!!\n");
		    return -1;
		}
		
		memset(server_message,'\0',sizeof(server_message));
		memset(client_message,'\0',sizeof(client_message));
    
    }
    
    close(client_sock);
    close(socket_desc);
    return 0;
}
