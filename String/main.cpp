#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> split(const string& s){
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i=0;

    //불변성 : 지금까지 [원래의 i, 현재의 i) 범위에 있는 문자들을 처리
    while(i != s.size()){
        // 선행하는 공백들을 무시
        // 불변성: [원래의 i, 현재의 i) 범위에 있는 문자들은 모두 공백
        while(i != s.size() && isspace(s[i]))
            ++i;
        
        //순서상 다음 단어의 끝을 찾음
        string_size j = i;

        // 불변상: [원래의 j, 현재의 j) 범위에 있는 문자들은 공백이 아님.
        while(j != s.size() && !isspace(s[j]))
            j++;

        // 공백이 아닌 문자들을 찾았을 때
        if(i != j){
            // i에서부터 j-i 개의 문자들을 s 에 복사
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return ret;
}

int main(){
    string s;

    // 문자열을 한 행씩 입력받아 분할

}