/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr
#include <string.h>

int main(void)
{
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];

    //Cleaning the Buffers

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    //Creating Socket

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc < 0)
    {
        printf("Could Not Create Socket. Error!!!!!\n");
        return -1;
    }

    printf("Socket Created\n");

    //Binding IP and Port to socket

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2011);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind Failed. Error!!!!!\n");
        return -1;
    }

    printf("Bind Done\n");

    //Put the socket into Listening State

    if (listen(socket_desc, 1) < 0)
    {
        printf("Listening Failed. Error!!!!!\n");
        return -1;
    }

    printf("Listening for Incoming Connections.....\n");

    //Accept the incoming Connections
    while (1 == 1)
    {
        client_size = sizeof(client_addr);
        client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);

        if (client_sock < 0)
        {
            printf("Accept Failed. Error!!!!!!\n");
            return -1;
        }

        printf("Client Connected with IP: %s and Port No: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //Receive the message from the client

        if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
        {
            printf("Receive Failed. Error!!!!!\n");
            return -1;
        }

        char word[100], next[100];
        int i, j, k, check;

        for (int i = 0; i < strlen(client_message); i++)
        {
            if (client_message[i] == ' ' || i == strlen(client_message) - 1)
            {

                check = 0;
                for (j = 0; j < strlen(word) && check == 0; j++)
                {
                    if (word[j] == 'a' || word[j] == 'A' || word[j] == 'e' || word[j] == 'E' || word[j] == 'i' || word[j] == 'I' || word[j] == 'o' || word[j] == 'O' || word[j] == 'u' || word[j] == 'U')
                    {
                        check = 1;
                    }
                }

                if (check == 1)
                {
                    k = 0;
                    for (j = strlen(word) - 1; j >= 0; j--)
                    {
                        next[k] = word[j];
                        k++;
                    }
                    next[k] = '\0';
                    strcat(server_message, next);
                }
                else
                {
                    strcat(server_message, word);
                }

                server_message[strlen(server_message)] = ' ';
                memset(word, '\0', sizeof(word));
                memset(next, '\0', sizeof(next));
            }
            else
            {
                word[strlen(word)] = client_message[i];
            }
        }

        //Send the message back to client

        //strcpy(server_message, client_message);
        printf("Client Message: %s\n", client_message);

        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
            return -1;
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
    }
    //Closing the Socket

    close(client_sock);
    close(socket_desc);
    return 0;
}
