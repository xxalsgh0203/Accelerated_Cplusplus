#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm> // sort함수
#include <stdexcept> // domain_error 예외 선언
#include <vector> 
#include "grade.h"
#include "Student_info.h"

double median(std::vector<double> vec);
double optimistic_median(const std::vector<Student_info>& s);
#endif
