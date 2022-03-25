#include "Queue.h"

#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string *s1 = new string("hello");
    string *s2 = new string("world");
    string *s3 = new string("your");
    string *s4 = new string("name");
    Queue<string> *q = new Queue<string>();
    q->enqueue(s1);
    q->enqueue(s2);
    q->enqueue(s3);
    q->enqueue(s4);

    // cout << q << endl;

    Queue<string>::Iterator it = q->begin();
    for (it; it != q->end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto i : *q)
    {
        cout << i << " ";
    }
    cout << endl;
    
    
    cout << "delete is : " << *(q->dequeue()) << endl;
    cout << q << endl << q->size() << endl;

    delete q;
    delete s4;
    delete s3;
    delete s2;
    delete s1;

    return 0;
}


