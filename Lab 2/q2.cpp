#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows (benches): ";
    cin >> rows;
    cout << "Enter number of seats per row: ";
    cin >> cols;
    
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
    
    cout << "Enter 1 for occupied seats and 0 for empty seats:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            while (true){
            cout << "Seat " << j + 1 << " in row " << i + 1 << ": ";
            cin >> val;
            
            if(val == 1 || val == 0){
                arr[i][j] = val;
                break;
            }
            else{
                cout << "Invalid. Please write 1 for occupied seats and 0 for empty seats." << endl;
               }
            }
        }
    }
    
    cout << "\nSeating Chart:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
