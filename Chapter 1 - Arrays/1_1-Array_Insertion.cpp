/*--------------------------------------------------------+
    Chapter: 1      | Arrays
    Section: 1.1    | Insertion
+--------------------------------------------------------*/

#include <iostream>

using namespace std;

void insertAtBegin(int arr[], int n, int val)
{
    n += 1;
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
}

void insertAtPos(int arr[], int pos, int n, int val){
    n += 1;
    for(int i = n-1; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
}

void display(int arr[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    //Insert at begin
    insertAtBegin(arr, n, 10);
    cout << "After inserting 10 at begin- " << endl;
    display(arr, n);

    //Insert at pos
    insertAtPos(arr, 2, n, 20);
    cout << "After inserting 20 at pos 2- " << endl;
    display(arr, n);

    return 0;
}

/*--------------------------------------------------------
    Output:
    Enter the n: 6
    1 2 3 4 5 6
    Array: 1 2 3 4 5 6
    After inserting 10 at begin-
    Array: 10 1 2 3 4 5 6
    After inserting 20 at pos 2-
    Array: 10 1 20 2 3 4 5 6

    Note:

+---------------------------------------------------------+
     Website: http://xanderbilla.com
     Email: dev.xanderbilla@gmail.com
     
     This program is written by © Xander Billa.
---------------------------------------------------------*/