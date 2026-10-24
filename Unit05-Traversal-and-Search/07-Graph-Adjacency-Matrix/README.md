# Experiment 07: Graph Representation Using an Adjacency Matrix

## Aim
To represent an undirected graph using an adjacency matrix in C++ and display the adjacent vertices of each vertex.

## Problem Statement
Write a C++ program to represent an undirected, unweighted graph using a two-dimensional array. The program should accept the number of vertices and edges, construct the adjacency matrix, display it, and list the adjacent vertices for each vertex.

## Theory
An **adjacency matrix** is a two-dimensional array used to represent graph connections.

For a graph with \(V\) vertices, the matrix has \(V \times V\) entries.

- `matrix[i][j] = 1` indicates an edge between vertices `i` and `j`.
- `matrix[i][j] = 0` indicates no edge.
- For an undirected graph, the matrix is symmetric: `matrix[i][j] = matrix[j][i]`.
- The diagonal entries remain zero because self-loops are not allowed in this implementation.

## Algorithm
1. Read the number of vertices \(V\) and edges \(E\).
2. Validate the graph dimensions.
3. Initialize the adjacency matrix with zeros.
4. Read each edge `(u, v)`.
5. Validate the vertex numbers and reject self-loops.
6. Set both `matrix[u-1][v-1]` and `matrix[v-1][u-1]` to `1`.
7. Display the adjacency matrix with vertex labels.
8. For each vertex, scan its matrix row and display all adjacent vertices.

## Pseudocode

```text
START
    Read V, E
    Validate V and E
    Initialize matrix[V][V] with zeros

    Repeat E times
        Read u, v
        Validate edge
        matrix[u-1][v-1] = 1
        matrix[v-1][u-1] = 1

    Display adjacency matrix

    For each vertex i
        Display all vertices j
        where matrix[i][j] = 1

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
Adjacency Matrix:
    1 2 3 4 5
1 | 0 1 1 0 0
2 | 1 0 0 1 0
3 | 1 0 0 1 0
4 | 0 1 1 0 1
5 | 0 0 0 1 0

Adjacent vertices:
Vertex 1: 2 3
Vertex 2: 1 4
Vertex 3: 1 4
Vertex 4: 2 3 5
Vertex 5: 4
```

## Complexity Analysis

Let \(V\) be the number of vertices and \(E\) the number of input edges.

| Operation | Complexity |
|---|---|
| Matrix initialization | \(O(V^2)\) |
| Graph construction | \(O(V^2 + E)\), including initialization |
| Checking whether an edge exists | \(O(1)\) |
| Listing neighbors of one vertex | \(O(V)\) |
| Listing neighbors of all vertices | \(O(V^2)\) |
| Space complexity | \(O(V^2)\) |

## Advantages
- Simple and straightforward representation.
- Checking whether an edge exists takes constant time.
- Suitable for dense graphs.
- Easy to implement using a two-dimensional array.

## Limitations
- Requires \(O(V^2)\) memory even when the graph has few edges.
- Listing the neighbors of a vertex requires scanning its entire row.
- This implementation represents an undirected, unweighted graph only.

## Edge Cases
- A graph with one vertex and no edges.
- A graph containing isolated vertices.
- A graph with no edges.
- Duplicate edge entries.
- Invalid vertex numbers.
- Self-loops, which are rejected.

## Learning Outcomes
- Understood graph representation using a two-dimensional array.
- Implemented an adjacency matrix for an undirected graph.
- Learned how to identify and display adjacent vertices.
- Analyzed the time and space complexity of the representation.

## Conclusion
The program successfully represents an undirected graph using an adjacency matrix and displays the connections of each vertex. The representation provides constant-time edge lookup at the cost of quadratic space complexity.
