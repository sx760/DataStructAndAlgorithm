#include "MinPriorityQueue.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string *s1 = new string("A");
    string *s2 = new string("B");
    string *s3 = new string("C");
    string *s4 = new string("D");
    string *s5 = new string("E");
    string *s6 = new string("F");
    string *s7 = new string("G");
    MinPriorityQueue<string> *queue = new MinPriorityQueue<string>(10);
    queue->insert(s3);
    queue->insert(s1);
    queue->insert(s2);
    queue->insert(s4);
    queue->insert(s5);
    queue->insert(s6);
    queue->insert(s7);

    while (!queue->isEmpty())
    {
        cout << *queue->delMin() << " ";
    }
    cout << endl;

    delete queue;

    return 0;
}

