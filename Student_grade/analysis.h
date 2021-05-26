#ifndef GUARD_analysis_h
#define GUARD_analysis_h
#include <vector>
#include <ostream>
#include "analysis.h"
#include "Student_info.h"

double median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, double analysis(const vector<Student_info>&), const vector<Student_info>&, const vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);

#endif