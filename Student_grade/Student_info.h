#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info{
    public:
        // 인터페이스
        std::istream& read(std::istream&);
        double grade() const;
    private:
        // 구현
        std::string name;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
bool did_all_hw(const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif