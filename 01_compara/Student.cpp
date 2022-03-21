#include "Student.h"

Student::Student()
{
}

Student::Student(std::string username, int age) : username_(username), age_(age)
{
}

std::ostream &operator<<(std::ostream &os, const Student &s)
{
    os << "username: " << s.username_ << " age: " << s.age_ << std::endl;
    return os;
}

bool Student::operator>(const Student other)
{
    return age_ > other.age_;
}
