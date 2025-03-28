def is_safe_state(processes, available, max_resources, allocation):
    n = len(processes)   # Number of processes
    m = len(available)   # Number of resource types

    # Calculate the need matrix: Need[i][j] = Max[i][j] - Allocation[i][j]
    need = [[max_resources[i][j] - allocation[i][j] for j in range(m)] for i in range(n)]

    # Mark all processes as not finished
    finish = [False] * n
    safe_sequence = []   # To store the safe sequence

    work = available[:]  # Copy of available resources

    # While there are processes that can be executed safely
    while len(safe_sequence) < n:
        allocated_in_this_round = False

        for i in range(n):
            if not finish[i]:
                # Check if resources can be allocated (Need[i] <= Work)
                if all(need[i][j] <= work[j] for j in range(m)):
                    # Allocate resources (simulate)
                    for j in range(m):
                        work[j] += allocation[i][j]
                    safe_sequence.append(processes[i])
                    finish[i] = True
                    allocated_in_this_round = True
                    break
        
        # If no process could be safely allocated in this round, system is not safe
        if not allocated_in_this_round:
            print("The system is in an UNSAFE state! No safe sequence exists.")
            return

    print("The system is in a SAFE state.")
    print(f"Safe sequence: {' -> '.join(safe_sequence)}")

num_processes = int(input("Enter the number of processes: "))
num_resources = int(input("Enter the number of resource types: "))

processes = [f"P{i}" for i in range(num_processes)]

print("\nEnter available instances of each resource (space-separated): ")
available = list(map(int, input().split()))

print("\nEnter the maximum resource matrix (one row per process, space-separated):")
max_resources = []
for i in range(num_processes):
    row = list(map(int, input(f"Max resources for {processes[i]}: ").split()))
    max_resources.append(row)

print("\nEnter the allocation matrix (one row per process, space-separated):")
allocation = []
for i in range(num_processes):
    row = list(map(int, input(f"Allocated resources for {processes[i]}: ").split()))
    allocation.append(row)

# Run the Banker's Algorithm to find the safe sequence
is_safe_state(processes, available, max_resources, allocation)
