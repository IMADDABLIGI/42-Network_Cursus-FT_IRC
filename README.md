# FT_IRC

<p align="center">  <img src="Assets/IrcExample.png" </p>

# Definition
Internet Relay Chat or IRC is a text-based communication protocol on the Internet, It offers real-time messaging that can be either public or private. Users can exchange direct messages and join group channels.
IRC clients connect to IRC servers in order to join channels. IRC servers are connected together to form a network.

# Summary
This project is about creating your own IRC server. You will use an actual IRC client to connect to your server and test it. Internet is ruled by solid standards protocols that allow connected computers to interact with each other.

# Subject Requirements
- You must be able to authenticate and to register, i.e to define a nickname, a username.
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
- You must handle ctrl+D to send the command in several parts, ctrl+C for leaks.

# Commands
| Command | Description |
| :-----------: | :----------- |
| Pass | The `PASS` command is used to set a ‘connection password’. If set, the password must be set before any attempt to register the connection is made. |
| Nick | The `NICK` command is used to give the client a nickname or change the previous one. |
| User | The `USER` command is used at the beginning of a connection to specify the username and realname of a new user. |
| Privmsg | The `PRIVMSG` command is used to send private messages between users, as well as to send messages to channels. |
| Join | The `JOIN` command indicates that the client wants to join the given channel(s), each channel using the given key for it. |
| Topic | The `TOPIC` command is used to change or view the topic of the given channel. |
| Invite | The `INVITE` command is used to invite a user to a channel. |
| Kick | The `KICK` command can be used to request the forced removal of a user from a channel. |
| Mode | The `MODE` command is used to set or remove options (or modes) from a given target.  User modes : i, o. Channels modes: l,k,t |
| BOT (BONUS)| The `BOT` command can be used with argument `DATE` to display the present time, and with the argument `HELP` to display a manual of all the commands |
| Ping | The `PING` command is sent by either clients or servers to check the other side of the connection is still connected and/or to check for connection latency, at the application layer. |
| Part | The `PART` command removes the client from the given channel(s). |
| Quit | The `QUIT` command is used to terminate a client’s connection to the server.

# Available Functions
- Everything in C++ 98.
- `socket`, `close`, `setsockopt`, `getsockname`,
- `getprotobyname`, `gethostbyname`, `getaddrinfo`,
- `freeaddrinfo`, `bind`, `connect`, `listen`, `accept`, `htons`,
- `htonl`, `ntohs`, `ntohl`, `inet_addr`, `inet_ntoa`, `send`,
- `recv`, `signal`, `sigaction`, `lseek`, `fstat`, `fcntl`, `poll(or equivalent)`

# Ressources
* Internet Relay Chat : http://chi.cs.uchicago.edu/chirc/index.html | https://www.rfc-editor.org/rfc/rfc1459.html
* Network Programming : https://beej.us/guide/bgnet/html/
* Modern IRC Client Protocol : https://modern.ircdocs.horse/
* Command Reference : https://dd.ircdocs.horse/refs/commands/
