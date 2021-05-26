#include "findurl.h"
#include <algorithm> // findif, find 함수
#include <cctype> //isalnum 함수 : 인수로 전달한 문자가 알파벳이나 숫자인지 여부를 판단
using std::vector;
using std::string;

vector<string> find_urls(const string& s){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // 인수로 전달받은 문자열 전체를 탐색
    while(b != e){
        // ://의 앞쪽에서 하나 이상의 문자를 탐색
        b = url_beg(b, e);
        if(b != e){
            // 해당 문자를 찾았다면 URL 의 나머지 부분을 탐색
            iter after = url_end(b, e);

            // URL 을 저장
            ret.push_back(string(b, after));

            // 인수로 전달받은 문자열에서 또 다른 URL을 찾기 위해 b 를 증가
            b = after;
        }
    }
    return ret;
}

bool not_url_char(char c){
    // URL 에 들어갈 수 있는 알파벳과 숫자 이외의 문자
    static const string url_ch = "~!;/?:@=&$-_.+!*`'(),";

    // c가 URL에 들어갈 수 있는 문자인지 확인하면 음수를 반환
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
    static const string sep = "://";
    typedef string::const_iterator iter;

    // i는 구분 기호를 발견한 위치를 표시
    iter i = b;
    while((i = search(i, e, sep.begin(), sep.end())) != e){ // 찾고자 하는 순차열을 발견했을때 -> search 함수 호출이 끝나면 i는 함수에 전달된 문자열의 마지막 부분 가리키거나 :를 가리키고 있을것임
        // 구분 기호가 현재 탐색 범위의 처음 또는 마지막에 있는지 확인
        if(i != b && i + sep.size() != e){
            // beg 는 프로토콜 이름의 시작 위치를 표시
            iter beg = i;
            while(beg != b && isalpha(beg[-1])) // 컨테이너가 인덱스를 지원하면 반복자도 인덱스를 지원한다는 사실
                --beg;  // 알파벳이 아닌 문자나 현재 탐색범위의 처음에 도달할때까지 반복자 beg를 거꾸로 이동

            // 구분 기호 앞뒤로 URL의 일부에서 유효한 문자가 하나라도 있는지 확인
            if(beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        // 발견한 구분 기호(구분 기호의 위치가 현재 탐색 범위의 처음 또는 마지막에 위치) 는 URL 일부가 아니므로 해당 구분 기호 이후를 표시하도록 i를 증가시킴
        i += sep.size();
    }
    return e;
}

