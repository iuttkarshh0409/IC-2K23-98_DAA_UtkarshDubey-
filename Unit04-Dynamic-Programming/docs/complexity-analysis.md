# Unit 04: Dynamic Programming
## Consolidated Time and Space Complexity Analysis

## 1. Objective

To analyze the time and space complexity of the algorithms implemented in Unit 04 and understand their computational requirements and practical limitations.

## 2. Complexity Summary

Let:
- `n` = Fibonacci position or number of cities, as applicable.
- `N` = number of items in Knapsack.
- `W` = knapsack capacity.
- `V` = number of graph vertices.

| No. | Experiment | Time Complexity | Space Complexity |
|---:|---|---|---|
| 1 | Fibonacci using Recursion | O(2ⁿ) upper bound | O(n) |
| 2 | Fibonacci using Memoization | O(n) | O(n) |
| 3 | 0/1 Knapsack using DP | O(NW) | O(NW) |
| 4 | Multistage Graph | O(V²) for the implemented matrix-based approach | O(V²) |
| 5 | Floyd-Warshall | O(V³) | O(V²) |
| 6 | Single-Source Shortest Path using Dijkstra | O(V²) | O(V²) |
| 7 | Traveling Salesperson using DP and Bitmasking | O(n² × 2ⁿ) | O(n × 2ⁿ) |
| 8 | Route Optimization System | O(V²) per route query | O(V²) |

These complexities describe the implementations in this repository, not every possible implementation of each algorithm.

## 3. Individual Analysis

### 3.1 Fibonacci using Recursion

The recursive implementation calculates smaller Fibonacci values repeatedly.

- **Time:** O(2ⁿ) upper bound.
- **Space:** O(n), due to recursive call-stack depth.

The number of function calls grows rapidly as the input increases, making this approach inefficient for large values of `n`.

### 3.2 Fibonacci using Memoization

The memoized implementation stores previously calculated Fibonacci values.

- **Time:** O(n) for the first call.
- **Space:** O(n), for cached values and the recursion stack.

Each required Fibonacci position is calculated at most once during the first call. The benchmark in `fibonacci_comparison.cpp` demonstrates the practical benefit of avoiding repeated calculations.

### 3.3 0/1 Knapsack using Dynamic Programming

The implementation fills a two-dimensional DP table for each item and each capacity.

- **Time:** O(NW).
- **Space:** O(NW).

The algorithm evaluates whether including or excluding an item produces the better value. Its running time depends on the numeric capacity `W`, making it pseudo-polynomial rather than polynomial in the total input bit length.

### 3.4 Multistage Graph

The implementation stores the graph in an adjacency matrix and scans vertices to calculate minimum costs.

- **Time:** O(V²) for the implemented matrix-based processing.
- **Space:** O(V²), for the adjacency matrix and O(V) auxiliary arrays.

The implementation processes vertices in reverse numeric order. Therefore, its correctness relies on the vertex numbering being compatible with the required reverse stage order. A general multistage graph should be processed in reverse topological order to guarantee correct results regardless of vertex numbering.

### 3.5 Floyd-Warshall Algorithm

The algorithm examines every intermediate vertex for every source-destination pair.

- **Time:** O(V³).
- **Space:** O(V²), for the distance matrix.

It computes shortest paths between all pairs of vertices. Its cubic running time makes it more suitable for smaller or moderately sized graphs than very large dense graphs.

### 3.6 Single-Source Shortest Path using Dijkstra

The implementation uses an adjacency matrix and a linear scan to select the next vertex with the minimum tentative distance.

- **Time:** O(V²).
- **Space:** O(V²), dominated by the graph matrix.

It supports non-negative edge weights and calculates shortest paths from one source. The adjacency-matrix approach is straightforward but can be less space-efficient for sparse graphs.

### 3.7 Traveling Salesperson using Dynamic Programming

The implementation combines dynamic programming with bitmasking to represent visited-city sets.

- **Time:** O(n² × 2ⁿ).
- **Space:** O(n × 2ⁿ).

The number of states grows exponentially with the number of cities. This is why the implementation restricts the input to 15 cities.

### 3.8 Route Optimization System

The application stores routes in an adjacency matrix and applies Dijkstra's algorithm for each route query.

- **Route query time:** O(V²).
- **Space:** O(V²), for the graph matrix.
- **Route insertion/update:** O(1).

The system supports non-negative route costs and undirected routes. Its performance is primarily determined by the shortest-path calculation.

## 4. Practical Comparison

| Algorithm | Main Strength | Main Limitation |
|---|---|---|
| Recursive Fibonacci | Simple implementation | Exponential running time |
| Memoized Fibonacci | Avoids repeated calculations | Requires cache storage and recursion |
| 0/1 Knapsack DP | Finds an optimal selection | Capacity-dependent memory and time |
| Multistage Graph DP | Uses stage structure to optimize paths | Requires correct processing order |
| Floyd-Warshall | Finds all-pairs shortest paths | Cubic running time |
| Dijkstra | Efficient for a single source in this implementation | Requires non-negative weights |
| TSP DP | Finds an optimal tour for supported inputs | Exponential state space |
| Route Optimization System | Practical route queries and path reporting | Matrix storage and quadratic query time |

## 5. Conclusions

The analysis demonstrates that algorithm choice depends on the problem structure, input size, and required output.

Memoization reduces Fibonacci's exponential repeated work to linear time. Dynamic programming provides optimal solutions for the implemented Knapsack and Traveling Salesperson problems, but may require substantial memory. Floyd-Warshall is useful for all-pairs shortest paths, while Dijkstra is appropriate for single-source shortest paths with non-negative edge weights.

The experiments also demonstrate that asymptotic complexity describes how resource requirements grow with input size; it does not directly predict execution time on every machine.

## 6. Learning Outcomes

- Analyzed time and space complexity across eight implementations.
- Distinguished exponential, polynomial, and pseudo-polynomial complexity.
- Understood the trade-off between computation and memory.
- Connected theoretical complexity with measured Fibonacci execution times.
- Identified implementation assumptions that affect algorithm correctness.
