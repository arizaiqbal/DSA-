// Task #7:
// A company has multiple departments, each department has a different number of employees.
// => Use a jagged array where each row corresponds to a department and columns store employee
// salaries.
// Calculate:
// -> The highest salary in each department.
// -> The department with the overall maximum average salary.

#include <iostream>
using namespace std;

int main(){
    int numDepartments;
    cout << "Enter number of departments: " << endl;
    cin >> numDepartments;
    int *numEmployee = new int[numDepartments];
    int **salary = new int*[numDepartments];

    for(int i = 0; i < numDepartments; i++){
        cout << "Enter number of employees in department " << i + 1 << ": ";
        cin >> numEmployee[i];

        salary[i] =  new int [numEmployee[i]];
    }
    
    for(int i = 0 ; i < numDepartments; i++){
        for(int j = 0; j < numEmployee[i]; j++){
            cout << "Enter Salary of employee " << i + 1 << " in department " << j + 1 <<" : ";
            cin >> salary[i][j];
        }
    }

    cout << "\n----Department Wise----\n";
    for(int i = 0 ; i < numDepartments; i++){
        int maxSalary = salary[i][0];

      for(int j = 0 ; j < numEmployee[i]; j++){
        if(salary[i][j] > maxSalary){
            maxSalary =  salary[i][j];
        }
    }
    cout << "Highest salary in Department " << i + 1 << ": " << maxSalary <<" rs" << endl;

} 
    int bestDept = 0;
    double maxAvg = 0.0;

    for(int i = 0 ; i < numDepartments ; i++){
        int sum = 0;
        for(int j = 0; j < numEmployee[i]; j++){
            sum += salary[i][j];
        }
        double avg = (double)sum/ numEmployee[i];

        cout << "Average salary in Department " << i + 1 << ": " << avg <<"rs" << endl;

        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << "\nDepartment " << bestDept + 1 << " has the highest average salary = " << maxAvg << endl;

    for (int i = 0; i < numDepartments ; i++) {
        delete[] salary[i];
    }
    delete[] salary;
    delete[] numEmployee;


    return 0;
}
