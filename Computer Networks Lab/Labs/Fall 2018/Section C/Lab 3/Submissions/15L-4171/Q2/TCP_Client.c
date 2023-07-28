/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void reverse_string(char*);
void reverse_words(char*);

void reverse_words(char *sample) {
  	char arr[100];
  	char *tempArray;
  	char *arr1;
  	int counter = 0;
 	int hasVowel=0;
  	tempArray = sample;
 
  	while(*tempArray) {
    		while(*tempArray != ' ' && *tempArray != '\0') {
      			arr[counter] = *tempArray;
      			tempArray++;
      			counter++;
    		}
    		arr[counter] = '\0';
    		counter = 0;
 		int i=0;
 		hasVowel=0;
 		while(i<strlen(arr)){
 			if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
	    		hasVowel=1;
	    		break;
	    		}
	    		i++;
 		}
 		if(hasVowel==0){
 			reverse_string(arr);
 		}
 	
    		arr1 = arr;
 
    		while (*arr1) { 
      			*sample = *arr1;
      			arr1++;
      			sample++;
    		}
 
    		while (*sample == ' ') {           
      			sample++;
    		}
    		tempArray = sample;
  	}
}
 
void reverse_string(char *sample) {
  	int len = 0;
  	int counter = 0;
  	char *temp1;
  	char temp;
 
  	len = strlen(sample);
  	temp1 = sample + len - 1;
 
  	for (counter = 0; counter < len/2; counter++) {
    		temp  = *sample;
    		*sample = *temp1;
    		*temp1 = temp;
    		sample++;
    		temp1--;
  	}
}


int main(void){
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
        
        reverse_words(server_message);
        
        printf("Server Message: %s\n",server_message);
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}
