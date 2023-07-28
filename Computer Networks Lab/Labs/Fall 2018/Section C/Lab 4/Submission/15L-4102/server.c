/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void printAll(char rollnos[][50], int length) {
        for(int i = 0; i < length; i++) {
                printf("%s\n", rollnos[i]);
        }
}

int readFromFile(char rollnos[][50]) {
        FILE* inputFile = fopen("./serverdata.txt", "r");

        char inputChar = '0';
        
        int i = 0;
        int length = 0;
        while (inputChar != EOF) {
                inputChar = fgetc(inputFile);
                if(inputChar == '\n') {
                        rollnos[length][i] = 0;
                        i = 0;
                        length++;
                        continue;
                }
                rollnos[length][i] = inputChar;
                i++;
        }
        fclose(inputFile);
        return length;
}

void writeToFile(char rollnos[][50], int length) {
        FILE* outputFile = fopen("./serverdata.txt", "w+");

        for(int i = 0; i < length; i++) {
                fprintf(outputFile, "%s\n", rollnos[i]);
        }
        fclose(outputFile);
}

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000];

        char check_ins[8][50];
        
        int client_struct_length = sizeof(client_addr);
        
        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Creating Socket
        
        socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        
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
        
        printf("Listening for Messages...\n\n");
        
        //Receive the message from the client
        int numOfClients = 0;

        printf("Currently Checked In:\n");
        numOfClients = readFromFile(check_ins);
        printAll(check_ins, numOfClients);

        while(1) {
                if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr,&client_struct_length) < 0)
                {
                        printf("Receive Failed. Error!!!!!\n");
                        return -1;
                }

                if(client_message[8] == 'C') {
                        int matched = -1;
                        if(client_message[9] == 'I') {
                                for(int j = 0; j < numOfClients; j++) {
                                        matched = j;
                                        for(int k = 0; k < 7; k++) {
                                                if(client_message[k] != check_ins[j][k]) {
                                                        matched = -1;
                                                        break;
                                                }
                                        }
                                        if(matched >= 0)
                                                break;
                                }
                                if(matched >= 0) {
                                        strcpy(server_message, "You are already here!");
                                
                                        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                                        {
                                                printf("Send Failed. Error!!!!!\n");
                                                return -1;
                                        }
                                } else {
                                        for(int i = 0; i < 7; i++) {
                                                check_ins[numOfClients][i] = client_message[i];
                                        }
                                        check_ins[numOfClients][7] = 0;
                                        numOfClients++;

                                        strcpy(server_message, "Welcome Student");
                                        int servMsgLen = strlen(server_message);
                                        server_message[servMsgLen] = ' ';
                                        servMsgLen++;
                                        for(int i = 0; i < 8; i++) {
                                                server_message[servMsgLen + i] = check_ins[numOfClients - 1][i];
                                        }

                                        int len = strlen(server_message);
                                        check_ins[numOfClients][len] = ' ';
                                        len++;
                                        int i = 0;
                                        for(; i < 7; i++) {
                                                check_ins[numOfClients][len + i] = client_message[i];
                                        }
                                        check_ins[numOfClients][len + i] = 0;

                                
                                        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                                        {
                                                printf("Send Failed. Error!!!!!\n");
                                                return -1;
                                        }
                                }
                                printf("Currently Checked In:\n");
                                printAll(check_ins, numOfClients);
                                writeToFile(check_ins, numOfClients);
                        } else if (client_message[9] == 'O') {
                                for(int j = 0; j < numOfClients; j++) {
                                        matched = j;
                                        for(int k = 0; k < 7; k++) {
                                                if(client_message[k] != check_ins[j][k]) {
                                                        matched = -1;
                                                        break;
                                                }
                                        }
                                        if(matched >= 0)
                                                break;
                                }
                                if(matched >= 0) {
                                        for(int m = matched + 1; m < numOfClients; m++) {
                                                for(int k = 0; k < 7; k++) {
                                                        check_ins[m - 1][k] = check_ins[m][k];
                                                }
                                        }
                                        numOfClients--;

                                        strcpy(server_message, "Good Bye! Have a nice day.");
                                
                                        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                                        {
                                                printf("Send Failed. Error!!!!!\n");
                                                return -1;
                                        }
                                } else {
                                        strcpy(server_message, "You didn’t check in today. Contact System Administrator.");
                                
                                        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                                        {
                                                printf("Send Failed. Error!!!!!\n");
                                                return -1;
                                        }
                                }
                                printf("Currently Checked In:\n");
                                printAll(check_ins, numOfClients);
                                writeToFile(check_ins, numOfClients);
                        } else {
                                //Send error message
                                
                                strcpy(server_message, "Invalid Message");
                                
                                if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                                {
                                        printf("Send Failed. Error!!!!!\n");
                                        return -1;
                                }
                        }
                } else {
                        //Send error message
                                
                        strcpy(server_message, "Invalid Message");
                        
                        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
                        {
                                printf("Send Failed. Error!!!!!\n");
                                return -1;
                        }
                }
        
                // printf("Received Message from IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

                // printf("Client Message: %s\n",client_message);
        }
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
              
        //Closing the Socket
        
        close(socket_desc);
        return 0;       
}
