#include "TwoWayLinkList.h"

#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;
    string str1 = "hello";
    string str2 = "world";
    string str3 = "your";
    string str4 = "name";
    string str5 = "nihao";
    TwoWayLinkList<string> *ll = new TwoWayLinkList<string>();
    ll->insert(&str1);
    ll->insert(&str2);
    ll->insert(&str3);
    ll->insert(&str4);
    ll->insert(2, &str5);

    cout << ll->length() << endl;
    cout << ll << endl;
    
    cout << *(ll->get(2)) << endl;

    cout << ll->indexOf(&str2) << endl;
    cout << ll->indexOf(&str5) << endl;
    cout << *(ll->getFirst()) << endl;
    cout << *(ll->getLast()) << endl;

    delete ll;

    return 0;
}
