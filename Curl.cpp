#include "Curl.h"
#include "Util.hpp"

#include <map>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>

Curl::Curl() {
	_curl = curl_easy_init();
	

}

void Curl::set_opts() {
	curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, _no_progress);
	curl_easy_setopt(_curl, CURLOPT_MAXREDIRS, _max_redirs);
	curl_easy_setopt(_curl, CURLOPT_TCP_KEEPALIVE, _keep_alive);
	curl_easy_setopt(_curl, CURLOPT_USERAGENT, _user_agent.c_str());
	
	
	curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, writeFunction);
	curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_response);
	curl_easy_setopt(_curl, CURLOPT_HEADERDATA, &_header_response);

	curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE, &_code_reponse);
	curl_easy_getinfo(_curl, CURLINFO_TOTAL_TIME, &_elapse);
	curl_easy_getinfo(_curl, CURLINFO_EFFECTIVE_URL, &_url_response);
	
	curl_easy_setopt(_curl, CURLOPT_URL, _url_request.c_str());
}



bool Curl::perform() {
	bool ret = false;

	CURLcode res;
	res = curl_easy_perform(_curl);
	_last_error = curl_easy_strerror(res);
	
	return ret == CURLE_OK;
}





void Curl::set_url(std::string url) {
	_url_request = url;
}


	
bool Curl::get(std::string url) {
	set_url(url);
	set_opts();
	return perform();
}



void Curl::set_post(std::string pst) {
	if (buffer)
		delete buffer;
	buffer = new char[pst.length()];
	strcpy(buffer, pst.c_str());
	curl_easy_setopt(_curl, CURLOPT_POST, 1);
	curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, buffer);
}
	



bool Curl::post_raw(std::string url, std::string raw) {
	set_url(url);
	set_opts();
	set_post(raw);
	return perform();
}



bool Curl::post_data(std::string url, std::map<std::string, std::string> data) {
	return post_raw(url, join_with(data, "=", "&"));
}


bool Curl::post_json_styled(std::string url, Json::Value value) {
	return post_raw(url, Json::StyledWriter().write(value));
}

bool Curl::post_json_fast(std::string url, Json::Value value) {
	return post_raw(url, Json::FastWriter().write(value));
}

bool Curl::post_json(std::string url, Json::Value value) {
	return post_json_fast(url, value);
}

bool Curl::put(std::string url, std::string file) {
	FILE *fp = fopen(file.c_str(), "rb");
	if (fp == NULL) {
		_last_error = file+" not found.";
		return false;
	}
	
	struct stat file_stat;
	stat(file.c_str(), &file_stat);
	
	set_url(url);
	set_opts();
	curl_easy_setopt(_curl, CURLOPT_READFUNCTION, fread);
	curl_easy_setopt(_curl, CURLOPT_UPLOAD, 1L);
	curl_easy_setopt(_curl, CURLOPT_READDATA, fp);
	curl_easy_setopt(_curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)file_stat.st_size);
	return perform();
}


std::string Curl::header_response() {
	return _header_response;
}

std::string Curl::response() {
	return _response;
}

long Curl::code() {
	return _code_reponse;
}


void Curl::set_no_progress(long np) {
	_no_progress = np;
}

long Curl::no_progress() {
}


void Curl::set_max_redirs(long mr) {
	_max_redirs = mr;
}

long Curl::max_redirs() {
	return _max_redirs;
}

void Curl::set_keep_alive(long ka) {
	_keep_alive = ka;
}

long Curl::keep_alive() {
	return _keep_alive;
}


void Curl::set_user_agent(std::string ua) {
	_user_agent = ua;
}


std::string Curl::user_agent() {
	return _user_agent;
}

double Curl::total_time() {
	return _elapse;
}

std::string Curl::last_error() {
	return _last_error;
}
