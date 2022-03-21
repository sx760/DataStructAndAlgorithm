#ifndef TWOWAYLINKLIST_H
#define TWOWAYLINKLIST_H

#include <iostream>

template <class T>
class TwoWayLinkList
{
private:
    class Node
    {
    public:
        Node(T *item, Node *pre, Node *next)
        {
            item_ = item;
            pre_ = pre;
            next_ = next;
        }

        T *item_;
        Node *pre_;
        Node *next_;
    };

public:
    TwoWayLinkList()
    {
        head_ = new Node(nullptr, nullptr, nullptr);
        last_ = nullptr;
        size_ = 0;
    }
    ~TwoWayLinkList()
    {
        if (head_ != nullptr)
        {
            delete head_;
        }
        if (last_ != nullptr)
        {
            delete last_;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const TwoWayLinkList *ll)
    {
        Node *n = ll->head_;
        while (n->next_ != nullptr)
        {
            n = n->next_;
            os << *(n->item_);
            if (n->next_ != nullptr)
            {
                os << "<->";
            }
        }

        return os;
    }

    void clear()
    {
        head_->next_ = nullptr;
        head_->pre_ = nullptr;
        head_->item_ = nullptr;
        last_ = nullptr;
        size_ = 0;
    }

    int length()
    {
        return size_;
    }

    bool isEmpty()
    {
        return size_ == 0;
    }

    T *getFirst()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        else
        {
            return head_->next_->item_;
        }
    }

    T *getLast()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        else
        {
            return last_->item_;
        }
    }

    void insert(T *t)
    {
        if (isEmpty())
        {
            Node *newNode = new Node(t, head_, nullptr);
            last_ = newNode;
            head_->next_ = last_;
        }
        else
        {
            Node *oldLast = last_;
            Node *newNode = new Node(t, oldLast, nullptr);
            oldLast->next_ = newNode;
            last_ = newNode;
        }
        size_++;
    }

    void insert(int i, T *t)
    {
        if (i < 0 || i >= size_)
        {
            return;
        }
        Node *pre = head_;
        for (int index = 0; index < i; index++)
        {
            pre = pre->next_;
        }
        Node *curr = pre->next_;
        Node *newNode = new Node(t, pre, curr);
        pre->next_ = newNode;
        curr->pre_ = newNode;
        size_++;
    }

    T *get(int i)
    {
        Node *n = head_->next_;
        for (int index = 0; index < i; index++)
        {
            n = n->next_;
        }
        return n->item_;
    }

    int indexOf(T *t)
    {
        Node *n = head_;
        for (int i = 0; n->next_ != nullptr; i++)
        {
            n = n->next_;
            if (*(n->item_) == *t)
            {
                return i;
            }
        }
        return -1;
    }

    T *remove(int i)
    {
        Node *pre = head_;
        for (int index = 0; index < i; index++)
        {
            pre = pre->next_;
        }
        Node *curr = pre->next_;
        Node *after = curr->next_;

        pre->next_ = after;
        after->pre_ = pre;

        size_--;
        return curr->item_;
    }

private:
    Node *head_;
    Node *last_;
    int size_;
};

#endif /* TWOWAYLINKLIST_H */
