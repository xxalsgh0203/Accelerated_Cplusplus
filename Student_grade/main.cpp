#include <iomanip>
#include <ios> // streamsize 사용
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept> // domain error 사용
#include "median.h"
#include "Student_info.h"
#include "grade.h"
#include "analysis.h"

using std::cin; using std::sort;
using std::cout; using std::string;
using std::endl; using std::streamsize; // 입출력 라이브러리에서 전송된 문자수나 버퍼크기를 나타내기 위해 사용
using std::setprecision; using std::vector;
using std::domain_error; using std::istream;
using std::max;

int main(){
    vector<Student_info> students;
    Student_info student;
    string::size_type maxlen = 0;
    vector<Student_info> did, didnt;

    // 학생 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음, 숙제를 다한학생과 다 하지 않은 학생 분류
    while(read(cin, student)){
        maxlen = max(maxlen, student.name.size());
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // 두 집단에 데이터가 있는지 각각 확인하여 분석할 필요가 있는지 확인
    if(did.empty()){
        cout << "No Student did all the homework!" << endl;
        return 1;
    }
    if(didnt.empty()){
        cout << "Every Student did all the homework" << endl;
        return 1;
    }

    // 분석 실행
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
    
    return 0;
}