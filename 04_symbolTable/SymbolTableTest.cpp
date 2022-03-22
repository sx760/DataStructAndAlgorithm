#include "SymbolTable.h"

#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;
    SymbolTable<int, string> *s = new SymbolTable<int, string>();
    int k1 = 1;
    int k2 = 2;
    int k3 = 3;
    int c = 3;
    cout << "address of k3: " << &k3 << endl;
    cout << "address of c: " << &c << endl;
    string v1 = "hello";
    string v2 = "world";
    string v3 = "nihao";
    string v4 = "your";
    s->put(&k1, &v1);
    s->put(&k2, &v2);
    s->put(&k3, &v3);

    cout << "size is : " << s->size() <<  endl;

    s->put(&k3, &v4);
    cout << "size is : " << s->size() << endl;

    cout << "key " << c << " is : " << *(s->get(&c)) << endl;

    s->del(&k3);
    cout << "size is : " << s->size() << endl;

    delete s;

    return 0;
}

