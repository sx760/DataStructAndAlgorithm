#include "PrimMST.h"

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    using namespace std;
    const string filename = "D:\\program\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\11_graphPlus\\WeightGraph\\mst.txt";
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int v = 0, e = 0, p, q;
    double w;
    char ch[20];
    fin >> v;
    EdgeWeightedGraph *G = new EdgeWeightedGraph(v);
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
        Edge *edge = new Edge(p, q, w);
        G->addEdge(edge);
    }
    fin.close();

    PrimMST *mst = new PrimMST(G);
    Queue<Edge> *edges = mst->edges();
    for (auto a : *edges)
    {
        cout << a << "  ";
    }
    cout << endl;

    delete edges;
    delete mst;
    delete G;

    return 0;
}
