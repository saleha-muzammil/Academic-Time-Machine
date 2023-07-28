
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr



int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000],client_message1[7];

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
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        
        if(listen(socket_desc, 1) < 0)
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        
        ////////////////////
        int i=0,k=0;
        
        char roll[5][20];
	// The row repesents no. of strings and col represents length of the string
	//printf("enter 5 strings of length not more than 20 each\n");
	//int i;
	//for(i=0;i<5;i++)
	//{
	//	scanf("%s",roll[i]);
	//}
	//printf("\n\nYOU ENTERED\n");
	
	//for(i=0;i<5;i++)
	//{
	//	printf("%s\n",names[i]);
	//}
        
        //Accept the incoming Connections
        while(1){
        
		    client_size = sizeof(client_addr);
		    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
		    
		    if (client_sock < 0)
		    {
		            printf("Accept Failed. Error!!!!!!\n");
		            return -1;
		    }
		    
		    printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		    
		    //Receive the message from the client
		    
		    if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
		    {
		            printf("Receive Failed. Error!!!!!\n");
		            return -1;
		    }
		    
		    
		    
		    //Send the message back to client
		    
		    
		    char temp[100];
		    //int i=0;
		    
		    strcpy(server_message,"");
		   // while(client_message[i]!='\0')
		   // {
		    	
		    //	temp[j++]=client_message[i++];
			//	if(client_message[i]==' ' || client_message[i]=='\0')
			//	{
			//		temp[j]='\0';
			//		j=0;
			//		if(checkvovel(temp)==1)
		//			{
		//				char temp2[100];
		//				int k=strlen(temp)-1;
		//				int x=0;
		//				for(;k>=0;k--)
		//				{
		//					temp2[x++]=temp[k];
		//				}
		//				temp2[x]='\0';			
		//				strcat(server_message,temp2);
		//				strcat(server_message," ");			
		//			}
		///			else
		///			{
		//				strcat(server_message,temp);
		//				strcat(server_message," ");
		//			}
		//		}		    	
		//  }
		
		//int size=sizeof(client_message);
		int j=0;
		while(client_message[j]!='\0')
		{
			j++;
		}
		 printf("size of roll num %d ",j);
		
		  printf("word at specific %c",client_message[j-1]);
		int m;
		for(m=0;m<7;m++)
		{
			client_message1[m]=client_message[m];
		}
		if(k<5)
		{
			if(client_message[j-1]=='I')
			{
				// printf("Good %d",k);
				strcat(server_message,"Welcome Student ");
				strcat(server_message,client_message1);
				//scanf("%s",roll[i]);
				strcat(roll[k],client_message1);
				k++;
			}
			
			if(client_message[j-1]=='O')
			{
				for(m=0;m<7;m++)
				{
					if(roll[m]==client_message1)
					{
						k--;
						
					}
				}
				k--;
				// printf("Good %d",k);
				strcat(server_message,"GOOD BYE! ");
				strcat(server_message,client_message1);
				strcat(server_message," Have a nice Day!!");
				
			}	
			printf("\n\nUsers Currently Logged in:\n");
			int m;
			for(m=0;m<5;m++)
			{
				printf("%s\n",roll[m]);
			}		
		
		}
		else
		{
			strcat(server_message," WE cant log you in, becoz server is full!!");
		}
		
		
		    //strcat(server_message,client_message);
		   // printf("Client Message: %s\n",server_message);
		    
		    if (send(client_sock, server_message, strlen(server_message),0)<0)
		    {
		            printf("Send Failed. Error!!!!!\n");
		            return -1;
		    }
		    
		    memset(server_message,'\0',sizeof(server_message));
		    memset(client_message,'\0',sizeof(client_message));
		          
		    //Closing the Socket
	 		       
		    close(client_sock);
		
        }
        close(socket_desc);
        return 0;       
}
