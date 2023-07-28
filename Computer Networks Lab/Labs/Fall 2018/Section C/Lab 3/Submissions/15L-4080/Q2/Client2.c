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
       
        
        strcpy(client_message,"thh birds fly in dry sky at night ");

        
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
        
        char s[10];
        char rev_s[10];
        int j=0; int i,k; int flag=0,r;
        for(i=0; i<strlen(client_message);i++)
        {
        	while(client_message[i]!=' ')
        	{
        		s[j]=client_message[i];
        		j++;
        		i++;
        	}
        	s[j]='\0';
        	//printf("%s\n",s);
        	j=0;
        	for(k=0; k<strlen(s);k++)
        	{
        		if(s[k]=='a' || s[k]=='e' || s[k]=='i' || s[k]=='o' || s[k]=='u')
        		{
        			flag=1;
        			break;
        		}
        	}
        	if(flag==1)
        	{	r=0;
        		for(k=strlen(s)-1; k>=0;k--)
        		{
        			rev_s[r]=s[k];
        			r++;
        		}
        	}
        	
        	rev_s[r]='\0';
        	strcat(rev_s," ");
        	//printf("%s\n",rev_s);
        	strcat(server_message,rev_s);
        	strcpy(s,"");
        	strcpy(rev_s,"");
        	flag=0;
        }
        
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

