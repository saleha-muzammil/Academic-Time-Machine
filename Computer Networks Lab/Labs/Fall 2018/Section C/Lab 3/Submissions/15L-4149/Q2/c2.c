/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr;
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
        
        //Specifying the IP and Port of the server to connect
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2007);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        //Now connecting to the server accept() using connect() from client side
        
        if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }
        
        printf("Connected\n");
        
        //Get Input from the User
        
        printf("Enter Message: ");
        gets(client_message);
                
        //Send the message to Server
        
        if(send(socket_desc, client_message, strlen(client_message),0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }
        

        //Receive the message back from the server
        
        
        if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        
        //invert without vowels
        memset(client_message,'\0',sizeof(client_message));
        strcpy(client_message,server_message);
        memset(server_message,'\0',sizeof(server_message));
        
        
	    	char* token = strtok(client_message, " ");
			while (token) 
			{
				int revert = 1;
				int i = 0;
				
				for (i=0; i <strlen(token);i++)
				{
					if (token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u')
						revert = 0;
				}
				
				char temp[100];
		        memset(temp,'\0',sizeof(temp));

				
				// revert
				if (revert == 1)
				{					
					int j = strlen(token) - 1;
					int k = 0;
					while (j > -1)
					{
						temp[k] = token[j];
						k++;
						j--;
					}				
				}
				else
				{				
					strcpy(temp,token);
				}
				
				
				strcat( server_message, temp);
				strcat( server_message, " ");

				token = strtok(NULL, " ");
			}
        

        
        printf("\n%s",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

