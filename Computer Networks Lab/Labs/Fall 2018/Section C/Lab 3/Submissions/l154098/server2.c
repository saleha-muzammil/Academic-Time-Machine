
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include<stdbool.h>
int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
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
        
        //Binding
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //to make socket in listening state
        while(1){
        if(listen(socket_desc, 1) < 0)
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        printf("Listening for Incoming Connections.....\n");
        
        //accept incoming connections
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
    
    //reversing the string by tokenizing first on the bases of space
char* parts=strtok(client_message," ");
printf("%s\n",token);        
 char* strrev(char* msg)
 {
   int st=0;
   int start=0;
  int len=strlen(msg)-1;
  reversing string
  char reverse;
  while(len>j)
  {
      reverse=msg[len];
      msg[len]=msg[st];
      msg[st]=reverse;
      len--;
      st++;
  }
  return msg;
 }   
while(token!=NULL)
{
int rev=0;
char *str=token;
int len1=strlen(str);
            bool check=false;
            while(len1>0&&!flag)
            {
             int ascii = (int)str[rev];

            if((ascii==97||ascii==101||ascii==105||ascii==111||ascii==117))
            {
                check=true;
                strrev(str);
            }
            rev++;
            len1--;
            }
            for(int j=0;j<strlen(str);j++)
            {
            //putting msg in server msg
                server_message[curr]=str[j];
                curr++;
            }
            
            server_message[curr]=' ';
            curr++;
            token=strtok(NULL," ");
        }
        

        printf("Client Message: %s\n",server_message);
       //sending msg to client
        if (send(client_sock, server_message, strlen(server_message),0)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
 }       
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
              
        //Closing the Socket
        
        close(client_sock);
        close(socket_desc);
        return 0;       
}
