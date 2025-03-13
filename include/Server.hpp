#ifndef SERVER_HPP
#define SERVER_HPP

#include "Parser.hpp"
#include "ReadWrite.hpp"
#include "ClientsContainer.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <fcntl.h>

namespace server_setup{
	
	int create_socket(int);

	int fill_address(sockaddr_in*, const char*, int);

	int bind_socket(int, sockaddr_in*);

	int socket_listen(int, int);

	int set_options(int);

	int set_nonblock(int);
};

const int DEFAULT_PORT = 8000;
const char DEFAULT_IP[] = "0.0.0.0";

class Server
{
	Parser* prs;
	ReadWrite* rw;
	ClientsContainer* fds;
	char* buffer;

	sockaddr_in* addr;
	socklen_t addrlen;

	void init_server();

public:
	Server(const char* ip = 0, int port = 0);
	~Server();
	void run();
};


#endif
