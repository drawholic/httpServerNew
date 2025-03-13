#include "Server.hpp"



Server::Server(const char* ip, int port)
{

};

Server::~Server(){};

void Server::run(){};


namespace server_setup{
	int create_socket(int sock)
	{
		sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(sock == -1)
		{
			perror("Failure creating socket");
			return -1;
		};
		return 0;
	};

	int fill_address(sockaddr_in* addr, const char* ip, int port)
	{
		if(inet_aton(ip, &addr->sin_addr) == 0)
		{
			printf("Failure setting address to string: %s\n", ip);
			return -1;
		};
		addr->sin_port = port;
		addr->sin_family = AF_INET;
		return 0;
	};

	int bind_socket(int sock, sockaddr_in* addr){
		int status = bind(sock, (sockaddr*)addr, sizeof(*addr));
		if(status == -1)
		{
			perror("Failure on binding");
			return -1;
		};
		return 0;
	};



};
