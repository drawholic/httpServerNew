#include "Request.hpp"

std::regex startline_regex(R"(.+) (.+) (.+)");
std::regex headers_regex (R"(.+): (.+)");

MethodsEnum get_method(std::string string_method)
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

int RequestStartLine::fill_members(std::string& input){

	std::smatch cm;

	if(std::regex_match(input, cm, startline_regex) && cm.size() == 4)
	{
		method = get_method(cm.str(1));

		uri = cm.str(2);

		version = cm.str(3);

	}else{
		return -1;
	}
	return 1; 
};