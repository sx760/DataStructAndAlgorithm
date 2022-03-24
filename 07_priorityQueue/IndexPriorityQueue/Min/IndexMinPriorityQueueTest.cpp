#include "IndexMinPriorityQueue.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string *a = new string("A");
    string *b = new string("B");
    string *c = new string("C");
    string *d = new string("D");
    string *e = new string("E");
    string *f = new string("F");
    string *g = new string("G");
    IndexMinPriorityQueue<string> *queue = new IndexMinPriorityQueue<string>(10);
    queue->insert(0, a);
    queue->insert(1, c);
    queue->insert(2, f);

    queue->changeItem(2, b);

    while (!queue->isEmpty())
    {
        cout << queue->delMin() << " ";
    }
    
    cout << endl;

    delete queue;

    return 0;
}

