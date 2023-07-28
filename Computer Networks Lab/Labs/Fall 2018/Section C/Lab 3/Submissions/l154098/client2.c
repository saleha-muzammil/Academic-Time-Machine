
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include<stdbool.h>
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

 char* strrev(char*str)
 {
  int i=strlen(str)-1,j=0;
  char ch;
  while(i>j)
  {
      ch=str[i];
      str[i]=str[j];
      str[j]=ch;
      i--;
      j++;
  }
  return str;
 }   
 int curr=0;
        while(token!=NULL)
        {
            int i=0;
            char *str=token;
            int size =strlen(str);
            bool check=false;
            while(size>0&&!flag)
            {
             int ascii = (int)str[i];

            if((ascii==97||ascii==101||ascii==105||ascii==111||ascii==117))
                check=true;

            i++;
            size--;
            }
            if(!check)
              strrev(str);
            
             for(int j=0;j<strlen(str);j++)
                {
                //putting string in server msg
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
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}
