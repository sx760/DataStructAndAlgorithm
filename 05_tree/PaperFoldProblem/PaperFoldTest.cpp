#include <string>
#include <iostream>

#include "Queue.h"

using namespace std;

string *down = new string("down");
string *up = new string("up");

template <class T>
class Node
{
public:
    Node(T *item, Node *left, Node *right)
    {
        item_ = item;
        left_ = left;
        right_ = right;
    }

    T *item_;
    Node *left_;
    Node *right_;
};

/**
 * @brief Create a Tree object
 * 
 * @param n 对折次数
 * @return Node* 
 */
Node<string> *createTree(int n)
{
    Node<string> *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) // 第一次对折
        {
            root = new Node<string>(down, nullptr, nullptr);
            continue;
        }
        // 层序遍历
        Queue<Node<string>> *q = new Queue<Node<string>>();
        q->enqueue(root);
        while (!q->isEmpty())
        {
            Node<string> *n = q->dequeue();

            if (n->left_ != nullptr)
            {
                q->enqueue(n->left_);
            }
            if (n->right_ != nullptr)
            {
                q->enqueue(n->right_);
            }

            if (n->left_ == nullptr && n->right_ == nullptr)
            {
                n->left_ = new Node<string>(down, nullptr, nullptr);
                n->right_ = new Node<string>(up, nullptr, nullptr);
            }
        }
    }

    return root;
}

void printTree(Node<string> *root)
{
    // 中序遍历
    if (root == nullptr)
    {
        return;
    }
    if (root->left_ != nullptr)
    {
        printTree(root->left_);
    }
    cout << *root->item_ << " ";
    if (root->right_ != nullptr)
    {
        printTree(root->right_);
    }
}

void deleteTree(Node<string> *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left_ != nullptr)
    {
        deleteTree(root->left_);
    }
    if (root->right_ != nullptr)
    {
        deleteTree(root->right_);
    }
    delete root;
    root = nullptr;
}

int main(int argc, char const *argv[])
{
    Node<string> *tree = createTree(3);
    printTree(tree);
    cout << endl;

    deleteTree(tree);
    delete down;
    delete up;
    return 0;
}
