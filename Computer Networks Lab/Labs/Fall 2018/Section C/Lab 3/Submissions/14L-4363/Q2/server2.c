/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int main(void)
{
        int socket_desc, client_sock, client_size; int j,k=0;
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000];
        int a;

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
       while(1==1)
       {
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
        strcpy(server_message,"");
        if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Client sends Message to server: %s\n",client_message);

        char temp[2000],temp1[2000];int check=0;int l,m;
        for(j=0;j<=strlen(client_message);j++)
        {
        if(client_message[j]=='a' || client_message[j]=='A' || client_message[j]=='e' ||client_message[j]=='E' || client_message[j]=='i' || client_message[j]=='I' || client_message[j]=='o' || client_message[j]=='O' || client_message[j]=='u' || client_message[j]=='U' ){
        check=1;
        temp[k]=client_message[j];
        k++;
        }
        else if(client_message[j]==' '){
        if (check==1)
        {
        m=strlen(temp);
        m=m;
        for (l=0;l<strlen(temp);l++)
        {
        temp1[m]=temp[l];
        m--;
        }
        strcpy(temp,temp1);
        strcat(server_message,temp);
        check=0;
        }
        else if (check==0)
        {
        strcat(server_message,temp);
        }
        k=0;
        strcpy(temp,"");
        strcpy(temp1,"");
        
        strcat(server_message," ");
        }
        else{
         temp[k]=client_message[j];
        k++;
        }
}
        //printf("server sends: %s\n",server_message);
        if (send(client_sock, server_message, strlen(server_message),0)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
      
        }
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
              
        //Closing the Socket
        
       //close(client_sock);
        //close(socket_desc);
        return 0;       
}
