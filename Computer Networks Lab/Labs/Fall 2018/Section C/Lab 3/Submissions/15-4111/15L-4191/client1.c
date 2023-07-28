
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 

void reverse_words(char *s) {
  char b[100], *t, *z;
  int c = 0;
 	int hasVowel=0;
  t = s;
 
  while(*t) {
    while(*t != ' ' && *t != '\0') {
      b[c] = *t;
      t++;
      c++;
    }
    b[c] = '\0';
    c = 0;
 	int i=0;
 	hasVowel=0;
 	while(i<strlen(b)){
 		if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u'){
	    	//reverse_string(b);
	    	hasVowel=1;
	    	break;
	    }
	    i++;
 	}
 	if(hasVowel==0){
 		reverse_string(b);
 	}
 	
    z = b;
 
    while (*z) { 
      *s = *z;
      z++;
      s++;
    }
 
    while (*s == ' ') {           
      s++;
    }
    t = s;       
  }
}
 
void reverse_string(char *t) {
  int l, c;
  char *e, s;
 
  l = strlen(t);
  e = t + l - 1;
 
  for (c = 0; c < l/2; c++) {
    s  = *t;
    *t = *e;
    *e = s;
    t++;
    e--;
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
