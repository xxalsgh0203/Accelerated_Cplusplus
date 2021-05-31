#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "median.h"
#include "Student_info.h"
#include "grade.h"
#include "analysis.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main(){
    vector<Student_info> students;
    Student_info student;
    vector<Student_info> did, didnt;

    // 학생 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음, 숙제를 다한학생과 다 하지 않은 학생 분류
    while(read(cin, student)){
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // 두 집단에 데이터가 있는지 각각 확인하여 분석할 필요 가 있는지 확인
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