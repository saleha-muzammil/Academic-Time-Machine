/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

int hasVowel(char inputChar) {
        char vowels[] = "aeiouAEIOU";
        for(int j = 0; j < strlen(vowels); j++){
                if(inputChar == vowels[j])
                        return 1;
        }
        return -1;
}

void invertStringClient(char inputStr[], char outputStr[]) {
        int length = strlen(inputStr);
        int beg = 0, end;
        int isVowel = -1;
        int outLen = 0;
        for(int i = 0; i < strlen(inputStr); i++) {
                if(inputStr[i] == ' ') {
                        end = i - 1;
                        if(isVowel < 0) {
                                for(int j = 0; j < (end - beg + 1); j++) {
                                        outputStr[outLen + j] = inputStr[end - j];
                                }
                        } else {
                                for(int j = 0; j < (end - beg + 1); j++) {
                                        outputStr[outLen + j] = inputStr[beg + j];
                                }
                                isVowel = -1;
                        }
                        outputStr[end + 1] = ' ';
                        outputStr[end + 2] = 0;
                        
                        outLen = strlen(outputStr);
                        beg = i + 1;
                }
                if(hasVowel(inputStr[i]) > 0) {
                        isVowel = 1;
                }
        }
        end = strlen(inputStr) - 1;
        if(isVowel < 0) {
                for(int j = 0; j < (end - beg + 1); j++) {
                        outputStr[outLen + j] = inputStr[end - j];
                }
                isVowel = -1;
        } else {
                for(int j = 0; j < (end - beg + 1); j++) {
                        outputStr[outLen + j] = inputStr[beg + j];
                }
        }
        outputStr[end + 1] = ' ';
        outputStr[end + 2] = 0;
}

int main(char** args)
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
        
        strcpy(client_message, "the birds fly in dry sky at night");
        
        if(send(socket_desc, client_message, strlen(client_message),0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }
        
        //Receive response back from the server
        
        if(recv(socket_desc, server_message, sizeof(server_message),0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Server responded: %s\n",server_message);
        
        char outStr[2000];
        invertStringClient(server_message, outStr);
        printf("Output: %s\n",outStr);

        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Closing the Socket
        
        close(socket_desc);
        
        return 0;
}

