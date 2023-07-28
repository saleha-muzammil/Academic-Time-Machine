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
int id;
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
        
      
        sprintf(client_message, "the birds fly in dry sky at thgin");
        //gets(client_message);
        
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
         function(server_message); 
	printf("%s" , server_message);
      //  printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}
int hasVowel(char word[])
{
int len = strlen(word);
int i=0;
for ( ;i < len ;i++)
{
if (word[i] == 'a' || word [i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
{
return 1; 
}

}
return 0;
}

void function(char arr[])
{
char word[20];
int i=0;
int k=0;


	while (i < strlen(arr))
	{
		if (arr[i] != ' ')
		{

			word[k] = arr[i];
			k++;
		}	
		else 
		{
			if (!hasVowel(word))
			{

		//reverse
	int l =strlen(word);	
	int index = i-1;
	int u=0;
		for (;u<l;u++)
		{
		arr[index] = word[u];
		index--;
}	
			}
int l =strlen(word);
			int o=0;

			for (;o < l;o++)
			word[o] = '\0';
			k=0;
		}


	i++;
	}


}
