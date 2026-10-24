# Experiment 10: Depth-First Search (DFS)

## Aim
To implement Depth-First Search (DFS) for traversing an undirected graph using a stack in C++.

## Problem Statement
Write a C++ program to represent an undirected graph using an adjacency matrix and traverse it using the iterative Depth-First Search algorithm. The program should accept a starting vertex, visit all vertices reachable from it, and report whether any vertices are unreachable.

## Theory
**Depth-First Search (DFS)** is a graph traversal algorithm that explores one path as deeply as possible before backtracking to explore other paths.

This implementation uses a **stack**, which follows the Last In, First Out (LIFO) principle.

A visited array tracks processed vertices to prevent repeated visits and avoid infinite traversal in cyclic graphs.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize the adjacency matrix with zeros.
3. Read and validate each undirected edge.
4. Read and validate the starting vertex.
5. Push the starting vertex onto the stack.
6. While the stack is not empty:
   - Pop a vertex from the stack.
   - If it has already been visited, skip it.
   - Otherwise, mark it visited and display it.
   - Push its unvisited neighbors in reverse numerical order.
7. Check whether any vertices remain unvisited.
8. If any vertices are unreachable, display a warning.

## Pseudocode

```text id="o9kr5m"
DFS(graph, start)
    Initialize visited[] as false
    Initialize an empty stack
    push(start)

    while stack is not empty
        current = pop()

        if visited[current]
            continue

        visited[current] = true
        display current

        for each neighbor in reverse vertex order
            if graph[current][neighbor] exists
               and visited[neighbor] is false
                push(neighbor)

    if any vertex remains unvisited
        display unreachable-vertices warning
```

## Sample Input

```text id="e0y04z"
6 5
1 2
1 3
2 4
2 5
3 6
1
```

## Sample Output

```text id="vt5z5r"
DFS Traversal: 1 2 4 5 3 6
```

The traversal order depends on the order in which neighbors are processed and pushed onto the stack.

## Complexity Analysis

Let \(V\) be the number of vertices and \(E\) be the number of edges.

| Operation | Complexity |
|---|---|
| Graph representation | \(O(V^2 + E)\) |
| DFS using an adjacency matrix | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |
| Stack and visited array | \(O(V)\) |
| Total storage including graph | \(O(V^2)\) |

DFS scans an entire row of the adjacency matrix for each processed vertex, giving \(O(V^2)\) traversal time.

## Applications
- Maze exploration and path discovery.
- Checking graph connectivity.
- Detecting cycles in graphs.
- Exploring networks.
- Supporting topological sorting in directed acyclic graphs.

## Edge Cases
- A graph containing a single vertex.
- A graph with no edges.
- A graph containing cycles.
- A graph with isolated vertices.
- An invalid starting vertex.
- A disconnected graph in which some vertices cannot be reached from the start.

## Learning Outcomes
- Understood depth-first graph exploration.
- Implemented iterative DFS using a stack.
- Learned how a visited array prevents repeated processing.
- Compared stack-based traversal with queue-based traversal.
- Analyzed time and space complexity.

## Conclusion
The program successfully performs iterative Depth-First Search on an undirected graph using an adjacency matrix and a stack. It visits reachable vertices and identifies when some vertices cannot be reached from the chosen starting vertex.
