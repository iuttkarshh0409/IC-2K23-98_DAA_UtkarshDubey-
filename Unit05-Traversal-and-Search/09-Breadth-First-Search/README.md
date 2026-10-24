# Experiment 09: Breadth-First Search (BFS)

## Aim
To implement Breadth-First Search (BFS) for traversing an undirected graph using a queue in C++.

## Problem Statement
Write a C++ program to represent an undirected graph using an adjacency matrix and traverse it using Breadth-First Search. The program should accept a starting vertex, visit reachable vertices level by level, and identify whether any vertices are unreachable from the starting vertex.

## Theory
**Breadth-First Search (BFS)** is a graph traversal algorithm that explores vertices in increasing order of their distance, measured in edges, from the starting vertex.

BFS uses a **queue**, which follows the First In, First Out (FIFO) principle.

The algorithm marks a vertex as visited when it is added to the queue. This prevents the same vertex from being enqueued repeatedly.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize the adjacency matrix with zeros.
3. Read and validate each undirected edge.
4. Read and validate the starting vertex.
5. Mark the starting vertex as visited and enqueue it.
6. While the queue is not empty:
   - Remove the front vertex.
   - Display the vertex.
   - Examine its neighbors.
   - Mark each unvisited neighbor as visited and enqueue it.
7. Check whether any vertices remain unvisited.
8. If any vertices are unreachable, display a warning.

## Pseudocode

```text id="y8w3pk"
BFS(graph, start)
    Initialize visited[] as false
    Initialize an empty queue

    visited[start] = true
    enqueue(start)

    while queue is not empty
        current = dequeue()
        display current

        for each vertex i
            if graph[current][i] exists
               and visited[i] is false
                visited[i] = true
                enqueue(i)

    if any vertex remains unvisited
        display unreachable-vertices warning
```

## Sample Input

```text id="v5z5mw"
6 5
1 2
1 3
2 4
2 5
3 6
1
```

## Sample Output

```text id="akm82c"
BFS Traversal: 1 2 3 4 5 6
```

## Complexity Analysis

Let \(V\) be the number of vertices and \(E\) be the number of edges.

| Operation | Complexity |
|---|---|
| Graph representation | \(O(V^2 + E)\) |
| BFS traversal using an adjacency matrix | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |
| Queue and visited array | \(O(V)\) |
| Total auxiliary storage including graph | \(O(V^2)\) |

The traversal takes \(O(V^2)\) time because it scans an entire row of the adjacency matrix for every visited vertex.

## Applications
- Finding vertices reachable from a starting vertex.
- Finding shortest paths in unweighted graphs.
- Exploring networks level by level.
- Discovering connected components by repeating BFS from unvisited vertices.

## Edge Cases
- A graph containing a single vertex.
- A graph with no edges.
- A graph containing isolated vertices.
- A starting vertex that cannot reach every other vertex.
- Invalid vertex numbers.
- Cycles, which must not cause repeated visits.

## Learning Outcomes
- Understood the FIFO principle of queues.
- Implemented graph traversal using an adjacency matrix.
- Learned how to track visited vertices.
- Understood BFS traversal order and reachability.
- Analyzed time and space complexity.

## Conclusion
The program successfully performs Breadth-First Search on an undirected graph using an adjacency matrix and a queue. It visits reachable vertices level by level and reports when some vertices cannot be reached from the chosen starting vertex.
