#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H

#include "EdgeWeightedDirectedGraph.h"
#include "IndexMinPriorityQueue.h"

#include <cfloat>

/**
 * @brief Dijkstra最短路径算法
 * 
 */
class DijkstraSP
{
public:
    /**
     * @brief Construct a new Dijkstra S P object
     * 
     * @param G 
     * @param s 
     */
    DijkstraSP(EdgeWeightedDirectedGraph *G, int s) : v_(G->V())
    {
        edgeTo_ = new DirectedEdge *[v_];
        distTo_ = new double[v_];
        pq_ = new IndexMinPriorityQueue<double>(v_);
        for (int i = 0; i < v_; i++)
        {
            edgeTo_[i] = nullptr;
            distTo_[i] = DBL_MAX;
        }

        distTo_[s] = 0.0; // 默认让顶点s进入最短路径树
        pq_->insert(s, new double(0.0));

        while (!pq_->isEmpty())
        {
            relax(G, pq_->delMin());
        }
    }
    ~DijkstraSP()
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
        }
        if (distTo_ != nullptr)
        {
            delete[] distTo_;
        }
        if (pq_ != nullptr)
        {
            delete pq_;
            pq_ = nullptr;
        }
    }

    double distTo(int v) const
    {
        return distTo_[v];
    }

    bool hasPathTo(int v) const 
    {
        return distTo_[v] < DBL_MAX;
    }

    /**
     * @brief 从起点s到v的最短路径
     * 
     * @param v 
     * @return Queue<DirectedEdge>* 
     */
    Queue<DirectedEdge> *pathTo(int v) const
    {
        if (!hasPathTo(v))
        {
            return nullptr;
        }
        Queue<DirectedEdge> *allEdges = new Queue<DirectedEdge>();
        while (true)
        {
            DirectedEdge *e = edgeTo_[v];
            if (e == nullptr)
            {
                break;
            }
            allEdges->enqueue(e);
            v = e->from();
        }
        return allEdges;
    }

private:
    /**
     * @brief 松弛顶点v
     * 
     * @param G 
     * @param v 
     */
    void relax(EdgeWeightedDirectedGraph *G, int v)
    {
        for (auto e : *G->adj(v))
        {
            int w = e.to(); // 终点

            if (distTo_[v] + e.weight() < distTo_[w])
            {
                distTo_[w] = distTo_[v] + e.weight();
                edgeTo_[w] = new DirectedEdge(e);

                if (pq_->contains(w))
                {
                    pq_->changeItem(w, new double(distTo_[w]));
                }
                else
                {
                    pq_->insert(w, new double(distTo_[w]));
                }
            }
        }
    }

private:
    const int v_;                       // 记录顶点数量
    DirectedEdge **edgeTo_;             // 索引为顶点, 值为从顶点s到当前的最短路径上的最后一条边
    double *distTo_;                    // 索引为顶点, 值为从顶点s到当前的最短路径的总权重
    IndexMinPriorityQueue<double> *pq_; // 存放树中顶点与非树中顶点之间的有效横切边
};

#endif /* DIJKSTRASP_H */
