# Experiment 05: Minimum-Cost Network Design System

## Aim
To develop a C++ application that designs a minimum-cost network using Prim's and Kruskal's algorithms and compares their results.

## Objectives
- Apply the Greedy Method to a practical network-design problem.
- Represent network locations as vertices and connections as weighted edges.
- Implement Prim's Algorithm to construct a Minimum Spanning Tree.
- Implement Kruskal's Algorithm with Disjoint Set Union for cycle detection.
- Compare the minimum network costs obtained by both algorithms.
- Handle invalid inputs and disconnected networks.

## Problem Statement
Design a minimum-cost network that connects a set of locations. Each possible connection has an associated cost. The system must select connections that connect every location while minimizing the total cost.

The application uses Prim's and Kruskal's algorithms to calculate the Minimum Spanning Tree (MST) and compare the resulting costs.

## Application Scenario
The system can be used as a simplified model for:
- Connecting buildings within a campus.
- Designing a computer network between offices.
- Planning connections between facilities.
- Estimating the cost of connecting locations using weighted links.

Each location is represented by a vertex, and each possible connection is represented by an undirected weighted edge.

## Theory
A Minimum Spanning Tree connects every vertex of a connected, undirected, weighted graph without cycles and with the minimum possible total edge weight.

### Prim's Algorithm
Prim's Algorithm begins with one vertex and repeatedly selects the cheapest edge connecting the existing tree to an unselected vertex.

The implementation uses an adjacency matrix and has a time complexity of O(V²).

### Kruskal's Algorithm
Kruskal's Algorithm sorts all edges by increasing cost and adds an edge only if it does not create a cycle. Disjoint Set Union (DSU) tracks connected components.

The implementation has a time complexity of O(E log E), where V is the number of vertices and E is the number of edges.

## System Design
**Input:**
- Number of locations.
- Number of possible connections.
- Starting location, destination location, and cost for every connection.

**Processing:**
1. Validate the input.
2. Build the undirected weighted graph.
3. Run Prim's Algorithm.
4. Run Kruskal's Algorithm.
5. Compare the resulting total network costs.

**Output:**
- Selected connections for Prim's Algorithm.
- Total cost calculated by Prim's Algorithm.
- Selected connections for Kruskal's Algorithm.
- Total cost calculated by Kruskal's Algorithm.
- Comparison of the two minimum costs.

## Algorithm
1. Read the number of locations and possible connections.
2. Validate the location count and connection count.
3. Read and validate each connection.
4. Store the graph in an adjacency matrix and an edge array.
5. Execute Prim's Algorithm to find a Minimum Spanning Tree.
6. Execute Kruskal's Algorithm using edge sorting and DSU.
7. If the network is disconnected, report that a spanning tree cannot be constructed.
8. Display the selected connections and total costs.
9. Compare the total costs obtained by both algorithms.

## Pseudocode
```text
BEGIN
    INPUT V, E
    INPUT and validate all connections

    BUILD adjacency matrix and edge list

    RUN Prim's Algorithm
    IF graph is disconnected
        REPORT error
        STOP
    END IF

    RUN Kruskal's Algorithm
    IF graph is disconnected
        REPORT error
        STOP
    END IF

    DISPLAY Prim's selected edges and total cost
    DISPLAY Kruskal's selected edges and total cost

    IF both total costs are equal
        DISPLAY matching minimum cost
    ELSE
        DISPLAY discrepancy warning
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

The first input specifies five locations. The second specifies seven possible connections. Each remaining row contains two location numbers followed by the connection cost.

## Expected Results
```text
Prim's total network cost: 16
Kruskal's total network cost: 16
Both algorithms produced the same minimum cost: 16
```

The selected edges may appear in different orders, but both algorithms should produce the same minimum total cost for this graph.

## Complexity Analysis

Let `V` represent the number of vertices and `E` the number of edges.

| Component | Time Complexity | Space Complexity |
|---|---|---|
| Graph representation | O(V²) initialization | O(V²) |
| Prim's Algorithm | O(V²) | O(V) auxiliary |
| Kruskal's Algorithm | O(E log E) | O(V + E) |
| Overall system | O(V² + E log E) | O(V² + E) |

The overall time complexity includes graph initialization, edge sorting, and the execution of both algorithms.

## Validation and Test Cases
- A connected sample network produces a minimum total cost of `16` using both algorithms.
- A single location requires no connections and has a network cost of `0`.
- A disconnected network is rejected.
- Duplicate connections are rejected.
- Invalid location numbers are rejected.
- Self-connections are rejected.
- Zero or negative connection costs are rejected.
- Invalid connection counts are rejected.

## Limitations
- The system supports at most 100 locations.
- Only undirected networks with strictly positive connection costs are accepted.
- Duplicate connections between the same pair of locations are rejected.
- The application assumes a connection cost is known for every entered edge.

## Learning Outcomes
- Applied greedy algorithms to a practical network-design problem.
- Implemented and compared Prim's and Kruskal's algorithms.
- Used adjacency matrices and edge lists to represent graphs.
- Applied DSU for cycle detection.
- Compared algorithmic time and space complexity.
- Implemented input validation and disconnected-network handling.

## Conclusion
The Minimum-Cost Network Design System was successfully implemented in C++ using Prim's and Kruskal's algorithms. Both algorithms construct a Minimum Spanning Tree for a connected network, and their calculated costs are compared to verify the minimum network cost.
