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

	// invert non vowel words -Q2 part 2

	char temp[2000];
	strcpy(temp,server_message);
	
	int i=0,j=0,start_index=0;
	//char word[40];
	while(temp[i]!= '\0'){
		
		//word = '\0';
		char word[40];
		memset(word,0,sizeof(word));
		j=0;
		start_index=i;
		while(temp[i]!=' ' && temp[i]!='\0'){
			word[j]=temp[i];
			i++;
			j++;
			
		}

		// check if the word has two vowels
		int size = strlen(word);
		int check=0;
		for(int k=0; k<size && check==0; k++){
			char y = word[k];
			if(y=='a' || y=='e' || y=='i' || y=='o' || y=='u' ||
				y=='A' || y=='E' || y=='I' || y=='O' || y=='U'){

					check=1;
			}
		}
		char rev[size];
		if(check==0){
			for(int a=0,b=size-1; a<size || b==0; a++,b--){
				rev[a] = word[b];
			}
			for(int l=start_index,m=0; m<size ; l++,m++){
				temp[l]=rev[m];
			}
		}

		i++;

	}

        strcpy(server_message,temp);
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));

        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

