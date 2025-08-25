// Suppose you are developing a bank account management system, and you have defined the
// BankAccount class with the required constructors. You need to demonstrate the use of these
// constructors in various scenarios.
// 1. Default Constructor Usage: Create a default-initialized BankAccount object named
// account1. Print out the balance of account1.
// 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
// an initial balance of $1000. Print out the balance of account2.
// 3. Copy Constructor Usage: Using the account2 you created earlier, create a new
// BankAccount object named account3 using the copy constructor. Deduct $200 from
// account3 and print out its balance. Also, print out the balance of account2 to ensure it
// hasn't been affected by the transaction involving account3.


#include <iostream>
using namespace std;

class BankAccount{

    private:
    double balance;

    public:

    BankAccount(){
        balance = 0;
        cout <<"Default constructor..." << endl;
    }

    BankAccount(double bal){
        balance = bal;
        cout << "Parametrized Constructor..." << endl;
    }

     BankAccount(BankAccount &acc){
        balance = acc.balance;
        cout << "Copy Constructor..." << endl;
    }

    void deduct (double amt){
        if(amt <= balance)
            balance -=amt;

        else
        cout << "Insufficient funds!";
        }

    double getBalance(){
        return balance;
    }
    
};

int main(){
    BankAccount account1;
    cout << "Balance in account 1 : " << account1.getBalance() << "rs" << endl;

    BankAccount account2(1000);
    cout << "Balance in account 2 : " << account2.getBalance() << "rs" << endl;

    BankAccount account3(account2);
    account3.deduct(200);
    cout << "Balance in account 3 : " << account3.getBalance() << "rs" << endl;
    return 0;
}
