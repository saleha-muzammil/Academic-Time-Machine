/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int checker(char *str)
{
	int i = 0;
	for(i = 0; i < strlen(str);i++)
	{
		if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			return -1;
		}
	}
	return 1;
}
int split(char *str, char arr[100][100])
{
	int n=0,i,j=0;
	
	for(i=0;strlen(str);i++)
	{
		if(str[i]=='\0')
		    break;
		if(str[i]!=' '){
			arr[n][j++]=str[i];
		}
		else{
			arr[n][j++]='\0';
			n++;
			j=0;
		}
		
	}
	return n;
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
        
	printf("Server message:\n");
      	int n = 0; 
	char arr[100][100];
	n= split(server_message,arr);
	int i =0,z,y;
	char temp;
	for(i = 0; i<=n; i++)
	{
		if(checker(arr[i]) == 1)
		{
			z = strlen(arr[i]);
			for(y = 0 ;y <z;y++)
			{
				temp = arr[i][y];
				arr[i][y] = arr[i][z-1];
				arr[i][z-1] = temp;
				z--;
			}
			printf("%s ",arr[i]);
		}
		else
		{
			printf("%s ",arr[i]);
		}
	}
	printf("\n");
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

