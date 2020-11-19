#Curl


So easy as


<h2>get example</h2>

```

std::string get_example(std::string url) {
	Curl curl;
	curl.get(url);
	return curl.response();
}

```

<h2>post example</h2>

```

std::string post_example(std::string url, Json::value) {
	Curl curl;
	curl.post_json(url, value);
	return curl.response();
}

```

<h2>put example</h2>

```

std::string put_example(std::string url, std::string filename) {
	Curl curl;
	curl.put(url, filename);
	return curl.response();
}

```


<h2>You can get the error with</h2>

```

std::string error_example(std::string url) {
	Curl.curl;
	bool ok = curl.get(url);
	if (not ok)
		return curl.last_error();
	return "not has error";
}

```


<h2>The functions are<h2/>

```

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

```

