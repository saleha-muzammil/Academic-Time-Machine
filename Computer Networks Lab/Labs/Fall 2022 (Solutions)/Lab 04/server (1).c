/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //// Needed for socket creating and binding
#include <arpa/inet.h> //inet_addr

int main(void)
{
        char array[10][1000]; //Array for server to store checked in clients
        int arrPointer = 9;
        int sCapacity = 10;
        int socket_desc;
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000]; 
        int client_struct_length = sizeof(client_addr);
        
        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Creating UDP Socket
        
        socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // bind your socket to localhost only, if you want connect any particular ip you should mention it in INET_ADDR.
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        while(1)
        {
        printf("Listening for Messages...\n\n");
        
        //Receive the message from the client
        
        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr,&client_struct_length) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
  	
  	 if(client_message[strlen(client_message) - 1] == 'I') //Check in request;
  	 {
  	 	int i = arrPointer;
  	 	int exists = 0;
  	 	if(arrPointer == 0)
  	 	{
  	 		strcpy(server_message, "Server Full!");
  	 	}
  	 	for(; i <= sCapacity; i++)
  	 	{
  	 		if(strcmp(array[i], client_message) == 0)
  	 		{
  	 			strcpy(server_message, "You are already checked In!");
  	 			exists = 1;
  	 		}
  	 	}
  	 	if(exists == 0)
  	 	{
  	 		strcpy(array[arrPointer], client_message);
  	 		strcpy(server_message, "Check In Successful!");
  	 		arrPointer--;
  	 	}
  	 }
  	 else if(client_message[strlen(client_message) - 1] == 'O')
  	 {
  	 	int i = arrPointer;
  	 	int notExists = 1;
  	 	for(; i < sCapacity; i++)
  	 	{
  	 		char pseudo[100];
  	 		strcpy(pseudo, client_message);
  	 		pseudo[strlen(pseudo) - 1] = 'I';
  	 		if(strcmp(array[i], pseudo) == 0)
  	 		{
  	 			strcpy(server_message, "GoodBye");
  	 			strcpy(array[i], "no");
  	 			notExists = 0;
  	 			arrPointer++;
  	 			break;
  	 		}
  	 	}
  	 	if(notExists == 0 && i != 0)
  	 	{
	  	 	int j = i;
	  	 	for(; j > arrPointer; j--)
	  	 	{
	  	 		bzero(array[j], 0);
	  	 		strcpy(array[j], array[j - 1]);
	  	 	}
	  	}
  	 	if(notExists == 1)
  	 	{
  	 		strcpy(server_message, "You Did not check in today! Contact Administrator");
  	 	}
  	 }
  	 else
  	 {
  	 	strcpy(server_message, "Wrong Input Format");
  	 }
        printf("Received Message from IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

        printf("Client Message: %s\n",client_message);
        
        //Send the message back to client
        
        //strcpy(server_message, client_message);
        
        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
              
        //Closing the Socket
        }
        close(socket_desc);
        return 0;       
}
