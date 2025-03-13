#ifndef CLIENTS_CONTAINER_HPP
#define CLIENTS_CONTAINER_HPP

#include <vector>
#include <poll.h>
#include <algorithm>

typedef std::vector<pollfd>::iterator pollfd_it;

class ClientsContainer
{
	std::vector<pollfd> fds;

	pollfd_it find_fd(int);
	bool check_if_exists(int);

public:
	ClientsContainer();
	int add(int);
	int remove(int);
	int remove(pollfd_it);
};


#endif