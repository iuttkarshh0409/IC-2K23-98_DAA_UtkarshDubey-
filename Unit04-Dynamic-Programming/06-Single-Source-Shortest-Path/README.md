# Experiment 06: Single-Source Shortest Path using Dijkstra's Algorithm

## Aim
To implement Dijkstra's algorithm to find the shortest distances and paths from a given source vertex to every other vertex in a weighted graph.

## Problem Statement
Given a weighted graph represented by an adjacency matrix and a source vertex, determine the shortest distance from the source to every vertex and display the corresponding paths.

## Algorithm
1. Read the number of vertices and the adjacency matrix.
2. Represent missing edges using `-1` and diagonal entries using `0`.
3. Reject negative edge weights because Dijkstra's algorithm requires non-negative weights.
4. Initialize all distances to infinity and the source distance to zero.
5. Repeatedly select the unvisited vertex with the smallest tentative distance.
6. Relax its outgoing edges and update distances and parent vertices when a shorter path is found.
7. Display the shortest distances and reconstruct the paths using the parent array.
8. Report unreachable vertices as `INF`.

## Pseudocode
```text
DIJKSTRA(graph, source, n):
    Set all distances to INF
    Set all parents to -1
    Set distance[source] = 0

    Repeat at most n times:
        Select unvisited vertex u with minimum distance
        If no reachable unvisited vertex exists:
            Stop

        Mark u as visited

        For each vertex v:
            If v is unvisited and edge (u, v) exists:
                candidate = distance[u] + weight(u, v)
                If candidate < distance[v]:
                    distance[v] = candidate
                    parent[v] = u

    Display distances and reconstruct paths
```

## Sample Input
```text
5
0 10 -1 5 -1
-1 0 1 2 -1
-1 -1 0 -1 4
-1 3 9 0 2
-1 -1 6 -1 0
1
```

## Sample Output
```text
Shortest distances from vertex 1:
Vertex  Distance  Path
1       0         1
2       8         1 -> 4 -> 2
3       9         1 -> 4 -> 2 -> 3
4       5         1 -> 4
5       7         1 -> 4 -> 5
```

## Complexity Analysis
- **Time Complexity:** O(V²), due to selecting the minimum-distance vertex through a linear scan and processing the adjacency matrix.
- **Space Complexity:** O(V²), for the adjacency matrix; auxiliary arrays require O(V) space.

## Edge Cases Tested
- A graph containing a single vertex.
- Unreachable vertices.
- Invalid source vertex.
- Negative edge weights.
- Zero-weight edges.
- Multiple possible paths to a destination.

## Limitations
- Dijkstra's algorithm does not support negative edge weights.
- The adjacency-matrix representation requires O(V²) memory.
- `-1` is reserved to represent a missing edge.

## Learning Outcomes
- Understood the single-source shortest-path problem.
- Implemented Dijkstra's greedy strategy.
- Learned how distance relaxation and parent tracking work.
- Reconstructed shortest paths from predecessor information.
- Analyzed time and space complexity.
