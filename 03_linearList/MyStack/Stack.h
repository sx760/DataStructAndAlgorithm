#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
{
private:
    class Node
    {
    public:
        Node(T *item, Node *next) : item_(item), next_(next)
        {
        }

        T *item_;
        Node *next_;
    };

public:
    Stack()
    {
        head_ = new Node(nullptr, nullptr);
        size_ = 0;
    }
    /* ~Stack()
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
    } */
    ~Stack()
    {
        if (head_ != nullptr)
        {
            deleteMemory(head_);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack *s)
    {
        Node *n = s->head_->next_;
        while (n != nullptr)
        {
            os << *(n->item_);
            n = n->next_;
            if (n != nullptr)
            {
                os << "->";
            }
        }
        return os;
    }

    bool isEmpty() const { return size_ == 0; }
    int size() const { return size_; }

    void push(T *t)
    {
        Node *oldFirst = head_->next_;
        Node *newNode = new Node(t, nullptr);
        head_->next_ = newNode;
        newNode->next_ = oldFirst;
        size_++;
    }

    T *pop()
    {
        Node *oldFirst = head_->next_;
        if (oldFirst == nullptr)
        {
            return nullptr;
        }
        head_->next_ = oldFirst->next_;
        size_--;
        return oldFirst->item_;
    }

private:
    void deleteMemory(Node *x)
    {
        if (x == nullptr)
        {
            return;
        }
        
        if (x->next_ != nullptr)
        {
            deleteMemory(x->next_);
        }
        
        delete x;
        x = nullptr;
    }

private:
    Node *head_;
    int size_;
};

#endif /* STACK_H */
