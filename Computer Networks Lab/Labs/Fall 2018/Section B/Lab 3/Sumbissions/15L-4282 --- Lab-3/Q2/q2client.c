/*
        TCP_Client. This Program wic1 implement the Client Side for TCP_Socket Programming.
        It wic1 get some data from user and wic1 send to the server and as a reply from the
        server, it wic1 get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr


int isVowel(char c){
	if((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u') || (c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'))
		return 1;
	else
		return 0;
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
        
        printf("Enter The Message To Be Inverted: ");
        gets(client_message);
        //Send the message to Server
        
        if(send(socket_desc, client_message, strlen(client_message),0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }
        
        //Receive the message back from the server and invert the words that have no vowels
        
        if(recv(socket_desc, server_message, 2000,0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Server Message: %s\n",server_message);
        

	memset(client_message,'\0',sizeof(client_message));
	strcpy(client_message, server_message);

        //invert non-vowels from server msg
       int l=strlen(server_message);
       int i=0,count=0;
       int m=0,j=0,n=0;
       int c1=0,c2=0;
       char arr[200]={0};
       for(m=0;(m<l);m++)
       {
	c1=0;
       	c2=i;
       	count=0; //count for vowels
       	for(i;((server_message[i]!=' ') && (i<l));i++)
       	{
       		if(isVowel(server_message[i]) == 1) 
       		{
       			count++;
		}
		c1++; //length of the word
	}
	if(count>0)  //vowel present
	{
		
		for(j=0;j<c1;j++)
		{
			client_message[n]=server_message[c2];
			n++;
			c2++;
		}
		client_message[n]=' ';
		n++;
	}
	else
	{
		int k=i-1;
		
		for(j=0;j<c1;j++)
		{
			client_message[n]=server_message[k];

			n++;
			k--;
		}
		client_message[n]=' ';
		n++;
	}
	i++;
       }

        printf("Client Message: %s\n",client_message);
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}


