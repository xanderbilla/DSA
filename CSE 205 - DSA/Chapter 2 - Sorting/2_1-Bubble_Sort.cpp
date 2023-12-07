/*--------------------------------------------------------+
    Chapter: 2      | Sorting
    Section: 2.1    | Bubble Sort
+--------------------------------------------------------*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bSort(int arr[], int n){
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
  }
    display(arr, n);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sorting: ";
    display(arr, n);
    cout << "After Sorting: ";
    bSort(arr, n);
    return 0;
}

/*--------------------------------------------------------
    Output:


    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com
     
     This program is written by © Xander Billa.
---------------------------------------------------------*/