#include <iomanip>
#include <ios> // streamsize 사용
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin; using std::sort;
using std::cout; using std::string;
using std::endl; using std::streamsize; // 입출력 라이브러리에서 전송된 문자수나 버퍼크기를 나타내기 위해 사용
using std::setprecision; using std::vector;

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
    double x;

    while(cin >> x)
        homework.push_back(x);

    //과제 점수의 입력 유무를 확인
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if(size == 0){
        cout << endl << "You must enter your grades. "
                            "Please try again. " << endl;
        return 1;
    }

    //점수를 정렬
    sort(homework.begin(), homework.end());

    //과제 점수의 중앙값을 구힘
    vec_sz mid = size/2;
    double median;
    median = size%2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];


    //최종 점수를 구해서 출력
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median << setprecision(prec) << endl;

    return 0;
}