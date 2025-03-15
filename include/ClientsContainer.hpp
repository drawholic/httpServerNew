#ifndef CLIENTS_CONTAINER_HPP
#define CLIENTS_CONTAINER_HPP

#include <vector>
#include <poll.h>
#include <algorithm>
#include <cstdio>
#include <unistd.h>

typedef std::vector<pollfd>::iterator pollfd_it;

class ClientsContainer
{
	std::vector<pollfd> fds;

	pollfd_it find_fd(int);
	bool check_if_exists(int);
	bool check_if_exists(pollfd_it);

public:
	ClientsContainer();
	int add(int);
	int remove(int);
	int remove(pollfd_it);
	pollfd* get_pointer();
	size_t get_size();

};



#endif