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
        server_addr.sin_port = htons(2000);
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
        
        char word[100];
            bool vowel =true;
            int i = 0;
			int len=strlen(server_message);
        	while(i<len)
        	{
        		word[i]=server_message[i];
        		i++;
        	}
        	word[i] = '\0';
        	//printf("%s\n", word);
        	char temp[20];
        	char word2[100];
        	int a = 0;
        	for(; word[a] != '\0'; a++)
        	{
        		
        		vowel = false;
        		if(word[a] == 'a'|| word[a]== 'e' || word[a]== 'i' || word[a]== 'o' || word[a] == 'u')
        			vowel = true;
        			
        		if(word[a]== ' ' && vowel == false)
        		{
        			vowel = true;
        			int copy = a-1;
        			int i =0;
        			for(;word[copy]!=' ' && copy>=0; copy--)
        			{
        				temp[i] = word[copy];
        				i++;
        			}
        			temp[i]='\0';
        			copy++;
        			int j = 0;
        			for(; temp[j] != '\0'; j++)
        			{
        				word[copy] = temp[j];
        				copy++;
        			}
        			
        		}
        	}


        	
        	printf("\n");
        	printf("%s\n", word);
			strcat(client_message,word);


			memset(word,'\0',sizeof(word));
        

        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}



