#include "TrieTree.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    TrieTree *tree = new TrieTree(); 
    tree->insert("hello");
    tree->insert("cat");
    tree->insert("car");
    tree->insert("dog");

    cout << "Exsit word 'carc' ?: " << tree->search("carc") << "\n";
    cout << "Exsit word 'ca' ?: " << tree->search("ca") << "\n";
    cout << "Prefix word 'ca' ?: " << tree->prefix("ca") << "\n";
    cout << "Exsit word 'your' ?: " << tree->search("your") << "\n";

    delete tree;

    return 0;
}

