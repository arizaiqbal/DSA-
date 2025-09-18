#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){  

    for (int i = 0 ; i < n ; i++){
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }

}

int search(int* nums, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        cout << "Checking: " << nums[mid] << endl;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){ int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
     cin >> arr[i];
   
    insertionSort(arr ,n);
    cout << "Sorted array: ";
    printArray(arr, n);

    int target;
        cout << "Enter value to search: ";
    cin >> target;

    int index = search(arr, n, target);
    if (index != -1)
        cout << "element " <<target<< " found at index " << index  << endl;
    else
        cout << "element " <<target<< " not found in the array" << endl;





}