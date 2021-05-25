#ifndef GUARD_findurl_h
#define GUARD_findurl_h

#include <vector>
#include <string>

std::vector<std::string> find_urls(const std::string&);
bool not_url_char(char c);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);

#endif