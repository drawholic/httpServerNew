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

struct Request
{
	MethodsEnum method;
	std::string url;
	std::string body;
};

#endif