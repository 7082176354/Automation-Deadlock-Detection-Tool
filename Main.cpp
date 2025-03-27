#include <iostream>
#include <vector>

using namespace std;

// Function to check if a process's resource request can be satisfied
bool canAllocate(const vector<int> &need, const vector<int> &work) {
    for (size_t i = 0; i < need.size(); i++) {
        if (need[i] > work[i]) {
            return false;  // Not enough resources available
        }
    }
    return true;
}

// Function to implement Banker's Algorithm for Deadlock Detection
void bankersAlgorithm(int processes, int resources, vector<vector<int>> &allocation,
    vector<vector<int>> &max, vector<int> &available) {
    vector<int> work = available;  // Copy of available resources
    vector<bool> finish(processes, false);  // Process finish status
    vector<int> safeSequence;  // Stores the safe sequence

    // Calculate the need matrix (Need[i][j] = Max[i][j] - Allocation[i][j])
    vector<vector<int>> need(processes, vector<int>(resources));
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm to find the safe sequence
    int processCount = 0;
    while (processCount < processes) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i] && canAllocate(need[i], work)) {
                // Simulate resource allocation to process i
                for (int j = 0; j < resources; j++) {
                    work[j] += allocation[i][j];  // Release allocated resources
                }
                safeSequence.push_back(i);  // Add process to the safe sequence
                finish[i] = true;           // Mark process as finished
                processCount++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "System is in an UNSAFE state. Deadlock may occur!" << endl;
            return;
        }
    }

    // If the system is in a safe state, print the safe sequence
    cout << "System is in a SAFE state. Safe Sequence: ";
    for (int i : safeSequence) {
        cout << "P" << i << " ";
    }
    cout << endl;
}

int main() {
    int processes, resources;

    // Taking number of processes and resources as input
    cout << "Enter the number of processes: ";
    cin >> processes;
    cout << "Enter the number of resource types: ";
    cin >> resources;

    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> max(processes, vector<int>(resources));
    vector<int> available(resources);

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix (Current allocation for each process):" << endl;
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input Maximum Demand Matrix
    cout << "\nEnter Maximum Matrix (Maximum demand for each process):" << endl;
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> max[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter Available Resources (Initial available resources of each type):" << endl;
    for (int i = 0; i < resources; i++) {
        cin >> available[i];
    }

    // Execute Banker's Algorithm
    bankersAlgorithm(processes, resources, allocation, max, available);

    return 0;
}
