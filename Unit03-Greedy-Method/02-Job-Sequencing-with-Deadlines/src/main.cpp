
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_JOBS = 100;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareProfit(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[MAX_JOBS];
    int n;

    cout << "Enter number of jobs (1-" << MAX_JOBS << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_JOBS) {
        cerr << "Error: invalid number of jobs.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter deadline and profit for job "
             << i + 1 << ": ";

        if (!(cin >> jobs[i].deadline >> jobs[i].profit)
            || jobs[i].deadline < 1
            || jobs[i].profit < 0) {
            cerr << "Error: deadline must be positive "
                 << "and profit must be non-negative.\n";
            return 1;
        }

        jobs[i].id = i + 1;
    }

    // Greedy choice: consider the highest-profit job first.
    sort(jobs, jobs + n, compareProfit);

    // At most n jobs can be scheduled, even if deadlines are huge.
    int slots[MAX_JOBS + 1];

    for (int i = 0; i <= n; i++) {
        slots[i] = -1;
    }

    int totalProfit = 0;
    int scheduledCount = 0;

    for (int i = 0; i < n; i++) {
        // Try the latest available slot before the deadline.
        int lastSlot = min(jobs[i].deadline, n);

        for (int slot = lastSlot; slot >= 1; slot--) {
            if (slots[slot] == -1) {
                slots[slot] = i;
                totalProfit += jobs[i].profit;
                scheduledCount++;
                break;
            }
        }
    }

    cout << "\nJob Schedule:\n";
    cout << "Slot\tJob\tDeadline\tProfit\n";

    for (int slot = 1; slot <= n; slot++) {
        if (slots[slot] != -1) {
            Job selected = jobs[slots[slot]];

            cout << slot << '\t'
                 << selected.id << '\t'
                 << selected.deadline << '\t'
                 << selected.profit << '\n';
        }
    }

    cout << "\nTotal jobs scheduled: " << scheduledCount << '\n';
    cout << "Maximum total profit: " << totalProfit << '\n';

    return 0;
}
