#include <iostream>
using namespace std;

void print(int n) {
    if (n<=0) {       
        return;
    }
    cout <<n<< " ";   
    print(n-1); 
}

int main() {
    int num = 5;
    cout << "direct recursion from " << num << " 5 down to 1:" << endl;
    print(num);
    cout << endl;
    return 0;
}
