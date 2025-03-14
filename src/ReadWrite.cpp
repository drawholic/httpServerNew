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
		delete[] buffer;
		return -1;

	}else if(bytes_read == 0){
		printf("Client disconnected\n");
	};


	delete[] buffer;
	return 1;
};

int ReadWrite::writeClient(int client_fd, std::string msg)
{
	unsigned bytes_sent = 0;
	unsigned bytes_sent_total = 0;
	unsigned msg_len = msg.size();


	while(bytes_sent_total < msg_len)
	{
		bytes_sent = send(client_fd, msg.c_str(), msg_len, 0);

		if(bytes_sent == -1)
		{
			perror("writeClient: Failure on sending");
			return bytes_sent;
		};
		bytes_sent_total += bytes_sent;
	};

	return 1;
};