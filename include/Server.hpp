#ifndef SERVER_HPP
#define SERVER_HPP

#include "Parser.hpp"
#include "ReadWrite.hpp"
#include "ClientsContainer.hpp"



class Server
{
	Parser* prs;
	ReadWrite* rw;
	ClientsContainer* fds;
	char* buffer;

public:
	Server(const char* ip = 0, int port = 0);
	void run();
};


#endif
