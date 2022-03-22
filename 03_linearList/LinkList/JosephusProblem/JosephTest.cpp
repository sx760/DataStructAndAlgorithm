#include <iostream>

template <class T>
class Node
{
public:
    Node(T *item, Node *next)
    {
        item_ = item;
        next_ = next;
    }

    T *item_;
    Node *next_;
};

void josephTest()
{
    Node<int> *first = nullptr;
    Node<int> *pre = nullptr;
    for (int i = 1; i <= 41; i++)
    {
        int *pi = new int(i);
        if (i == 1)
        {
            first = new Node<int>(pi, nullptr);
            pre = first;
            continue;
        }
        Node<int> *newNode = new Node<int>(pi, nullptr);
        pre->next_ = newNode;
        pre = newNode;
        if (i == 41)
        {
            pre->next_ = first;
        }
    }

    int count = 0;
    Node<int> *n = first, *nDel, *before = nullptr;
    while (n != n->next_)
    {
        count++;
        if (count == 3)
        {
            before->next_ = n->next_;
            std::cout << *(n->item_) << ",";
            count = 0;
            nDel = n;
            n = n->next_;
            delete nDel;
        }
        else
        {
            before = n;
            n = n->next_;
        }
    }
    std::cout << *(n->item_) << std::endl;
    delete n;
}

int main(int argc, char const *argv[])
{
    josephTest();
    return 0;
}
