#include <iostream>
using namespace std;

void functionB(int n); 

void functionA(int n) {
    if (n<=0) {
        return; 
    }
    cout << "A" << n << " ";
    functionB(n-1);  
}

void functionB(int n) {
    if (n<=0) {
        return; 
    }
    cout << "B" <<n << " ";
    functionA(n/2); 
}

int main() {
    int num = 10;
    cout <<"indirect recursion:" << endl;
    functionA(num);
    cout << endl;
    return 0;
}
