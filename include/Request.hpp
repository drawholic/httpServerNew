#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <vector>
#include <regex>

enum MethodsEnum
{	
	GET,
	POST,
	DELETE,
	HEAD,
	PATCH,
	PUT,
	NONE
};

#include <string>

MethodsEnum get_method(std::string);

struct RequestStartLine
{
	MethodsEnum method;
	std::string uri;
	std::string version;

	int fill_members(std::string&);
};

struct RequestHeader
{
	std::pair<std::string, std::string> header;

};

struct Request
{
	RequestStartLine startline;
	std::vector<RequestHeader> headers;
	std::string body;
	
	void fill_startline(std::string&);
	void fill_headers(std::string&);
};

#endif