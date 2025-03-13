#ifndef READW_RITE_HPP
#define READW_RITE_HPP

class ReadWrite
{

public:
	ReadWrite();
	void echoClient(int);
	void readClient(int);
	void writeClient(int, std::string);
};

#endif