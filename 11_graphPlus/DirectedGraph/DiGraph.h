#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "Queue.h"

/**
 * @brief 有向图
 * 
 */
class DiGraph
{
public:
    DiGraph(int v)
    {
        v_ = v;
        e_ = 0;
        adj_ = new Queue<int> *();
        for (int i = 0; i < v; i++)
        {
            adj_[i] = new Queue<int>();
        }
    }
    ~DiGraph()
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
            delete adj_;
            adj_ = nullptr;
        }
    }

    int V() const { return v_; }
    int E() const { return e_; }

    /**
     * @brief 添加一条v指向w的边, v->w
     * 
     * @param v 
     * @param w 
     */
    void addEdge(int v, int w)
    {
        adj_[v]->enqueue(new int(w));
        e_++;
    }

    Queue<int> *adj(int v) const
    {
        return adj_[v];
    }

private:
    /**
     * @brief 反向
     * 
     * @return DiGraph* 
     */
    DiGraph *reverse()
    {
        DiGraph *r = new DiGraph(v_);
        for (int v = 0; v < v_; v++)
        {
            for (auto w : *adj_[v])
            {
                r->addEdge(w, v); // w->v
            }
        }
        return r;
    }

private:
    int v_;
    int e_;
    Queue<int> **adj_;
};

#endif /* DIGRAPH_H */
