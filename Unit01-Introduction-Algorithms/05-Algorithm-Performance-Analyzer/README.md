# Experiment 05: Algorithm Performance Analyzer

## 1. Aim

To develop an **Algorithm Performance Analyzer** that compares iterative and recursive binary search by measuring their execution time for different input sizes, storing experimental results in a CSV file, and generating a performance graph.

## 2. Problem Statement

Implement iterative and recursive binary search on sorted arrays. Evaluate both algorithms across increasing input sizes, record their execution times, and compare their theoretical time complexity with their observed experimental performance.

The experiment demonstrates how asymptotic analysis and empirical benchmarking complement each other when evaluating algorithms.

## 3. Objectives

- Implement iterative binary search in C++.
- Implement recursive binary search in C++.
- Benchmark both algorithms using the same sorted arrays and search targets.
- Measure average execution time using the C++ `chrono` library.
- Store benchmark results in CSV format.
- Generate a graph using Python and Matplotlib.
- Compare theoretical complexity with observed execution-time trends.

## 4. Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Algorithm implementation and benchmarking |
| `chrono` | Execution-time measurement |
| `vector` | Dynamic array storage |
| `random` | Reproducible target generation |
| CSV | Storage of experimental results |
| Python 3 | Visualization of benchmark data |
| Matplotlib | Graph generation |
| Git and GitHub | Version control and documentation |

## 5. Project Structure

```text
05-Algorithm-Performance-Analyzer/
├── src/
│   ├── main.cpp
│   └── plot_results.py
├── data/
│   ├── .gitkeep
│   └── benchmark_results.csv
├── graphs/
│   ├── .gitkeep
│   └── binary_search_performance.png
└── README.md
```

The generated CSV and PNG files should be present after a successful benchmark and plotting run. The `.gitkeep` files can be removed from directories that now contain tracked output files.

## 6. Algorithm Description

### A. Iterative Binary Search

The iterative implementation repeatedly calculates the middle index of the current search interval.

- If the middle element equals the target, return its index.
- If the target is smaller, continue in the left half.
- If the target is larger, continue in the right half.
- If the interval becomes empty, report that the target was not found.

### B. Recursive Binary Search

The recursive implementation follows the same search strategy through function calls.

- **Base case 1:** The search interval is empty, so return `-1`.
- **Base case 2:** The middle element matches the target, so return its index.
- **Recursive case:** Search either the left or right half of the current interval.

### C. Benchmarking Procedure

1. Generate sorted arrays of increasing sizes.
2. Generate search targets at reproducible, randomly selected array positions.
3. Warm up each search implementation before timing.
4. Execute repeated searches and measure elapsed time using `chrono`.
5. Calculate average execution time per search.
6. Write the results of both algorithms to a CSV file.
7. Use Python to read the CSV and generate a comparison graph.

## 7. Pseudocode

### Iterative Binary Search

```text
ITERATIVE-BINARY-SEARCH(A, target)
    low  = 0
    high = length(A) - 1

    WHILE low <= high
        mid = low + (high - low) / 2

        IF A[mid] == target
            RETURN mid
        ELSE IF A[mid] < target
            low = mid + 1
        ELSE
            high = mid - 1

    RETURN -1
```

### Recursive Binary Search

```text
RECURSIVE-BINARY-SEARCH(A, low, high, target)
    IF low > high
        RETURN -1

    mid = low + (high - low) / 2

    IF A[mid] == target
        RETURN mid
    ELSE IF A[mid] < target
        RETURN RECURSIVE-BINARY-SEARCH(
            A, mid + 1, high, target
        )
    ELSE
        RETURN RECURSIVE-BINARY-SEARCH(
            A, low, mid - 1, target
        )
```

### Performance Analyzer

```text
PERFORMANCE-ANALYZER
    inputSizes = [1000, 5000, 10000, 50000,
                  100000, 500000, 1000000]
    repetitions = 20000

    OPEN benchmark_results.csv
    WRITE CSV HEADER

    FOR each n in inputSizes
        GENERATE sorted array A of size n
        GENERATE reproducible successful search targets

        FOR each algorithm in [iterative, recursive]
            WARM UP the algorithm
            START timer

            REPEAT repetitions times
                SEARCH for the next target
                ACCUMULATE returned index

            STOP timer
            CALCULATE total and average execution time
            WRITE benchmark result to CSV

    CLOSE CSV FILE
    GENERATE performance graph from CSV data
```

## 8. Flowchart

```text
          ┌─────────────────────┐
          │        START        │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Define input sizes  │
          │ and repetitions     │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Generate sorted     │
          │ array and targets   │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Warm up algorithm   │
          │ and start timer     │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Execute repeated    │
          │ binary searches     │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Calculate timings   │
          │ and write CSV       │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ More input sizes or │
          │ algorithms remain?  │
          └──────┬────────┬─────┘
                 │ Yes    │ No
                 │        │
          ┌──────▼───┐    ▼
          │ Continue │  ┌──────────────────┐
          │ testing  │  │ Generate graph   │
          └──────────┘  └────────┬─────────┘
                                 │
                       ┌─────────▼─────────┐
                       │        END        │
                       └───────────────────┘
```

## 9. Input Sizes and Benchmark Methodology

The implementation benchmarks the following array sizes:

