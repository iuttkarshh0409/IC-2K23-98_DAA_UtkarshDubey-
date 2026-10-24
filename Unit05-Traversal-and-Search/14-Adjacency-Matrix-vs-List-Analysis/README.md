# Experiment 14: Comparative Analysis of Adjacency Matrix and Adjacency List

## Aim
To compare adjacency matrix and adjacency list representations of an undirected graph based on storage requirements, graph construction time, neighbor traversal time, and theoretical complexity.

## Problem Statement
Develop a C++ program that represents the same undirected graph using an adjacency matrix and an array-based adjacency list. Measure construction and neighbor-scanning times, report allocated array storage, and validate that both representations contain the same number of adjacency entries.

## Theory

### Adjacency Matrix
An adjacency matrix represents a graph using a two-dimensional array of size \(V \times V\).

- A value of `1` indicates an edge.
- A value of `0` indicates no edge.
- For an undirected graph, the matrix is symmetric.
- It provides constant-time edge existence checks.

### Adjacency List
An adjacency list stores the neighbors of each vertex. In this experiment, it uses fixed-size arrays:
- `head[]` stores the first adjacency entry for each vertex.
- `to[]` stores destination vertices.
- `nextEdge[]` links adjacency entries.

For an undirected graph, each input edge is stored in both directions.

## Algorithm
1. Read the number of vertices and edges.
2. Validate the graph dimensions and edge endpoints.
3. Store the input edges in arrays for reuse.
4. Construct the adjacency matrix and measure construction time.
5. Construct the adjacency list and measure construction time.
6. Scan the complete matrix to count adjacency entries and measure scan time.
7. Traverse all adjacency lists to count entries and measure scan time.
8. Display the entry counts, timings, allocated array sizes, and theoretical complexities.
9. Verify that both representations contain the same number of adjacency entries.

## Pseudocode

```text id="0kcq3v"
START
    Read V, E
    Validate graph dimensions

    Read and validate all edges
    Store edges in input arrays

    Start matrix timer
    Insert every edge in both directions into matrix
    Stop matrix timer

    Initialize adjacency list

    Start list timer
    Insert every edge in both directions into list
    Stop list timer

    Scan all matrix cells and count entries
    Measure matrix scan time

    Traverse every adjacency list and count entries
    Measure list scan time

    Display timings, storage, and complexity
    Compare adjacency-entry counts

STOP
```

## Sample Input

```text id="atjzhw"
5 5
1 2
1 3
2 4
3 4
4 5
```

## Expected Validation Output

```text id="cdx9n7"
Vertices: 5
Input edges: 5

Adjacency Matrix:
Directed adjacency entries: 10

Adjacency List:
Directed adjacency entries: 10

Validation: Both representations store the same number of adjacency entries.
```

Execution times and allocated storage values are displayed by the program and may vary with the platform and compiler.

## Complexity Analysis

Let \(V\) represent the number of vertices and \(E\) represent the number of edges.

| Operation | Adjacency Matrix | Adjacency List |
|---|---|---|
| Storage complexity | \(O(V^2)\) | \(O(V+E)\) |
| Construction, excluding initialization | \(O(E)\) | \(O(E)\) |
| Initialization | \(O(V^2)\) | \(O(V)\) |
| Checking whether an edge exists | \(O(1)\) | \(O(\deg(u))\) |
| Listing neighbors of one vertex | \(O(V)\) | \(O(\deg(u))\) |
| Listing all neighbors | \(O(V^2)\) | \(O(V+E)\) |

The matrix is suitable when the graph is dense or frequent edge-existence checks are needed. The adjacency list is usually more memory-efficient for sparse graphs.

## Experimental Observations
- Both representations should contain the same number of adjacency entries.
- An undirected graph with \(E\) distinct edges contains \(2E\) adjacency entries when self-loops are excluded.
- The adjacency matrix allocates space for all possible vertex pairs.
- The adjacency list stores entries for existing connections.
- Construction and scanning timings vary with graph size, graph density, compiler settings, and system load.
- Small graphs may produce noisy microsecond measurements.

Record measurements from sparse and dense test graphs if empirical comparisons are required in the final lab report.

## Limitations
- The implementation uses fixed-size arrays, so allocated storage represents array capacity rather than exact active-entry memory consumption.
- The benchmark uses one run per operation, so the measured timings are not statistically robust.
- The program represents an undirected, unweighted graph.

## Edge Cases
- A graph containing one vertex and no edges.
- A graph with no edges.
- A sparse graph.
- A dense graph.
- Invalid vertex numbers.
- Self-loops, which are rejected.

## Learning Outcomes
- Understood two common graph representations.
- Compared their storage and neighbor-traversal requirements.
- Learned how graph density affects representation choice.
- Used runtime measurements to compare implementations.
- Distinguished allocated array capacity from active graph data.

## Conclusion
The experiment compares adjacency matrix and adjacency list representations using construction and neighbor-scanning measurements. Both represent the same graph, but their storage and traversal characteristics differ. Adjacency matrices provide constant-time edge checks, while adjacency lists generally use less space for sparse graphs.
