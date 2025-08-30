// Task #3:
// Design a program to handle marks of students in different courses using a jagged array
// (since each student is enrolled in a different number of courses).
// => Input the number of courses each student takes.
// => Dynamically allocate memory for each student accordingly.
// => Calculate and display each student’s average marks

#include <iostream>
using namespace std;

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;
    int* numCourses = new int[numStudents];
    int** marks = new int*[numStudents];
    
    for(int i = 0; i < numStudents ; i++){
        cout << "Enter number of courses for student " << i+1 << ": ";
        cin >> numCourses[i];
        
        marks[i] = new int[numCourses[i]];
    }
    
    for(int i = 0 ; i < numStudents; i++){
        for(int j = 0 ; j < numCourses[i]; j++){
            cout << "Enter marks for Student " << i + 1<< " for Course " << j +1 <<": ";
            cin >> marks[i][j];
        }
    }
        cout << "---------------" << endl;
    
    cout << "Marks of each Student" << endl;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numCourses[i]; j++) {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    cout << "Average marks" << endl;
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < numCourses[i]; j++) {
            sum += marks[i][j]; 
        }
        double average = (double) sum /numCourses[i];
        cout << "\nAverage marks for student " << i + 1 << ": " << average;
    }    
    
    return 0;
}
