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
	void print();
};

struct RequestHeader
{
	std::pair<std::string, std::string> header;

	int fill_header(std::string&);
	void print();

};

struct Request
{
	RequestStartLine startline;
	std::vector<RequestHeader> headers;
	std::string body;
	
	int fill_startline(std::string&);
	int fill_headers(std::string&);
	void print();

};

#endif