#include "RedBlackTree.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    RedBlackTree<int, string> *tree = new RedBlackTree<int, string>();
    tree->put(new int(1), new string("hello"));
    tree->put(new int(2), new string("world"));
    tree->put(new int(3), new string("nihao"));

    cout << *tree->get(new int(1)) << "\n";
    cout << *tree->get(new int(2)) << "\n";
    cout << *tree->get(new int(3)) << "\n";

    cout << endl;

    return 0;
}

