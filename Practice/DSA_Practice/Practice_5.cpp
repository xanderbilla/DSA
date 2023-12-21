/*------------------------------------------------------------------------------------------+
|Find the Multiplication of Matrix                                                          |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 21/12/2023                                                            |
|Copyright © 2023 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

#include<iostream>
#define MAX_SIZE 100
using namespace std;

void displayMatrix(int arr[][MAX_SIZE], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void inputMatrix(int arr[][MAX_SIZE], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    displayMatrix(arr, row, col);
}

void resultMatrix(int arr1[][MAX_SIZE], int arr2[][MAX_SIZE], int row, int col){
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(i == j){
                result[i][j] = arr1[i][j] * arr2[i][j];
            }
        }
    }
    displayMatrix(result, row, col);
}

int main(){
    int size, row, col;
    cout<<"Enter the size of the matrix: ";
    cin>>size;
    row = col = size;

    if(size <= 0 || size > MAX_SIZE){
        cout << "Invalid Matrix.";
    }
    int arr1[MAX_SIZE][MAX_SIZE];
    int arr2[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of matrix 1: " << endl;
    inputMatrix(arr1, row, col);

    cout << "Enter the elements of matrix 2: " << endl;
    inputMatrix(arr2, row, col);

    cout << "Result: " << endl;
    resultMatrix(arr1, arr2, row, col);

}