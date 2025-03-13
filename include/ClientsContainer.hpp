#ifndef CLIENTS_CONTAINER_HPP
#define CLIENTS_CONTAINER_HPP

#include <vector>
#include <poll.h>


typedef std::vector<pollfd>::iterator pollfd_it;

class ClientsContainer
{
	std::vector<pollfd> fds;

public:
	ClientsContainer();
	int add(int);
	int remove(int);
	int remove(pollfd_it);
};


#endif