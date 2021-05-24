#include "frame.h"
#include <algorithm>
using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;
    for(vector<string>::size_type i=0; i!=v.size(); i++){
        maxlen = max(maxlen, v[i].size());
    }

    return maxlen;
}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // 상단 테두리를 추가
    ret.push_back(border);

    // 양 끝이 별표와 공백으로 둘러싸인 문자열들을 각각 추가
    for(vector<string>::size_type i=0; i!=v.size(); ++i){
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    // 하단 테두리를 추기
    ret.push_back(border);
    return ret;
}