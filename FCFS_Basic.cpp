// FCFS = First Come First Serve 0 2 5 1 

// P1 = Name: P1 Burst time: 24  Arrival time: 0
// P2 3 1
// P3 3 2


// FCFS => Frist Come (Arrival Time) First Serve (Arrival Time)
// FCFS => Frist Come (0) First Seve (0)
// FCFS => Frist Come (1) First Seve (1)
// FCFS => Frist Come (2) First Seve (2)

#include <iostream>
using namespace std;

class Process {
public:
    string name;  //Given 
    int burstTime; // Given
    int arrivalTime; // Given
    int complitionTime; // Calculated
    int waitingTime; // Calculated
    int turnAroundTime; // Calculated
    Process() {}
    Process(string name, int burstTime, int arrivalTime) {
        this->name = name;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTime;
    }
};

int no_of_process = 3;

int main() {

    int sum = 0;
    float awt;

    Process p[3] = { Process("P1", 24, 0),Process("P2", 3, 1),Process("P3", 3, 2) };

    for (int i = 0;i < no_of_process;i++) {
        cout << "Process: " << p[i].name << ", Burst time: " << p[i].burstTime << ", Arrival time: " << p[i].arrivalTime << "." << endl;
    }

    for (int i = 0; i < no_of_process; i++)
    {
        for (int j = 0; j < no_of_process; j++) {
            if (p[j].arrivalTime > p[j + 1].arrivalTime) { // P1 > P2
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "Sorted: " << endl;
    for (int i = 0;i < no_of_process;i++) {
        cout << "Process: " << p[i].name << ", Burst time: " << p[i].burstTime << ", Arrival time: " << p[i].arrivalTime << "." << endl;
    }

    //compliton time
    p[0].complitionTime = p[0].arrivalTime + p[0].burstTime;
    for (int i = 1;i < no_of_process;i++) {
        p[i].complitionTime = p[i - 1].complitionTime + p[i].burstTime;
    }

    cout << "Complition Time: " << endl;
    for (int i = 0;i < no_of_process;i++) {
        cout << "Process: " << p[i].name << ", Compition time: " << p[i].complitionTime << "." << endl;
    }

    //turn around time
    for (int i = 0;i < no_of_process;i++) {
        p[i].turnAroundTime = p[i].complitionTime - p[i].burstTime;
    }

    cout << "Turn Around Time: " << endl;
    for (int i = 0;i < no_of_process;i++) {
        cout << "Process: " << p[i].name << ", Turn Around time: " << p[i].turnAroundTime << "." << endl;
    }

    // waiting time
    for (int i = 0;i < no_of_process;i++) {
        p[i].waitingTime = p[i].turnAroundTime - p[i].arrivalTime;
        sum += p[i].waitingTime;
    }

    cout << "Waiting Time: " << endl;
    for (int i = 0;i < no_of_process;i++) {
        cout << "Process: " << p[i].name << ", Waiting time: " << p[i].waitingTime << "." << endl;
    }

    awt = sum / no_of_process;
    cout << "Average waiting time: " << awt << endl;






    return 0;
}


// a = 5                => a = 10
// b = 10               => b = 5

// temp = a             => temp = 0(g) , a = 5 => temp = 5
// a = b                => a = 5, b = 10 => a = 10, b=10
// b = temp             => b = 10, temp = 5 => b = 5, temp = 5

// a => 10
// b => 5