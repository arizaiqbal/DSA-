#include <iostream>
using namespace std;

int ackrmann(int m, int n) {
    if (m==0) {
        return n+1;
    } 
    else if (m>0 && n==0) {
        return ackrmann(m-1, 1);
    } 
    else if (m>0 && n>0) {
        return ackrmann(m-1, ackrmann(m, n-1));
    }

    return -1;  
}

int main() {
    int m, n;
    cout << "Enter value of m: ";
    cin >> m;
    cout << "Enter value of n: ";
    cin >> n;

    cout << "Ackrmann(" <<m<< "," <<n<< ") = " << ackrmann(m, n) << endl;

    return 0;
}
