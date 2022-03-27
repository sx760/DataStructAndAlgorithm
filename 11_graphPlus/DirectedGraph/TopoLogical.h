#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H

#include "DirectedCycle.h"
#include "DepthFirstOrder.h"

class TopoLogical
{
public:
    TopoLogical(DiGraph *G)
    {
        DirectedCycle *cycle = new DirectedCycle(G);
        if (!cycle->hasCycle())
        {
            DepthFirstOrder *depthFirstOrder = new DepthFirstOrder(G);
            order_ = depthFirstOrder->reversePost();
        }
    }
    ~TopoLogical()
    {
        if (order_ != nullptr)
        {
            delete order_;
            order_ = nullptr;
        }
    }

    bool isCycle() const { return order_ ==nullptr; }

    Stack<int> *order() const { return order_; }

private:
    Stack<int> *order_;

};

#endif /* TOPOLOGICAL_H */
