#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T>
class Queue
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
    Queue()
    {
        head_ = new Node(nullptr, nullptr);
        last_ = nullptr;
        size_ = 0;
    }
    /* ~Queue()
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
    ~Queue()
    {
        deleteMemory(head_);
    }

    friend std::ostream &operator<<(std::ostream &os, const Queue *q)
    {
        Node *n = q->head_->next_;
        while (n != nullptr)
        {
            os << *(n->item_);
            n = n->next_;
            if (n != nullptr)
            {
                os << ",";
            }
        }
        return os;
    }

    bool isEmpty() const { return size_ == 0; }
    int size() const { return size_; }

    void enqueue(T *t)
    {
        if (last_ == nullptr)
        {
            last_ = new Node(t, nullptr);
            head_->next_ = last_;
        }
        else
        {
            Node *oldLast = last_;
            last_ = new Node(t, nullptr);
            oldLast->next_ = last_;
        }
        size_++;
    }

    T *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        Node *oldFirst = head_->next_;
        head_->next_ = oldFirst->next_;
        size_--;
        if (isEmpty())
        {
            last_ = nullptr;
        }
        return oldFirst->item_;
    }

public: // 迭代器实现
    class Iterator
    {
        friend class Queue<T>;

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
    Node *last_;
    int size_;
};

#endif /* QUEUE_H */
