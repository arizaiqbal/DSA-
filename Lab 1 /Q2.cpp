// Create a C++ class named "Exam" using DMA designed to manage student exam records,
// complete with a shallow copy implementation? Define attributes such as student name, exam
// date, and score within the class, and include methods to set these attributes and display exam
// details. As part of this exercise, intentionally omit the implementation of the copy constructor
// and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
// shallow copy, and observe any resulting issues?

#include <iostream>
#include <string.h>
using namespace std;

class Exam{
    private:
    char* stdName;
    char* examDate;
    int score;

    public:
    Exam(const char* name,const char* date, int s){

        stdName = new char[strlen(name) + 1];
        strcpy(stdName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = s;
    }

    ~Exam(){
        cout << "Destructor Called...." << endl;
        delete[] stdName;
        delete[] examDate;
    }

    void displayDetails(){
        cout << "Student Name : " << stdName << endl;
        cout << "Date : " << examDate << endl;
        cout << "Score : " << score << endl;
    }
}; 

int main(){

    Exam exam1("Ariza", "09-08-2025", 90);
    exam1.displayDetails();

    Exam exam2 = exam1;
    exam2.displayDetails();

    return 0;
}
