#include "UF_TreeWeighted.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    UF_TreeWeighted *uf = new UF_TreeWeighted(5);
    char f = 'y';
    cout << "\nThere are " << uf->count() << " groups now. ";
    while (f == 'y')
    {
        cin.clear();

        cout << endl
             << "Please input first element to union: ";
        int p, q;
        cin >> p;
        cout << "Please input second element to union: ";
        cin >> q;

        if (uf->isConnected(p, q))
        {
            cout << endl
                 << p << ", " << q << " were in same group.";
            cout << "\nEnter 'y' to conyinue, enter other any key to stop. ";
            cin >> f;
            continue;
        }
        uf->unions(p, q);
        cout << "\nGroup number of uf is: " << uf->count();

        cout << "\nEnter 'y' to conyinue, enter other any key to stop. ";
        cin >> f;
    }

    return 0;
}
