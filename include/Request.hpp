#ifndef REQUEST_HPP
#define REQUEST_HPP

enum MethodsEnum
{	
	GET,
	POST,
	DELETE,
	HEAD,
	PATCH,
	PUT
};

#include <string>

struct RequestStartLine
{
	MethodsEnum method;
	std::string uri;
	std::string version;
};

struct RequestHeader
{
	std::pair<std::string, std::string> header;
};

struct Request
{
	MethodsEnum method;
	std::string url;
	std::string body;
};

#endif