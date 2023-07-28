/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr


int hasId(char db[100][100], char id[100], int 	arrLen){

	int i = 0;
	for (i = 0;i < arrLen;i++){

		if (strcmp(db[i], id) == 0){
			return i;
		}

	}
	return -1;
}

int removeId(char db[100][100], int index, int arrLen){

	int i = index;
	for (;i < (arrLen-1);i++){

		strcpy(db[i], db[i+1]);

	}
	arrLen--;
	return arrLen;
}

void printDB(char db[100][100], int arrLen){

	int i = 0;
	printf("\nPrinting Database...\n");
	for (i = 0;i < arrLen;i++){

		printf("%s\n", db[i]);

	}
	return;
}

//void writeDB(char db[100][100], int arrLen, File *fp){

//	int i = 0;
//	printf("\nWriting Database To File...\n");
//	for (i = 0;i < arrLen;i++){

//		fput(db[i], fp);

//	}
//	return;
//}

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000];
        
        int client_struct_length = sizeof(client_addr);
	
	FILE *fp;
	char buff[255];
	fp = fopen("db.txt", "a+");


	char db[100][100];
	int arrLen = 0;

	//Reading from file
	while (!feof(fp)){
		if (fscanf(fp, "%s", buff) == 1){
			strcpy(db[arrLen], buff);
			arrLen++;
		}
	}
	


	printDB(db, arrLen);


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

	
	
	
	
	while (1){        

		printf("Listening for Messages...\n\n");
		
		//Receive the message from the client
		
		if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr,&client_struct_length) < 0)
		{
		        printf("Receive Failed. Error!!!fclose(fp);!!\n");
		        return -1;
		}
	  
		printf("Received Message from IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

		printf("Client Message: %s\n",client_message);
		
		
		char d = client_message[9];
		client_message[7] = '\0';
		printf("Client:\t%s\n", client_message);
		int index = hasId(db, client_message, arrLen);		
		if (d == 'I' || d == 'i'){
			
			if (index >= 0){
//				printf("You are already here.");
				strcpy(server_message, "You are already here.");
			}
			else{
				strcpy(db[arrLen], client_message);
				arrLen++;
//				printf("Welcome Student %s", client_message);
				strcpy(server_message, "Welcome Student ");
				strcat(server_message, client_message);
			}
		}
		else if (d == 'O' || d == 'o'){

			if (index >= 0){
				arrLen = removeId(db, index, arrLen);
//				printf("Good Bye Student %s", client_message);
//				printf("! Have a nice day.");
				strcpy(server_message, "Good Bye Student ");
				strcat(server_message, client_message);
				strcat(server_message, "! Have a nice day.");
			}
			else{
//				printf("You didn’t check in today. Contact System Administrator.");
				strcpy(server_message, "You didn’t check in today. Contact System Administrator.");
			}
		}

		//Send the message back to client
		
		
		if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
		{
		        printf("Send Failed. Error!!!!!\n");
		        return -1;
		}

		printDB(db, arrLen);		

		if (client_message[0] == 'q' && client_message[1] == 'u' && client_message[2] == 'i' && client_message[3] == 't' ){

			int i = 0;
//			printf("\nWriting Database To File...\n");
			for (i = 0;i < arrLen;i++){
	
				fputs(db[i], fp);
				fputs("\n", fp);

			}
			close(socket_desc);
			fclose(fp);
			break;
		}
		
		memset(server_message,'\0',sizeof(server_message));
		memset(client_message,'\0',sizeof(client_message));
		      
		//Closing the Socket

	}

        FILE *fp2;
	fp2 = fopen("db.txt", "w");
	int i = 0;
//	printf("\nWriting Database To File...\n");
	for (i = 0;i < arrLen;i++){
	
		fputs(db[i], fp2);
		fputs("\n", fp2);

	}
        close(socket_desc);
	fclose(fp);
	fclose(fp2);
        return 0;       
}
