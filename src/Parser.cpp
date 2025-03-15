#include "Parser.hpp"

Parser::Parser()
{

};


Request Parser::parse(std::string input)
{
	Request rq;
	std::string startline;
	std::string headers;
	std::string body;

	unsigned end_of_startline;
	unsigned end_of_headers;
	
	end_of_startline = input.find('\n');
	end_of_headers = input.find("\n\n");

	startline = input.substr(0, end_of_startline);
	headers = input.substr(end_of_startline+1, end_of_headers - end_of_startline);
 

	rq.fill_startline(startline);
	rq.fill_headers(headers);
	rq.body = input.substr(end_of_headers);

	rq.print();

	return rq;
};