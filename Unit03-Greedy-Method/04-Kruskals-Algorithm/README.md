# Experiment 04: Minimum Cost Spanning Tree Using Kruskal's Algorithm

## Aim
To implement Kruskal's Algorithm in C++ to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.

## Objectives
- Understand the concept of a Minimum Spanning Tree.
- Apply the Greedy Method to select edges in increasing order of weight.
- Represent a graph using an edge list.
- Detect cycles using the Disjoint Set Union (DSU) technique.
- Analyze the time and space complexity of Kruskal's Algorithm.

## Problem Statement
Given a connected, undirected, weighted graph, determine a spanning tree with the minimum possible total edge weight.

A spanning tree connects all vertices without cycles and contains exactly `V - 1` edges, where `V` is the number of vertices.

## Theory
Kruskal's Algorithm is a greedy algorithm that constructs a Minimum Spanning Tree by selecting edges in ascending order of weight.

The algorithm examines each edge and adds it only if doing so does not create a cycle. A Disjoint Set Union (DSU) structure efficiently tracks connected components.

The implementation uses:
- An edge array to store the graph.
- Sorting to process edges from lowest to highest weight.
- A parent array to represent connected components.
- A rank array to help keep the DSU structure efficient.
- Path compression and union by rank to optimize component operations.

## Algorithm
1. Read the number of vertices and edges.
2. Initialize each vertex as a separate connected component.
3. Read and validate the edge list.
4. Sort all edges by increasing weight.
5. Initialize the total cost and selected-edge count to zero.
6. Process edges in sorted order:
   - Find the components containing the edge's endpoints.
   - If the endpoints belong to different components, add the edge to the MST and merge the components.
   - Otherwise, skip the edge because it would create a cycle.
7. Stop after selecting `V - 1` edges or exhausting all edges.
8. If fewer than `V - 1` edges were selected, report that the graph is disconnected.
9. Otherwise, display the selected edges and minimum total cost.

## Pseudocode
```text
BEGIN
    INPUT V, E

    INITIALIZE each vertex as a separate component
    INPUT all edges
    SORT edges by increasing weight

    edgeCount = 0
    totalCost = 0

    FOR each edge (u, v, weight) in sorted order
        IF FIND(u) != FIND(v)
            ADD edge to MST
            UNION(u, v)
            totalCost = totalCost + weight
            edgeCount = edgeCount + 1
        END IF

        IF edgeCount = V - 1
            BREAK
        END IF
    END FOR

    IF edgeCount != V - 1
        OUTPUT "Graph is disconnected"
    ELSE
        OUTPUT MST edges and totalCost
    END IF
END
```

## Sample Input
```text
5
7
1 2 2
1 4 6
2 3 3
2 4 8
2 5 5
3 5 7
4 5 9
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

The MST contains four edges with a total cost of `16`. The order of selected edges may vary when multiple edges have equal weights.

## Complexity Analysis

Let `V` be the number of vertices and `E` the number of edges.

| Operation | Complexity |
|---|---|
| Sorting the edges | O(E log E) |
| DSU operations | Nearly constant amortized time per operation |
| Overall time complexity | **O(E log E)** |
| Space complexity | **O(V + E)** |

The sorting step dominates the overall time complexity. Path compression and union by rank make cycle detection efficient.

## Test Cases
- The sample graph produces a minimum total cost of `16`.
- A graph containing one vertex and no edges returns a cost of `0`.
- A disconnected graph reports that a spanning tree does not exist.
- Equal-weight edges are processed correctly.
- Zero-weight edges are supported.
- Invalid vertex numbers are rejected.
- Self-loops and negative weights are rejected.
- Edge counts outside the supported range are rejected.

## Limitations
- The implementation supports at most 100 vertices.
- The graph is treated as undirected.
- Negative edge weights are rejected by input validation, although the general Kruskal algorithm can support negative weights.

## Learning Outcomes
- Understood the greedy strategy for constructing a Minimum Spanning Tree.
- Learned to represent graphs using an edge list.
- Implemented cycle detection with Disjoint Set Union.
- Applied path compression and union by rank.
- Analyzed the time and space complexity of Kruskal's Algorithm.

## Conclusion
Kruskal's Algorithm was successfully implemented in C++ using the Greedy Method. By processing edges in increasing order of weight and rejecting edges that form cycles, the algorithm constructs a Minimum Spanning Tree with minimum total cost.
