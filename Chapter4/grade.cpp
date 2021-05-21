#include "grade.h"
#include "median.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double final, const vector<double>&hw){
    if(hw.size() == 0)
        throw domain_error("student has done no homework");

    return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}

double grade(const Student_info& s){ // 오버로딩
    return grade(s.midterm, s.final, s.homework);
}