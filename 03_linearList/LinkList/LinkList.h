#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

template <class T>
class LinkList
{
public:
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
    LinkList()
    {
        head_ = new Node(nullptr, nullptr);
        n_ = 0;
    }
    ~LinkList()
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

    void clear()
    {
        head_->next_ = nullptr;
        n_ = 0;
    }

    int length() const
    {
        return n_;
    }

    bool isEmpty() const
    {
        return n_ == 0;
    }

    T *get(int i) const
    {
        Node *n = head_->next_;
        for (int index = 0; index < i; index++)
        {
            n = n->next_;
        }
        return n->item_;
    }

    void insert(T *t)
    {
        Node *n = head_;
        while (n->next_ != nullptr)
        {
            n = n->next_;
        }

        Node *newNode = new Node(t, nullptr);
        n->next_ = newNode;
        n_++;
    }

    void insert(int i, T *t)
    {
        if (i < 0 || i >= n_)
        {
            return;
        }
        Node *pre = head_;
        for (int index = 0; index < i; index++)
        {
            pre = pre->next_;
        }
        Node *curr = pre->next_;

        Node *newNode = new Node(t, curr);
        pre->next_ = newNode;
        n_++;
    }

    T *remove(int i)
    {
        Node *pre = head_;
        for (int index = 0; index < i; index++)
        {
            pre = pre->next_;
        }
        Node *curr = pre->next_;
        Node *nextNode = curr->next_;
        pre->next_ = nextNode;
        n_--;
        return curr->item_;
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

    /**
    * @brief ????????????
    * 
    */
    void reverse()
    {
        if (isEmpty())
        {
            return;
        }
        reverse(head_->next_);
    }

    /**
     * @brief ?????????????????????
     * 
     * @param curr ???????????????
     * @return Node* ??????????????????
     */
    Node *reverse(Node *curr)
    {
        if (curr->next_ == nullptr)
        {
            head_->next_ = curr;
            return curr;
        }
        Node *pre = reverse(curr->next_);
        pre->next_ = curr;
        curr->next_ = nullptr;
        return curr;
    }

    friend std::ostream &operator<<(std::ostream &os, const LinkList *ll)
    {
        Node *n = ll->head_;
        while (n->next_ != nullptr)
        {
            n = n->next_;
            os << *(n->item_);
            if (n->next_ != nullptr)
            {
                os << "->";
            }
        }
        return os;
    }

private:
    Node *head_;
    int n_;
};

#endif /* LINKLIST_H */
