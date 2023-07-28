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
        
        int i=0,size=0,curr=0,j=0,MarkedIndex,size_of_word;
        int Vowel_found = 0;
        char word[50];
        memset(word,'\0',sizeof(word));
        
        while(1)
        {
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
		
		i=0;
		size = strlen(server_message);
		while(i < size)
		{
			MarkedIndex=i;	// mark the starting index of word
			curr=0;
			
			while(server_message[i] != ' ' && server_message[i] != '\0')
			{
				word[curr] = server_message[i];
				i++;
				curr++;
			}
			word[curr] = '\0';
			
			size_of_word = strlen(word);
			
			for(curr=0 ; curr<size_of_word && Vowel_found == 0 ; curr++)
			{
				if(word[curr] == 'a' || word[curr] == 'A' || word[curr] == 'e' || word[curr] == 'E' || word[curr] == 'i' || 					   word[curr] == 'I' || word[curr] == 'o' || word[curr] == 'O' || word[curr] == 'u' || word[curr] == 'U')
				{
					Vowel_found = 1;
				}
			}
			
			curr=0;
			j=MarkedIndex;
			
			if(Vowel_found == 1)		// vowel found
			{
				while(curr < size_of_word)
				{
					client_message[j] = server_message[j];
					j++;
					
					curr++;
				}
			}
			else
			{
				while(size_of_word != 0)
				{
					client_message[j] = server_message[MarkedIndex + size_of_word -1];
					j++;
					
					size_of_word--;
				}
			}
			
			Vowel_found = 0;
			client_message[i] = server_message[i];
			
			if(server_message[i] != '\0')
				i++;
			
		}
		
		printf("Server Message: %s\n",client_message);
		
		memset(server_message,'\0',sizeof(server_message));
		memset(client_message,'\0',sizeof(client_message));
	}
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}
