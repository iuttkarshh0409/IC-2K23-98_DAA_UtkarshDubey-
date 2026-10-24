# Experiment 03: Minimum Cost Spanning Tree Using Prim's Algorithm

## Aim
To implement Prim's Algorithm in C++ to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.

## Objectives
- Understand the concept of a spanning tree and a Minimum Spanning Tree.
- Apply the Greedy Method to graph problems.
- Represent a graph using an adjacency matrix.
- Find the minimum-cost edges required to connect all vertices.
- Analyze the time and space complexity of Prim's Algorithm.

## Problem Statement
Given a connected, undirected, weighted graph, find a spanning tree that connects all vertices with the minimum possible total edge weight.

A spanning tree of a graph with `V` vertices contains exactly `V - 1` edges and has no cycles.

## Theory
Prim's Algorithm is a greedy algorithm used to construct a Minimum Spanning Tree.

The algorithm begins with an arbitrary vertex and repeatedly selects the minimum-weight edge connecting a vertex already included in the tree to a vertex not yet included.

This process continues until all vertices are included.

The implementation uses an adjacency matrix to represent the graph and a Boolean array to track the vertices already selected.

**Input representation:** The graph is represented by a square adjacency matrix. A weight of `0` indicates the absence of an edge. Positive weights represent edges. The matrix must be symmetric because the graph is undirected.

## Algorithm
1. Read the number of vertices and the adjacency matrix.
2. Validate the matrix and reject invalid weights or asymmetric input.
3. Mark the first vertex as selected.
4. Initialize the edge count and total cost to zero.
5. Until `V - 1` edges have been selected:
   - Find the minimum-weight edge connecting a selected vertex to an unselected vertex.
   - If no such edge exists, report that the graph is disconnected.
   - Otherwise, include the edge and mark its destination vertex as selected.
   - Add the edge weight to the total cost.
6. Display the selected edges and the minimum total cost.

## Pseudocode
```text
BEGIN
    INPUT V
    INPUT adjacency matrix

    MARK all vertices as unselected
    MARK vertex 1 as selected

    edgeCount = 0
    totalCost = 0

    WHILE edgeCount < V - 1
        minimum = INFINITY
        FIND the minimum-weight edge (u, v)
        WHERE u is selected and v is unselected

        IF no such edge exists
            OUTPUT "Graph is disconnected"
            STOP
        END IF

        MARK v as selected
        OUTPUT edge (u, v) and its weight
        totalCost = totalCost + weight(u, v)
        edgeCount = edgeCount + 1
    END WHILE

    OUTPUT totalCost
END
```

## Sample Input
```text
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
```

## Sample Output
```text
Minimum Spanning Tree edges:
Edge    Weight
1 - 2   2
2 - 3   3
2 - 5   5
1 - 4   6

Minimum total cost: 16
```

The Minimum Spanning Tree contains four edges, connecting all five vertices with a total cost of `16`. Edge selection order may vary while preserving the same minimum cost.

## Complexity Analysis

Let `V` be the number of vertices.

| Operation | Complexity |
|---|---|
| Reading the adjacency matrix | O(V²) |
| Finding each minimum-weight connecting edge | O(V²) overall |
| Overall time complexity | **O(V²)** |
| Space complexity | **O(V²)** |

The adjacency matrix requires O(V²) space, while the selected-vertex array requires O(V) space.

## Test Cases
- A sample connected graph produces a minimum total cost of `16`.
- A graph containing a single vertex returns a cost of `0`.
- A disconnected graph reports that a spanning tree does not exist.
- An asymmetric adjacency matrix is rejected.
- Negative edge weights are rejected.
- Invalid vertex counts outside the supported range of 1 to 100 are rejected.

## Limitations
- The implementation uses `0` to represent the absence of an edge; therefore, zero-weight edges are not supported.
- The adjacency matrix requires O(V²) storage.
- The implementation supports non-negative edge weights for undirected graphs.

## Learning Outcomes
- Understood the Greedy Method for constructing a Minimum Spanning Tree.
- Learned to represent weighted graphs using adjacency matrices.
- Implemented edge selection using a Boolean array.
- Identified disconnected graphs where a spanning tree cannot be constructed.
- Analyzed the time and space complexity of Prim's Algorithm.

## Conclusion
Prim's Algorithm was successfully implemented in C++ using the Greedy Method. The algorithm constructs a Minimum Spanning Tree by repeatedly selecting the minimum-weight edge connecting the existing tree to an unselected vertex.
