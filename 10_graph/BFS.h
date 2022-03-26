#ifndef BFS_H
#define BFS_H

#include "Queue.h"
#include "Graph.h"

/**
 * @brief 广度优先搜索
 * 
 */
class BFS
{
public:
    BFS(Graph *G, int s)
    {
        marked_ = new bool[G->V()];
        for (int i = 0; i < G->V(); i++)
        {
            marked_[i] = false;
        }
        count_ = 0;
        waitSearch_ = new Queue<int>();

        bfs(G, s);
    }
    ~BFS()
    {
        if (marked_ != nullptr)
        {
            delete[] marked_;
            marked_ = nullptr;
        }
        if (waitSearch_ != nullptr)
        {
            delete waitSearch_;
            waitSearch_ = nullptr;
        }
    }

    bool marked(int w) const { return marked_[w]; }
    int count() const { return count_; }

private:
    void bfs(Graph *G, int v)
    {
        marked_[v] = true;
        count_++;
        waitSearch_->enqueue(new int(v));
        while (!waitSearch_->isEmpty())
        {
            int wait = *waitSearch_->dequeue();
            for (auto w : *G->adj(wait))
            {
                if (!marked_[w])
                {
                    // bfs(G, w);
                    marked_[w] = true;
                    count_++;
                    waitSearch_->enqueue(new int(w));
                }
            }
        }
    }

private:
    bool *marked_;
    int count_;              // 与顶点s相通的顶点数量
    Queue<int> *waitSearch_; // 待搜索邻接表的点
};

#endif /* BFS_H */
