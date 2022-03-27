#ifndef EDGE_H
#define EDGE_H

#include <iostream>

/**
 * @brief 加权边
 * 
 */
class Edge
{
public:
    Edge(int v, int w, double weight)
    {
        v_ = v;
        w_ = w;
        weight_ = weight;
    }
    Edge(const Edge &e)
    {
        v_ = e.v_;
        w_ = e.w_;
        weight_ = e.weight_;
    }

    double weight() const { return weight_; }
    int either() const { return v_; }
    int other(int verter) const { return verter == v_ ? w_ : v_; }

    Edge &operator=(const Edge &other)
    {
        v_ = other.v_;
        w_ = other.w_;
        weight_ = other.weight_;
        return *this;
    }
    bool operator<(Edge &other) const
    {
        return weight_ < other.weight_;
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge& e)
    {
        os << e.v_ << "-" << e.w_ << ":" << e.weight_;
        return os;
    }

private:
    int v_;         // 顶点1
    int w_;         // 顶点2
    double weight_; // 权重
};

#endif /* EDGE_H */
