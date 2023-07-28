/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
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

void invertStringServer(char inputStr[], char outputStr[]) {
        int length = strlen(inputStr);
        int beg = 0, end;
        int isVowel = -1;
        int outLen = 0;
        for(int i = 0; i < strlen(inputStr); i++) {
                if(inputStr[i] == ' ') {
                        end = i - 1;
                        if(isVowel > 0) {
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
                        
                        outLen = strlen(outputStr);
                        beg = i + 1;
                }
                if(hasVowel(inputStr[i]) > 0) {
                        isVowel = 1;
                }
        }
        end = strlen(inputStr) - 1;
        if(isVowel > 0) {
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

// int main() {
//         char* inputStr = "the birds fly in dry sky at night";
//         char outputStr[2000];
//         char outputStr2[2000];
        
//         invertStringServer(inputStr, outputStr);
//         printf("%s\n", outputStr);
//         invertStringClient(outputStr, outputStr2);
//         printf("%s\n", outputStr2);
//         return 0;
// }

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
        
        while(1 == 1){
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
                
                //Receive the message from the client
                
                if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
                {
                        printf("Receive Failed. Error!!!!!\n");
                        return -1;
                }
                
                char outputStr[2000];

                printf("Client Sent: %s\n",client_message);
                
                //Send the message back to client
                invertStringServer(client_message, outputStr);
                // strcpy(server_message, "Hello I am server. Your received id is ");
                int servLen = strlen(outputStr);
                if (send(client_sock, outputStr, strlen(outputStr),0)<0)
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
