#include "ClientsContainer.hpp"


ClientsContainer::ClientsContainer()
{

};



int ClientsContainer::add(int client_fd)
{
	if(check_if_exists(fd))
	{
		printf("Already exists");
		return -1;
	}else
	{
		pollfd new_fd;
		new_fd.fd = client_fd;
		new_fd.event = POLLIN;

		fds.push_back(new_fd);
		return 1;
	};

};

pollfd_it ClientsContainer::find_fd(int fd)
{
	pollfd_it it = std::find_if(fds.begin(), fds.end(), [&fd](pollfd el){
		return el.fd == fd;
	});

	return it;
};

bool ClientsContainer::check_if_exists(int fd)
{
	return fds.end() == find_fd(fd);
};