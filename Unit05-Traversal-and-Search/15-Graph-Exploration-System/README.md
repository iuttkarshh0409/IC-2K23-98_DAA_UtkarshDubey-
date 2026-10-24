# Experiment 15: Graph Exploration / Network Traversal System

## Aim
To develop a menu-driven Network Exploration System in C++ using graph representation, Breadth-First Search (BFS), Depth-First Search (DFS), and shortest-route discovery.

## Problem Statement
Develop a program that models locations as vertices and connections as undirected edges. The system should allow users to add locations, establish connections, display the network, explore connected locations using BFS and DFS, and find the shortest route between two locations.

## Features
- Add locations dynamically within a fixed capacity.
- Add undirected connections between locations.
- Display the network and each location's neighbors.
- Explore reachable locations using BFS.
- Explore reachable locations using iterative DFS.
- Find the shortest route in terms of number of connections using BFS.
- Validate location numbers and reject self-connections and duplicate connections.

## Theory
The system represents the network using an **adjacency matrix**.

- Each location is represented by a vertex.
- Each connection is represented by an undirected edge.
- BFS uses a queue to explore the network level by level.
- Iterative DFS uses a stack to explore paths deeply before backtracking.
- BFS finds a path with the fewest edges in an unweighted graph.

The shortest route returned by this program minimizes the number of connections, not physical distance or travel time.

## Algorithm

### 1. Add Location
1. Check whether the maximum capacity has been reached.
2. Mark the next location as available.
3. Increase the location count.

### 2. Add Connection
1. Read two location numbers.
2. Validate both locations.
3. Reject self-connections and duplicate connections.
4. Update the adjacency matrix in both directions.

### 3. BFS Exploration
1. Mark the starting location as visited.
2. Insert it into a queue.
3. Repeatedly remove the front location and display it.
4. Add unvisited neighbors to the queue.
5. Stop when the queue is empty.

### 4. DFS Exploration
1. Push the starting location onto a stack and mark it visited.
2. Pop and display a location.
3. Push its unvisited neighbors onto the stack and mark them visited.
4. Stop when the stack is empty.

### 5. Shortest Route
1. Initialize the parent array.
2. Run BFS from the source location.
3. Record each newly discovered location's parent.
4. If the destination is unreachable, report that no route exists.
5. Otherwise, reconstruct the route by following parent links from destination to source.
6. Display the route and number of connections.

## Pseudocode

```text id="g7j2p3"
REPEAT
    Display menu
    Read choice

    IF choice = Add Location
        Add a location within capacity

    ELSE IF choice = Add Connection
        Validate endpoints
        Add edge in both directions

    ELSE IF choice = Display Network
        Display neighbors of every location

    ELSE IF choice = BFS
        Traverse reachable locations using a queue

    ELSE IF choice = DFS
        Traverse reachable locations using a stack

    ELSE IF choice = Shortest Route
        Run BFS from source
        Record parent of each discovered location
        Reconstruct and display the route

UNTIL choice = Exit
```

## Sample Network

The test network contains five locations and the following connections:

```text id="e5t9u4"
1 -- 2
|    |
3 -- 4 -- 5
```

## Expected Results

For BFS starting at location 1:

```text id="s6r2b7"
BFS exploration: 1 2 3 4 5
```

For iterative DFS starting at location 1:

```text id="m2p8c1"
DFS exploration: 1 2 4 3 5
```

For the shortest route from location 1 to location 5:

```text id="v1n5x8"
Shortest route: 1 -> 2 -> 4 -> 5
Number of connections: 3
```

Traversal order depends on the order in which neighboring vertices are processed.

## Complexity Analysis

Let \(V\) represent the number of locations and \(E\) represent the number of connections.

| Operation | Time Complexity |
|---|---|
| Add location | \(O(1)\) |
| Add connection | \(O(1)\) |
| Display network | \(O(V^2)\) |
| BFS exploration | \(O(V^2)\) |
| DFS exploration | \(O(V^2)\) |
| Shortest route using BFS | \(O(V^2)\) |
| Graph storage | \(O(V^2)\) |

The adjacency matrix requires \(O(V^2)\) memory. BFS and DFS also require \(O(V)\) auxiliary space for their traversal structures and visited arrays.

## Edge Cases
- Attempting to add more than the supported number of locations.
- Adding a connection before enough locations exist.
- Invalid location numbers.
- Duplicate connections.
- Self-connections.
- A network containing isolated locations.
- A destination unreachable from the source.
- A route from a location to itself.

## Learning Outcomes
- Applied adjacency-matrix graph representation.
- Implemented a menu-driven network application.
- Used BFS and DFS for graph exploration.
- Applied BFS to find a shortest route in an unweighted graph.
- Practiced input validation and fixed-size array management.
- Analyzed the time and space complexity of graph operations.

## Conclusion
The Network Exploration System successfully demonstrates graph construction, network display, BFS exploration, iterative DFS exploration, and shortest-route discovery. It combines fundamental graph algorithms into a single interactive C++ application.
