#ifndef TRIETREE_H
#define TRIETREE_H

#include <string>

/**
 * @brief 字典树
 * 
 */
class TrieTree
{
private:
    static const int MAX = 123; // a-Z (65 - 122)

    class Node
    {
    public:
        Node(char *item)
        {
            item_ = item;
            for (int i = 0; i < MAX; i++)
            {
                next_[i] = nullptr;
            }

            isEnd_ = false;
        }
        ~Node()
        {
            if (item_ != nullptr)
            {
                delete item_;
            }
        }

        char *item_;      // 存储的元素
        Node *next_[MAX]; // 子节点
        bool isEnd_;      // 是否有单词在此结尾
    };

public:
    TrieTree()
    {
        root_ = new Node(nullptr);
    }
    ~TrieTree()
    {
        deleteMemory(root_);
    }

    void insert(const std::string &word)
    {
        if (word.empty())
        {
            return;
        }
        Node *n = root_;
        int index = 0;
        for (auto ch : word)
        {
            index = ch - 'a';
            if (n->next_[index] == nullptr)
            {
                n->next_[index] = new Node(new char(ch));
            }
            n = n->next_[index];
        }
        n->isEnd_ = true;
    }

    bool search(const std::string &word) const
    {
        if (word.empty())
        {
            return false;
        }
        Node *n = root_;
        for (auto ch : word)
        {
            n = n->next_[ch - 'a'];
            if (n == nullptr)
            {
                return false;
            }
        }
        return n->isEnd_;
    }

    bool prefix(const std::string &word) const
    {
        if (word.empty())
        {
            return false;
        }
        Node *n = root_;
        for (auto ch : word)
        {
            n = n->next_[ch - 'a'];
            if (n == nullptr)
            {
                return false;
            }
        }
        return true;
    }

private:
    void deleteMemory(Node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        for (int i = 0; i < MAX; i++)
        {
            if (n->next_[i] != nullptr)
            {
                deleteMemory(n->next_[i]);
            }
        }
        delete n;
        n = nullptr;
    }

private:
    Node *root_;

};

#endif /* TRIETREE_H */
