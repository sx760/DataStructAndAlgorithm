#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H

#include "Queue.h"
#include "Edge.h"

/**
 * @brief 加权无向图
 * 
 */
class EdgeWeightedGraph
{
public:
    EdgeWeightedGraph(int v) : v_(v)
    {
        e_ = 0;
        adj_ = new Queue<Edge> *[v];
        for (int i = 0; i < v; i++)
        {
            adj_[i] = new Queue<Edge>();
        }
    }
    ~EdgeWeightedGraph()
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
     * @param e 
     */
    void addEdge(Edge *e)
    {
        int v = e->either();
        int w = e->other(v);

        adj_[v]->enqueue(e);
        adj_[w]->enqueue(e);
        e_++;
    }

    Queue<Edge> *adj(int v) const { return adj_[v]; }
    Queue<Edge> *edges() const
    {
        Queue<Edge> *allEdges = new Queue<Edge>();
        for (int v = 0; v < v_; v++)
        {
            for (auto e : *adj_[v])
            {
                if (e.other(v) < v)
                {
                    allEdges->enqueue(new Edge(e));
                }
            }
        }

        return allEdges;
    }

private:
    const int v_;       // 顶点数量
    int e_;             // 边数量
    Queue<Edge> **adj_; // 邻接表
};

#endif /* EDGEWEIGHTEDGRAPH_H */
