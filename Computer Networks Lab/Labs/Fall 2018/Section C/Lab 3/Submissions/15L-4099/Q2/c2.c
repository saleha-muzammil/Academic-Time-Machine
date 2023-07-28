/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include<stdbool.h>


 char* reverse(char*str);
int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr;
        char server_message[2000], client_message[2000];
        //Cleaning the Buffers
        memset(server_message,'\0',sizeof(server_message));
        //memset(client_message,'\0',sizeof(client_message));
        
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
       while(1)
{ 
        printf("Enter Message: ");
        gets(client_message);
        //Send the message to Server
         
     
        if(send(socket_desc, client_message, sizeof(client_message),0) < 0)
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


        char* token=strtok(server_message," ");
        printf("%s\n",token);        

 
        int curr=0;
        while(token!=NULL)
        {
            int i=0;
            char * str=token;
            int size =strlen(str);
            bool flag=false;
            while(size>0 && !flag)
            {
             int v = (int)str[i];

            if((v==97||v==101||v==105||v==111||v==117))
                flag=true;

            i++;
            size--;
            }

            if(!flag)
              reverse(str);
            
             for(int j=0;j<strlen(str);j++)
                {
                        server_message[curr]=str[j];
                        curr++;
                }
            
            server_message[curr]=' ';
            curr++;
            
            token=strtok(NULL," ");
        }
        
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
      }  
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}
// reverse function
 char* reverse(char*s)
 {
  int i=strlen(s)-1;
  int j=0;
  char c;
  while(i>j)
  {
      c=s[i];
      s[i]=s[j];
      s[j]=c;
      i--;j++;
  }
  return s;
 }  
