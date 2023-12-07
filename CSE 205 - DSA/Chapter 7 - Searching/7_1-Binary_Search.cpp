/*--------------------------------------------------------+
    Chapter: 7      | Searching
    Section: 7.1    | Binary Search
+--------------------------------------------------------*/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void binarySearch(int arr[], int n, int key){
    int mid = n/2;
    int low = 0;
    int high = n-1;

    if(arr[mid] > key){
        high = mid - 1;
    }
    else if(arr[mid] < key){
        low = mid + 1;
    }
    else{
        cout << "Element found at index " << mid << endl;
        return;
    }    
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    binarySearch(arr, n, key);
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