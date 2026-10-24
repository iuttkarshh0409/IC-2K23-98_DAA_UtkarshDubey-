# Performance Analysis: Recursive vs Memoized Fibonacci

## 1. Objective

To compare recursive and memoized implementations of the Fibonacci sequence in terms of execution time, computational efficiency, and time and space complexity.

## 2. Experimental Setup

Both implementations calculate the Fibonacci number at the same input position. Execution time is measured using C++'s `chrono` library, and the results are checked for correctness.

- **Language:** C++
- **Compiler standard:** C++17
- **Input values:** 10, 20, 30, and 40
- **Measurement unit:** Milliseconds
- **Validation:** Both implementations must return identical results.

## 3. Theoretical Comparison

| Parameter | Recursive Fibonacci | Memoized Fibonacci |
|---|---|---|
| Technique | Direct recursion | Recursion with caching |
| Time complexity | O(2ⁿ) upper bound | O(n) |
| Auxiliary space | O(n) | O(n) |
| Repeated calculations | Many | Avoided after calculation |
| Additional storage | Recursion stack | Cache arrays and recursion stack |
| Efficiency for larger inputs | Poorer | Better |

## 4. Experimental Results

The following measurements were collected on the same system using the supplied benchmark program.

| Input n | Fibonacci result | Recursive time (ms) | Memoized time (ms) |
|---:|---:|---:|---:|
| 10 | 55 | 0.0027 | 0.0013 |
| 20 | 6,765 | 0.0988 | 0.0007 |
| 30 | 832,040 | 10.2292 | 0.0011 |
| 40 | 102,334,155 | 450.8530 | 0.0006 |

**Validation:** Both implementations returned identical Fibonacci values for all four inputs.

## 5. Analysis of Results

### 5.1 Execution Time

At n = 10, both implementations execute very quickly, so the difference is small. As the input increases, the recursive implementation becomes substantially slower.

At n = 30, the recursive version required 10.2292 ms, compared with 0.0011 ms for memoization. At n = 40, recursive execution increased to 450.853 ms, whereas memoized execution was reported as 0.0006 ms.

The memoized timings are extremely small and should be interpreted cautiously because they approach the practical measurement limits of a single timing run.

### 5.2 Why Memoization Is Faster

The recursive implementation repeatedly calculates the same smaller Fibonacci values. This creates a large number of redundant function calls.

Memoization stores previously calculated values. Once a Fibonacci position has been computed, its result can be reused instead of recalculated. The first memoized call therefore computes the required sequence in linear time.

### 5.3 Complexity Analysis

- **Recursive time complexity:** O(2ⁿ) upper bound.
- **Memoized time complexity:** O(n) for the first call.
- **Recursive auxiliary space:** O(n), due to recursion depth.
- **Memoized auxiliary space:** O(n), for recursion depth and cached values.

Both approaches have linear auxiliary-space complexity, but their time requirements differ dramatically as n grows.

## 6. Conclusion

The experiment demonstrates that memoization significantly reduces redundant computation in the Fibonacci problem. Both implementations produce correct results, but the memoized implementation scales much better for larger inputs.

The measured results support the theoretical complexity analysis. However, execution-time measurements are hardware-dependent, and the very small memoized timings should not be treated as universally precise performance figures.

## 7. Learning Outcomes

- Distinguished direct recursion from memoization.
- Understood overlapping subproblems and redundant computation.
- Compared theoretical complexity with measured execution times.
- Used C++'s `chrono` library for performance measurement.
- Observed the practical performance benefits of caching.
