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
        ~Node()
        {
            if (item_ != nullptr)
            {
                delete item_;
                item_ = nullptr;
            }
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
        deleteMemory(head_);
    }

    /* Stack *operator=(const Stack *other) 
    {
        if (this != other)
        {
            if (head_ != nullptr)
            {
                delete head_;
            }
            head_ = new Node(nullptr, other->head_);
            size_ = other->size_;
        }
        return this;
    } */

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

public: // 迭代器实现
    class Iterator
    {
        friend class Stack<T>;

    public:
        Iterator() {}

        bool operator==(const Iterator &iter) const { return curr_ == iter.curr_; }
        bool operator!=(const Iterator &iter) const { return curr_ != iter.curr_; }
        T &operator*() const { return *curr_->item_; }
        Iterator operator++(int) // iter++
        {
            Iterator temp = *this;
            curr_ = curr_->next_;
            return temp;
        }
        Iterator &operator++() // ++iter
        {
            curr_ = curr_->next_;
            return *this;
        }

    protected:
        Node *curr_;
        Iterator(Node *n) { curr_ = n; }
    };

    Iterator begin()
    {
        return Iterator(head_->next_);
    }
    Iterator end()
    {
        return Iterator(nullptr);
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
