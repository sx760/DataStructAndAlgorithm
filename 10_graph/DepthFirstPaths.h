#ifndef DEPTHFIRSTPATHS_H
#define DEPTHFIRSTPATHS_H

#include "Graph.h"
#include "Stack.h"

/**
 * @brief 路径查找
 * 
 */
class DepthFirstPaths
{
public:
    /**
     * @brief Construct a new Depth First Paths object
     * 深度优先搜索起点s到达各个顶点路径
     * 
     * @param G 
     * @param s 
     */
    DepthFirstPaths(Graph *G, int s)
    {
        marked_ = new bool[G->V()];
        for (int i = 0; i < G->V(); i++)
        {
            marked_[i] = false;
        }
        s_ = s;
        edgeTo_ = new int[G->V()];

        dfs(G, s);
    }
    ~DepthFirstPaths()
    {
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
        if (edgeTo_ != nullptr)
        {
            delete[] edgeTo_;
            edgeTo_ = nullptr;
        }
    }

    /**
     * @brief 起点s与v是否有路径
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    bool hasPathTo(int v)
    {
        return marked_[v];
    }

    /**
     * @brief 起点s与v的路径
     * 
     * @param v 
     * @return Stack<int>* 
     */
    Stack<int> *pathTo(int v)
    {
        if (!hasPathTo(v))
        {
            return nullptr;
        }
        Stack<int> *path = new Stack<int>();
        for (int x = v; x != s_; x = edgeTo_[x])
        {
            path->push(new int(x));
        }
        path->push(new int(s_));

        return path;
    }

private:
    void dfs(Graph *G, int v)
    {
        marked_[v] = true;
        for (auto w : *G->adj(v))
        {
            if (!marked_[w])
            {
                edgeTo_[w] = v; // 到达w路径的最后一个顶点是v
                dfs(G, w);
            }
        }
    }

private:
    bool *marked_;
    int s_;       // 起点
    int *edgeTo_; // 索引代表顶点, 值代表从s到当前顶点路径的最后一个顶点
};

#endif /* DEPTHFIRSTPATHS_H */
