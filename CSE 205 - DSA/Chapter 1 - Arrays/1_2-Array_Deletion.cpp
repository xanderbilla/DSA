/*--------------------------------------------------------+
    Chapter: 1      | Arrays
    Section: 1.2    | Deletion
+--------------------------------------------------------*/

#include <iostream>

using namespace std;

void display(int arr[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteAtEnd(int arr[], int &n){
    n -= 1;
    display(arr, n);
}

void deleteAtPos(int arr[], int pos, int &n){
    for(int i = pos; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n -= 1;
    display(arr, n);
}

void deleteAtBegin(int arr[], int &n){
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n -= 1;
    display(arr, n);
}

int main()
{
    int n;
    cout << "Enter the n: ";
    cin >> n;

    int arr[n];
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
    //Array: 1 2 3 4 5 6
    display(arr, n);

    //Delete at begin
    cout << "After deletion at begining -" << endl;
    deleteAtBegin(arr, n);

    //Delete at pos
    cout << "After deletion at 2 pos -" << endl;
    deleteAtPos(arr, 2, n);

    //Delete at end
    cout << "After deletion at end -" << endl;
    deleteAtEnd(arr, n);
    return 0;
}

/*--------------------------------------------------------
    Output:
        Enter the n: 6
        1 2 3 4 5 6
        Array: 1 2 3 4 5 6
        After deletion at begining -
        Array: 2 3 4 5 6
        After deletion at 2 pos -
        Array: 2 3 5 6
        After deletion at end -
        Array: 2 3 5

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com
     
     This program is written by © Xander Billa.
---------------------------------------------------------*/