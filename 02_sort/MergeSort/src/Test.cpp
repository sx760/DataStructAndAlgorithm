//#include "Factorial.h"
#include "Merge.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    //std::cout << factorial(5) << std::endl;

    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    Merge<int> *merge = new Merge<int>(8);
    merge->sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
