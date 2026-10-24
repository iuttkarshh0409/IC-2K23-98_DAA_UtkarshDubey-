# Experiment 08: Route Optimization System

## Aim
To develop a menu-driven route optimization system that finds the minimum-cost path between locations in a weighted, undirected graph.

## Problem Statement
Develop a system that allows users to add or update routes, display the route-cost matrix, and find the minimum-cost route between two locations.

## Features
1. Add or update a route between two locations.
2. Display the route-cost matrix.
3. Find the minimum-cost route between a selected source and destination.
4. Display the optimal path and its total cost.
5. Detect unreachable destinations.
6. Validate user input and menu choices.

## Algorithm
1. Read the number of locations.
2. Initialize the adjacency matrix, setting diagonal entries to zero and all other entries to infinity.
3. Display the menu.
4. For route insertion, validate the locations and non-negative cost, then update the matrix symmetrically.
5. For route optimization, initialize distances and parent arrays.
6. Apply Dijkstra's algorithm to calculate minimum distances.
7. Reconstruct the path using parent information.
8. Display the minimum route cost and optimal path, or report that no route exists.
9. Repeat until the user chooses Exit.

## Pseudocode
```text
INITIALIZE_GRAPH(n)

Repeat:
    Display menu
    Read choice

    If choice = 1:
        Read route endpoints and cost
        Validate input
        Update both directions in graph

    Else if choice = 2:
        Display route-cost matrix

    Else if choice = 3:
        Read source and destination
        Run Dijkstra's algorithm
        If destination is unreachable:
            Display no-route message
        Else:
            Display minimum cost and reconstructed path

    Else if choice = 4:
        Exit

    Else:
        Display invalid-choice message
```

## Sample Test Scenario

Add the following routes:

| Source | Destination | Cost |
|---:|---:|---:|
| 1 | 2 | 10 |
| 1 | 3 | 3 |
| 2 | 3 | 1 |
| 2 | 4 | 2 |
| 3 | 4 | 8 |
| 3 | 5 | 2 |
| 4 | 5 | 7 |

Find the minimum-cost route from location 1 to location 4.

## Expected Result
```text
Starting location: 1
Destination: 4
Minimum route cost: 6
Optimal route: 1 -> 3 -> 2 -> 4
```

## Complexity Analysis
- **Route insertion/update:** O(1).
- **Route optimization:** O(V²) time using an adjacency matrix and linear minimum-distance selection.
- **Space Complexity:** O(V²), dominated by the adjacency matrix.

## Edge Cases Tested
- Identical source and destination.
- Unreachable destinations.
- Invalid location numbers.
- Zero-cost routes.
- Updating an existing route.
- Invalid menu choices.

## Limitations
- Routes are undirected.
- Negative route costs are not supported.
- The system supports at most 20 locations.
- The graph is stored in an adjacency matrix.

## Learning Outcomes
- Applied graph representation to a practical route-planning problem.
- Integrated Dijkstra's algorithm into a menu-driven application.
- Learned path reconstruction using parent arrays.
- Implemented route updates and input validation.
- Analyzed algorithmic time and space complexity.
