# Automation-Deadlock-Detection-Tool
Project Overview
In multi-tasking systems, where several processes run simultaneously and share limited resources, deadlocks can occur, leading to system freezes and reduced efficiency. A deadlock arises when a group of processes becomes stuck waiting for resources held by each other, with no process able to proceed. Detecting and resolving these deadlocks is critical to ensuring smooth system operations.
This project focuses on developing an Automated Deadlock Detection Tool that can monitor resource allocation, detect deadlocks, and alert users about any circular wait conditions that may arise. By implementing a modified version of the Banker’s Algorithm, the tool evaluates system states to determine whether they are safe or unsafe.
Expected Outcomes: A functional tool that accurately detects circular wait conditions in a given set of process and resource data .Clear identification of processes and resources involved in any detected deadlock .Practical suggestions for resolving deadlocks, such as terminating a process or preempting a resource.

Module-Wise Breakdown
This project is divided into various modules, each performing a specific function in the overall task of automating deadlock detection and resource allocation. Below is a breakdown of the modules:
Module 1: User Input Module
Purpose: To collect necessary inputs from the user such as the number of processes, number of resources and matrices representing resource allocations, maximum resource requirements and available resources.
Role: At the starting point for the tool gather essential data to analyze the system state. Ensure accurate data entry to avoid errors during the deadlock detection process.

Module 2: Need Matrix Calculation Module
Purpose: To compute the Need Matrix using the formula:
Need[i][j] = Max[i][j] - Allocation[i][j]  where each element in the Need Matrix represents the remaining resources a process requires to complete.
Role: Plays a key role in determining the potential future resources needs of processes and use for safe state sequence.

Module 3: Safe State Check and Deadlock Detection
Purpose: To check if the system is in a safe state by searching over the processes and analyzing whether available resources can satisfy their needs.
Role: Ensures that resources are allocated only if they lead to a safe state. If a safe sequence exists it identifies the correct order of process execution to avoid deadlocks.

Module 4: Resource Allocation and Release Module
Purpose: To allocate resources to processes and release they back to the system when processes complete. To simulate real-time execution by adding back the allocated resources to the available resources once a process finishes.
Role: Ensures that completed processes release their allocated resources which can then be used by other processes.

Module 5: Output Module
Purpose: To display the results of the deadlock detection process or either show a safe sequence of processes or alert if a deadlock is detected.
Role: Helps users if the system is safe and all processes can complete without any deadlocks and Plays an essential role in user interaction by making the results of the deadlock detection process understandable and actionable.
