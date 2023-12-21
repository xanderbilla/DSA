/*------------------------------------------------------------------------------------------+
|Find the Sum of Matrix                                                                     |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 21/12/2023                                                            |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include <iostream>
#define MAX_SIZE 100

using namespace std;

void displayMatrix(int arr[][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void arrInput(int arr[][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    displayMatrix(arr, row, col);
}

int sumArray(int arr[][MAX_SIZE], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "Sum of array: " << sum;
}

int main()
{
    int row, col;
    cout << "Enter the size of row: ";
    cin >> row;
    cout << "Enter the size of col: ";
    cin >> col;
    if (row <= 0 || row >= MAX_SIZE || col <= 0 || col >= MAX_SIZE)
    {
        cout << "Invalid array dimensions." << endl;
        return 1;
    }

    int arr[MAX_SIZE][MAX_SIZE];
    arrInput(arr, row, col);
    sumArray(arr, row, col);
}