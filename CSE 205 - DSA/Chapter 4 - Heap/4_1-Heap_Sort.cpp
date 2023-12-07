/*--------------------------------------------------------+
    Chapter: 4      | Heap
    Section: 4.1    | Heap Sort
+--------------------------------------------------------*/

#include <iostream>
using namespace std;
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    display(arr, n);
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array: ";
    display(arr, n);
    cout << "After Heap Sort: " << endl;
    heapSort(arr, n);
    return 0;
}

/*--------------------------------------------------------
    Output:
        Array: 12 11 13 5 6 7 
        After Heap Sort: 
        5 6 7 11 12 13

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com
     
     This program is written by © Xander Billa.
---------------------------------------------------------*/