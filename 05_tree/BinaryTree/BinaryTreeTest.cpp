#include "BinaryTree.h"

#include <iostream>
#include <string>

/* int main(int argc, char const *argv[])
{
    using namespace std;
    int *k1 = new int(1);
    int *k2 = new int(2);
    int *k3 = new int(3);
    int *k4 = new int(4);
    string *v1 = new string("hello");
    string *v2 = new string("world");
    string *v3 = new string("nihao");
    string *v4 = new string("hi");

    BinaryTree<int, string> *tree = new BinaryTree<int, string>();
    tree->put(k1, v1);
    tree->put(k2, v2);
    tree->put(k3, v3);
    cout << "size is: " << tree->size() << endl;

    cout << "key " << *k2 << " value is: " << *tree->get(k2) << endl;

    tree->del(k3);
    cout << "size is: " << tree->size() << endl;
    if (tree->get(k3) == nullptr)
    {

        cout << "key " << *k3 << " value is: " << "nullptr" << endl;
    }

    delete tree;
    delete k1;
    delete k2;
    delete k3;
    delete k4;
    delete v1;
    delete v2;
    delete v3;
    delete v4;

    return 0;
} */

int main(int argc, char const *argv[])
{
    using namespace std;

    char *k1 = new char('E');
    string *v1 = new string("5");
    char *k2 = new char('B');
    string *v2 = new string("2");
    char *k3 = new char('G');
    string *v3 = new string("7");
    char *k4 = new char('A');
    string *v4 = new string("1");
    char *k5 = new char('D');
    string *v5 = new string("4");
    char *k6 = new char('F');
    string *v6 = new string("6");
    char *k7 = new char('H');
    string *v7 = new string("8");
    char *k8 = new char('C');
    string *v8 = new string("3");

    BinaryTree<char, string> *tree = new BinaryTree<char, string>();
    tree->put(k1, v1);
    tree->put(k2, v2);
    tree->put(k3, v3);
    tree->put(k4, v4);
    tree->put(k5, v5);
    tree->put(k6, v6);
    tree->put(k7, v7);
    tree->put(k8, v8);

    Queue<char> keysPre = tree->preErgodic();
    Queue<char> keysMid = tree->midErgodic();
    Queue<char> keysAft = tree->afterErgodic();
    Queue<char> keysLay = tree->layerErgodic();
    cout << "pre ergodic: " << &keysPre << endl;
    cout << "mid ergodic: " << &keysMid << endl;
    cout << "aft ergodic: " << &keysAft << endl;
    cout << "lay ergodic: " << &keysLay << endl;

    cout << "max depth is: " << tree->maxDepth() << endl;

    int keysSize = keysPre.size();
    /* for (int i = 0; i < keysSize; i++)
    {
        char *key = keys.dequeue();
        cout << *key << "----" << *tree->get(key) << endl;
    } */
    cout << endl;

    delete k1;
    delete v1;
    delete k2;
    delete v2;
    delete k3;
    delete v3;
    delete k4;
    delete v4;
    delete k5;
    delete v5;
    delete k6;
    delete v6;
    delete k7;
    delete v7;
    delete k8;
    delete v8;

    delete tree;

    return 0;
}
