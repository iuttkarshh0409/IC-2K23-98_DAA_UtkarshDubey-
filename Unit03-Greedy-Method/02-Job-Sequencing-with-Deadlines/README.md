# Experiment 02: Job Sequencing with Deadlines

## Aim
To implement the Job Sequencing with Deadlines problem using the Greedy Method to maximize total profit while scheduling jobs within their deadlines.

## Objectives
- Understand the Greedy Method and its application to scheduling problems.
- Arrange jobs in descending order of profit.
- Schedule each job in the latest available time slot before its deadline.
- Maximize the total profit of the selected jobs.
- Analyze the time and space complexity of the algorithm.

## Problem Statement
Given a set of jobs, where each job has a deadline and an associated profit, schedule the jobs to maximize total profit.

Assume each job requires one unit of time and must be completed on or before its deadline. Only one job can occupy a time slot.

## Theory
The Job Sequencing with Deadlines problem is a scheduling problem commonly solved using a greedy strategy.

The algorithm prioritizes jobs with higher profits. After sorting jobs in descending order of profit, it attempts to schedule each job in the latest available time slot at or before its deadline.

Placing a job as late as possible preserves earlier slots for other jobs that may have tighter deadlines.

The implementation uses a fixed-size array and a `struct` to represent jobs.

## Algorithm
1. Read the number of jobs.
2. Read the deadline and profit of each job.
3. Assign a unique identifier to every job.
4. Sort the jobs in descending order of profit.
5. Initialize all time slots as empty.
6. For each job in sorted order:
   - Determine the latest usable slot, limited to the number of jobs.
   - Search backward from that slot to find an available position.
   - If a free slot exists, schedule the job and add its profit to the total.
   - If no slot is available, skip the job.
7. Display the scheduled jobs, their time slots, the number of scheduled jobs, and the maximum total profit.

## Pseudocode
```text
BEGIN
    INPUT n

    FOR i = 1 TO n
        INPUT deadline[i], profit[i]
        id[i] = i
    END FOR

    SORT jobs by descending profit

    INITIALIZE all time slots as empty
    totalProfit = 0
    scheduledCount = 0

    FOR each job in sorted order
        lastSlot = MIN(job.deadline, n)

        FOR slot = lastSlot DOWN TO 1
            IF slot is empty
                schedule job in slot
                totalProfit = totalProfit + job.profit
                scheduledCount = scheduledCount + 1
                BREAK
            END IF
        END FOR
    END FOR

    DISPLAY scheduled jobs
    DISPLAY scheduledCount and totalProfit
END
```

## Sample Input
```text
5
2 100
1 19
2 27
1 25
3 15
```

Each input row after the job count contains the job's deadline followed by its profit.

## Sample Output
```text
Total jobs scheduled: 3
Maximum total profit: 142
```

The selected jobs are:

| Slot | Job | Deadline | Profit |
|---:|---:|---:|---:|
| 1 | 3 | 2 | 27 |
| 2 | 1 | 2 | 100 |
| 3 | 5 | 3 | 15 |

**Total profit:** 27 + 100 + 15 = 142.

## Complexity Analysis

Let `n` be the number of jobs.

| Operation | Complexity |
|---|---|
| Sorting jobs | O(n log n) |
| Searching for available slots | O(n²) in the worst case |
| Overall time complexity | **O(n²)** |
| Auxiliary storage | **O(n)** |

The worst-case time complexity is O(n²) because each job may require searching through multiple time slots.

## Test Cases
- Standard sample input produces a maximum total profit of `142`.
- A single job is scheduled correctly.
- Jobs with identical deadlines are handled correctly.
- Deadlines greater than the number of jobs are safely limited to the available scheduling slots.
- Jobs with zero profit are accepted.
- Zero or negative deadlines are rejected.
- Job counts outside the supported range of 1 to 100 are rejected.

## Learning Outcomes
- Understood greedy scheduling and profit-based job selection.
- Implemented sorting with a custom comparison function.
- Learned how deadlines constrain job scheduling.
- Applied backward slot searching to preserve earlier time slots.
- Analyzed the time and space complexity of a greedy algorithm.

## Conclusion
The Job Sequencing with Deadlines problem was successfully implemented in C++ using the Greedy Method. Jobs are prioritized by profit and placed in the latest available slot before their deadlines to maximize the total profit.
