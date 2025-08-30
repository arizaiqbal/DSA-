// Task #8:
// Create a dynamic program to store temperature readings of a city for n days and m different times in a day
// using a 2D array.
// => Calculate the daily average temperature.
// => Find the hottest and coldest day

#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of different times: ";
    cin >> m;

    int **temperature = new int*[n];
    for(int i = 0 ; i < n; i++){
        temperature[i] = new int[m];
    } 

    for (int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cout << "Enter temperature reading for day " << i + 1 << " and " << j + 1 << " different time: ";
            cin >> temperature[i][j];
        }
    }

    double hottestAvg = -1e9, coldestAvg = 1e9;
    int hottestDay = -1, coldestDay = -1;


    for(int i = 0 ; i < n; i++){
        int dailyTemp = 0;
        for(int j = 0; j < m; j++){
            dailyTemp += temperature[i][j];
        }

        double avgTemp = (double)dailyTemp/m;

        cout << "Average daily temperature of day " << i + 1 << ": " << avgTemp <<" C" << endl;

        if(avgTemp > hottestAvg){
            hottestAvg = avgTemp;
            hottestDay = i + 1;
        }

        
        if(avgTemp < coldestAvg){
            coldestAvg = avgTemp;
            coldestDay = i + 1;
        }

    }
        cout << "\nHottest Day: Day " << hottestDay << " with Avg Temp = " << hottestAvg << " C" << endl;
        cout << "Coldest Day: Day " << coldestDay << " with Avg Temp = " << coldestAvg << " C" << endl;

        for(int i = 0 ; i < n; i++){
            delete[] temperature[i];
        }

        delete[] temperature;


    return 0;
}                                            