/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:16:38 by idabligi          #+#    #+#             */
/*   Updated: 2023/10/29 16:35:27 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void    Server::getDate(int fd)
{
    char buff[100];
    std::string time;
    std::time_t now_time_s = std::time(NULL);
    std::tm *localtime = std::localtime(&now_time_s);
    
    std::strftime(buff, sizeof(buff), "%d/%m/%Y---%H:%M:%S", localtime);
    time = buff;
    this->sendMessage(fd, "[" + time + "]\n");
}

void    Server::getHelp(int fd)
{
    // std::string help;
    std::string top[50] = {
        "||----------------------------------------------------------------------------------||\n",
        "||--------------------------------------MANUAL--------------------------------------||\n",
        "||----------------------------------------------------------------------------------||\n",
        "||                                                                                  ||\n",
        "|| ∗ Set UserName   : USER + (your username)                                        ||\n",
        "|| ∗ Set NickName   : NICK + (your nickname)                                        ||\n",
        "|| ∗ Join a channel : JOIN + #(channel name)                                        ||\n",
        "|| ∗ KICK - Eject a client from the channel                                         ||\n",
        "|| ∗ INVITE - Invite a client to a channel                                          ||\n",
        "|| ∗ TOPIC - Change or view the channel topic                                       ||\n",
        "|| ∗ MODE - Change the channel’s mode:                                              ||\n",
        "||   · i: Set/remove Invite-only channel                                            ||\n",
        "||   · t: Set/remove the restrictions of the TOPIC command to channel operators     ||\n",
        "||   · k: Set/remove the channel key (password)                                     ||\n",
        "||   · o: Give/take channel operator privilege                                      ||\n",
        "||   · l: Set/remove the user limit to channel                                      ||\n",
        "||__________________________________________________________________________________||\n",
        };    
    for (int i = 0; i < 17; i++)
        this->sendMessage(fd, top[i]);
}

void    Server::getJoke(int fd)
{
    this->sendMessage(fd, "Sending Joke !!!\n");
}

void Server::bot(int fd, std::stringstream &iss)
{
    int i;
    std::string str;
    std::string str2;
    std::string check[] = {"DATE", "HELP", "JOKE"};
    iss >> str;
    iss >> str2;
    if (!iss.eof())
        return (this->sendMessage (fd, "421 " + str2 + " :Unknown command\r\n"));
    for (i = 0; i < 3; i++)
    {
        if (str == check[i])
        break ;
    }
    switch (i)
    {
        case 0:
            getDate(fd);
            break;
        case 1:
            getHelp(fd);
            break;
        case 2:
            getJoke(fd);
            break;
        default:
            this->sendMessage (fd, "421 " + str + " :Unknown command\r\n");
    }
}
