#include "grade.h"
#include "median.h"
#include <numeric> // accumulate 함수
using std::vector;
using std::list;
using std::domain_error;

double grade(double midterm, double final, const vector<double>&hw){
    if(hw.size() == 0)
        throw domain_error("student has done no homework");

    return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}

double grade(const Student_info& s){ // 오버로딩
    return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s){
    try{
        return grade(s);
    }
    catch(domain_error){
        return grade(s.midterm, s.final, 0);
    }
}


// 학생의 과락 여부를 결정하는 서술 함수
bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

double average(const vector<double>& v){
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s){
    return grade(s.midterm, s.final, average(s.homework));
}

// 기준 점수를 통과한 학생과 통과하지 못한 학생의 정보를 분류
list<Student_info> extract_fails(list<Student_info>& students){
    
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    while(iter!=students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}