#include "Student.h"

int main(int argc, char const *argv[])
{
    Student s1("Hello", 14);
    Student s2("World", 21);

    if (s1 > s2)
    {
        std::cout << s1;
    }
    else
    {
        std::cout << s2;
    }
    return 0;
}
