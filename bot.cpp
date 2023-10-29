/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:16:38 by idabligi          #+#    #+#             */
/*   Updated: 2023/10/29 12:10:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void    Server::getDate(int fd)
{
    this->sendMessage(fd, "Sending Date !!!\n");
}

void    Server::getHelp(int fd)
{
    this->sendMessage(fd, "Sending Help !!!\n");
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
    {
        this->sendMessage (fd, "421 " + str2 + " :Unknown command\r\n");
        return ;
    }
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