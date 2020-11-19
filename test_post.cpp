#include <iostream>
#include "Curl.h"

#include <json/json.h>
#include <string>

int main(int argc, char *argv[]) {
	
	Curl curl;

	std::string url;
	Json::Value values;

	for (int x = 0; x < 100; x++)
		values[std::to_string(x)+""] = x;

	url = "https://postman-echo.com/post";

	if (curl.post_json(url, values)) {
		Json::Value root;
		Json::StyledWriter writer;
		Json::Reader reader;
		reader.parse(curl.response(), root, false);

		std::cout << writer.write(root["form"]) << std::endl;
	} else {
		std::cerr << "error: " << curl.last_error() << std::endl;
	}

	return 0;
}
