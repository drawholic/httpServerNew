#ifndef PARSER_HPP
#define PARSER_HPP

#include "Request.hpp"

class Parser
{

public:
	Parser();
	Request parser(std::string);
};

#endif