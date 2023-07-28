#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int main(void)
{
	int socket_desc;
	struct sockaddr_in server_addr;
	char buf[20], server_message[2000], client_message[2000];
	
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
	int i = 0;
	//while (i <= 9)
	//{
		//Get Input
		printf("Enter Message: ");
		scanf( "%d", &i);
		sprintf(buf,"%d",i);
		strcpy(client_message, buf);
	
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
		
		//Print on screen
		printf("Client Message: Hello. I am Client and my ID is %d.\n", i);
		printf("Server Message: %s\n",server_message);
		//i++;
	//}
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	
	//Closing the Socket
	close(socket_desc);
	return 0;
}
