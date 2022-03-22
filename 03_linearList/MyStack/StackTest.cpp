#include  "Stack.h"

#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string str1 = "hello";
    string str2 = "world";
    string str3 = "your";
    string str4 = "name";
    Stack<string> *s = new Stack<string>();
    s->push(&str1);
    s->push(&str2);
    s->push(&str3);
    s->push(&str4);

    cout << s << endl;
    cout << "===============================\n";

    string *result = s->pop();
    cout << "pop is: " << *result << endl << s << endl;

    return 0;
}
