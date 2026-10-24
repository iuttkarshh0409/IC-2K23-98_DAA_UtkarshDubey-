# Experiment 05: All-Pairs Shortest Path Using Floyd-Warshall

## Aim
To implement the Floyd-Warshall algorithm in C++ to calculate the shortest distances between every pair of vertices in a weighted directed graph.

## Objectives
- Understand the All-Pairs Shortest Path problem.
- Apply Dynamic Programming to graph algorithms.
- Represent a weighted graph using an adjacency matrix.
- Calculate shortest distances using intermediate vertices.
- Detect negative-weight cycles.
- Analyze the time and space complexity of the algorithm.

## Problem Statement
Given a weighted directed graph with `V` vertices, determine the shortest-path distance between every pair of vertices.

The graph may contain negative-weight edges, provided it does not contain a negative-weight cycle.

## Theory
The Floyd-Warshall algorithm is a Dynamic Programming algorithm that calculates shortest-path distances between all pairs of vertices.

It progressively considers each vertex as a possible intermediate vertex on a path.

Let `dist[i][j]` represent the shortest known distance from vertex `i` to vertex `j`.

For each intermediate vertex `k`, the algorithm checks whether travelling from `i` to `j` through `k` produces a shorter path.

The recurrence relation is:

\[
D[i][j]=\min(D[i][j],D[i][k]+D[k][j])
\]

The implementation uses a fixed-size two-dimensional array. The value `-1` in the input represents the absence of a direct edge, while `0` is used for diagonal entries. Internally, a large value represents infinity.

## Algorithm
1. Read the number of vertices.
2. Read the adjacency matrix.
3. Convert input values representing absent edges into infinity.
4. For every vertex `k`, consider it as an intermediate vertex.
5. For every pair of vertices `(i, j)`:
   - Skip the calculation if either required subpath is unreachable.
   - Calculate the candidate distance through `k`.
   - Update the distance if the candidate is smaller.
6. Inspect the diagonal entries for negative values.
7. If a negative-weight cycle exists, report an error.
8. Otherwise, display the final shortest-distance matrix.

## Pseudocode
```text
BEGIN
    INPUT V
    INPUT adjacency matrix

    FOR k = 1 TO V
        FOR i = 1 TO V
            FOR j = 1 TO V
                IF D[i][k] and D[k][j] are finite
                    candidate = D[i][k] + D[k][j]

                    IF candidate < D[i][j]
                        D[i][j] = candidate
                    END IF
                END IF
            END FOR
        END FOR
    END FOR

    FOR i = 1 TO V
        IF D[i][i] < 0
            OUTPUT "Negative-weight cycle detected"
            STOP
        END IF
    END FOR

    DISPLAY shortest-distance matrix
END
```

## Sample Input
```text
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0
```

In this directed graph, `-1` indicates that no direct edge exists.

## Sample Output
```text
All-Pairs Shortest Distance Matrix:
       0       5       8       9
     INF       0       3       4
     INF     INF       0       1
     INF     INF     INF       0
```

The shortest path from vertex 1 to vertex 4 has cost `9`, using the path `1 → 2 → 3 → 4`.

## Complexity Analysis

Let `V` represent the number of vertices.

| Operation | Complexity |
|---|---|
| Initialization and matrix input | O(V²) |
| Floyd-Warshall computation | O(V³) |
| Negative-cycle detection | O(V) |
| Overall time complexity | **O(V³)** |
| Space complexity | **O(V²)** |

The three nested loops dominate the overall execution time.

## Test Cases
- The sample graph produces the expected shortest-distance matrix.
- A graph containing one vertex returns distance `0` from the vertex to itself.
- Unreachable vertex pairs are displayed as `INF`.
- Negative-weight edges are supported when no negative-weight cycle exists.
- A negative-weight cycle is detected.
- Invalid vertex counts and malformed matrix input are rejected.

## Limitations
- The implementation supports at most 100 vertices.
- The input convention reserves `-1` for the absence of an edge, so a direct edge with weight `-1` cannot be represented.
- The algorithm requires O(V³) time, making it expensive for very large graphs.

## Learning Outcomes
- Understood the All-Pairs Shortest Path problem.
- Applied Dynamic Programming to weighted graphs.
- Used intermediate vertices to improve shortest-path estimates.
- Learned to represent unreachable paths using infinity.
- Detected negative-weight cycles.
- Analyzed the time and space complexity of Floyd-Warshall.

## Conclusion
The Floyd-Warshall algorithm was successfully implemented in C++ using Dynamic Programming. It calculates shortest-path distances between all pairs of vertices and detects negative-weight cycles.
