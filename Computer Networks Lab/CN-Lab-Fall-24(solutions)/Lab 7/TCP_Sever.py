import socket
import threading

contListening=True

def checkVoterEntries(str):
    fileName="Voters_List.txt"
    f=open(fileName, "r")
    data=f.read()
    arr=data.split("\n")
    for x in arr:
        if x==str:
            return True
    return False


def checkPlacedVoted(str):
    # print(str)
    fileName="output.txt"
    f=open(fileName, "r")
    data=f.read()
    parArr=str.split("/")
    if len(data)!=0:
        arr=data.split("\n")
        for x in arr:
            votedArr=x.split("/")
            if votedArr[0].lower()==parArr[0].lower() and votedArr[1].lower()==parArr[1].lower():
                print(f"{votedArr[0]} with CNIC: {votedArr[1]} has already voted for symbol {votedArr[2]}.")
                return True
        return False
    return False


def readCandidateFileContents():
    fileName="Candidates_List.txt"
    f=open(fileName, "r")
    data=f.read()
    # str=data.split("\n")
    # for x in str:
    #     # print(x)
    #     cand, symbol=x.split(",")
    #     # print(f"{i} = {cand} and {symbol}")
    return data


def placeVote(symbol, voterDetailList):
    fileName="Candidates_List.txt"
    f=open(fileName, "r")
    data=f.read()
    list1=data.split("\n")
    for x in list1:
        # print(x)
        cand, symb=x.split(",")
        # print(f"{i} = {cand} and {symbol}")
        if (symbol.lower()==symb.lower()):
            fout=open("output.txt", "a")
            fout.write(f"{voterDetailList[0]}/{voterDetailList[1]}/{symb}\n")
            return True
    return False



def handle_threads(client_socket, client_address):
    global contListening
    print(f"Client connected with IP: {client_address[0]} and Port: {client_address[1]}")
    # Receiving the message from the client
    try:
        client_message = client_socket.recv(2000).decode('utf-8')
        print(f"Client Message: {client_message}")
    except socket.error as err:
        print(f"Receive failed. Error: {err}")
        client_socket.close()

    messageArr=client_message.split("/")
    if messageArr[0].lower()=="exit":
        contListening=False
        client_socket.close()
        return
    else:
        #compare the message to the Voters_List.txt content
        isVerified=checkVoterEntries(client_message)
        if not isVerified:
            print("Details not matched!")
            client_socket.close()
            print("Client disconnesting!")
            return
        else:
            print("Details have been succesfully authorized!")
            #check if the voter has already voted or not
            isVerified1=checkPlacedVoted(client_message)
            if isVerified1:
                client_socket.close()
                print("Client disconnecting!")
                return
            #read the candidate_list.txt file and send the content to the client
            server_message=readCandidateFileContents()
            # Sending the message back to the client
            try:
                #sending the candidate list back to the client
                client_socket.send(server_message.encode('utf-8'))
            except socket.error as err:
                print(f"Send failed. Error: {err}")
                contListening=False

            # Receiving the message from the client(Vote Symbol)
            try:
                client_message = client_socket.recv(2000).decode('utf-8')
                print(f"Client Message: {client_message}")
            except socket.error as err:
                print(f"Receive failed. Error: {err}")
                client_socket.close()
                print("Client disconnecting!")

            hasVoted=placeVote(client_message, messageArr)
            if hasVoted:
                print("Vote has been succesfully placed")
            else:
                print("The symbol was not found!")
    # Closing the client connection
    client_socket.close()
    print("Client disconnecting!")
    return


def main():
    # Creating the socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Binding the socket to IP and port
    server_address = ('127.0.0.1', 2000)  # Localhost, port 2000
    try:
        server_socket.bind(server_address)
        print("Socket successfully bound to IP and port")
    except socket.error as err:
        print(f"Bind failed. Error: {err}")
        return
    
    # Putting the socket into listening state
    server_socket.listen(1)
    print("Listening for incoming connections...")

    global contListening
    contListening=True

    while contListening:     
        # Accepting a connection
        client_socket, client_address = server_socket.accept()
        thread=threading.Thread(target=handle_threads, args=(client_socket, client_address))
        thread.daemon=True  # the thread will end when the main function ends, need to do before thread starts
        thread.start()
        # note that thread join is not necessary to use as the thread will auto end when the function associated ends, join is only used so that the main threads wait until all the threads have performed their tasks and combined
        # thread.join() Without this, the exit command takes place after a single loop iteration

    # Closing the server socket
    server_socket.close()

if __name__ == "__main__":
    main()
