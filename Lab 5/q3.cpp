#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if (n==0) {
        return total; 
    }

    return sumTail(n-1, total+n); 
}

int sumNonTail(int n) {
    if (n==0) {
        return 0; 
    }
    return n + sumNonTail(n-1);
}

int main() {
    int n = 5;

    int tailResult = sumTail(n, 0);
    int nonTailResult = sumNonTail(n);

    cout << "sum using tail recursion: " << tailResult << endl;
    cout << "sum using non-tail recursion: " << nonTailResult << endl;

    return 0;
}

//Comparision 
//In tail recursion the recursive call is the last thing the function does, so it doesnt need to keep the current state on the stack. This lets the compiler optimize it to use less memory.
//In non-tail recursion the function does more work after the recursive call, so it has to keep each calls state on the stack until all calls finish. This uses more memory.