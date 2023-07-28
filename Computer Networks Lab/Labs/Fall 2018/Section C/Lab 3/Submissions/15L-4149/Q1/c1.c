/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <time.h>
#include <stdlib.h>
#include <math.h>


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
        server_addr.sin_port = htons(2009);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        //Now connecting to the server accept() using connect() from client side
        
        if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }
        
        printf("Connected\n");
        

        srand(time(NULL));   // should only be called once
		int r = rand() % 10;      // returns a pseudo-random integer between 0 and RAND_MAX        
        char digit = r +'0';
        
        printf("Hello I am client. My id is  %c", digit);
        
        char str1[10];
        memset(str1,'\0',sizeof(str1));

		str1[0] = digit;
		str1[1] = '\0';
		
        //Send the message to Server
        
        if(send(socket_desc, str1, strlen(str1),0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }
        
        /*
        //Receive the message back from the server
        
        if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Server Message: %s\n",server_message);
        */
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

