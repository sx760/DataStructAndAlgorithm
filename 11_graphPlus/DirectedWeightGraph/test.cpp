#include "DijkstraSP.h"

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    using namespace std;
    char name[] = "sp.txt";
    ifstream fin;
    fin.open(name);
    if (!fin.is_open())
    {
        cerr << "Could not open the file: " << name << endl;
        exit(EXIT_FAILURE);
    }
    int v = 0, e = 0, p, q;
    double w;
    char ch[20];
    fin >> v;
    EdgeWeightedDirectedGraph *G = new EdgeWeightedDirectedGraph(v);
    fin >> e;
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fin.getline(ch, 20, ' ');
            switch (j)
            {
            case 0:
                p = atoi(ch);
                break;
            case 1:
                q = atoi(ch);
                break;
            case 2:
                w = atof(ch);
                break;
            default:
                break;
            };
        }
        G->addEdge(new DirectedEdge(p, q, w));
    }
    fin.close();
    
    DijkstraSP *d = new DijkstraSP(G, 0);
    Queue<DirectedEdge> *path = d->pathTo(6);
    for (auto p : *path)
    {
        cout << p << " ";
    }
    cout << endl;

    delete path;
    delete d;
    delete G;

    return 0;
}

