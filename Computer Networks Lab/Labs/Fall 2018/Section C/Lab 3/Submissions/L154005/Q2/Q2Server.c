#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

int CheckVowel(char str[]){
        int v=0;
        int i=0;
        while(i<strlen(str))
        {
                if(str[i]=='a' || str[i]=='e'  || str[i]=='i' || str[i]=='o' || str[i]=='u'|| 
                      str[i]=='A' || str[i]=='E'  || str[i]=='I' || str[i]=='O' || str[i]=='U')
                {
                        v=1;
                        
                }
                i++;            
        }
        return v;
}

int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
   
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
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
        
        while(1){
        char server_message[2000], client_message[2000];
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        if(listen(socket_desc, 1) < 0)
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        
        //Accept the incoming Connections
        
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
        
        printf("Client Message: %s\n",client_message);
        
        //Send the message back to client
        
        char word[15];
        int i=0;
        while(i<strlen(client_message))
        {       
                if(client_message[i]!=' ')
                {
                       strcat(word,&client_message[i]);
                } 
                else if(client_message[i]==' ')
                {    
                        int vowel=CheckVowel(word);
                        if(vowel==0)
                        {
                               strcat(server_message,word);
                        }
                        else
                        {
                                int size=strlen(word);
                                char temp[15];
                                int j=0;
                                int k=size-1;
                                while(j<size){
                                      temp[j]=word[k];
                                }  
                                strcat(server_message,temp);
                        }
                        strcat(server_message,&client_message[i]);                        
                 }
                i++;                  
        }
        printf("Client Message: %s\n",server_message);
        if (send(client_sock, server_message, strlen(server_message),0)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        }     
        //Closing the Socket
        
        close(client_sock);
        close(socket_desc);
        return 0;       
}
