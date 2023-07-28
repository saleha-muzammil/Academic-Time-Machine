/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void writeFile(char rolls[1000][8], int length)
{
    FILE* file = fopen("data.txt", "w");
    int i = 0;
    for(; i < length; i++)
    {
        fprintf(file, rolls[i]);
        if(i < length - 1)
        {
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

void printAll(char rolls[1000][8], int length)
{
    printf("Students Present:\n");
    int i = 0;
    for(; i < length; i++)
    {
        printf(rolls[i]);
        printf("\n");
    }
}

int main(void)
{
    FILE* file = fopen("data.txt", "r");
    char rolls[1000][8];
    int i = 0;
    for (; i < 1000; i++) { rolls[i][0] = '\0'; }
    for (i = 0; fgets(rolls[i], 8, file); i++)
        if(rolls[i][0] == '\n')
            i--;
    fclose(file);
    rolls[i][0] = '\0';

    printf("Data Read");

    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];

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

    while (1)
    {

        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr *) &client_addr,
                     &client_struct_length) < 0) {
            printf("Receive Failed. Error!!!!!\n");
            return -1;
        }

//        char temp[8];
//        int j = 0;
//        for(; j < 7; j++)
//        {
//            temp[j] = client_message[j];
//        }
//        temp[7] = '\0';

        if (client_message[9] == 'I')
        {
            client_message[7] = '\0';
            int exists = 0;
            int j;
            for (j = 0; j < i; j++)
            {
                if (strcmp(rolls[j], client_message) == 0)
                {
                    exists = 1;
                    break;
                }
            }
            if(!exists)
            {
                strcpy(server_message, "Welcome Student ");
                strcpy(server_message + 16, client_message);
                strcpy(rolls[i++], client_message);
                writeFile(rolls, i);
            }
            else
            {
                strcpy(server_message, "You are already here.");
            }
        }
        else
        {
            client_message[7] = '\0';
            int exists = 0;
            int j;
            for (j = 0; j < i; j++)
            {
                if (strcmp(rolls[j], client_message) == 0)
                {
                    exists = 1;
                    break;
                }
            }
            if(exists)
            {
                for (; j < i - 1; j++)
                {
                    strcpy(rolls[j], rolls[j + 1]);
                }
                memset(rolls[--i], '\0', 8);
                strcpy(server_message, "Good Bye Student ");
                strcat(server_message, client_message);
                strcat(server_message, "! Have a nice day.");
                writeFile(rolls, i);
            }
            else
            {
                strcpy(server_message, "You didn't check in today. Contact System Administrator");
            }
        }
        printAll(rolls, i);

        //Send the message back to client

        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr *) &client_addr,
                   client_struct_length) < 0) {
            printf("Send Failed. Error!!!!!\n");
            return -1;
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

    }

    //Closing the Socket

    close(socket_desc);
    return 0;
}
