#include "ClientsContainer.hpp"


ClientsContainer::ClientsContainer()
{

};



int ClientsContainer::add(int client_fd)
{

};

pollfd_it ClientsContainer::find_fd(int fd)
{
	pollfd_it it = std::find_if(fds.begin(), fds.end(), [&fd](pollfd el){
		return el.fd == fd;
	});

	return it;
};
