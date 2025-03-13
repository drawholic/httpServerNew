#ifndef PARSER_HPP
#define PARSER_HPP

#include "Request.hpp"

class Parser
{

public:
	Parser();
	Request parse(std::string);
};

#endif