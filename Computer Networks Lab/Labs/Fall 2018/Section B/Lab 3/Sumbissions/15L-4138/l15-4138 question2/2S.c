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
        
        int i=0,size=0,curr=0,j=0,MarkedIndex,size_of_word;
        int no_Vowel = 1;
        char word[50];
        memset(word,'\0',sizeof(word));
        
        while(1)
        {
		//Receive the message from the client
		
		if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
		{
		        printf("Receive Failed. Error!!!!!\n");
		        return -1;
		}
		
		i=0;
		size = strlen(client_message);
		while(i < size)
		{
			MarkedIndex=i;	// mark the starting index of word
			curr=0;
			
			while(client_message[i] != ' ' && client_message[i] != '\0')
			{
				word[curr] = client_message[i];
				i++;
				curr++;
			}
			word[curr] = '\0';
			
			size_of_word = strlen(word);
			
			for(curr=0 ; curr<size_of_word && no_Vowel == 1 ; curr++)
			{
				if(word[curr] == 'a' || word[curr] == 'A' || word[curr] == 'e' || word[curr] == 'E' || word[curr] == 'i' || 					   word[curr] == 'I' || word[curr] == 'o' || word[curr] == 'O' || word[curr] == 'u' || word[curr] == 'U')
				{
					no_Vowel = 0;
				}
			}
			
			curr=0;
			j=MarkedIndex;
			
			if(no_Vowel == 1)		// no vowel found
			{
				while(curr < size_of_word)
				{
					server_message[j] = client_message[j];
					j++;
					
					curr++;
				}
			}
			else
			{
				while(size_of_word != 0)
				{
					server_message[j] = client_message[MarkedIndex + size_of_word -1];
					j++;
					
					size_of_word--;
				}
			}
			
			no_Vowel = 1;
			server_message[i] = client_message[i];
			
			if(client_message[i] != '\0')
				i++;
			
		}
		
		printf("Client Message: %s\n",server_message);
		
		//Send the message back to client
		
		
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
