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
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2006);
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
        
        //Accept the incoming Connections

        while(1)
        {
        
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

                
                int k=0;
                for(k;client_message[k]!='\0';k++)
                {
                        if(client_message[k]=='a'|| client_message[k]=='e' || client_message[k]=='i'|| client_message[k]=='o' || client_message[k]=='u' || client_message[k]=='A'|| client_message[k]=='E' || client_message[k]=='I'|| client_message[k]=='O' || client_message[k]=='U')
                        {
                                int m=k;
                                printf("mm: %i\n",m );
                                for(m; m!=-1 && client_message[m]!=' ' ;m--)
                                {
                                }
                                m++;

                                printf(" m=%i\n",m );


                                int n=k;
                                for(n;client_message[n]!='\0' && client_message[n]!=' ';n++)
                                {
                                }
                                n--;                                                                

                                printf(" n=%i\n",n );

                                int spc=n;

                                while (m<n)
                                {
                                        char chr=client_message[m];
                                        client_message[m]=client_message[n];
                                        client_message[n]=chr;
                                        m++;
                                        n--;
                                }
                                k=spc;
                                k++;

                                printf("k: %i\n", k);

                        }
                }



                printf("Client Message: %s\n",client_message);
                
                //Send the message back to client

      
                strcpy(server_message, client_message);


                
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
