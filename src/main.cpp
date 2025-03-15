#include "Request.hpp"
#include "Parser.hpp"
#include "Server.hpp"
#include <cstdio>
 

Server s;
 
void handle_interrupt(int);

int main(int argc, char const *argv[])
{
	return 0;
}



void handle_interrupt(int sig)
{
	printf("Interrupting...\n");
	s.stop();
};