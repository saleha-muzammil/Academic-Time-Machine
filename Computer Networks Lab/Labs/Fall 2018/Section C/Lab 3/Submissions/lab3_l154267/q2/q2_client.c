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
        
      
        
        char c_msg[2000];
	strcpy(c_msg, server_message);
 	char word[50];
	
	
	for(int i=0; i< strlen(c_msg); i++){
	   
	   char word[50];
	  memset(word,'\0',sizeof(word));
           int j=0;
	   int vowel =0;
           while(c_msg[i] != ' '){
		
		word[j++] = c_msg[i];
		i++;
	   }
           for(int k=0; k<strlen(word); k++)
	   { // check vowel word ?
		if (word[k] == 'a' || word[k] =='e'||word[k] == 'i' ||word[k] == 			'o' ||word[k] == 'u' ||word[k] == 'A' ||word[k] == 'E' ||word[k] 			== 'I' ||word[k] == 'O' || word[k] == 'U')
		{
                   vowel= 1; break;
		}
 	   }
           if (vowel ==0) // contains no vowel and reverse it 
	   {
               int index = i-1;
        	for(int m =0; m<strlen(word); m++){
		   c_msg[index] = word[m];
		   index--;
                }
		
  	   }
	}

	printf("in client: after changing server msg : %s\n", c_msg);
	

        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

