/*------------------------------------------------------------------------------------------+
|Find the indexes of a specified element by searching the entire array for a match.         |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 21/12/2023                                                            |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

int Solution(int arr[], int size, int key)
{
    int res[size];
    int count = 0;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == key)
        {
            res[count] = i;
            count++;
        }
    }
    if (sizeof(res) / sizeof(res[0]) == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << res[i] << " ";
        }
    }
}

int main()
{
    // Example usage
    int arr[5] = {10, 20, 20, 30, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Call the solution function
    Solution(arr, size, 20);
}
