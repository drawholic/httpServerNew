#ifndef SERVER_HPP
#define SERVER_HPP

#include "Parser.hpp"
#include "ReadWrite.hpp"
#include "ClientsContainer.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>

namespace server_setup{
	
	void create_socket(int);

	void fill_address(sockaddr_in*, const char*, int);

	void bind_socket(int, sockaddr_in*);

	void socket_listen(int);

	void set_options(int);
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
