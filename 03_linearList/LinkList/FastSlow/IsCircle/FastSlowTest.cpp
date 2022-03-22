#include <iostream>
#include <string>

template <class T>
class Node
{
public:
    Node(T *item, Node *next)
    {
        item_ = item;
        next_ = next;
    }

    bool operator==(const Node *other)
    {
        if (*item_ == *(other->item_))
        {
            return true;
        }
        return false;
    }

    T *item_;
    Node *next_;
};

/**
 * @brief 
 * 
 * @param first 
 * @return true 
 * @return false 
 */
static bool isCircle(Node<std::string> *first)
{
    Node<std::string> *slow = first, *fast = first;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Get the Entrance object
 * 
 * @param first 
 * @return Node<std::string>* 
 */
static Node<std::string> *getEntrance(Node<std::string> *first)
{
    Node<std::string> *slow = first, *fast = first, *temp = nullptr;;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow)
        {
            temp = first;
            continue;
        }
        if (temp != nullptr)
        {
            temp = temp->next_;
            if (temp == slow)
            {
                break;
            }
        }
    }
    return temp;
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

    fifth->next_ = third; // 环

    if (isCircle(first))
    {
        cout << "with circle!" << endl;
    }
    else
    {
        cout << "without circle!" << endl;
    }

    Node<string> *entrance = getEntrance(first);
    cout << "entrance is: " << *(entrance->item_) << endl;

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}
