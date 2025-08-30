#include <iostream>
using namespace std;

class SafePointer{
    int *ptr;

    public:
    SafePointer() : ptr(nullptr) {}

    ~SafePointer(){
        delete ptr;
        ptr = nullptr;
    }

    void setValue(int value){
        if(!ptr){
            ptr = new int;
        }
        *ptr = value;
    }

    int getValue() const{
        if(ptr){
            return *ptr;
        }
        else{
            cout <<"Pointer not initialized.";
        }
    }

    void release(){
        delete[] ptr;
        ptr = nullptr;
    }
};
int main(){
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    SafePointer students[size];

    cout << "Enter marks of " << size << " students: " <<endl;
    for(int i = 0 ; i < size; i++){
        int marks;
        cout << "Student " << i + 1 << ": ";
        cin >> marks;
        students[i].setValue(marks);
    }

    cout << "\nMarks of Students:\n:";
    for(int i = 0 ; i < size; i++){
        cout << "Student " << i+1 <<"marks: " << students[i].getValue() <<endl;
    }

    for(int i = 0 ; i < size; i++){
        students[i].release();
    }
    return 0;
}