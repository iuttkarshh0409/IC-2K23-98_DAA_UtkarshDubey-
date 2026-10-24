# Experiment 03: Traveling Salesperson Problem Using Branch and Bound

## Aim
To implement the Traveling Salesperson Problem (TSP) using Branch and Bound to find a minimum-cost tour that visits every city exactly once and returns to the starting city.

## Problem Statement
Given `N` cities and a cost matrix representing the travel cost between each pair of cities, determine the minimum-cost tour that:

- Starts from city `0`.
- Visits every other city exactly once.
- Returns to city `0`.
- Minimizes the total travel cost.

The program supports 2 to 10 cities. A cost of `0` between distinct cities represents the absence of a direct route. All actual route costs must be positive.

## Algorithm
1. Read the number of cities and the cost matrix.
2. Mark city `0` as visited and set it as the starting city.
3. Explore unvisited cities that have a direct route from the current city.
4. Add the route cost to the accumulated tour cost.
5. If the accumulated cost is already at least the best complete tour cost found, prune that branch.
6. Recursively explore the next city.
7. When all cities have been visited, check whether a route back to city `0` exists.
8. If a complete tour has a lower cost than the current best, save its cost and path.
9. Backtrack and explore alternative routes.
10. Display the minimum tour cost and the corresponding tour, or report that no complete tour exists.

## Sample Input
```text
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
```

## Sample Output
```text
Minimum tour cost: 80
Optimal tour: 0 -> 1 -> 3 -> 2 -> 0
```

## Test Cases

| Test Case | Expected Result |
|---|---|
| Four-city symmetric matrix | Minimum cost: 80 |
| Three-city symmetric matrix | Minimum cost: 45 |
| No complete tour exists | Appropriate no-tour message |

## Complexity Analysis

- **Worst-case Time Complexity:** \(O(N!)\), since the algorithm may explore permutations of the cities.
- **Auxiliary Space Complexity:** \(O(N)\) for the visited array, current path, best path, and recursion stack.
- **Cost Matrix Storage:** \(O(N^2)\).

The implementation prunes branches when their accumulated cost cannot improve the best complete tour found so far. This basic pruning can reduce practical search time, but the worst-case time complexity remains factorial.

## Concepts Used
- Traveling Salesperson Problem
- Branch and Bound
- Recursive search
- Backtracking
- State-space exploration
- Branch pruning
- Adjacency cost matrix

## Limitations
- Supports a maximum of 10 cities.
- Uses city `0` as the fixed starting city.
- Assumes non-negative route costs and positive costs for existing routes.
- Uses accumulated cost for pruning rather than a stronger lower-bound calculation.
- May require factorial time in the worst case.

## Conclusion
The experiment demonstrates how Branch and Bound can solve the Traveling Salesperson Problem by exploring candidate tours and pruning routes that cannot improve the best solution found. It returns an optimal tour when a complete tour exists.
