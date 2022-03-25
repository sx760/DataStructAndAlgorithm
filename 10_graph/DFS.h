#ifndef DFS_H
#define DFS_H

#include "Graph.h"

/**
 * @brief 深度优先搜索
 * 
 */
class DFS
{
public:
    /**
     * @brief Construct a new DFS object, 深度优先搜索找出graph中s顶点所有相通的顶点
     * 
     * @param G 
     * @param s 
     */
    DFS(Graph *G, int s)
    {
        marked_ = new bool[G->V()];
        count_ = 0;

        dfs(G, s);
    }
    ~DFS()
    {
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
    }

    /**
     * @brief 顶点w是否与当前s相通
     * 
     * @param w 
     * @return true 
     * @return false 
     */
    bool marked(int w) const { return marked_[w]; }

    /**
     * @brief 与s顶点相通的顶点数量
     * 
     * @return int 
     */
    int count() const { return count_; }

private:
    void dfs(Graph *G, int v)
    {
        marked_[v] = true;
        for (auto w : *G->adj(v))
        {
            if (!marked_[w])
            {
                dfs(G, w);
            }
        }

        count_++;
    }

private:
    bool *marked_; // 索引为顶点, 值为当前顶点是否已经被搜索
    int count_;    // 与s顶点相通的顶点数量
};

#endif /* DFS_H */
