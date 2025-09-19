#include <iostream>
using namespace std;

int fact(int n) {
    if (n==0 || n==1) {
        return 1;
    } 
    else{
    return n*fact(n - 1);
    }
}

int main() {
    int n;
    cout << "enter a number: ";
    cin >> n;
    
    int result=fact(n);
    cout <<"factorial of "<<n<< " is " <<result<< endl;

    return 0;
}
 
