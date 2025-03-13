#include "Server.hpp"



Server::Server()
{

};

Server::~Server(){};

void Server::run(){};


namespace server_setup{
	void create_socket(int sock)
	{
		sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(sock == -1)
		{
			perror("Failure creating socket");
		};
	};

	void fill_address(sockaddr_in* addr, const char* ip, int port)
	{
		if(inet_aton(ip, &addr->in_addr) == 0)
		{
			printf("Failure setting address to string: %s\n", ip);
		};
		addr->sin_port = port;
		addr->sin_family = AF_INET;
	};

	void bind_socket(int sock, sockaddr_in* addr){

	};



};
