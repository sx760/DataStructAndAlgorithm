#include "PrimMST.h"

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>

int main(int argc, char const *argv[])
{
    using namespace std;
    //const string filename = "D:\\program\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\11_graphPlus\\WeightGraph\\mst.txt";
    //const string filename = "D:\\Projects\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\11_graphPlus\\WeightGraph\\mst.txt";
    char *pwd;
    if ((pwd = getcwd(nullptr, 0)) == nullptr)
    {
        cerr << "getcwd error.\n";
    }
    else
    {
        cout << pwd << "\n";
        free(pwd);
    }
    string filename(pwd, strlen(pwd));
    filename += "\\mst.txt";
    cout << filename << endl;
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
