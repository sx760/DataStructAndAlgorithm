#include "Insert.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};

    Insert<int> *insert = new Insert<int>();
    insert->sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
