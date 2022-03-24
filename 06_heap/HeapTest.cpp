#include "Heap.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string *s1 = new string("A");
    string *s2 = new string("B");
    string *s3 = new string("C");
    string *s4 = new string("D");
    string *s5 = new string("E");
    string *s6 = new string("F");
    string *s7 = new string("G");
    string *result;
    Heap<string> *heap = new Heap<string>(10);
    heap->insert(s1);
    heap->insert(s2);
    heap->insert(s3);
    heap->insert(s4);
    heap->insert(s5);
    heap->insert(s6);
    heap->insert(s7);

    while ((result = heap->delMax()) != nullptr)
    {
        cout << *result << " ";
    }
    cout << endl;

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
    delete heap;
    return 0;
}
