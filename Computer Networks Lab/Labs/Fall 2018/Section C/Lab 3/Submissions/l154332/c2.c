/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

char* invertArr(char arr[]){
	
	char x[100];
	strcpy(x, arr);
	int i, j;
	j = 0;
	for (i = strlen(arr)-1;i >= 0;i--,j++){

		arr[j] = x[i];
	}
	arr[j] = '\0';
	return arr;
}

int hasVowels(char arr[]){

	int i;
	for (i = 0;i < strlen(arr);i++){

		if (arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U' || 
			arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){

			return 1;
		}
	}
	return 0;
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
        
        printf("Server Message: %s\n",server_message);
        
        
        
        char str[1000];
	strcpy(str,server_message);
        char p_server_message[2000];
	int firstIsDone = 0;
	p_server_message[0] = '\0';

	int i;	
	for (i = 0; i < strlen(str);i++){

		if (str[i] == ' ' || firstIsDone == 0){
		
			firstIsDone = 1;
			char word[1000];
			int j = i;
			int k = 0;
			while (str[j] == ' '){
		
				j++;		//Ignoring Whitespaces
			}
			for (;str[j] != ' ' && j<strlen(str);j++,k++){
		
				word[k] = str[j];				
			}
			word[k] = '\0';
		
			if (!hasVowels(word)){
		
				strcat(p_server_message, invertArr(word));
				strcat(p_server_message, " ");
			}
			else{
		
				strcat(p_server_message, word);
				strcat(p_server_message, " ");				
			}
		
			i = j-1;
		}
	}

        
	printf("ProcessedServerMessage: %s\n",p_server_message);
        
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

