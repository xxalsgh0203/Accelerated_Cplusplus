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

    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
}
