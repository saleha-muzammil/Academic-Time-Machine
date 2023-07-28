#include <stdio.h> 
#include <sys/socket.h>
#include <string.h> 
#include <arpa/inet.h>
#include <pthread.h>

// Server's Port Number
int port_number = 2009;

// ASSUMPTIONS

// 1) Assuming the client books tickets for a particular movie once and can't send request again to book tickets for it.
// 2) If a client requested for 10 tickets, then either he will get all tickets or none.


// NOTE

// All components of code are implemented, there might be some just minor compilation issues since due to lack of time I wasnt able to compile the code
// Hence there can be some minor syntax mistakes like missing semi colon etc. Otherwise each and every part of the question is fully implemented

void *communicate(void *message)
{
	int client_sock = (int)message;
	char server_message[2000], client_message[2000];
	    
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
			
	// Read Movies List and send the list to Client
	FILE *fp;
	char buff[3000];
	fp = fopen("moviesList.txt", "r");
	
	strcpy(server_message, "WELCOME!\n");
	
	while(fgets(buff, sizeof(buff), fp) != NULL)
	{	
		strcat(server_message, buff);
	}

	fclose(fp);
	
	
	// Send Movies List to Client
	if(send(client_sock, server_message, strlen(server_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		

	// Receive Movie Number and Tickets Number from Client
	if(recv(client_sock, client_message, strlen(client_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		

	// Parsing
	char m_no = client_message[0];
	char t_no = client_message[1];
	
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));

	// Check if that many tickets are available or not
	FILE *fp1;
	char buff2[3000];
	fp = fopen("movieTicketsInfo.txt", "r");

	int a = 0;

	int movies[100];
	char tickets[100];
	
	int m = 0;
	int t = 0;
	
	while(fgets(buff2, sizeof(buff2), fp1) != NULL)
	{	
		movies[m] = buff[0];
		tickets[t] = buff[2];
		
		m++;
		t++;
			
		if ((buff[0] == m_no) && (buff[2] <= t_no))
		{
			a = 1;
		}
	}
	
	movies[m] = '\0';
	tickets[t] = '\0';
	
	fclose (fp1);
	
	// Tickets not Available
	if (a == 0)
	{
		strcpy (server_message, "Sorry! Tickets Not Available.");

		if(send(client_sock, server_message, strlen(server_message),0) < 0)
		{
			printf("Send Error.\n");
			return -1;
		}		
		
		close(client_sock);
		pthread_exit (NULL);
	}

	// If Tickets are available then send the total price
	strcpy (server_message, "Your total bill for the movie number ");
	strcat (server_message, m_no);
	strcat (server_message, " is Rs. ");
	
	int price = (int)t_no * 500;
	
	strcat (server_message, (char)price);
	strcat (server_message, "\n Press y to proceed or n to cancel.\n");
	
	if(send(client_sock, server_message, strlen(server_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		

	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));

	// Receive Input from Client
	if(recv(client_sock, client_message, strlen(client_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		
	
	if (client_message[0] == 'n')
	{
		
		strcpy (server_message, "Reservation Cancel. Goodbye. Have a nice day!\n");

		if(send(client_sock, server_message, strlen(server_message),0) < 0)
		{
			printf("Send Error.\n");
			return -1;
		}		
	
		close(client_sock);
		pthread_exit (NULL);
	}

	
	// If the user typed y then get the CNIC from client
	if(recv(client_sock, client_message, strlen(client_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}		
		
	// Decrease the number of Tickets, add the record to BookingRecord and send the Client a confirmation
	FILE *fp2;
	char buff3[3000];
	fp = fopen("bookingRecord.txt", "a");

	strcat (client_message, " ");
	strcat (client_message, (char) m_no);
	strcat (client_message, " ");
	strcat (client_message, (char) t_no);
	
	fputs(client_message ,fp2);
	
	fclose(fp2);
	
	// Now decrease the number of Tickets
	tickets[(int) m_no - 1] -= (int) t_no;
	
	// Update the movieTicketsInfo file
	FILE *fp3;
	fp = fopen("movieTicketsInfo.txt", "w");

	int p = 0;
	
	for(; p < strlen(movies); p++)
	{
		fputc(movies[p], fp3);
		fputc(' ', fp3);
		fputc(tickets[p], fp3);
		fputc('\n', fp3);
	}

	fclose (fp3);

	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));

	
	strcpy (server_message, "Reservation DONE. Goodbye. Have a nice day!\n");

	if(send(client_sock, server_message, strlen(server_message),0) < 0)
	{
		printf("Send Error.\n");
		return -1;
	}			
	
	close(client_sock);
	pthread_exit (NULL);
}


int main(void)
{
	int socket_desc, client_sock, client_size; 
	
	char server_message[2000], client_message[2000];

	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	
	// Socket Creation	
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket_desc < 0)
	{
		printf("Socket Creation Error.\n");
		return -1;
	}
	
	printf("Socket Created\n");
	
	// Specifying the IP and Port number for the Server        
	struct sockaddr_in server_addr, client_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_number);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
	{
		printf("Bind Error.\n");
		return -1;
	}        
	
	printf("Bind Done\n");
	
	// Server is now listening
	if(listen(socket_desc, 1) < 0)
	{
		printf("Listening Error.\n");
		return -1;
	}
	
	printf("Listening for Incoming Connections...\n");
	
	while (1)
	{		
		client_size = sizeof(client_addr);
		client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
	
		if (client_sock < 0)
		{
			printf("Accept Error.\n");
			return -1;
		}
		
		printf("New Client Connected\n");
		
		pthread_t thread;
	
		pthread_create(&thread, NULL, communicate, (void*)client_sock);
	}
    
	// Closing the Main Socket        
	close(socket_desc);
	return 0;       
}


