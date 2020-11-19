#ifndef __CURL_H__
#define __CURL_H__

#include <curl/curl.h>
#include <json/json.h>
#include <string>
#include <map>

class Curl {
	

public:

	Curl();
	
	bool get(std::string);


	void set_post(std::string);
	bool post_raw(std::string, std::string);
	bool post_data(std::string, std::map<std::string, std::string>);
	bool post_json_styled(std::string, Json::Value);
	bool post_json_fast(std::string, Json::Value);
	bool post_json(std::string, Json::Value);
	bool put(std::string, std::string);
	
	std::string header_response();
	std::string response();
	std::string last_error();
	long code();

	void set_user_agent(std::string);
	std::string user_agent();

	void set_url(std::string);

	void set_no_progress(long);
	long no_progress();

	void set_max_redirs(long);
	long max_redirs();

	void set_keep_alive(long);
	long keep_alive();


	double total_time();

private:
	void set_opts();
	bool perform();
	void parse_response();

	char *buffer{nullptr};

	CURL *_curl;
	std::string _response, _header_response;
	long _code_reponse;
	
	std::string _user_agent{"curl/7.42.0"};
	std::string _url_request;
	std::string _last_error;
	char *_url_response;
	double _elapse;

	long _no_progress{1L}, _max_redirs{50L}, _keep_alive{1L};


};



#endif
