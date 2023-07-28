/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <stdbool.h>
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
           printf("Server Message: %s \n",server_message);
           printf("\n");
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
		char buffer[2000];
			 
			  char * pch;
			  int ind=0;
			  bool flag=false;  
			  
			 
			  char word[25];
			  
			 
			  pch = strtok (server_message," ");
			  while (pch != NULL)
			  {
			   flag=true;
			  
			   
			  
				for (ind=0;ind<strlen(pch);ind++)
				{
				   if (pch[ind]=='a' || pch[ind]=='e' || pch[ind]=='i' || pch[ind]=='o' || pch[ind]=='u'){
				  
				   
				   flag=false;
				   break;
				   }
		
				}
			  
				  if (flag==true)
				  {
				    int k=0;
					for (ind=strlen(pch)-1; ind>=0;ind--)
						{
						  word[k]=pch[ind];
						  k++;
						}
		
					word[k]=' ';
					word[k+1]='\0';
				  }
				  else
				  {
					  strcpy(word,pch);
					  int space=strlen(word);
					   
					  word[space]=' ';
				      word[space+1]='\0';
				  
				  }
			   
			  
			    
				strcat(buffer,word);
			   
				pch = strtok (NULL, " ");
			  }
			  
			 
   
        
        
        
        
        
        
        
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////
       printf("Server Message with changes: %s \n",buffer);
       
       
            
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

