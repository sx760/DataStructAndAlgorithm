#include "PrimMST.h"
#include "KruskalMST.h"

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>

int main(int argc, char const *argv[])
{
    using namespace std;
    //const string filename = "D:\\program\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\11_graphPlus\\WeightGraph\\mst.txt";
    //const string filename = "D:\\Projects\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\11_graphPlus\\WeightGraph\\mst.txt";

    char name[] = "mst.txt";
    /* char *cwd;
    if ((cwd = getcwd(nullptr, 0)) == nullptr)
    {
        cerr << "getcwd error.\n";
        exit(EXIT_FAILURE);
    }
    strcat(cwd, name); */
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

    PrimMST *prim = new PrimMST(G);
    KruskalMST *kruskal = new KruskalMST(G);
    Queue<Edge> *edges1 = prim->edges();
    Queue<Edge> *edges2 = kruskal->edges();
    for (auto a : *edges1)
    {
        cout << a << "  ";
    }
    cout << endl;
    for (auto b : *edges2)
    {
        cout << b << "  ";
    }
    cout << endl;

    delete edges1;
    delete edges2;
    delete kruskal;
    delete prim;
    delete G;

    return 0;
}
