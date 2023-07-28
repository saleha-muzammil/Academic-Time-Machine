/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int checkforVowl( char buff[2000])
{

   int count=0;

    int i;
    for( i = 0; i < strlen(buff); i++){
   if(buff[i]=='a' || buff[i]=='e' || buff[i]=='i' || buff[i]=='o' || buff[i]=='u')
   {
     count++;

   }  


    else if(buff[i]=='A' || buff[i]=='E' || buff[i]=='I' || buff[i]=='O' || buff[i]=='U')
   { 

      count++;
   }

   }

   if(count>=1)

    {
       return 1;
    }


    else
   {  
     return 0;

   }





}



void rvereseArray(char arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
} 









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
        
        printf("Server  Response Message  : %s\n",server_message);



char WordString[200]="";
char PrintString[2000]="";
int counter=0;
int i=0;
int j=0;

for(i=0;i<=(strlen(server_message));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(server_message[i]==' '||server_message[i]=='\0')
        {
            WordString[j]='\0';
            j=0;    //for next word, init index to 0

           
              if( !checkforVowl(WordString))
            {
                     // printf("---%s---",WordString); 
                 rvereseArray(WordString,0,strlen(WordString)-1);
                  //printf("---%s---",WordString); 
                   strcat(PrintString," ");
                 strcat(PrintString,WordString);
                 strcpy(WordString,"");
           
            }
            else
            
            {
                 strcat(PrintString,WordString);
                 strcat(PrintString," ");
                 strcpy(WordString,"");
            }




        }
        else
        {
            WordString[j]=server_message[i];
            j++;
        }
    }





 printf("Client working after server response   : %s\n",PrintString);






















        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

