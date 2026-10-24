# Experiment 11: Recursive Depth-First Search (DFS)

## Aim
To implement Depth-First Search recursively for traversing an undirected graph using C++.

## Problem Statement
Write a C++ program to represent an undirected graph using an adjacency matrix and traverse it using recursive Depth-First Search. The program should accept a starting vertex, visit all vertices reachable from it, and report whether any vertices are unreachable.

## Theory
**Depth-First Search (DFS)** explores a graph by visiting a vertex and recursively exploring each unvisited neighbor before backtracking.

In recursive DFS, the program's **call stack** manages the traversal state. Each recursive call processes a vertex and explores its unvisited neighbors.

A visited array prevents repeated visits, including when the graph contains cycles.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize the adjacency matrix with zeros.
3. Read and validate each undirected edge.
4. Read and validate the starting vertex.
5. Call the recursive DFS function with the starting vertex.
6. In the DFS function:
   - Mark the current vertex as visited.
   - Display the current vertex.
   - Examine its neighbors in ascending vertex order.
   - Recursively visit each unvisited neighbor.
7. After traversal, check whether any vertices remain unvisited.
8. Display a warning if some vertices are unreachable from the starting vertex.

## Pseudocode

```text id="8kp4wc"
RECURSIVE_DFS(current)
    visited[current] = true
    display current

    for each vertex i in ascending order
        if graph[current][i] exists
           and visited[i] is false
            RECURSIVE_DFS(i)

MAIN
    Read vertices and edges
    Initialize adjacency matrix
    Read and validate edges
    Read starting vertex
    RECURSIVE_DFS(start)

    if any vertex remains unvisited
        display unreachable-vertices warning
```

## Sample Input

```text id="q8x41e"
6 5
1 2
1 3
2 4
2 5
3 6
1
```

## Sample Output

```text id="l8w91b"
Recursive DFS Traversal: 1 2 4 5 3 6
```

## Complexity Analysis

Let \(V\) be the number of vertices and \(E\) the number of edges.

| Operation | Complexity |
|---|---|
| Graph initialization and representation | \(O(V^2 + E)\) |
| Recursive DFS using an adjacency matrix | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |
| Recursion stack | \(O(V)\) |
| Total storage including graph | \(O(V^2)\) |

The traversal takes \(O(V^2)\) time because it scans the complete adjacency-matrix row for each visited vertex.

## Applications
- Exploring graph connections.
- Checking reachability from a starting vertex.
- Maze and path exploration.
- Detecting cycles with suitable graph-state tracking.
- Traversing tree and network structures.

## Edge Cases
- A graph containing a single vertex.
- A graph with no edges.
- A graph containing cycles.
- A graph with isolated vertices.
- An invalid starting vertex.
- A disconnected graph.

## Learning Outcomes
- Understood recursive graph traversal.
- Implemented DFS using recursive function calls.
- Learned how the call stack handles backtracking.
- Understood the role of visited arrays in cyclic graphs.
- Analyzed time and space complexity.

## Conclusion
The program successfully performs recursive Depth-First Search on an undirected graph represented by an adjacency matrix. It visits reachable vertices and reports whether some vertices remain unreachable from the chosen starting vertex.
