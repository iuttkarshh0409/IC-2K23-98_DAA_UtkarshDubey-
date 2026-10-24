# Experiment 07: Sorting Performance Comparison System

## Aim
To implement and experimentally compare Merge Sort, Quick Sort, and Heap Sort using execution-time measurements for different input sizes.

## Problem Statement
Sorting algorithms differ in their theoretical complexity, practical execution time, and memory requirements. This experiment develops a benchmark system that measures the execution time of three sorting algorithms on generated datasets and visualizes the results.

## Objectives
- Implement Merge Sort, Quick Sort, and Heap Sort.
- Generate random integer datasets of different sizes.
- Measure execution time using the C++ `steady_clock`.
- Verify that each algorithm produces sorted output.
- Record average execution times in a CSV file.
- Generate a graph comparing the measured performance.

## Algorithms Compared

### 1. Merge Sort
Divides the input into two halves, recursively sorts each half, and merges the sorted halves.

- Best, average, and worst time complexity: \(\Theta(n\log n)\)
- Auxiliary space: \(\Theta(n)\)
- Stable: Yes

### 2. Quick Sort
Partitions the array around a pivot and recursively sorts the resulting partitions. This implementation uses the last element as the pivot.

- Best and average time complexity: \(\Theta(n\log n)\)
- Worst time complexity: \(\Theta(n^2)\)
- Average recursion stack: \(O(\log n)\)
- Worst recursion stack: \(O(n)\)
- Stable: No

### 3. Heap Sort
Builds a max heap and repeatedly moves the maximum element to the end of the active array.

- Best, average, and worst time complexity: \(\Theta(n\log n)\)
- Auxiliary space: \(O(1)\) for the sorting operation, excluding implementation stack details
- Stable: No

## Experimental Methodology

1. Generate random integer datasets using a pseudorandom number generator.
2. Test input sizes of 1,000, 5,000, 10,000, and 20,000 elements.
3. Perform five trials for each input size.
4. Use the same original dataset for all three algorithms within each trial.
5. Copy the dataset before sorting so that each algorithm receives unsorted input.
6. Measure only the sorting operation using `steady_clock`.
7. Validate each output using `is_sorted`.
8. Calculate the average execution time for each algorithm and input size.
9. Export the results to a CSV file.
10. Plot the measured execution times for comparison.

## Input Sizes

| Input size | Trials per algorithm |
|---:|---:|
| 1,000 | 5 |
| 5,000 | 5 |
| 10,000 | 5 |
| 20,000 | 5 |

The benchmark performs 60 sorting runs in total: four input sizes multiplied by three algorithms and five trials.

## Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Merge Sort | \(\Theta(n\log n)\) | \(\Theta(n\log n)\) | \(\Theta(n\log n)\) |
| Quick Sort | \(\Theta(n\log n)\) | \(\Theta(n\log n)\) | \(\Theta(n^2)\) |
| Heap Sort | \(\Theta(n\log n)\) | \(\Theta(n\log n)\) | \(\Theta(n\log n)\) |

## Output and Results

The benchmark displays each input size, algorithm, average execution time in microseconds, and validation status.

The results are written to:

`data/results.csv`

The performance graph is generated at:

`graphs/sorting_performance.png`

The graph compares average execution time against input size for all three algorithms.

### Experimental Observations

Complete this section after reviewing the generated CSV and graph.

- **Fastest observed algorithm:** Record the algorithm with the lowest measured time for the tested input sizes.
- **Growth with input size:** Describe how the measured execution times change as the input size increases.
- **Quick Sort behavior:** Discuss its measured performance on random inputs and note that its last-element pivot can cause quadratic behavior on certain input patterns.
- **Theoretical versus measured performance:** Explain how the results compare with the expected complexity of each algorithm.

Actual observations should be based on the generated benchmark results, not assumed in advance.

## Files

- `src/benchmark.cpp` — implementations and benchmark driver
- `src/plot_results.py` — graph-generation script
- `data/results.csv` — measured performance data
- `graphs/sorting_performance.png` — generated comparison graph
- `tests/` — additional test cases, if maintained

## Learning Outcomes

- Implemented and compared three sorting algorithms.
- Applied empirical performance measurement using a high-resolution clock.
- Verified algorithm output programmatically.
- Stored experimental results in CSV format.
- Visualized performance trends using Matplotlib.
- Compared theoretical complexity with observed execution time.

## Conclusion

The Sorting Performance Comparison System measures Merge Sort, Quick Sort, and Heap Sort on multiple randomly generated input sizes. It validates sorted output, records average execution times, and generates a performance graph. The experiment demonstrates how theoretical complexity and practical measurements can be used together to evaluate algorithm performance.

## Reproducibility Note

Execution times depend on the processor, operating system, compiler, optimization flags, and system load. The CSV measurements should be retained with the report so the conclusions can be traced to the actual experiment.
