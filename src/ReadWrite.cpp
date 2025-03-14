#include "ReadWrite.hpp"


ReadWrite::ReadWrite(){};

int ReadWrite::readClient(int client_fd)
{
	const unsigned buffersize = 1024;
	const char* buffer = new char[buffersize];

	unsigned bytes_read;
	unsigned bytes_read_total = 0;

	printf("Receiving...\n");

	while((bytes_read = read(client_fd, buffer, buffersize)) > 0)
	{
		bytes_read_total += bytes_read;
		buffer[bytes_read] = 0;
		printf("%s", buffer);
	};
	
	printf("End of receiving...");

	if(bytes_read == -1)
	{
		perror("Failure on reading client");
		return -1;
	};


	delete[] buffer;
	return 1;
};