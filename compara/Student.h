#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
public:
    Student();
    Student(std::string username, int age);

    friend std::ostream &operator<<(std::ostream &os, const Student& s);
    bool operator>(const Student other);

    std::string getUsername() const { return username_; }
    void setUsername(const std::string &username) { username_ = username; }

    int getAge() const { return age_; }
    void setAge(const int age) { age_ = age; }

private:
    std::string username_;
    int age_;
};
#endif /* STUDENT_H */
