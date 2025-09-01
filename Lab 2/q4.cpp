#include <iostream>
using namespace std;

void resizeArray(int*& arr, int& n, int newSize) {
    int* newArr = new int[newSize];   

    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }

    for (int i = n; i < newSize; i++) {
        newArr[i] = 0;
    }

    delete[] arr;   
    arr = newArr;    
    n = newSize;     
}

    

int main() {
   int n;
   cout << "Enter number of months: " ;
   cin >> n;
   int *arr = new int[n];
   
   for (int i = 0 ; i < n ; i++){
       cout << "Enter expense of month " << i+1 << ": ";
       cin >> arr[i];
   }

   char choice;
    cout << "Do you want to add more months later? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int extra;
        cout << "How many more months do you want to add? ";
        cin >> extra;

        resizeArray(arr, n, n + extra);

        for (int i = n - extra; i < n; i++) {
            cout << "Enter expense of month " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

   
   int total = 0;
   for (int i = 0 ; i < n; i++){
       total +=arr[i];
   }
      int average = 0;
      average = total / n;
     
      cout << "Total Expense of " << n << " months: " << total << endl;
      cout << "Average Expense of " << n << " months: " << average << endl;

      delete[] arr;
     

    return 0;
}

