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
                for (int j = 0; j < resources; j++) {
                    work[j] += allocation[i][j];  
                }
                safeSequence.push_back(i);  
                finish[i] = true;          
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
