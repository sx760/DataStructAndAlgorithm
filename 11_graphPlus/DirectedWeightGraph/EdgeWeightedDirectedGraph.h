#ifndef EDGEWEIGHTEDDIRECTEDGRAPH_H
#define EDGEWEIGHTEDDIRECTEDGRAPH_H

#include "Queue.h"
#include "DirectedEdge.h"

/**
 * @brief 加权有向图
 * 
 */
class EdgeWeightedDirectedGraph
{
public:
    EdgeWeightedDirectedGraph(int v) : v_(v)
    {
        e_ = 0;
        adj_ = new Queue<DirectedEdge>*[v];
        for (int i = 0; i < v; i++)
        {
            adj_[i] = new Queue<DirectedEdge>();
        }
        
    }
    ~EdgeWeightedDirectedGraph() 
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
        }
    }

    int V() const { return v_; }
    int E() const { return e_; }

    void addEdge(DirectedEdge *e)
    {
        adj_[e->from()]->enqueue(e);
        e_++;
    }

    /**
     * @brief 获取顶点v指出的所有边
     * 
     * @param v 
     * @return Queue<DirectedEdge>* 
     */
    Queue<DirectedEdge> *adj(int v) const
    {
        return adj_[v];
    }

    /**
     * @brief 获取所有边
     * 
     * @return Queue<DirectedEdge> 
     */
    Queue<DirectedEdge> *edges() const
    {
        Queue<DirectedEdge> *allEdges = new Queue<DirectedEdge>();
        for (int i = 0; i < v_; i++)
        {
            for(auto e : *adj_[i])
            {
                allEdges->enqueue(new DirectedEdge(e));
            }
        }
        
        return allEdges;
    }

private:
    const int v_;               // 顶点数量
    int e_;                     // 边的数量
    Queue<DirectedEdge> **adj_; // 邻接表
};

#endif /* EDGEWEIGHTEDDIRECTEDGRAPH_H */
