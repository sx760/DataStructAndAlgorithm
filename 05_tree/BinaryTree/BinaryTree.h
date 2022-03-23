#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Queue.h"

template <class Key, class Value>
class BinaryTree
{
private:
    class Node
    {
    public:
        Node(Key *key, Value *value, Node *left, Node *right)
        {
            key_ = key;
            value_ = value;
            left_ = left;
            right_ = right;
        }

        Key *key_;
        Value *value_;
        Node *left_;
        Node *right_;
    };

public:
    BinaryTree()
    {
        root_ = nullptr;
        size_ = 0;
    }
    ~BinaryTree()
    {
        if (root_ != nullptr)
        {
            deleteMemeory(root_);
        }
    }

    int size() const { return size_; }

    void put(Key *key, Value *value)
    {
        root_ = put(root_, key, value);
    }

    Value *get(Key *key) const
    {
        return get(root_, key);
    }

    void del(Key *key)
    {
        del(root_, key);
    }

    /**
     * @brief 查找整个树中最小的键
     * 
     * @return Key* 
     */
    Key *minKey() const
    {
        return minKey(root_)->key_;
    }

    /**
     * @brief 查找整个树中最大的键
     * 
     * @return Key* 
     */
    Key *maxKey() const
    {
        return maxKey(root_)->key_;
    }

    /**
     * @brief 前序遍历
     * 
     * @return Queue<Key>
     */
    Queue<Key> preErgodic()
    {
        Queue<Key> keys;
        preErgodic(root_, keys);
        return keys;
    }

    /**
     * @brief 中序遍历
     * 
     * @return Queue<Key> 
     */
    Queue<Key> midErgodic()
    {
        Queue<Key> keys;
        midErgodic(root_, keys);
        return keys;
    }

    /**
     * @brief 后序遍历
     * 
     * @return Queue<Key> 
     */
    Queue<Key> afterErgodic()
    {
        Queue<Key> keys;
        afterErgodic(root_, keys);
        return keys;
    }

    /**
     * @brief 层序遍历
     * 
     * @return Queue<Key> 
     */
    Queue<Key> layerErgodic()
    {
        Queue<Key> keys;
        Queue<Node> *nodes = new Queue<Node>();

        nodes->enqueue(root_);
        while (!nodes->isEmpty())
        {
            Node *n = nodes->dequeue();
            keys.enqueue(n->key_);
            if (n->left_ != nullptr)
            {
                nodes->enqueue(n->left_);
            }
            if (n->right_ != nullptr)
            {
                nodes->enqueue(n->right_);
            }
        }

        delete nodes;
        return keys;
    }

    /**
     * @brief 最大深度
     * 
     * @return int 
     */
    int maxDepth()
    {
        return maxDepth(root_);
    }

private:
    void deleteMemeory(Node *x)
    {
        if (x == nullptr)
        {
            return;
        }
        if (x->left_ != nullptr)
        {
            deleteMemeory(x->left_);
        }
        if (x->right_ != nullptr)
        {
            deleteMemeory(x->right_);
        }
        delete x;
        x = nullptr;
    }

    Node *put(Node *x, Key *key, Value *value)
    {
        if (x == nullptr)
        {
            size_++;
            return new Node(key, value, nullptr, nullptr);
        }

        if ((*key - *(x->key_)) > 0)
        {
            x->right_ = put(x->right_, key, value);
        }
        else if ((*key - *(x->key_)) < 0)
        {
            x->left_ = put(x->left_, key, value);
        }
        else
        {
            x->value_ = value;
        }
        return x;
    }

    Value *get(Node *x, Key *key) const
    {
        if (x == nullptr)
        {
            return nullptr;
        }

        if ((*key - *(x->key_)) > 0)
        {
            return get(x->right_, key);
        }
        else if ((*key - *(x->key_)) < 0)
        {
            return get(x->left_, key);
        }
        else
        {
            return x->value_;
        }
    }

    Node *del(Node *x, Key *key)
    {
        if (x == nullptr)
        {
            return nullptr;
        }

        if ((*key - *(x->key_)) > 0)
        {
            x->right_ = del(x->right_, key);
        }
        else if ((*key - *(x->key_)) < 0)
        {
            x->left_ = del(x->left_, key);
        }
        else
        {
            size_--;
            if (x->right_ == nullptr)
            {
                return x->left_;
            }
            if (x->left_ == nullptr)
            {
                return x->right_;
            }

            Node *minNode = x->right_;
            while (minNode->left_ != nullptr)
            {
                minNode = minNode->left_;
            }
            Node *n = x->right_;
            while (n->left_ != nullptr)
            {
                if (n->left_->left_ == nullptr)
                {
                    n->left_ = nullptr;
                }
                else
                {
                    n = n->left_;
                }
            }

            minNode->left_ = x->left_;
            minNode->right_ = x->right_;
            x = minNode;
        }

        return x;
    }

    /**
     * @brief 查找指定树x中最小的键所在节点
     * 
     * @param x 指定树x
     * @return Node* 指定树x中最小的键所在节点
     */
    Node *minKey(Node *x)
    {
        if (x->left_ != nullptr)
        {
            return minKey(x->left_);
        }
        else
        {
            return x;
        }
    }

    /**
     * @brief 查找指定树x中最大的键所在节点
     * 
     * @param x 
     * @return Node* 
     */
    Node *maxKey(Node *x)
    {
        if (x->right_ != nullptr)
        {
            return maxKey(x->right_);
        }
        else
        {
            return x;
        }
    }

    void preErgodic(Node *x, Queue<Key> &keys)
    {
        if (x == nullptr)
        {
            return;
        }
        keys.enqueue(x->key_);
        if (x->left_ != nullptr)
        {
            preErgodic(x->left_, keys);
        }
        if (x->right_ != nullptr)
        {
            preErgodic(x->right_, keys);
        }
    }

    void midErgodic(Node *x, Queue<Key> &keys)
    {
        if (x == nullptr)
        {
            return;
        }
        if (x->left_ != nullptr)
        {
            midErgodic(x->left_, keys);
        }
        keys.enqueue(x->key_);
        if (x->right_ != nullptr)
        {
            midErgodic(x->right_, keys);
        }
    }

    void afterErgodic(Node *x, Queue<Key> &keys)
    {
        if (x == nullptr)
        {
            return;
        }

        if (x->left_ != nullptr)
        {
            afterErgodic(x->left_, keys);
        }
        if (x->right_ != nullptr)
        {
            afterErgodic(x->right_, keys);
        }
        keys.enqueue(x->key_);
    }

    int maxDepth(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }

        // x的最大深度, 左子树的最大深度, 右子树的最大深度
        int max = 0, maxL = 0, maxR = 0;
        if (x->left_ != nullptr)
        {
            maxL = maxDepth(x->left_);
        }
        if (x->right_ != nullptr)
        {
            maxR = maxDepth(x->right_);
        }
        max = maxL > maxR ? maxL + 1 : maxR + 1;

        return max;
    }

private:
    Node *root_;
    int size_;
};

#endif /* BINARYTREE_H */
