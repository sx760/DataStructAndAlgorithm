#include "TopoLogical.h"

#include "iostream"

int main(int argc, char const *argv[])
{
    
    using namespace std;

    DiGraph *G = new DiGraph(6);
    G->addEdge(0, 2);
    G->addEdge(0, 3);
    G->addEdge(1, 3);
    G->addEdge(2, 4);
    G->addEdge(3, 4);
    G->addEdge(4, 5);

    TopoLogical *tl = new TopoLogical(G);
    Stack<int> *order = tl->order();
    for (auto i : *order)
    {
        cout << i << " ";
    }
    cout << endl;

    delete tl;
    delete G;

    return 0;
}

