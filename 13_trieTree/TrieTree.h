#ifndef TRIETREE_H
#define TRIETREE_H

#include <string>
#include <memory>

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
        Node(std::shared_ptr<char> item)
        {
            item_ = item;
            for (int i = 0; i < MAX; i++)
            {
                next_[i] = nullptr;
            }

            isEnd_ = false;
        }

        std::shared_ptr<char> item_;      // 存储的元素
        std::shared_ptr<Node> next_[MAX]; // 子节点
        bool isEnd_;                      // 是否有单词在此结尾
    };

public:
    TrieTree()
    {
        root_ = std::make_shared<Node>(nullptr);
    }

    void insert(const std::string &word)
    {
        if (word.empty())
        {
            return;
        }
        std::shared_ptr<Node> n = root_;
        int index = 0;
        for (auto ch : word)
        {
            index = ch - 'a';
            if (n->next_[index] == nullptr)
            {
                n->next_[index] = std::make_shared<Node>(std::make_shared<char>(ch));
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
        std::shared_ptr<Node> n = root_;
        for (auto ch : word)
        {
            if (n == nullptr)
            {
                return false;
            }
            n = n->next_[ch - 'a'];
        }
        return n->isEnd_;
    }

private:
    std::shared_ptr<Node> root_;

private:
};

#endif /* TRIETREE_H */
