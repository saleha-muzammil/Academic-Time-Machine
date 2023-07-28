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
        server_addr.sin_port = htons(2006);
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

        int k=0;
                for(k;server_message[k]!='\0';k++)
                {
                        if(server_message[k]=='a'|| server_message[k]=='e' || server_message[k]=='i'|| server_message[k]=='o' || server_message[k]=='u' || server_message[k]=='A'|| server_message[k]=='E' || server_message[k]=='I'|| server_message[k]=='O' || server_message[k]=='U')
                        {

                        }
                        else
                        {

                                int m=k;
                                printf("mm: %i\n",m );
                                for(m; m!=-1 && server_message[m]!=' ' ;m--)
                                {
                                }
                                m++;

                                printf(" m=%i\n",m );


                                int n=k;
                                for(n;server_message[n]!='\0' && server_message[n]!=' ';n++)
                                {
                                }
                                n--;                                                                

                                printf(" n=%i\n",n );

                                int spc=n;

                                while (m<n)
                                {
                                        char chr=server_message[m];
                                        server_message[m]=server_message[n];
                                        server_message[n]=chr;
                                        m++;
                                        n--;
                                }
                                k=spc;
                                k++;

                                printf("k: %i\n", k);
                        }
                }

                k=0;
                for(k;server_message[k]!='\0';k++)
                {
                        if(server_message[k]=='a'|| server_message[k]=='e' || server_message[k]=='i'|| server_message[k]=='o' || server_message[k]=='u' || server_message[k]=='A'|| server_message[k]=='E' || server_message[k]=='I'|| server_message[k]=='O' || server_message[k]=='U')
                        {
                        	int m=k;
                                printf("mm: %i\n",m );
                                for(m; m!=-1 && server_message[m]!=' ' ;m--)
                                {
                                }
                                m++;

                                printf(" m=%i\n",m );


                                int n=k;
                                for(n;server_message[n]!='\0' && server_message[n]!=' ';n++)
                                {
                                }
                                n--;                                                                

                                printf(" n=%i\n",n );

                                int spc=n;

                                while (m<n)
                                {
                                        char chr=server_message[m];
                                        server_message[m]=server_message[n];
                                        server_message[n]=chr;
                                        m++;
                                        n--;
                                }
                                k=spc;
                                k++;

                                printf("k: %i\n", k);

                        }
                        else
                        {
                        	
                                
                        }
                }
        
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

