#include "DFS.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    Graph *G = new Graph(13);
    G->addEdge(0, 5);
    G->addEdge(0, 1);
    G->addEdge(0, 2);
    G->addEdge(0, 6);
    G->addEdge(5, 3);
    G->addEdge(5, 4);
    G->addEdge(3, 4);
    G->addEdge(4, 6);

    G->addEdge(7, 8);

    G->addEdge(9, 11);
    G->addEdge(9, 10);
    G->addEdge(9, 12);
    G->addEdge(11, 12);

    DFS *dfs = new DFS(G, 0);
    cout << "number of nodes can go to 0 is: " << dfs->count() << endl;
    cout << "5 can go to 0? : " << dfs->marked(5) << endl;
    cout << "7 can go to 0? : " << dfs->marked(7) << endl;

    delete G;
    
    return 0;
}

