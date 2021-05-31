#include "Student_info.h"
#include "grade.h"
using std::istream;
using std::vector;

istream& Student_info::read(istream& in){
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const{
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s){
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw){
    if(in){
        hw.clear(); // 이전 내용을 제거

        double x; // 과제 점수를 읽음 

        while(in >> x) // EOF나 double이 아닌 유효하지 않은 데이터 값 발생할때까지 과제점수 반복해서 읽음
            hw.push_back(x);
        
        in.clear(); // 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
    }
    return in;
}

bool did_all_hw(const Student_info& s){
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end()); // find 함수의 반환값과 homework.end() 함수의 반환값을 비교하여 학생이 모든 과제를 제출했는지 확인
}