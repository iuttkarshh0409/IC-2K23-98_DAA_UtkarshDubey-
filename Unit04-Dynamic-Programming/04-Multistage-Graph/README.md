# Experiment 04: Multistage Graph Using Dynamic Programming

## Aim
To implement a Dynamic Programming algorithm in C++ to find the minimum-cost path from the source vertex to the destination vertex in a multistage graph.

## Objectives
- Understand multistage graphs and their stage-based structure.
- Represent a directed graph using an adjacency matrix.
- Apply Dynamic Programming to calculate minimum path costs.
- Reconstruct the minimum-cost path.
- Analyze the time and space complexity of the algorithm.

## Problem Statement
Given a directed multistage graph, determine the minimum-cost path from the source vertex to the destination vertex.

The vertices are divided into ordered stages. Edges must connect vertices from an earlier stage to a later stage. Each edge has an associated cost.

## Theory
A multistage graph is a directed acyclic graph whose vertices are partitioned into stages. The source belongs to the first stage, and the destination belongs to the final stage.

Dynamic Programming solves the problem by calculating minimum costs in reverse order, starting from the destination.

Let `cost(u)` represent the minimum cost of reaching the destination from vertex `u`.

The recurrence relation is:

\[
cost(u)=\min_{(u,v)\in E}\{w(u,v)+cost(v)\}
\]

The destination has a cost of zero because no additional travel is required once it has been reached.

The implementation stores:
- `graph[][]`: edge costs in an adjacency matrix.
- `stage[]`: stage number of each vertex.
- `cost[]`: minimum cost from each vertex to the destination.
- `nextVertex[]`: next vertex on the selected minimum-cost path.

A matrix entry of zero represents the absence of an edge, so the implementation does not support zero-cost edges.

## Algorithm
1. Read the number of vertices, stages, and directed edges.
2. Read the stage number of each vertex.
3. Validate that the source belongs to the first stage and the destination belongs to the final stage.
4. Read and validate the directed edges.
5. Initialize all vertex costs to infinity and the destination cost to zero.
6. Process vertices in reverse order.
7. For each vertex, examine its outgoing edges:
   - Ignore edges whose destination cannot reach the final vertex.
   - Calculate the edge cost plus the destination vertex's minimum cost.
   - Store the smallest candidate cost and the corresponding next vertex.
8. If the source remains unreachable, report that no path exists.
9. Otherwise, display the minimum cost and reconstruct the path using `nextVertex[]`.

## Pseudocode
```text
BEGIN
    INPUT V, stages, E
    INPUT stage of every vertex
    INPUT and validate all directed edges

    FOR each vertex u
        cost[u] = INFINITY
        nextVertex[u] = NONE
    END FOR

    cost[destination] = 0

    FOR u from V-2 DOWN TO 0
        FOR each vertex v
            IF edge(u, v) exists AND cost[v] is finite
                candidate = weight(u, v) + cost[v]

                IF candidate < cost[u]
                    cost[u] = candidate
                    nextVertex[u] = v
                END IF
            END IF
        END FOR
    END FOR

    IF cost[source] is INFINITY
        OUTPUT "No path exists"
    ELSE
        OUTPUT cost[source]
        RECONSTRUCT path using nextVertex[]
        OUTPUT path
    END IF
END
```

## Sample Input
```text
8
4
12
1
2
2
3
3
3
3
4
1 2 2
1 3 1
2 4 2
2 5 3
3 5 6
3 6 4
4 7 2
5 7 6
5 8 4
6 8 7
7 8 1
4 8 8
```

The input specifies eight vertices, four stages, twelve directed edges, followed by the stage assignments and edge definitions.

## Sample Output
```text
Minimum path cost: 7
Minimum-cost path: 1 -> 2 -> 4 -> 7 -> 8
```

The selected path has total cost `2 + 2 + 2 + 1 = 7`.

## Complexity Analysis

Let `V` be the number of vertices and `E` the number of edges.

| Operation | Complexity |
|---|---|
| Reading the adjacency matrix | O(V²) |
| Calculating minimum costs | O(V²) |
| Reconstructing the path | O(V) |
| Overall time complexity | **O(V²)** |
| Space complexity | **O(V²)** |

The adjacency matrix dominates the space requirement.

## Test Cases
- The sample graph produces minimum cost `7`.
- A graph without a source-to-destination path reports an error.
- Invalid vertex numbers and stage assignments are rejected.
- Edges connecting the same or an earlier stage are rejected.
- Duplicate edges are rejected.
- A valid minimum-cost path is printed in source-to-destination order.

## Limitations
- The implementation supports at most 100 vertices.
- Zero-cost edges cannot be represented because zero indicates no edge.
- The graph must respect the specified stage ordering.
- The source is vertex 1 and the destination is vertex `V`.

## Learning Outcomes
- Understood the structure of multistage graphs.
- Applied Dynamic Programming to a minimum-cost path problem.
- Used reverse-order processing to solve dependent subproblems.
- Reconstructed a path using stored decisions.
- Analyzed the time and space complexity of the implementation.

## Conclusion
The Multistage Graph problem was successfully implemented in C++ using Dynamic Programming. The algorithm calculates minimum costs in reverse order and reconstructs the minimum-cost path from the source to the destination.
