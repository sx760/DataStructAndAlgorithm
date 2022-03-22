#ifndef ORDERSYMBOLTABLE_H
#define ORDERSYMBOLTABLE_H

#include <iostream>

/**
 * @brief 有序符号表
 * 
 * @tparam Key 
 * @tparam Value 
 */
template <class Key, class Value>
class OrderSymbolTable
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
    OrderSymbolTable()
    {
        head_ = new Node(nullptr, nullptr, nullptr);
        size_ = 0;
    }
    ~OrderSymbolTable()
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

    friend std::ostream &operator<<(std::ostream &os, const OrderSymbolTable *s)
    {
        Node *n = s->head_->next_;
        while (n != nullptr)
        {
            os << *(n->key_) << ":\t" << *(n->value_) << std::endl; 
            n = n->next_;
        }
        return os;
    }

    int size()
    {
        return size_;
    }

    void put(Key *key, Value *value)
    {
        Node *curr = head_->next_, *pre = head_;
        while (curr != nullptr && *(curr->key_) < *key)
        {
            pre = curr;
            curr = curr->next_;
        }
        
        if (curr != nullptr && *(curr->key_) == *key) // 替换
        {
            curr->value_ = value;
            return;
        }
        Node *newNode = new Node(key, value, curr);
        pre->next_ = newNode;
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

#endif /* ORDERSYMBOLTABLE_H */
