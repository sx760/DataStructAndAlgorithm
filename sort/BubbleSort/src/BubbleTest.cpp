#include "Bubble.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {4, 5, 6, 3, 2, 1};
    Bubble<int> *bubble = new Bubble<int>();
    bubble->sort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
