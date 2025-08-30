// Write a C++ program that dynamically creates a 2D matrix and provides:
// => Addition of two matrices.
// => Subtraction of two matrices.
// => Ensure safe memory handling with proper allocation/deallocation.
#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of cols: ";
    cin >> cols;

    int **m1 = new int*[rows];

    for(int i = 0 ; i < rows; i++){
        m1[i] = new int [cols];
    }

    cout << "Enter elements for Matrix 1 of (" << rows << " x " << cols <<"): " << endl;
    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cout << "m1[" << i << "][" << j << "] = ";
            cin >> m1[i][j];
        }
    }

    int **m2 = new int*[rows];

    for(int i = 0 ; i < rows; i++){
        m2[i] = new int [cols];
    }

    cout << "Enter elements for Matrix 2 of (" << rows << " x " << cols <<"): " << endl;
    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cout << "m2[" << i << "][" << j << "] = ";
            cin >> m2[i][j];
        }
    }

    
    int **add = new int*[rows];
    int **sub = new int*[rows];


    for(int i = 0 ; i < rows; i++){
        add[i] = new int [cols];
        sub[i] = new int [cols];

    }

    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            add[i][j] = m1[i][j] + m2[i][j];
        }
    }

    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            add[i][j] = m1[i][j] + m2[i][j];
            sub[i][j] = m1[i][j] - m2[i][j];
        }
    }

    cout << "\nMatrix Addition:\n";
    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cout << add[i][j] <<" ";
        }
        cout << endl;
    }


    cout << "\nMatrix Subtraction:\n";
    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        delete[] m1[i];
        delete[] m2[i];
        delete[] sub[i];
        delete[] add[i];
    }

        delete[] m1;
        delete[] m2;
        delete[] sub;
        delete[] add;

    
    return 0;
}