#include "split.h"
#include <algorithm> // find_if
using std::vector;
using std::string;

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string> split(const string& str){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();

    while(i != str.end()){
        // 선행 공백을 무시
        // 첫번째 문자를 찾음
        i = find_if(i, str.end(), not_space);

        // 다음 단어의 끝을 찾음
        iter j = find_if(i, str.end(), space);

        // [i,j] 의 범위의 문자를 복사
        if(i != str.end())
            ret.push_back(string(i, j));

        i = j;
    }
    return ret;
}