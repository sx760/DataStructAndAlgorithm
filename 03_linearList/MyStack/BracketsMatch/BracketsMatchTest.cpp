#include "Stack.h"

#include <iostream>
#include <string>

bool isMatch(std::string &str)
{
    Stack<char> *s = new Stack<char>();
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            s->push(&ch);
        }
        else if (ch == ')')
        {
            char *pop = s->pop();
            if (pop == nullptr)
            {
                return false;
            }
        }
        else
        {
            continue;
        }
    }

    if (s->isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    using namespace std;

    string str = "((HELLO)(world)))";
    cout << "\"" << str << "\" barckets match? ";
    if (isMatch(str))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No " << endl;
    }

    return 0;
}
