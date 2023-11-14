#include <iostream>

using std::cout;
using std::swap;
using std::endl;

void heapify(int arr[], int size, int i){
    int largest = i; 
    int l = (2 * i) + 1; 
    int r = (2 * i) + 2;

    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < size && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, i);
    }
}

void insert(int arr[], int &size, int val){
    size++;
    arr[size-1] = val;
    heapify(arr, size, 0);
}

void deleteEl(int arr[], int &size){
    arr[0] = arr[size-1];
    size--;
    heapify(arr, size, 0);
}

void heapSort(int arr[], int size){
    for (int i = (size - 1)/2; i >= 0; i-- ){
        heapify(arr, size, i);
    }

    for(int i = n -1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, size, 0);
    }
}

int main()
{

    return 0;
}
