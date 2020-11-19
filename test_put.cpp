#include <iostream>
#include <stdio.h>
#include "Curl.h"

#include <json/json.h>
#include <string>
#include <fstream>

/*
 *
 *	TODO: HAS BUG WHEN PUT, NULL IT'S SENDED.
 *
 *
 **/


int main(int argc, char *argv[]) {
	
	Curl curl;
	std::string url, file_name;
	url = "https://postman-echo.com/put";
	file_name = "temp_put";

	//create a temporary file with a message
	std::ofstream out;
	out.open(file_name);
	out << "Testing put requests.";
	out.close();
	
	//send temp file
	if (curl.put(url, file_name)) {
		std::cout << curl.response() << std::endl;

	} else {
		std::cerr << "error: " << curl.last_error() << std::endl;
	}
	remove(file_name.c_str());	

	return 0;
}
