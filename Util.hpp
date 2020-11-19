#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include <map>

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}


std::string join_with(std::map<std::string, std::string> mp, std::string sig, std::string el) {
	std::string ret;
	for (auto it = mp.begin(); it != mp.end(); it++)
		ret += it->first + sig + it->second + el;
	
	ret.pop_back(); //remove last end-of-line
	return ret;
}




#endif
