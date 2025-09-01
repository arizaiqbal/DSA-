#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }
    
    int zeroCount = 0 ;
    int total = rows * cols;

    while(true){
    cout << "Enter elements of the matrix:" << endl;
    for(int i = 0 ; i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cin >> matrix[i][j];
           if( matrix[i][j] == 0 ){
            zeroCount++;
           }
        }
    }

    if(zeroCount > total/2){
    cout << "The matrix is sparse." << endl;
    break;
    }
    else
    cout << "\nThe matrix is not sparse. Please enter elements again. " << endl;
}
    cout << "\nMatrix in normal form: " << endl;
    for(int i = 0 ; i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix in compressed form (row, col, value): " << endl;
    for(int i = 0; i < rows; i++){
        for (int j = 0 ; j < cols; j++){
            if (matrix[i][j] !=0){
                cout << "(" << i + 1 << ", " << j + 1 << ", " << matrix[i][j] << ")" << endl;
            }
        }
    }

    for(int i = 0 ; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
