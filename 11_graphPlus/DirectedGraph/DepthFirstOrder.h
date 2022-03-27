#ifndef DEPTHFIRSTORDER_H
#define DEPTHFIRSTORDER_H

#include "Stack.h"
#include "DiGraph.h"

/**
 * @brief 顶点排序
 * 
 */
class DepthFirstOrder
{
public:
    DepthFirstOrder(DiGraph *G)
    {
        marked_ = new bool[G->V()];
        for (int i = 0; i < G->V(); i++)
        {
            marked_[i] = false;
        }
        reversePost_ = new Stack<int>();

        for (int v = 0; v < G->V(); v++)
        {
            if (!marked_[v])
            {
                dfs(G, v);
            }
        }
    }
    ~DepthFirstOrder()
    {
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
        if (reversePost_ != nullptr)
        {
            delete reversePost_;
            reversePost_ = nullptr;
        }
    }

    Stack<int> *reversePost() const
    {
        return reversePost_;
    }

private:
    /**
     * @brief 深度优先搜索进行顶点排序
     * 
     * @param G 
     * @param v 
     */
    void dfs(DiGraph *G, int v)
    {
        marked_[v] = true;
        for (auto w : *G->adj(v))
        {
            if (!marked_[w])
            {
                dfs(G, w);
            }
        }
        reversePost_->push(new int(v));
    }

private:
    bool *marked_;
    Stack<int> *reversePost_; // 存储顶点序列
};

#endif /* DEPTHFIRSTORDER_H */
