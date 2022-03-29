#ifndef DIRECTEDEDGE_H
#define DIRECTEDEDGE_H

#include <iostream>

/**
 * @brief 加权有向边
 * 
 */
class DirectedEdge
{
public:
    DirectedEdge(int v, int w, double weight) : v_(v), w_(w), weight_(weight)
    {
    }
    DirectedEdge(const DirectedEdge &e) : v_(e.v_), w_(e.w_), weight_(e.weight_)
    {
    }

    bool operator<(const DirectedEdge &other) const
    {
        return weight_ < other.weight_;
    }

    bool operator==(const DirectedEdge &other) const
    {
        return v_ == other.v_ && w_ == other.w_ && weight_ == other.weight_;
    }

    friend std::ostream &operator<<(std::ostream &os, const DirectedEdge &e)
    {
        os << e.v_ << "->" << e.w_ << ":" << e.weight_;
        return os;
    }

    double weight() const { return weight_; }
    /**
     * @brief 起点
     * 
     * @return int 
     */
    int from() const { return v_; }
    /**
     * @brief 终点
     * 
     * @return int 
     */
    int to() const { return w_; }

private:
    const int v_;         // 起点
    const int w_;         // 终点
    const double weight_; // 权重
};

#endif /* DIRECTEDEDGE_H */
