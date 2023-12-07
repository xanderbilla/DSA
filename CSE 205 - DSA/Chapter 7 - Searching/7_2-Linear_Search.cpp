/*--------------------------------------------------------+
    Chapter: 7      | Searching
    Section: 7.2    | Linear Search
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

void linearSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            cout << "`"<< arr[i] << "` Found at index: " << i << endl;
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int key = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array: ";
    display(arr, n);
    linearSearch(arr, n, key);
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