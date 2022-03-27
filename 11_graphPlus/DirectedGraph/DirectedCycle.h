#ifndef DIRECTEDCYCLE_H
#define DIRECTEDCYCLE_H

#include "DiGraph.h"

/**
 * @brief 检测有向环
 * 
 */
class DirectedCycle
{
public:
    DirectedCycle(DiGraph *G)
    {
        marked_ = new bool[G->V()];
        hasCycle_ = false;
        onStack_ = new bool[G->V()];
        for (int i = 0; i < G->V(); i++)
        {
            marked_[i] = false;
            onStack_[i] = false;
        }

        for (int v = 0; v < G->V(); v++)
        {
            if (!marked_[v])
            {
                dfs(G, v);
            }
        }
    }
    ~DirectedCycle()
    {
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
        if (onStack_ != nullptr)
        {
            delete[] onStack_;
            onStack_ = nullptr;
        }
    }

    bool hasCycle() const
    {
        return hasCycle_;
    }

private:
    /**
     * @brief 深度优先搜索检测是否有环
     * 
     * @param G 
     * @param v 
     */
    void dfs(DiGraph *G, int v)
    {
        marked_[v] = true;
        onStack_[v] = true;
        for (auto w : *G->adj(v))
        {
            if (!marked_[w])
            {
                dfs(G, w);
            }

            if (onStack_[w])
            {
                hasCycle_ = true;
                return;
            }
        }
        onStack_[v] = false;
    }

private:
    bool *marked_;
    bool hasCycle_;
    bool *onStack_; // 索引为顶点, 记录当前顶点是否处于正在搜索的有向路径上
};

#endif /* DIRECTEDCYCLE_H */
