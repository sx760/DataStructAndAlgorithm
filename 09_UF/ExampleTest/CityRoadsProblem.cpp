#include "UF_TreeWeighted.h"

#include <fstream>
#include <iostream>

const std::string filename = "D:\\program\\VSCodeProjects\\CppProjects\\DataStructAndAlgorithm\\09_UF\\ExampleTest\\roads.txt";

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
    UF_TreeWeighted *uf = new UF_TreeWeighted(cityNum);
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
            default:
                break;
            };
        }
        uf->unions(p, q);
    }
    fin.close();

    haveTo = uf->count() - 1;
    cout << "Need to build " << haveTo << " roads. \n ";

    delete uf;

    return 0;
}
