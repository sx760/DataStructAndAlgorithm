#include "HeapSort.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string **arr = new string *[11];
    arr[0] = new string("S");
    arr[1] = new string("O");
    arr[2] = new string("R");
    arr[3] = new string("T");
    arr[4] = new string("E");
    arr[5] = new string("X");
    arr[6] = new string("A");
    arr[7] = new string("M");
    arr[8] = new string("P");
    arr[9] = new string("L");
    arr[10] = new string("E");
    //string arr[] = {"S", "O", "R", "T", "E", "X", "A", "M", "P", "L", "E"};
    HeapSort<string>::sort(arr, 11);
    for (int i = 0; i < 11; i++)
    {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 1; i++)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
