#include "SequenceList.h"

#include <iostream>
#include <string>

/* 
int main(int argc, char const *argv[])
{
    using namespace std;
    SequenceList<std::string> *list = new SequenceList<std::string>(10);
    list->insert("HELLO");
    list->insert("WORLD");
    list->insert("YOUR");
    list->insert(1, "NAME");

    string get1 = list->get(1);
    std::cout << get1 << std::endl;

    string rem1 = list->remove(0);
    std::cout << rem1 << std::endl;

    list->clear();
    std::cout << list->length() << std::endl;

    return 0;
}
 */

int main(int argc, char const *argv[])
{
    using namespace std;
    SequenceList<std::string> *list = new SequenceList<std::string>(3);
    list->insert("HELLO");
    list->insert("WORLD");
    list->insert("YOUR1");
    list->insert("YOUR2");
    list->insert("YOUR3");
    list->insert("YOUR4");
    list->insert("YOUR5");
    list->insert("YOUR6");
    list->insert("YOUR7");

    return 0;
}
