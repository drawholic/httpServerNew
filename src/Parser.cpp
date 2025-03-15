#include "Parser.hpp"

Parser::Parser()
{

};


Request Parser::parse(std::string input)
{
	Request rq;
	std::string startline, headers, body;

	size_t end_of_startline = input.find("\r\n");
	size_t end_of_headers = input.find("\r\n\r\n");
	
	if(end_of_startline == std::string::npos)
	{
		return rq;
	};

 
	startline = input.substr(0, end_of_startline);

	if(end_of_headers != std::string::npos)
	{
		headers = input.substr(end_of_startline + 1, end_of_headers - end_of_startline);
		body = input.substr(end_of_headers + 4);
	}else
	{
		headers = input.substr(end_of_startline+2);
		body = "";
	}

	rq.fill_startline(startline);
	rq.fill_headers(headers);
	rq.body = body;

	return rq;
};