# Experiment 08: Graph Representation Using an Adjacency List

## Aim
To represent an undirected graph using an adjacency list in C++ and display the neighboring vertices of each vertex.

## Problem Statement
Write a C++ program to represent an undirected, unweighted graph using an adjacency list. The program should accept the number of vertices and edges, store the connections efficiently, and display the adjacency list for every vertex.

## Theory
An **adjacency list** stores the neighbors of each vertex rather than reserving space for every possible connection.

In this implementation, the adjacency list is represented using three fixed-size arrays:
- `head[]`: stores the index of the first edge for each vertex.
- `to[]`: stores the destination vertex of each edge.
- `nextEdge[]`: links each edge entry to the next edge in the same list.

The value `-1` indicates the end of a list. Since the graph is undirected, each edge `(u, v)` is stored twice: once from `u` to `v`, and once from `v` to `u`.

## Algorithm
1. Read the number of vertices \(V\) and edges \(E\).
2. Validate the graph dimensions.
3. Initialize each vertex's `head` entry to `-1`.
4. Read each edge `(u, v)` and validate its endpoints.
5. Convert the vertex labels to zero-based indices.
6. Check whether the edge already exists.
7. Insert the edge in both directions using the array-based linked-list representation.
8. Display the neighbors of each vertex.
9. Display `None` for vertices without neighbors.

## Pseudocode

```text
START
    Read V, E
    Validate graph dimensions
    Initialize head[] with -1

    Repeat E times
        Read u, v
        Validate endpoints and reject self-loops
        Convert u and v to zero-based indices

        If edge (u, v) already exists
            Ignore duplicate edge
        Else
            Insert v into u's adjacency list
            Insert u into v's adjacency list

    For each vertex u
        Display u
        Traverse its adjacency list
        Display all neighboring vertices
        If no neighbors exist, display None

STOP
```

## Sample Input

```text
5 5
1 2
1 3
2 4
3 4
4 5
```

## Sample Output

```text
Adjacency List:
1 -> 3 -> 2
2 -> 4 -> 1
3 -> 4 -> 1
4 -> 5 -> 3 -> 2
5 -> 4
```

The order of neighbors depends on the insertion strategy. This implementation inserts each new edge at the beginning of the corresponding list, so neighbors appear in reverse insertion order.

## Complexity Analysis

Let \(V\) represent the number of vertices and \(E\) the number of input edges.

| Operation | Complexity |
|---|---|
| Graph initialization | \(O(V)\) |
| Edge insertion without duplicate checks | \(O(1)\) per directed entry |
| Duplicate-edge check | \(O(\deg(u))\) |
| Listing all adjacency lists | \(O(V+E)\) |
| Space complexity | \(O(V+E)\) |

For an undirected graph, each distinct edge is represented by two adjacency entries. The implementation uses fixed-size arrays, so its actual capacity is bounded by the declared constants.

## Advantages
- Uses less memory than an adjacency matrix for sparse graphs.
- Lists only existing connections.
- Efficiently traverses all neighbors of a vertex.
- Can be implemented using arrays without STL containers.

## Limitations
- Checking whether a particular edge exists may require scanning a vertex's adjacency list.
- Fixed-size arrays limit the maximum graph size.
- Each undirected edge requires two stored entries.

## Edge Cases
- A graph containing one vertex and no edges.
- A graph with isolated vertices.
- A graph with no edges.
- Duplicate edge entries.
- Invalid vertex numbers.
- Self-loops, which are rejected.

## Learning Outcomes
- Understood adjacency-list graph representation.
- Implemented linked-list-style connections using fixed-size arrays.
- Learned how undirected edges are stored in both directions.
- Compared the memory requirements of adjacency lists and adjacency matrices.

## Conclusion
The program successfully represents an undirected graph using an array-based adjacency list and displays each vertex's neighbors. This representation is particularly useful for sparse graphs because it stores existing connections rather than all possible connections.
