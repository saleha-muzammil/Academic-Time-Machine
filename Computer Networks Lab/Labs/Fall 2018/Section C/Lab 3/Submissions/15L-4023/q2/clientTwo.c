/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include<stdbool.h>

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
        server_addr.sin_port = htons(2002);
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
        
        printf("Server Message: %s\n",server_message);
        
        char word[20], reverse[20], temp[255];
	int i = 0, j = 0, k;
	bool isVowel = false;
	
	memset(word,'\0',sizeof(word));
	memset(reverse,'\0',sizeof(reverse));
	memset(temp,'\0',sizeof(temp));

	for(i = 0; i < 255 && server_message[i] != '\0'; i++)
	{
		if(server_message[i] == ' ' || server_message[i] == '.' || server_message[i] == ',')
		{
			if(!isVowel)
			{
				for(k = 0, j = j - 1; j >= 0; j--, k++)
				{
					reverse[k] = word[j];
				}
				reverse[k++] = server_message[i];
				reverse[k] = '\0';
	
				printf("original Word: '%s'\nReversed: '%s'\n", word, reverse);
				strcat(temp, reverse);
			}
			else
			{
				word[j++] = server_message[i];
				word[j] = '\0';
				strcat(temp, word);
			}
	
			isVowel = false;
			memset(word,'\0',sizeof(word));
			j = 0;
		}
		else
		{
			word[j++] = server_message[i];
	
			if(server_message[i] == 'A' || server_message[i] == 'a'
			|| server_message[i] == 'E' || server_message[i] == 'e'
			|| server_message[i] == 'I' || server_message[i] == 'i'
			|| server_message[i] == 'O' || server_message[i] == 'o'
			|| server_message[i] == 'U' || server_message[i] == 'u')
			{
				isVowel = true;
			}
		}
	}
        
        memset(server_message,'\0',sizeof(client_message));
        printf("Client Changed: %s\n",temp);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

