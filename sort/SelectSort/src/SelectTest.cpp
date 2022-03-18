#include "Select.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {4, 6, 8, 7, 9, 2, 10, 1};
    Select<int> *select = new Select<int>();
    select->sort(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
