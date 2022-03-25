#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

/**
 * @brief 红黑树
 * 
 * @tparam Key 
 * @tparam Value 
 */
template <class Key, class Value>
class RedBlackTree
{
private:
    class Node
    {
    public:
        Node(Key *key, Value *value, Node *left, Node *right, bool color)
        {
            key_ = key;
            value_ = value;
            left_ = left;
            right_ = right;
            color_ = color;
        }

        Key *key_;
        Value *value_;
        Node *left_;
        Node *right_;
        bool color_; // 其父节点指向它的链接的颜色: red为true, black为false
    };

public:
    RedBlackTree()
    {
        root_ = nullptr;
        size_ = 0;
    }
    ~RedBlackTree()
    {
        deleteMemory(root_);
    }

    int size() const { return size_; }

    void put(Key *key, Value *value)
    {
        root_ = put(root_, key, value);
        root_->color_ = BLACK;
    }

    Value *get(Key *key) const
    {
        return get(root_, key);
    }

private:
    void deleteMemory(Node *x)
    {
        if (x == nullptr)
        {
            return;
        }

        if (x->left_ != nullptr)
        {
            deleteMemory(x->left_);
        }
        if (x->right_ != nullptr)
        {
            deleteMemory(x->right_);
        }
        delete x;
        x = nullptr;
    }

    bool isRed(Node *x) const
    {
        if (x == nullptr)
        {
            return false;
        }

        return x->color_ == RED;
    }

    /**
     * @brief 左旋
     * 
     * @param h 
     * @return Node* 
     */
    Node *rotateLeft(Node *h)
    {
        Node *x = h->right_;
        h->right_ = x->left_;
        x->left_ = h;

        x->color_ = h->color_;
        h->color_ = RED;

        return x;
    }

    /**
     * @brief 右旋
     * 
     * @param h 
     * @return Node* 
     */
    Node *rotateRight(Node *h)
    {
        Node *x = h->left_;
        h->left_ = x->right_;
        x->right_ = h;

        x->color_ = h->color_;
        h->color_ = RED;

        return x;
    }

    /**
     * @brief 颜色反转
     * 
     * @param h 
     */
    void flipColors(Node *h)
    {
        h->color_ = RED;
        h->left_->color_ = BLACK;
        h->right_->color_ = BLACK;
    }

    Node *put(Node *h, Key *key, Value *value)
    {
        if (h == nullptr)
        {
            size_++;
            return new Node(key, value, nullptr, nullptr, RED);
        }

        if (*key < *h->key_)
        {
            // 向左
            h->left_ = put(h->left_, key, value);
        }
        else if (*key > *h->key_)
        {
            // 向右
            h->right_ = put(h->right_, key, value);
        }
        else
        {
            // 替换
            h->value_ = value;
        }

        // 左旋: 当前节点的左子节点为黑, 右子节点为红
        if (!isRed(h->left_) && isRed(h->right_))
        {
            h = rotateLeft(h);
        }

        // 右旋: 当前节点的左子节点和左子节点的左子节点为红
        if (isRed(h->left_) && isRed(h->left_->left_))
        {
            h = rotateRight(h);
        }

        // 颜色反转: 当前节点的左子节点和右子节点为红
        if (isRed(h->left_) && isRed(h->right_))
        {
            flipColors(h);
        }

        return h;
    }

    Value *get(Node *x, Key *key) const
    {
        if (x == nullptr)
        {
            return nullptr;
        }

        if (*key < *x->key_)
        {
            return get(x->left_, key);
        }
        else if (*key > *x->key_)
        {
            return get(x->right_, key);
        }
        else
        {
            return x->value_;
        }
    }

private:
    Node *root_;
    int size_;

    const static bool RED = true;
    const static bool BLACK = false;
};

#endif /* REDBLACKTREE_H */
