/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

//int checkvovel(char a[])
//{
//	int l=strlen(a);
//	int i=0;
//	for(;i<l;i++)
//	{
//		if(a[i]=='a' ||  a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
//			return 1;
//	}
//	return 0;
//}

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
        
        printf("Enter Roll num: ");
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
        
        char temp[100];
		    int i=0;
		    int j=0;
		    
		   char disp[2000];
		   strcpy(disp,"");
       // while(server_message[i]!='\0')
	//	    {
	//	    	
	//	    	temp[j++]=server_message[i++];
	//			if(server_message[i]==' ' || server_message[i]=='\0')
	//			{
	//				temp[j]='\0';
	//				j=0;
	//				if(checkvovel(temp)==0)
	//				{
	//					char temp2[100];
	//					int k=strlen(temp)-1;
	//					int x=0;
	//					for(;k>=0;k--)
	//					{
	//						temp2[x++]=temp[k];
	//					}
	//					temp2[x]='\0';				
	//					strcat(disp,temp2);
	//					strcat(disp,"");			
	//				}
	//				else
	//				{
	//				
	//					strcat(disp,temp);
	//					strcat(disp,"");
	//				}
	//			}		    	
	//	    }
        
       //printf("Server Message: %s\n",disp);
       printf("      %s\n");
        // printf("Server Message: %s\n",client_message);
        printf("Server Message: %s\n",server_message);
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

