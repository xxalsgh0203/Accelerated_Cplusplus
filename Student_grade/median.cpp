#include "median.h"
using std::domain_error;
using std::sort;
using std::vector;

// vector<double> 타입 객체의 중앙값을 구함
// 이 함수를 호출하면 인수로 전달된 벡터 전체를 복사
template <class T>
T median(vector<T> vec){
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = vec.size();

    if(size==0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double optimistic_median(const Student_info& s){
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if(nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

