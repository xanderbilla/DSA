/*------------------------------------------------------------------------------------------+
|Find the Sum of Array                                                                      |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 21/12/2023                                                            |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

void arrInput(int arr[], int size)
{
    for (int i = 1; i <= size; i++){
        cin >> arr[i];
    }
}

int sumArray(int arr[], int size){
    int sum = 0;
    for (int i = 1; i <= size; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of array: " << sum;
}

int main()
{
    int size;    
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    arrInput(arr, size);
    sumArray(arr, size);    
}