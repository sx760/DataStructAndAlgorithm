#include "DFS.h"
#include "BFS.h"

#include <iostream>
#include <fstream>

const std::string filename = "D:\\program\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\10_graph\\roads.txt";

/* int main(int argc, char const *argv[])
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

    BFS *bfs = new BFS(G, 0);
    cout << "-------------------------------------\n";
    cout << "number of nodes can go to 0 is: " << bfs->count() << endl;
    cout << "5 can go to 0? : " << bfs->marked(5) << endl;
    cout << "7 can go to 0? : " << bfs->marked(7) << endl;

    delete G;
    delete dfs;
    delete bfs;
    
    return 0;
}
 */
int main(int argc, char const *argv[])
{
    using namespace std;
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int cityNum = 0, already = 0, haveTo = 0, p, q;
    char ch[20];
    fin >> cityNum;
    Graph *G = new Graph(cityNum);
    fin >> already;
    for (int i = 0; i < already; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fin.getline(ch, 20, ',');
            switch (j)
            {
            case 0:
                p = atoi(ch);
                break;
            case 1:
                q = atoi(ch);
                break;
            default:
                break;
            };
        }
        G->addEdge(p, q);
    }
    fin.close();

    DFS *dfs = new DFS(G, 9);
    cout << "City 8 can go to 9? " << dfs->marked(8) << ". \n";
    cout << "City 10 can go to 9? " << dfs->marked(10) << ". \n";

    delete G;
    delete dfs;

    return 0;
}
