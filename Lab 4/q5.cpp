#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
     int pos = low + ((double)(high - low) * (key - arr[low])) / (arr[high] - arr[low]);
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main(){
    int* arr;
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    arr = new int[n];
    for(int i = 0;i < n ; i++){
        cin >> arr[i];
    }
     cout << "Array:" << endl;
    for(int i = 0 ; i < n ;i++){
       cout << arr[i] << " ";
    }

    int target;
    cout << "\nEnter target: ";
    cin >> target;
    int res = interpolationSearch(arr,n,target);
    if (res==-1){
        cout << "Target not present";
    }
    else 
    cout << "Target is at index "<< res;
    return 0;
}