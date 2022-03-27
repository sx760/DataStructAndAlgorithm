#ifndef PRIMMST_H
#define PRIMMST_H

#include "EdgeWeightedGraph.h"
#include "IndexMinPriorityQueue.h"

#include <limits>
#include <cfloat>

/**
 * @brief 最小生成树prim算法
 * 
 */
class PrimMST
{
public:
    PrimMST(EdgeWeightedGraph *G) : v_(G->V())
    {
        edgeTo_ = new Edge*[G->V()];
        distTo_ = new double[G->V()];
        marked_ = new bool[G->V()];
        pq_ = new IndexMinPriorityQueue<double>(G->V());
        for (int i = 0; i < G->V(); i++)
        {
            edgeTo_[i] = nullptr;
            distTo_[i] = DBL_MAX;
            marked_[i] = false;
        }

        // 默认让顶点0进入数中
        distTo_[0] = 0.0;
        pq_->insert(0, new double(0.0));

        while (!pq_->isEmpty())
        {
            visit(G, pq_->delMin());
        }
    }
    ~PrimMST()
    {
        if (edgeTo_ != nullptr)
        {
            for (int i = 0; i < v_; i++)
            {
                if (edgeTo_[i] != nullptr)
                {
                    delete edgeTo_[i];
                    edgeTo_[i] = nullptr;
                }
            } 
            delete[] edgeTo_;
            edgeTo_ = nullptr;
        }
        if (distTo_ != nullptr)
        {
            delete[] distTo_;
            distTo_ = nullptr;
        }
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
        if (pq_ != nullptr)
        {
            delete pq_;
            pq_ = nullptr;
        }
    }

    Queue<Edge> *edges()
    {
        Queue<Edge> *allEdges = new Queue<Edge>();
        for (int i = 0; i < v_; i++)
        {
            if (edgeTo_[i] != nullptr)
            {
                allEdges->enqueue(edgeTo_[i]);
            }
        }

        return allEdges;
    }

private:
    /**
     * @brief 将v添加到最小生成树
     * 
     * @param G 
     * @param v 
     */
    void visit(EdgeWeightedGraph *G, int v)
    {
        marked_[v] = true;
        for (auto e : *G->adj(v))
        {
            int w = e.other(v);
            if (marked_[w]) // 已经在树中
            {
                continue;
            }

            if (e.weight() < distTo_[w]) // e的权重小于从w顶点到树中已经存在的最小边的权重
            {
                edgeTo_[w] = new Edge(e);
                distTo_[w] = e.weight();

                if (pq_->contains(w))
                {
                    pq_->changeItem(w, new double(e.weight()));
                }
                else
                {
                    pq_->insert(w, new double(e.weight()));
                }
            }
        }
    }

private:
    const int v_;    // 节点数量
    Edge **edgeTo_;  // 索引为顶点, 值为当前顶点和最小生成树之间的最短边
    double *distTo_; // 索引为顶点, 值为当前顶点和最小生成树之间的最短边的权重
    bool *marked_;
    IndexMinPriorityQueue<double> *pq_; // 树中顶点与非树中顶点之间的有效横切边
};

#endif /* PRIMMST_H */
