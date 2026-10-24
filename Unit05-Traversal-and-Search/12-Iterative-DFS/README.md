# Experiment 12: Iterative Depth-First Search (DFS)

## Aim
To implement iterative Depth-First Search for traversing an undirected graph using a stack in C++.

## Problem Statement
Write a C++ program to represent an undirected graph using an adjacency matrix and traverse it using iterative Depth-First Search. The program should accept a starting vertex, visit all vertices reachable from it, and report whether any vertices are unreachable.

## Theory
**Depth-First Search (DFS)** explores a graph by following one path as deeply as possible before backtracking.

In iterative DFS, an explicit **stack** is used to manage the vertices waiting to be processed. The stack follows the Last In, First Out (LIFO) principle.

A visited array prevents vertices from being processed repeatedly, particularly when the graph contains cycles.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize the adjacency matrix with zeros.
3. Read and validate each undirected edge.
4. Read and validate the starting vertex.
5. Push the starting vertex onto the stack.
6. While the stack is not empty:
   - Pop the top vertex.
   - If it has already been visited, skip it.
   - Otherwise, mark it visited and display it.
   - Push its unvisited neighbors in reverse numerical order.
7. Check whether any vertices remain unvisited.
8. Display a warning if some vertices are unreachable from the starting vertex.

## Pseudocode

```text id="9kfd1p"
ITERATIVE_DFS(graph, start)
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

```text id="d2m8f3"
6 5
1 2
1 3
2 4
2 5
3 6
1
```

## Sample Output

```text id="m7y3qk"
Iterative DFS Traversal: 1 2 4 5 3 6
```

The exact traversal order depends on the order in which neighboring vertices are pushed onto the stack.

## Complexity Analysis

Let \(V\) be the number of vertices and \(E\) be the number of edges.

| Operation | Complexity |
|---|---|
| Graph initialization and representation | \(O(V^2 + E)\) |
| DFS using an adjacency matrix | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |
| Stack and visited array | \(O(V)\) each |
| Total storage including graph | \(O(V^2)\) |

The traversal takes \(O(V^2)\) time because it scans the adjacency-matrix row of each processed vertex.

## Applications
- Exploring graph connections.
- Maze and path exploration.
- Checking reachability.
- Detecting connected components.
- Traversing network structures.

## Edge Cases
- A graph containing a single vertex.
- A graph with no edges.
- A graph containing cycles.
- A graph with isolated vertices.
- An invalid starting vertex.
- A disconnected graph.

## Learning Outcomes
- Understood stack-based graph traversal.
- Implemented DFS without recursive traversal calls.
- Learned how the visited array prevents repeated processing.
- Compared iterative and recursive DFS.
- Analyzed time and space complexity.

## Conclusion
The program demonstrates iterative Depth-First Search using an adjacency matrix and an explicit stack. It visits reachable vertices and reports whether some vertices remain unreachable from the chosen starting vertex.
