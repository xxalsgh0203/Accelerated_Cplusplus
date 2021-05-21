#include <iomanip>
#include <ios> // streamsize 사용
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept> // domain error 사용
#include "median.h"
#include "Student_info.h"

using std::cin; using std::sort;
using std::cout; using std::string;
using std::endl; using std::streamsize; // 입출력 라이브러리에서 전송된 문자수나 버퍼크기를 나타내기 위해 사용
using std::setprecision; using std::vector;
using std::domain_error; using std::istream;
using std::max;


double grade(double midterm, double final, const vector<double>&hw){
    if(hw.size() == 0)
        throw domain_error("student has done no homework");

    return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}

double grade(const Student_info& s){ // 오버로딩
    return grade(s.midterm, s.final, s.homework);
}


int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 학생 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음
    while(read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i=0; i!=students.size(); ++i){
        // 이름과 오른쪽 공백을 포함하여 maxlen + 1 개의 문자를 출력
        cout << students[i].name << string(maxlen+1 - students[i].name.size(), ' ');

        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }

        catch(domain_error e){
            cout << e.what();
        }
    }
    
    return 0;
}