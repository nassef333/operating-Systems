#include <bits/stdc++.h>
using namespace std;

class sol {
public:

    void solve() {


        cout << "Slect From Menu :\n1-FCFS\n2-None preemptive\n";
        int choice{}; cin >> choice;
        /*
            this code is for FCFS
        */
        if (choice == 1) {
        int n, a;
        cout << "Enter the number of processes: ";
        cin >> n;
        vector<int> burst, wait(n);
        wait[0] = 0;
        for (int i = 0; i < n; i++) {
            cout << "Enter Burst time of process: " << i + 1 << ": ";
            cin >> a;
            burst.push_back(a);
        }
        
        float sum = 0;
        for (int i = 1; i < n; i++) {
            wait[i] = burst[i - 1] + wait[i - 1];
            sum += wait[i];
        }
        cout <<"the average of waiting time is: " << sum / n;

        }






        else if (choice == 2) {
        /*
            Short job first "None preemptive"
        */

        int n, a, b;
        cout << "Enter the number of processes: ";
        cin >> n;
        vector<int> arrival, burst, time;
        for (int i = 0; i < n; i++) {
            cout << "Enter the Arrival of process " << i + 1 << " : ";
            cin >> a;
            cout << "Enter the Burst of process " << i + 1 << " : ";
            cin >> b;
            arrival.push_back(a), burst.push_back(b);
        }
        int arriv = 0;
        arriv += burst[min_element(arrival.begin(), arrival.end()) - arrival.begin()];
        burst[min_element(arrival.begin(), arrival.end()) - arrival.begin()] = 0;
        double sum = 0;
        int i{}, j{};
        for (i = 0; i < n-1; i++) {
            int minVal = INT_MAX, minnIndex{};
            for (j = 0; j < n; j++) {
                if (burst[j] < minVal && burst[j] != 0 && arrival[j] <= arriv) {
                    minVal = burst[j];
                    minnIndex = j;
                }
            }
            time.push_back(arriv);
            sum += (time[i] - arrival[minnIndex]);
            arriv += burst[minnIndex];
            burst[minnIndex] = 0;
        }
        cout << "The Average waiting time is : " << sum / n;
        }


    }
};

int main() {
    sol obj;
    //ll t; in(t); while (t--)
        obj.solve();
    return 0;
}