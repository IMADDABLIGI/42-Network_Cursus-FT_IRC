#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Server.hpp"

const int BUFFER_SIZE = 4096;

void send_message(int socket, const std::string& message) {
    std::string formatted_message = message + "\n";
    send(socket, formatted_message.c_str(), formatted_message.length(), 0);
    usleep(100);
}

void Server::exec_bot(int fd) {
    // Configuration
    int pid = fork();
    if (pid == -1)
        throw "Failed to create child process";
    else if (!pid)
    {
        const std::string server = "localhost";
        const int port = 8080;
        const std::string nickname = "SYKONO";
        const std::string channel = "#Gaming";

        // Create socket
        int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1)
            throw "Failed to create socket.";

        // Connect to the server
        sockaddr_in server_addr; 
        if (inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr)) <= 0)
        throw "Invalid address/Address not supported";
        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
            throw "Failed to connect to the server.";
        
        std::cout << fd << std::endl;
        std::cout << socket_desc << std::endl;

        // Send user and nickname information
        send_message(socket_desc, "PASS hello");
        send_message(socket_desc, "NICK " + nickname);
        send_message(socket_desc, "USER " + nickname + " 0 * :" + nickname);

        // Join the channel
        send_message(socket_desc, "JOIN " + channel);

        // Main loop
        char buffer[BUFFER_SIZE];
        while (true) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(socket_desc, buffer, sizeof(buffer), 0) <= 0) {
                throw "Connection closed by the server.";
                break;
            }
            std::string message(buffer);
            std::cout << message;
        }
        close (socket_desc);
    }
    else
        waitpid(pid, NULL, 0);
}