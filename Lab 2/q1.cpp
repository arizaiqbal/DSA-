#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    for(int i = 0 ; i < size; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < size; i++){
        cout << "Enter value of array at position " <<i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++){
        cout << arr[i];
        cout << " ";
    }

    delete[] arr;
    return 0;
}
