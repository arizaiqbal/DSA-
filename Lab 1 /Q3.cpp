// Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
// Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
// Demonstrate the behavior of both shallow and deep copy using test cases.

#include <iostream>
using namespace std;

class Box{
    private:
    int* size;

    public:
    Box(int s = 0){
        size = new int(s);
        cout << "Constructor called for size " << *size << endl;
    }

    ~Box(){
        cout << "Destructor called for size " << *size << endl;
        delete size;
    }

    Box(const Box& box){
        size = new int(*box.size);
        cout << "Copy constructor called for size " << *size << endl;
    }

    Box& operator=(const Box& box) {
        cout << "Copy Assignment called" << endl;
        if (this!= &box) {  
            delete size;      
            size = new int(*box.size); 
        }
        return *this;
    }

    void setSize(int s){
        *size = s;
    }

    int getSize() const{
        return *size;
    }
};

int main(){
    cout << "Deep Copy" << endl;
    Box b1(10);
    Box b2 = b1; //new memory is allocated and value of 10 is duplicated to this new space, after copying b1 into b2, changing b2's size does not modify b1, because it has its own memory
    b2.setSize(20);  //only changes b2 value

    cout << "Box 1 size " << b1.getSize() << endl;
    cout << "Box 2 size " << b2.getSize() << endl;

    Box b3;
    b3 = b1; //copy assignment operator
    b3.setSize(30);  //it will only change b3 memory

    cout << "Box 1 size " << b1.getSize() << endl;
    cout << "Box 3 size " << b3.getSize() << endl;

    cout << "Shallow Copy" << endl;
    int* s1 = new int(50);
    int* s2 = s1;    //shallow copy as both will point to SAME memory, creating a dangling pointer and double deletion
    cout << "s1 = " << *s1 << endl;
    cout << "s2 = " << *s2 << endl;

    delete s1;
    return 0;
}
