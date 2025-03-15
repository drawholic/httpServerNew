#include "Server.hpp"



Server::Server(const char* ip, int port)
{
	init_server(ip, port);


};

void Server::init_server(const char* ip, int port)
{
	int status;
	addr = new sockaddr_in;
	addrlen = sizeof(*addr);

	status = server_setup::create_socket(fd);

	if(status)
		exit(EXIT_FAILURE);

	const char* correct_ip = ip ? ip: DEFAULT_IP;
	const int correct_port = port ? port : DEFAULT_PORT;
	
	status = server_setup::fill_address(addr, correct_ip, correct_port);

	if(status)
		exit(EXIT_FAILURE);

	status = server_setup::bind_socket(fd, addr, addrlen);

	if(status)
		exit(EXIT_FAILURE);

	status = server_setup::set_options(fd);

	if(status)
		exit(EXIT_FAILURE);

	status = server_setup::set_nonblock(fd);

	if(status)
		exit(EXIT_FAILURE);

	buffer = new char[BUFFER_SIZE];
};

Server::~Server(){
	delete[] buffer;
	delete addr;
	close_socket();
};

void Server::close_socket(){};

void Server::run(){
	
	fds->add(fd);

	while(running)
	{ 
		poll_clients();
	};
};

void Server::poll_clients()
{
	int fd_num = poll(fds->get_pointer(), fds->get_size(), 1000);

	if(fd_num == -1)
	{
		perror("Server::poll_clients(): failure on poll call");
		return;
	}else if(fd_num == 0)
	{
		printf("Server::poll_clients: poll timed out");
	};

	std::string buffer;
	int current = 0;
	pollfd_it it = fds->begin();
	while(current != fd_num)
	{

		if(it->revents & POLLIN)
		{
			if(it->fd == fd)
			{
				accept_client();
			}else{
				rw->readClient(it->fd, buffer);
				printf("Received: %s\n", buffer.c_str());
			};
			current++;
		};

		std::next(it);
	};
};

int Server::accept_client()
{
	int client = accept(fd, 0, 0);

	if(client == -1)
	{
		perror("accept_client: Failure accepting");
		return client;
	};

	int status = fds->add(client);

	if(status == -1)
	{
		perror("accept_client::Bad accept");
		return status;
	};
	return 1;
};


namespace server_setup{
	int create_socket(int& sock)
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
		int status = inet_pton(AF_INET, ip, &addr->sin_addr);

		if(status == 0)
		{
			printf("Failure setting address to string: %s\n", ip);
			return -1;
		}else if(status == -1){
			perror("Failure setting address to string\n");
			return -1;
		};
		addr->sin_port = htons(port);
		addr->sin_family = AF_INET;
		return 0;
	};

	int bind_socket(int sock, sockaddr_in* addr, socklen_t len){
		int status = bind(sock, (sockaddr*)addr, len);
		if(status == -1)
		{
			perror("Failure on binding");
			return -1;
		};
		return 0;
	};

	int sock_listen(int sock, int limit)
	{
		int status = listen(sock, limit);
		if(status == -1)
		{
			perror("Failure setting to listen");
			return status;
		};
		return 0;
	};

	int set_options(int sock)
	{
		int option = 1;
		int status = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
		if(status == -1)
		{
			perror("Failure setting options");
			return status;
		};
		return status;
	};

	int set_nonblock(int sock)
	{
		int status = fcntl(sock, F_SETFL, O_NONBLOCK);
	
		if(status == -1)
		{
			perror("Failure setting nonblock");
			return status;
		};
		return 0;
	};

};
