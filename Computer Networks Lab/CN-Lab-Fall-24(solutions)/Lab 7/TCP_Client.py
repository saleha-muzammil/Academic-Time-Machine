import socket

def main():
    # Creating the socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Server details (IP and port)
    server_address = ('127.0.0.1', 2000)

    # Connecting to the server
    try:
        client_socket.connect(server_address)
        print("Connected to server")
    except socket.error as err:
        print(f"Connection failed. Error: {err}")
        return

    # Get input from the user
    name=input("Enter your name:")
    cnic=input("Enter your CNIC number:")
    client_message = f"{name}/{cnic}"

    # Send the message to the server
    try:
        client_socket.send(client_message.encode('utf-8'))
    except socket.error as err:
        print(f"Send failed. Error: {err}")
        client_socket.close()
        return

    # Receive the message back from the server(Candidate List)
    try:
        server_message = client_socket.recv(2000).decode('utf-8')
        print(f"Candidate List:\n{server_message}")
    except socket.error as err:
        print(f"Receive failed. Error: {err}")

    #getting the symbol input from the user
    client_message=input("Enter the symbol you want to vote for: ")
    # Send the message to the server
    try:
        client_socket.send(client_message.encode('utf-8'))
    except socket.error as err:
        print(f"Send failed. Error: {err}")
        client_socket.close()
        return

    # Closing the socket
    client_socket.close()

if __name__ == "__main__":
    main()
