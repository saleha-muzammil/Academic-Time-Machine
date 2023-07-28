/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <stdbool.h>

bool validate_message(char * message){
	int dash_index1 = 2;
	int dash_index2 = 7;

	int i = 0;
	while (message[i] != '\0'){
		if (i < dash_index1 || (i < dash_index2 && i > dash_index1)){
			if (!(message[i] < 58  && message[i] > 48)){
				return false;
			}
		}
		if (i == dash_index1 && message[i] != '-'){
				return false;
		}

		if (i == dash_index2 && message[i] != '-'){
				return false;
		}

		i++;
	}
	return true;

}

int lookup_id(int id, int db[1000]){
	for(int i =0; db[i] != -1; i++){
		if (db[i] == id){
			return i;
		}
	}
	return -1;
}

void print_db(int db[1000]){
	printf("\n\nCurrent Database\n");
	for(int i =0; db[i] != -1; i++){
		printf("%d\n", db[i]);
	}
}

void add_to_db(int db[1000], int id){
	int i = 0;
	for(; db[i] != -1; i++){}
	db[i] = id;
}

void delete_from_db(int db[1000], int id){
	int ind = lookup_id(id, db);
	if (ind >= 0){
		int i = ind;
		int j = ind+1;
		for (; db[i] != -1; i++, j++){
			db[i] = db[j];
		}
	}
}

int check_type(char * message){
	//YY-AAAA-CI
	//1 for check in and -1 for check out
	if (message[9] == 'I'){
		return 1;
	}
	else {
		return -1;
	}
}

int message_to_id(char * message){
	//YY-AAAA-CI
	char buff[6];
	int j =0;
	for (int i =0; i < 7; i++){
		if (message[i] != '-'){
			buff[j++] = message[i];	
		}
	}
	buff[j] = '\0';
	return atoi(buff);
}


char* message_to_id_string(char* message){
	char buff[6];
	int j =0;
	for (int i =0; i < 7; i++){
		if (message[i] != '-'){
			buff[j++] = message[i];	
		}
	}
	buff[j] = '\0';
	return buff;
}


void initialize_db(int db[1000]){
	for(int i =0; i<1000; i++){
		db[i] = -1;
	}
}

void save_to_file(int db[1000], char * filename){
	FILE *file;
	file = fopen(filename, "w");
	if( file == NULL)
	{
	    printf("Something went wrong reading %s\n", filename);
	    return;
	}
	else
	{
	    for(int i=0; db[i] != -1; i++){
	        fprintf(file, "%d\n", db[i]);
	    }
	}
	fclose(file);
}

void read_file(int db[1000], char*filename){
	FILE *file;
	file = fopen(filename, "r");
	char * line = NULL;
    size_t len = 0;

	if( file == NULL)
	{
	    printf("Something went wrong reading %s\n", filename);
	    return;
	}
	else
	{
		int i =0;
	    while (getline(&line, &len, file) != -1) {
	        db[i++] = atoi(line);
	    }
	}
	fclose(file);
}

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr, client_addr;
        char server_message[2000], client_message[2000];
        
        int client_struct_length = sizeof(client_addr);
        
        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
        
        //Initializing database for check ins
        int db[1000];
        initialize_db(db);

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
        

        //read from file
        read_file(db, "attendance.txt");
        // print_db(db);
        printf("Database read from file\n\n\n");

        printf("Listening for Messages...\n\n");


        while(true){


	        //Receive the message from the client
	        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr, &client_struct_length) < 0)
	        {
	                printf("Receive Failed. Error!!!!!\n");
	                return -1;
	        }
	  
	        printf("Received Message from IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

	        printf("Client Message: %s\n",client_message);

	        //validate message format
	        if (!validate_message(client_message)){
	        	//oops	
	        }
	        int id = message_to_id(client_message);

	        if (check_type(client_message) >= 1){ //i.e. check in
	        	if (lookup_id(id, db) == -1){//i.e. id doesnt already exist
	        		add_to_db(db, id);
	        		printf("Successfully added to DB\n");
	        		printf("Welcome student %d\n", id);
	        		strcpy(server_message, "Welcome student ");
	        		strcat(server_message, message_to_id_string(client_message));
	        	}
	        	else{
	        		printf("You are already here\n");	      
	        		strcpy(server_message, "You are already here");
	        	}
	        }
	        else {
	        	if (lookup_id(id, db) >= 0){//i.e. id does already exist
	        		delete_from_db(db, id);
	        		printf("Successfully deleted from DB\n");
	        		printf("GoodBye Student %d! Have a nice day.\n", id);
	        		strcpy(server_message, "GoodBye Student ");
	        		strcat(server_message, message_to_id_string(client_message));
	        		strcat(server_message, "Have a nice day.");
	        	}
	        	else{
	        		printf("You didn't check in today please contact system admin\n");
	        		strcpy(server_message, "You didn't check in today please contact system admin");
	        	}
	        }
	        
	        //Send the message back to client
	        
	        // strcpy(server_message, client_message);
	        
	        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
	        {
	                printf("Send Failed. Error!!!!!\n");
	                return -1;
	        }

	        //printing current db
	        print_db(db);

	        //write to file
	        save_to_file(db, "attendance.txt");
	        printf("Written to File\n");

	        //break loop
			char buff[10];
			printf("\n\nWant to exit ([y]/n):  ");
			gets(buff);

			if (strcmp(buff, "y") == 0){
				break;
			}
	        
	        memset(server_message,'\0',sizeof(server_message));
	        memset(client_message,'\0',sizeof(client_message));

	        printf("\n\nListening for Messages...\n\n");


        }

        //Closing the Socket

        
        close(socket_desc);
        return 0;       
}