| Test | Input size (`n`) | Repetitions per algorithm |
|---:|---:|---:|
| 1 | 1,000 | 20,000 |
| 2 | 5,000 | 20,000 |
| 3 | 10,000 | 20,000 |
| 4 | 50,000 | 20,000 |
| 5 | 100,000 | 20,000 |
| 6 | 500,000 | 20,000 |
| 7 | 1,000,000 | 20,000 |

**Benchmark conditions:**

- The array contains sorted, unique even integers.
- Search targets are selected from existing array positions, so the measured searches are successful.
- Both algorithms use the same target sequence for each input size.
- A fixed random seed makes target generation reproducible.
- Warm-up searches occur outside the timed region.
- Average time is calculated by dividing total measured time by the number of timed repetitions.
- The CSV records the algorithm, input size, test case, repetitions, total execution time, average execution time, and theoretical-complexity label.

## 10. Complexity Analysis

Let `n` denote the number of elements in the sorted array.

| Algorithm | Best-case time | Average-case time | Worst-case time | Auxiliary space |
|---|---|---|---|---|
| Iterative binary search | Θ(1) | Θ(log n) | Θ(log n) | Θ(1) |
| Recursive binary search | Θ(1) | Θ(log n) | Θ(log n) | Θ(log n) |

**Explanation:**

- **Best case:** The target is found at the first middle-element comparison.
- **Average case:** The search interval is repeatedly reduced by approximately half.
- **Worst case:** The algorithm continues until the target is found near the end of the search process or the interval becomes empty.
- **Iterative space:** The algorithm uses a constant number of variables.
- **Recursive space:** Recursive calls require a call stack whose depth grows logarithmically with the input size.

Both implementations have logarithmic average- and worst-case time complexity. Their practical execution times may differ because of function-call overhead, compiler optimizations, processor behavior, and measurement noise.

## 11. Compilation and Execution

Run these commands from the `05-Algorithm-Performance-Analyzer` directory.

### Step 1: Compile the C++ program

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/main.cpp -o analyzer.exe
```

### Step 2: Run the benchmark

```powershell
.\analyzer.exe
```

The program generates:

```text
data/benchmark_results.csv
```

Ensure the `data` directory exists before running the executable.

### Step 3: Install Matplotlib

```powershell
python -m pip install matplotlib
```

### Step 4: Generate the graph

```powershell
python src/plot_results.py
```

The plotting script generates:

```text
graphs/binary_search_performance.png
```

Open the PNG to inspect the measured execution-time comparison.

## 12. Experimental Results

The actual measurements are machine-dependent and should be taken from the generated `data/benchmark_results.csv`, rather than copied from another system.

| Measurement | Result |
|---|---|
| Algorithms tested | Iterative and recursive binary search |
| Number of input sizes | 7 |
| Repetitions per algorithm and input size | 20,000 |
| Search case | Successful searches |
| Raw output | `data/benchmark_results.csv` |
| Generated graph | `graphs/binary_search_performance.png` |

### Observations

1. Both implementations repeatedly reduce the search interval by approximately half.
2. Their theoretical average- and worst-case time complexities are logarithmic.
3. Iterative binary search uses constant auxiliary space, while recursive binary search uses a logarithmic call stack.
4. Experimental execution times can differ even when theoretical time complexities are identical.
5. Small timing differences should not automatically be treated as proof that one implementation is universally faster.
6. Reliable conclusions should account for compiler settings, hardware, background processes, and measurement variability.

**Note:** The generated graph compares measured execution times of the two implementations. The theoretical complexity comparison is established by the analysis above; the graph itself does not independently prove the asymptotic complexity.

## 13. Validation Checklist

- [ ] C++ program compiles successfully.
- [ ] Both search implementations return correct results.
- [ ] All seven input sizes are benchmarked.
- [ ] CSV contains results for both algorithms at every input size.
- [ ] Execution times are recorded as positive values.
- [ ] Python plotting script executes successfully.
- [ ] Generated PNG opens and displays both algorithms.
- [ ] CSV and graph are saved in their intended directories.
- [ ] README and experiment artifacts are committed to GitHub.

## 14. Limitations

- The current benchmark measures successful searches only.
- Results represent one local execution environment.
- Timing measurements can be affected by background system activity.
- The graph compares measured implementation timings; it does not plot a separately fitted theoretical complexity curve.
- Repeated runs may produce slightly different timing results.

## 15. Learning Outcomes

After completing this experiment, the student should be able to:

- Implement iterative and recursive binary search.
- Measure execution time in C++ using `chrono`.
- Design a repeatable benchmarking procedure.
- Store experimental data in CSV format.
- Visualize algorithm performance using Python and Matplotlib.
- Distinguish theoretical complexity from empirical execution time.
- Explain the time-space trade-off between iterative and recursive algorithms.

## 16. Conclusion

The Algorithm Performance Analyzer demonstrates how theoretical analysis and practical measurement can be used together to study algorithm efficiency. Iterative and recursive binary search both achieve logarithmic average- and worst-case time complexity, but differ in auxiliary-space usage and implementation overhead.

By benchmarking multiple input sizes, storing results in CSV format, and visualizing the measured timings, this experiment provides a practical introduction to algorithm performance evaluation.

**Experiment 05 completed:** Algorithm Performance Analyzer.
