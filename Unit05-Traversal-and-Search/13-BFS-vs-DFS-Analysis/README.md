# Experiment 13: Comparative Analysis of BFS and DFS

## Aim
To compare Breadth-First Search (BFS) and Depth-First Search (DFS) in terms of traversal order, reachability, execution time, and time and space complexity.

## Problem Statement
Develop a C++ program that represents an undirected graph using an adjacency matrix and performs both BFS and iterative DFS from the same starting vertex. Display both traversal orders, count the vertices reached by each algorithm, measure their execution times, and summarize their theoretical complexity.

## Theory

### Breadth-First Search (BFS)
BFS explores vertices level by level, visiting neighboring vertices before moving to vertices farther away. It uses a **queue** following the First In, First Out (FIFO) principle.

### Depth-First Search (DFS)
DFS explores one path as deeply as possible before backtracking. The iterative implementation uses a **stack** following the Last In, First Out (LIFO) principle.

Both algorithms can determine which vertices are reachable from a given starting vertex. When run on the same graph and starting vertex, they should reach the same set of vertices, although their traversal orders may differ.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize the adjacency matrix.
3. Read and validate the undirected edges.
4. Read and validate the starting vertex.
5. Run BFS and record its traversal order and execution time.
6. Run iterative DFS and record its traversal order and execution time.
7. Display both traversal orders.
8. Display the number of vertices reached by each algorithm.
9. Display the measured execution times and theoretical complexity observations.

## Pseudocode

```text
MAIN
    Read vertices, edges
    Initialize adjacency matrix
    Read and validate edges
    Read starting vertex

    Start BFS timer
    Run BFS using a queue
    Stop BFS timer

    Start DFS timer
    Run iterative DFS using a stack
    Stop DFS timer

    Display BFS traversal order
    Display DFS traversal order
    Display vertices reached by each algorithm
    Display measured execution times
    Display theoretical complexity comparison
```

## Sample Input

```text
6 5
1 2
1 3
2 4
2 5
3 6
1
```

## Sample Output

```text
BFS order: 1 2 3 4 5 6
DFS order: 1 2 4 5 3 6
Vertices reached by BFS: 6
Vertices reached by DFS: 6
```

Execution times are measured at runtime and vary depending on the system, compiler settings, graph size, and system load.

## Comparative Analysis

| Property | BFS | DFS |
|---|---|---|
| Data structure | Queue | Stack |
| Traversal strategy | Level by level | Depth first, then backtracking |
| Shortest path in an unweighted graph | Finds minimum-edge paths | Not guaranteed |
| Adjacency-matrix traversal time | \(O(V^2)\) | \(O(V^2)\) |
| Auxiliary space | \(O(V)\) | \(O(V)\) |
| Typical applications | Unweighted shortest paths, level exploration | Connectivity exploration, cycle detection with suitable tracking |

## Complexity Analysis

Let \(V\) represent the number of vertices and \(E\) represent the number of edges.

| Operation | Complexity |
|---|---|
| Adjacency-matrix initialization | \(O(V^2)\) |
| Graph construction, including initialization | \(O(V^2 + E)\) |
| BFS traversal using an adjacency matrix | \(O(V^2)\) |
| Iterative DFS using an adjacency matrix | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |
| Queue or stack and visited array | \(O(V)\) per traversal |

Both algorithms have the same asymptotic traversal complexity when using an adjacency matrix. Runtime measurements on small graphs may be dominated by measurement overhead and system variation, so repeated measurements on larger graphs provide more meaningful comparisons.

## Experimental Observations
- BFS and DFS may produce different traversal orders on the same graph.
- Both algorithms should reach the same vertices from the same starting point.
- A disconnected graph may contain vertices unreachable from the selected starting vertex.
- Measured execution times can fluctuate between runs.
- The graph representation influences performance and memory requirements.

Record the measured BFS and DFS execution times from your program runs here if your lab report requires empirical results.

## Edge Cases
- A graph containing a single vertex.
- A graph with no edges.
- A graph containing cycles.
- A disconnected graph.
- Invalid starting vertex input.
- Duplicate edge entries.

## Learning Outcomes
- Understood BFS and DFS traversal strategies.
- Compared queue-based and stack-based graph traversal.
- Distinguished traversal order from graph reachability.
- Compared theoretical complexity with measured execution time.
- Identified suitable applications for each traversal algorithm.

## Conclusion
The experiment compares BFS and iterative DFS on the same undirected graph. Both algorithms identify the vertices reachable from the starting point, but their traversal orders differ because they use different exploration strategies. With an adjacency matrix, both have \(O(V^2)\) traversal time and \(O(V^2)\) graph storage.
