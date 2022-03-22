#include <iostream>
#include <string>

template<class T>
class Node
{
public:
    Node(T *item, Node *next)
    {
        item_ = item;
        next_ = next;
    }

    T *item_;
    Node *next_;
};

/**
 * @brief Get the Mid object
 * 
 * @param first 
 * @return std::string* 
 */
static std::string *getMid(Node<std::string> *first)
{
    Node<std::string> *slow = first, *fast = first;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
    }
    
    return slow->item_;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    string str1 = "hello";
    string str2 = "world";
    string str3 = "your";
    string str4 = "name";
    string str5 = "nihao";
    Node<string> *first = new Node<string>(&str1, nullptr);
    Node<string> *second = new Node<string>(&str2, nullptr);
    Node<string> *third = new Node<string>(&str3, nullptr);
    Node<string> *forth = new Node<string>(&str4, nullptr);
    Node<string> *fifth = new Node<string>(&str5, nullptr);

    first->next_ = second;
    second->next_ = third;
    third->next_ = forth;
    forth->next_ = fifth;

    string *mid = getMid(first); 
    cout << "mid is: " << *mid << endl;

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}

