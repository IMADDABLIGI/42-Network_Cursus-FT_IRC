# FT_IRC
IRC (Internet Relay Chat) is a protocol for real-time text messaging between internet-connected computers created in 1988. It is mainly used for group discussion in chat rooms called “channels” although it supports private messages between two users, data transfer, and various server-side and client-side commands. As of April 2011, the top 100 IRC networks served over 500,000 users at a time on hundreds of thousands of channels.

# Summary
This project is about creating your own IRC server. We will use an actual IRC client to connect to our server and test it. Internet is ruled by solid standards protocols that allow connected computers to interact with each other.

# Subject Requirements
- Youmust be able to authenticate and to register, i.e to define a nickname, a username.
- You should be able to join a channel, send or receive private messages.
- Every message sent by a client in a channel must be received by all of the clients who have joined this channel.

# Rules
- Code the IRC server in C++98.
- Your executable will be run as follows: `./ircserv <port> <password>`
  - port : The port number on which your IRC server will be listening to for incoming IRC connections.
  - password: The connection password. It will be needed by any IRC client that tries to connect to your server.
- The server must be capable of handling multiple clients at the same time and never hang.
- Forking is not allowed. All I/O operations must be non-blocking.
- Only 1 poll() (or equivalent) can be used for handling all these operations (read, write, but also listen, and so forth).
- Several IRC clients exist. You have to choose one of them as a reference. Your reference client will be used during the evaluation process.
- Communication between client and server has to be done via TCP/IP (v4 or v6).
