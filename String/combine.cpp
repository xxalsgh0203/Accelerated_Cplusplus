#include "combine.h"
#include "frame.h"
using std::vector;
using std::string;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
    // 위쪽 문자 그림을 복사
    vector<string> ret = top;

    // 아래쪽 문자 그림을 복사
    // 방법 1: 
    // ret.insert(ret.end(), bottom.begin(), bottom.end());
    // 방법 2:
        for(vector<string>::const_iterator it=bottom.begin(); it!=bottom.end(); ++it){
        ret.push_back(*it);
    }
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;

    // 두 문자 사이에 공백 하나를 남김
    string::size_type width1 = width(left) + 1;

    // 왼쪽 문자 그림과 오른쪽 문자 그림의 요소를 살펴보는 인덱스
    vector<string>::size_type i = 0, j = 0;

    // 두 문자 그림의 모든 행을 살펴봄
    while(i!=left.size() || j!=right.size()){
        // 두 문자 그림의 문자들을 저장할 새로운 문자열을 생성
        string s;

        // 왼쪽 문자 그림에서 행 하나를 복사
        if(i != left.size())
            s = left[i++];

        // 공백을 포함하여 문자열을 적절한 너비까지 채움
        s += string(width1 - s.size(), ' ');

        // 오른쪽 문자 그림에서 행 하나를 복사
        if(j != right.size())
            s += right[j++];

        // 새로운 문자 그림에 문자열 s 를 추가
        ret.push_back(s);

    }

    return ret;
}