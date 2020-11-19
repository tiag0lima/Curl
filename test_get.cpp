#include <iostream>
#include "Curl.h"

#include <string>

int main(int argc, char *argv[]) {
	
	Curl curl;
	std::string url;

	url = "https://ifconfig.me";

	if (curl.get(url)) {
		std::cout << curl.response() << std::endl;
	} else {
		std::cerr << "error: " << curl.last_error() << std::endl;
	}

	return 0;
}
