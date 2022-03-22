#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>

/**
 * @brief 符号表
 * 
 * @tparam Key 
 * @tparam Value 
 */
template <class Key, class Value>
class SymbolTable
{
private:
    class Node
    {
    public:
        Node(Key *key, Value *value, Node *next)
        {
            key_ = key;
            value_ = value;
            next_ = next;
        }

        Key *key_;
        Value *value_;
        Node *next_;
    };

public:
    SymbolTable()
    {
        head_ = new Node(nullptr, nullptr, nullptr);
        size_ = 0;
    }
    ~SymbolTable()
    {
        Node *temp = head_->next_;
        while (temp != nullptr)
        {
            Node *del = temp;
            temp = temp->next_;
            delete del;
        }
        if (head_ != nullptr)
        {
            delete head_;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SymbolTable *s)
    {

        return os;
    }

    int size()
    {
        return size_;
    }

    void put(Key *key, Value *value)
    {
        Node *n = head_;
        while (n->next_ != nullptr)
        {
            n = n->next_;
            if (*(n->key_) == *key)
            {
                n->value_ = value;
                return;
            }
        }

        Node *newNode = new Node(key, value, nullptr);
        Node *oldFirst = head_->next_;
        newNode->next_ = oldFirst;
        head_->next_ = newNode;
        size_++;
    }

    void del(Key *key)
    {
        Node *n = head_;
        while (n->next_ != nullptr)
        {
            if (*(n->next_->key_) == *key)
            {
                n->next_ = n->next_->next_;
                size_--;
                return;
            }
            n = n->next_;
        }
    }

    Value *get(Key *key)
    {
        Node *n = head_;
        while (n->next_ != nullptr)
        {
            n = n->next_;
            if (*(n->key_) == *key)
            {
                return n->value_;
            }
        }
        return nullptr;
    }

private:
    Node *head_;
    int size_;
};

#endif /* SYMBOLTABLE_H */
