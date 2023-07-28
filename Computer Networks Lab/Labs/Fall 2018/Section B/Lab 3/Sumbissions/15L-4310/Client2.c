/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <stdbool.h>

//Muhammad Nauman
//15L-4310
//CS-B2

void invertClient(char str[])
{
	int i = 0;
	int firstCount = 0;
	for (i = 0; str[i] != NULL; ++i)
	{
		if (str[i] == ' ')
		{
			if (firstCount == 0)
			{
				firstCount++;
				int start = 0;
				int end = i - 1;
				int k = 0;
				bool vowel = false;
				for (k = start; k <= end; ++k)
				{
					if (str[k] == 'A' || str[k] == 'a' || str[k] == 'E' || str[k] == 'e' || str[k] == 'I' || str[k] == 'i' || str[k] == 'O' || str[k] == 'o' || str[k] == 'U' || str[k] == 'u')
					{
						vowel = true;
						break;
					}
				}
				if (vowel == false)
				{
					int j = end;
					for (k = start; k <= end && k <= j; ++k)
					{
						char temp = str[k];
						str[k] = str[j];
						str[j--] = temp;
					}
				}
			}
			else
			{
				firstCount++;
				int start = 0;
				int end = i - 1;
				int k = 0;
				bool vowel = false;
				for (k = end; str[k] != ' ' && str[k] != NULL; --k)
				{
					if (str[k] == 'A' || str[k] == 'a' || str[k] == 'E' || str[k] == 'e' || str[k] == 'I' || str[k] == 'i' || str[k] == 'O' || str[k] == 'o' || str[k] == 'U' || str[k] == 'u')
					{
						vowel = true;
						break;
					}
				}

				start = k + 1;
				if (vowel == false)
				{
					int j = end;
					for (k = start; k <= end && k <= j; ++k)
					{
						char temp = str[k];
						str[k] = str[j];
						str[j--] = temp;
					}
				}
			}
		}
	}
}


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
        server_addr.sin_port = htons(2003);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        //Now connecting to the server accept() using connect() from client side
        
        if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }
        
        printf("Connected\n");
        
        //Get Input from the User
        
        //printf("Enter Message: ");
        //gets(client_message);
        strcpy(client_message,"the birds fly in dry sky at night ");
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
        invertClient(server_message);
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

