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
    DirectedCycle(Graph *G)
    {
        marked_ = new int[G->V()];
        hasCycle_ = false;
        onStack_ = new int[G->V()];
        for (int i = 0; i < G->V(); i++)
        {
            marked_[i] = false;
            onStack_[i] = false;
        }

        for (int v = 0; v < G->V(); v++)
        {
            if (!marked_[v])
            {
                dfs(G, v)
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
    void dfs(Graph *G, int v)
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
