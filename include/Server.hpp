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
	
	int create_socket(int&);

	int fill_address(sockaddr_in*, const char*, int);

	int bind_socket(int, sockaddr_in*, socklen_t);

	int sock_listen(int, int);

	int set_options(int);

	int set_nonblock(int);
};

const int DEFAULT_PORT = 8000;
const char DEFAULT_IP[] = "0.0.0.0";
const unsigned BUFFER_SIZE = 1024;
const unsigned DEFAULT_LIMIT = 10;
class Server
{
	bool running = true;
	int fd;
	Parser* prs;
	ReadWrite* rw;
	ClientsContainer* fds;
	char* buffer;

	sockaddr_in* addr;
	socklen_t addrlen;

	void init_server(const char*, int);
	int accept_client();
	void close_socket();
	void poll_clients();

public:
	Server(const char* ip = 0, int port = 0);
	~Server();
	void run();
};


#endif
