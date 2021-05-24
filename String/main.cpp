#include <vector>
#include <string>
#include <iostream>
#include <cctype> // isspace 함수
#include "split.h"
#include "frame.h"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::isspace;
using std::endl;

int main(){
    string s;

    // 문자열을 한 행씩 입력받아 분할
    while(getline(cin, s)){
        vector<string> v = split(s);

        vector<string> result = frame(v);
        for(vector<string>::size_type i=0; i<result.size(); i++){
            cout << result[i] << endl;
        }
    }

    return 0;
}

