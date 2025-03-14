#ifndef READW_RITE_HPP
#define READW_RITE_HPP

#include <string>
#include <cstdio>

class ReadWrite
{

public:
	ReadWrite();
	int echoClient(int);
	int readClient(int, std::string&);
	int writeClient(int, std::string&);
};

#endif