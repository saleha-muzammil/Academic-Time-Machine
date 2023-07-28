/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void myFunction1(char buff[])
{
    int i = 0;
    for(i = 0; buff[i] != '\0'; i++) {
            int j = i + 1;
            while (buff[i] != '\0' && buff[i] != ' ') i--;
            i++;
            while (buff[j] != '\0' && buff[j] != ' ') j++;
            j--;
            int k = j;
            for(; i < j; i++, j--) {
                char t = buff[i];
                buff[i] = buff[j];
                buff[j] = t;
            }
            i = k;
    }
}

void myFunction(char buff[])
{
    myFunction1(buff);
    int i = 0;
    for(i = 0; buff[i] != '\0'; i++) {
        if(buff[i] == 'A' || buff[i] == 'a' || buff[i] == 'E' || buff[i] == 'e' || buff[i] == 'I' || buff[i] == 'i' || buff[i] == 'O' || buff[i] == 'o' || buff[i] == 'U' || buff[i] == 'u') {
            int j = i;
            while (buff[i] != '\0' && buff[i] != ' ') i--;
            i++;
            while (buff[j] != '\0' && buff[j] != ' ') j++;
            j--;
            int k = j;
            for(; i < j; i++, j--) {
                char t = buff[i];
                buff[i] = buff[j];
                buff[j] = t;
            }
            i = k;
        }
    }
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
    server_addr.sin_port = htons(2020);
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
    myFunction(server_message);

    printf("Inverted Server Message: %s\n",server_message);

    memset(server_message,'\0',sizeof(server_message));
    memset(client_message,'\0',sizeof(client_message));

    //Closing the Socket

    close(socket_desc);

    return 0;
}

