#include "Request.hpp"

std::regex startline_regex = "(.+) (.+) (.+)";
std::regex headers_regex = "(.+): (.+)";

MethodsEnum get_method(std::string& string_method)
{
	if(string_method == "GET")
		return GET;
	
	if(string_method == "POST")
		return POST;

	if(string_method == "DELETE")
		return DELETE;	

	if(string_method == "HEAD")
		return HEAD;
	
	if(string_method == "PATCH")
		return PATCH;
	
	if(string_method == "PUT")
		return PUT;
	return NONE;

};

void RequestStartLine::fill_members(std::string& input){

	std::smatch cm;
	std::regex_match(input, cm, startline_regex);

	method = get_method(cm[0]);

	uri = cm[1];

	version = cm[2];

};