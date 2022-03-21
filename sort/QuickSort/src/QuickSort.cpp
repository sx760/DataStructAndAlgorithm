#include "Quick.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 8};
    Quick<int>::sort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
