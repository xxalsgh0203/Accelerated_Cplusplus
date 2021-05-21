#include <iomanip>
#include <ios> // streamsize 사용
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept> // domain error 사용

using std::cin; using std::sort;
using std::cout; using std::string;
using std::endl; using std::streamsize; // 입출력 라이브러리에서 전송된 문자수나 버퍼크기를 나타내기 위해 사용
using std::setprecision; using std::vector;
using std::domain_error; using std::istream;

istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        hw.clear(); // 이전 내용을 제거

        double x; // 과제 점수를 읽음 

        while(in >> x) // EOF나 double이 아닌 유효하지 않은 데이터 값 발생할때까지 과제점수 반복해서 읽음
            hw.push_back(x);
        
        in.clear(); // 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
    }
    return in;
}

double grade(double midterm, double final, const vector<double>&hw){
    if(hw.size() == 0)
        throw domain_error("student has done no homework");

    return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}

// 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통쨰로 복사
double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if(size==0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

int main(){
    //학생의 이름을 묻고 입력받음
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    //중간시험과 기말시험의 점수를 묻고 입력받음
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    //과제점수를 물음 
    cout << "Enter all your Homework grades, "
            "followed by end-of-file: ";
    vector<double> homework;
    
    read_hw(cin, homework);

    
    // 종합 점수를 계산해 생성
    try{
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec) << endl;
    }
    catch(domain_error){
        cout << endl << "You must enter your grades. "
                        "Please try agin. " << endl;
        return 1;
    }

    return 0;
}