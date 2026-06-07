import socket

def main():
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Bind the socket to the server address and port
    server_address = ('127.0.0.1', 2000)
    sock.bind(server_address)

    print("Socket created and bound")
    print("Listening for messages...\n")

    while True:
        try:
            # Receive the message from the client
            client_message, client_address = sock.recvfrom(2000)
            print(f"Received message from IP: {client_address[0]} and Port No: {client_address[1]}")
            print(f"Client Message: {client_message.decode()}")

            # Send the message back to the client
            sock.sendto(client_message, client_address)

        except Exception as e:
            print(f"An error occurred: {e}")
            break

    # Closing the socket
    sock.close()

if __name__ == "__main__":
    main()
