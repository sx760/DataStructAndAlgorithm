#include "TrieTree.h"

#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    using namespace std;

    shared_ptr<TrieTree> tree = make_shared<TrieTree>(); 
    string s1("hello");
    string s2("world");
    string s3("hi");
    string s4("nihao");
    string s5("your");
    tree->insert(s1);
    tree->insert(s2);
    tree->insert(s3);
    tree->insert(s4);

    cout << "Exsit word 'hello' ?: " << tree->search(s1);
    cout << "Exsit word 'your' ?: " << tree->search(s5);

    return 0;
}

