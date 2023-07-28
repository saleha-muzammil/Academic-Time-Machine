
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <pthread.h>


void get_client_info(char* client_status,char* client_info, char* message)
{
        int i;
        memset(client_status,'\0',sizeof(client_status));
        memset(client_info,'\0',sizeof(client_info));

        client_status[0] = message[strlen(message)-2];
        client_status[1] = message[strlen(message)-1];               
        //client_status=CO/CI
           
        for(i=0;i<strlen(message)-3;i++)
        {
                client_info[i]=message[i];
        }

}

void * thread_routine(void* socket)
{
        int client_sock = *((int*)socket);
        char client_message[2000];
        char client_status[3],client_info[20];
        
        memset(client_message,'\0',sizeof(client_message));

        //Receive the message from the client
        
        if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                pthread_exit(NULL);
        }
                       
        pthread_exit(client_message);

}

int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;
        int i,j;
        
        pthread_t thread;
        char *message;
        char client_status[3],client_info[20];
        char database[10][2000];
        int client_count = 0, check_in;
        char server_message[2000];
       

        for(i=0;i<10;i++)
        {
                strcpy(database[i],"\0");
        }
        
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
        client_size = sizeof(client_addr);
        
        while(1)
        {       
                printf("Listening for Incoming Connections.....\n");
                int present=0;

                memset(client_status,'\0',sizeof(client_status));
                memset(client_info,'\0',sizeof(client_info));
                memset(server_message,'\0',sizeof(server_message));
                
                                
                //Accept the incoming Connections
                
                client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
                
                if (client_sock < 0)
                {
                        printf("Accept Failed. Error!!!!!!\n");
                        return -1;
                }
                
                printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
                
                int ret1 = pthread_create(&thread, NULL, thread_routine, (void *)&client_sock);
                
                if(ret1!=0)
                {
                        printf("Thread Creation Failed\n");
                }
                
                pthread_join(thread, (void*)&message);
                get_client_info(client_status,client_info,message);
               
                //Check in Database
                for(i=0;i<client_count;i++)
                {
                        if(strcmp(client_info,database[i])==0)
                        {
                                present=i+1; //We get the postion of client in database
                                break;
                        }
                }

                check_in = strcmp(client_status,"CI");
                
                if(check_in==0) //Check_In
                {
                        
                        if(present!=0)  //Already Present
                        {
                                strcpy(server_message,"You are already checked in.");
                                
                        }
                        
                        else //Not present
                        {
                                strcpy(database[client_count],client_info);
                                client_count++;
                                
                                strcpy(server_message, "Welcome Student ");
                                strcat(server_message,client_info);
                                strcat(server_message,". You are checked in.");                                
                        }                        
                }

                else    //Check_Out
                {
                        if(present!=0) //present in database
                        {
                                for(i=present;i<client_count;i++)
                                {
                                        strcpy(database[i-1],database[i]);
                                }
                                strcpy(database[client_count-1],"\0");
                                client_count--;
                             
                                strcpy(server_message, "Goobye Student ");
                                strcat(server_message,client_info);
                                strcat(server_message,". Have a Nice Day.");                        
                        }
                        else    //Not present
                        {
                                strcpy(server_message,"You are not checked in. Contact System Administrator.");        
                        }
                }

                //Send message back to client
                if (send(client_sock, server_message, strlen(server_message),0)<0)
                {
                        printf("Send Failed. Error!!!!!\n");
                
                }

                //Now displaying the database
                printf("Student Database:\n");
                for(i=0;i<client_count;i++)
                {
                        printf("%s\n",database[i]);
                }
                printf("\n");
                
                memset(message,'\0',strlen(message));
        }
        //Closing the Socket
        
        close(socket_desc);
        pthread_exit(NULL);
}
