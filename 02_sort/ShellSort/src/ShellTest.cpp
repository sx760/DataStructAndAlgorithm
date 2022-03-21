#include "Shell.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
    Shell<int>::sort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n sizeof(arr) / sizeof(int) = " << sizeof(arr) / sizeof(int) << std::endl;
    return 0;
}
