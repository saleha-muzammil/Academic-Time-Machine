

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
        
        //Get Input from the User
        
        printf("Enter String: ");
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
        
        char temp2[2000];
        char*token;
        
        int t=0;
        int check=0;
        int length=0;
        //int in=0;
        token=strtok(server_message," ");
        int k=0;
        int j=0;
        int i=0;
        while(token!=NULL)
        {
        //	length=strlen(token);
        	for(i=0;i<strlen(token);i++)
        	{
        if(token[i]=='a'||token[i]=='e'||token[i]=='i'||token[i]=='o'||token[i]=='u'||token[i]=='A'||token[i]=='E'||token[i]=='I'||token[i]=='O'||token[i]=='U')
        		{	
        				check=1;
        				break;
        		
        		}
        		else
        		check=0;
        	        	
        	
        	}
        //	in=length-1;
        	if(check==0)
        	{
        		for(j=strlen(token)-1;j>=0;j--)
        		{
        			temp2[t]=token[j];
        			t++;
        		
        		}
        	temp2[t]=' ';
        	t++;
        	
        	}
        	else
        	{
        		for( j=0;j<strlen(token);j++)
        		{
        			temp2[t]=token[j];
        			t++;
        		
        		}
        	temp2[t]=' ';
        	t++;
        	
        	}
        	
        	
        
        token = strtok(NULL, " "); 
        
        }
        if(token==NULL)
        temp2[t]='\0';
        
        
        
        
        printf("client  Message 2 : %s\n",temp2);
        
        
        
        
        
        
        
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

