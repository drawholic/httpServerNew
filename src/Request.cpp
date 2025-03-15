#include "Request.hpp"

std::regex startline_regex("(.+) (.+) (.+)");
std::regex headers_regex (
	// "^(.+): (.+)\n$"
	R"(^(\S+):\s*(.+)$)"
	);

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

std::string method_to_string(MethodsEnum method)
{
	switch(method)
	{
	case GET: return "GET";break;
	case POST: return "POST";break;
	case DELETE: return "DELETE";break;
	case HEAD: return "HEAD"; break;
	case PATCH: return "PATCH"; break;
	case PUT: return "PUT"; break;
	case NONE: return "NONE"; break;
	default: return "NONE"; break;
	};
}

void RequestStartLine::print()
{
	std::string method_str = method_to_string(method);

	printf("Method: %s, URI: %s, version: %s\n", 
		method_str.c_str(),
	 	uri.c_str(), 
	 	version.c_str()
	 );
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

int RequestHeader::fill_header(std::string& input)
{
	std::smatch cm;

	 if(std::regex_match(input, cm, headers_regex))
	 { 
	 	std::pair<std::string, std::string> header_pair{cm.str(1), cm.str(2)};
	 	header = header_pair; 
	 	return 1;
	 }else{
	 	return -1;
	 };
};

int Request::fill_headers(std::string& input)
{
	RequestHeader rh;
	std::stringstream ss(input);
	std::string line;

	while(getline(ss, line))
	{ 
		if(rh.fill_header(line) == -1)
		{
			return -1;
		}
		headers.push_back(rh); 
	} 
	return 1;
};

int Request::fill_startline(std::string& input)
{
	if(startline.fill_members(input) == -1)
	{
		return -1;
	}else{
		return 1;
	};

};

void RequestHeader::print()
{
	printf("%s: %s\n", header.first.c_str(), header.second.c_str());
};