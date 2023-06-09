#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

// Server's Port Number
int port_number = 2009;

int main(void)
{
	int socket_desc;

	char server_message[2000], client_message[2000];
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	
	// Socket Creation
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket_desc < 0)
	{
		printf("Socket Creation Error.\n");
		return -1;
	}
	
	printf("Socket Created\n");
	
	// Setting the IP and Port address of the Server's Socket
	struct sockaddr_in server_addr;
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_number);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	
    // Connecting to Server's Socket
	if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("Connection Error.\n");
		return -1;
	}
 
	// Receiving Welcome Message
	if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
	{
		printf("Receive Failed.\n");
		return -1;
	}
	
	printf("%s\n",server_message);
	
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	

	// Client gives Movie Number	
	printf("Enter Movie Number and Total Tickets: ");
	gets(client_message);

	
	// Send Movie Number and Ticket Details to Server
	if(send(socket_desc, client_message, strlen(client_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		
		

	// Receive Confirmation Message from Server
	if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
	{
		printf("Receive Failed.\n");
		return -1;
	}
	
	
	printf("Server Message: %s\n",server_message);
	
	// If Tickets are not available then end the client program
	if (strcmp(server_message, "Sorry! Tickets Not Available.") == 0)
	{
		close(socket_desc);
		return 0;
	}
	
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));

	// Client gives Confirmation to Buy Tickets
	gets(client_message);
	
	// Send Confirmation to Server
	if(send(socket_desc, client_message, strlen(client_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		
	
	
	if (strcmp(client_message, "y") == 0)
	{	
		memset(server_message,'\0',sizeof(server_message));
		memset(client_message,'\0',sizeof(client_message));

		// Client gives CNIC
		gets(client_message);

		// Send CNIC to Server
		if(send(socket_desc, client_message, strlen(client_message),0) < 0)
		{
			printf("Send Error.\n");
			return -1;
		}		
	}
		

	// Receive Final Confirmation
	if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
	{
		printf("Receive Error.\n");
		return -1;
	}

	printf("Server Message: %s\n",server_message);

	close(socket_desc);
	return 0;
}

