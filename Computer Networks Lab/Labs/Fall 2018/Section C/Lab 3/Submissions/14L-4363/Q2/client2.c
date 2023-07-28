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
        int socket_desc;int i=0;char temp[2000],temp1[2000];int check=0;int l,m;int j,k=0;
        struct sockaddr_in server_addr;
        char server_message[2000], client_message[2000],print_message[2000];
        
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
        printf("Enter Message: ");
        gets(client_message);
        //strcpy(client_message,"client id 1");
        
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
         printf("Server returns to client: %s\n",print_message);


        for(i=0;i<strlen(server_message);i++) 
       {
        
       if(server_message[j]=='a' || server_message[j]=='A' || server_message[j]=='e' ||server_message[j]=='E' || server_message[j]=='i' || server_message[j]=='I' || server_message[j]=='o' || server_message[j]=='O' || server_message[j]=='u' || server_message[j]=='U' ){
        check=1;
        temp[k]=server_message[j];
        k++;
        }
        else if(server_message[j]==' '){
        if (check==0)
        {
        m=strlen(temp);
        m=m;
        for (l=0;l<strlen(temp);l++)
        {
        temp1[m]=temp[l];
        m--;
        }
        strcpy(temp,temp1);
        strcat(print_message,temp);
        check=0;
        }
        else if (check==0)
        {
        strcat(print_message,temp);
        }
        k=0;
        strcpy(temp,"");
        strcpy(temp1,"");
        
        strcat(print_message," ");
        }
        else{
         temp[k]=server_message[j];
        k++;
        }
       }       

        printf("Client Prints: %s\n",print_message);

        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

