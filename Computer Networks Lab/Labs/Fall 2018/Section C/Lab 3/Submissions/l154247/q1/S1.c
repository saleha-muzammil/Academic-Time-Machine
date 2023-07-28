/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int main(void)
{
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
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        
        if(listen(socket_desc, 1) < 0)
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        
        //Accept the incoming Connections
        while(1)
        {
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
		int i=0;
		char a;
		while(i<sizeof(client_message))
		{
			if(client_message[i]>48 && client_message[i]<57)
			{
					a=client_message[i];
			}
			i++;
		}
		
		printf("Client Message: %s\n",client_message);
		
		//Send the message back to client
		if(a!=NULL)
		{
		size_t len = strlen("Hello I am server. Your received id is ");
	   	char *str2 = malloc(len + 1 + 1 ); /* one for extra char, one for trailing zero */
	    	strcpy(str2, "Hello I am server. Your received id is ");
	    	str2[len] = a;
	    	str2[len + 1] = '\0';

		strcpy(server_message, str2);
		}
		else
		{
		strcpy(server_message, "Hello I am server. I din'nt received your id");
		}
		
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
