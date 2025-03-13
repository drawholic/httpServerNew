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
	Server();
	void run();
};


#endif
