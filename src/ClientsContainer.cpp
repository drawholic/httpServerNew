#include "ClientsContainer.hpp"


ClientsContainer::ClientsContainer()
{

};

pollfd_it ClientsContainer::begin()
{
	return fds.begin();
};

pollfd_it ClientsContainer::end()
{
	return fds.end();
}

void ClientsContainer::close_clients()
{
	for(auto i : fds)
		close(i.fd);
};

pollfd* ClientsContainer::get_pointer()
{
	return fds.data();
};

size_t ClientsContainer::get_size()
{
	return fds.size();
};

int ClientsContainer::add(int client_fd)
{
	if(client_fd == -1)
	{
		perror("ClientsContainer::add(int client_fd): Invalid descriptor\n");
		return -1;
	}
	if(check_if_exists(client_fd))
	{
		perror("ClientsContainer::add(int client_fd): Already exists\n");
		return -1;
	}else
	{
		pollfd new_fd;
		new_fd.fd = client_fd;
		new_fd.events = POLLIN;

		fds.push_back(new_fd);

		return 1;
	};

};

pollfd_it ClientsContainer::find_fd(int fd)
{
	if(fd == -1)
	{
		perror("find_fd(int fd): Invalid descriptor\n");
		return fds.end();
	};

	pollfd_it it = std::find_if(fds.begin(), fds.end(), [&fd](pollfd el){
		return el.fd == fd;
	});

	return it;
};

bool ClientsContainer::check_if_exists(int fd)
{
	if(fd == -1)
	{
		perror("check_if_exists(int fd): Invalid descriptor\n");
		return 0;
	}
	return fds.end() != find_fd(fd);
};

bool ClientsContainer::check_if_exists(pollfd_it it)
{
	return it != fds.end();
};

int ClientsContainer::remove(int fd)
{
	if(fd == -1)
	{
		perror("remove(int fd): Invalid descriptor");
		return -1;
	};

	pollfd_it it = find_fd(fd);
	if(check_if_exists(it))
	{
		close(fd);
		fds.erase(it);
		return 1;
	}else
	{
		perror("remove(int fd): Descriptor doesn't exist\n");
		return -1;
	};
};

