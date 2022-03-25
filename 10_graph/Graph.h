#ifndef GRAPH_H
#define GRAPH_H

#include "Queue.h"

/**
 * @brief 无向图
 * 
 */
class Graph
{
public:
    Graph(int v)
    {
        v_ = v;
        e_ = 0;
        adj_ = new Queue<int> *[v];
        for (int i = 0; i < v; i++)
        {
            adj_[i] = new Queue<int>();
        }
    }
    ~Graph()
    {
        if (adj_ != nullptr)
        {
            for (int i = 0; i < v_; i++)
            {
                if (adj_[i] != nullptr)
                {
                    delete adj_[i];
                    adj_[i] = nullptr;
                }
            }
            delete[] adj_;
            adj_ = nullptr;
        }
    }

    int V() const { return v_; }
    int E() const { return e_; }

    /**
     * @brief 
     * 
     * @param v 
     * @param w 
     */
    void addEdge(int v, int w)
    {
        adj_[v]->enqueue(new int(w));
        adj_[w]->enqueue(new int(v));
        e_++;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Queue<int>* 
     */
    Queue<int> *adj(int v) const { return adj_[v]; }

private:
    int v_;     // 顶点数量
    int e_;            // 边数量
    Queue<int> **adj_; // 邻接表
};

#endif /* GRAPH_H */
