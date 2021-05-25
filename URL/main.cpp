#include <iostream>
#include <string>
#include <vector>
#include "findurl.h"

using std::string;
using std::vector;
using std::cout;

int main(){
    string s = "https://github.com/xxalsgh0203https://www.acmicpc.net/problem/5639https://blog.naver.com/music4537";

    vector <string> result = find_urls(s);

    for(vector<string>::const_iterator it=result.begin(); it!=result.end(); ++it){
        cout << *it << '\n';
    }
}