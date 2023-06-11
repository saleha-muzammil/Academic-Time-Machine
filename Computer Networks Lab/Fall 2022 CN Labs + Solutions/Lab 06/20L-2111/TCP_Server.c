/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <pthread.h>

struct thread_struct
{
        int client_sock;
};

int connected = 0;

void respond_client(void *thread_struct) {
	char client_message[2000];
    char server_message[2000];  
    connected++;
	struct thread_struct *data = (struct thread_struct*)thread_struct;
    while(1) {
		if (recv(data->client_sock, client_message, sizeof(client_message),0) < 0)
		{
		        printf("Receive Failed. Error!!!!!\n");
		        return -1;
		}
		if (!strcmp(client_message, "DISCONNECT")) {
		
			strcpy(server_message, "DISCONNECTED");
			if (send(data->client_sock, server_message, strlen(server_message),0)<0)
			{
				    printf("Send Failed. Error!!!!!\n");
				    return -1;
			}
			connected--;
			memset(server_message,'\0',sizeof(server_message));
			memset(client_message,'\0',sizeof(client_message));
		    pthread_exit(NULL);
			break;
		}
		printf("Client Message: %s\n",client_message);
		strcpy(server_message, client_message);
		
		if (send(data->client_sock, server_message, strlen(client_message),0)<0)
		{
		        printf("Send Failed. Error!!!!!\n");
		        return -1;
		}
		
    }

}

int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;         //SERVER ADDR will have all the server address
        char server_message[2000], client_message[2000];                 // Sending values from the server and receive from the server we need this

        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));     // Set all bits of the padding field//
        
        //Creating Socket
        
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;               /* Address family = Internet */
        server_addr.sin_port = htons(2002);               // Set port number, using htons function to use proper byte order */
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");    /* Set IP address to localhost */
		
		
		
		// BINDING FUNCTION
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)    // Bind the address struct to the socket.  /
	                            	//bind() passes file descriptor, the address structure,and the length of the address structure
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        
        if(listen(socket_desc, 1) < 0)                               //This listen() call tells the socket to listen to the incoming connections.
     // The listen() function places all incoming connection into a "backlog queue" until accept() call accepts the connection.
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        
	    //Accept the incoming Connections
	    
	    client_size = sizeof(client_addr);
	
	 	pthread_t thread[4];

		struct thread_struct thread_st[4];
		while(connected < 4) {
			client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
			thread_st[connected].client_sock= client_sock;
			pthread_create(&thread[connected],NULL,respond_client,(void*)&thread_st[connected]); 
			if (client_sock < 0)
			{
			        printf("Accept Failed. Error!!!!!!\n");
			        return -1;
			}
			printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	    }
        //Closing the Socket
        pthread_join(thread[0],NULL);
        pthread_join(thread[1],NULL);
        pthread_join(thread[2],NULL);
        pthread_join(thread[3],NULL);
        close(client_sock);
        close(socket_desc);
        return 0;       
}
