#include <iostream>
using namespace std;

int main() {
    int n, target, index = -1;
    cout << "enter number of elements: ";
    cin >>n;

    int arr[n];
    cout << "enter "<<n<< " integers: ";
    for (int i = 0; i<n; i++) cin >> arr[i];

    cout << "enter value to search: ";
    cin >> target;

    for (int i = 0; i<n; i++) {
        if (arr[i]==target) {
            index = i;
            break;
        }
    }

    if (index!= -1)
        cout << "element " <<target<< " found at index " << index << endl;
    else
        cout << "element " <<target<< " not found in the array" << endl;
}
