#include <algorithm>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
using std::vector;
using std::ostream;
using std::string;
using std::endl;

double median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt){
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

double average_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students){
    
}

