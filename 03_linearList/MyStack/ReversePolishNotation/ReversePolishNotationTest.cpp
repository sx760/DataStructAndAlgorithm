#include "Stack.h"

#include <iostream>

double caculate(std::string *notation, int n)
{
    using std::string;
    Stack<double> *s = new Stack<double>();
    for (int i = 0; i < n; i++)
    {
        string curr = notation[i];
        double o1;
        double o2;
        double result;
        if (curr == "+")
        {
            o1 = *(s->pop());
            o2 = *(s->pop());
            result = o2 + o1;
        }
        else if (curr == "-")
        {
            o1 = *(s->pop());
            o2 = *(s->pop());
            result = o2 - o1;
        }
        else if (curr == "*")
        {
            o1 = *(s->pop());
            o2 = *(s->pop());
            result = o2 * o1;
        }
        else if (curr == "/")
        {
            o1 = *(s->pop());
            o2 = *(s->pop());
            result = o2 / o1;
        }
        else
        {
            result = atof(curr.c_str());
        }
        double *pResult = new double(result);
        s->push(pResult);
    }
    int caculateResult = *(s->pop());
    delete s;
    return caculateResult;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    string notation[] = {"3", "17", "15", "-", "*", "18", "6", "/", "+"};
    cout << "result is : " << caculate(notation, 9) << endl;

    return 0;
}
