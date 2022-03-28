#ifndef KRUSKALMST_H
#define KRUSKALMST_H

#include "EdgeWeightedGraph.h"
#include "Queue.h"
#include "UF_TreeWeighted.h"
#include "MinPriorityQueue.h"

class KruskalMST
{
public:
    KruskalMST(EdgeWeightedGraph *G)
    {
        mst_ = new Queue<Edge>();
        uf_ = new UF_TreeWeighted(G->V());
        pq_ = new MinPriorityQueue<Edge>(G->E() + 1);

        for (auto e : *G->edges())
        {
            pq_->insert(new Edge(e));
        }

        while (!pq_->isEmpty() && mst_->size() < G->V() - 1)
        {
            Edge *e = pq_->delMin();
            int v = e->either();
            int w = e->other(v);

            if (uf_->isConnected(v, w))
            {
                continue;
            }
            uf_->unions(v, w);
            mst_->enqueue(e);
        }
        }
    ~KruskalMST()
    {
        if (mst_ != nullptr)
        {
            delete mst_;
            mst_ = nullptr;
        }
        if (uf_ != nullptr)
        {
            delete uf_;
            uf_ = nullptr;
        }
        if (pq_ != nullptr)
        {
            delete pq_;
            pq_ = nullptr;
        }
    }

    Queue<Edge> *edges() const
    {
        return mst_;
    }

private:
    Queue<Edge> *mst_;           // 最小生成树的边
    UF_TreeWeighted *uf_;        // 索引代表顶点
    MinPriorityQueue<Edge> *pq_; // 图中所有边, 按权重排序
};

#endif /* KRUSKALMST_H */
