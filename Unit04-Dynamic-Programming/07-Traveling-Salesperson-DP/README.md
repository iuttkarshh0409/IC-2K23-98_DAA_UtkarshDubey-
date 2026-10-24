# Experiment 07: Traveling Salesperson Problem using Dynamic Programming

## Aim
To implement the Traveling Salesperson Problem (TSP) using dynamic programming and bitmasking to find a minimum-cost tour.

## Problem Statement
Given a cost matrix representing travel costs between cities, find the minimum-cost tour that starts at city 1, visits every other city exactly once, and returns to city 1.

## Algorithm
1. Read the number of cities and the cost matrix.
2. Represent unavailable routes using `-1`.
3. Initialize all DP states to infinity, except the starting state at city 1 with cost zero.
4. Represent visited cities using a bitmask.
5. For each valid state, try visiting every unvisited city with an available route.
6. Update the DP state if the new route produces a lower cost.
7. After visiting all cities, calculate the cost of returning to city 1.
8. Reconstruct and display the minimum-cost tour.
9. If no complete tour exists, display an appropriate message.

## Pseudocode
```text
TSP(cost, n):
    Initialize all dp[mask][city] = INF
    dp[mask containing only city 1][city 1] = 0

    For each valid mask:
        For each current city u in mask:
            For each unvisited city v:
                If route u -> v exists:
                    nextMask = mask with v added
                    Update dp[nextMask][v] with minimum cost

    Find minimum cost of visiting all cities
    and returning to city 1

    If no complete tour exists:
        Report that no tour is possible
    Otherwise:
        Reconstruct and display the tour
```

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
Tour: 1 -> 3 -> 4 -> 2 -> 1
```

The reverse optimal tour is also valid and has the same total cost.

## Complexity Analysis
- **Time Complexity:** O(n² × 2ⁿ)
- **Space Complexity:** O(n × 2ⁿ)

Here, `n` represents the number of cities. The implementation supports at most 15 cities because the number of DP states grows exponentially.

## Edge Cases Tested
- A single city.
- Two cities with available return routes.
- Missing routes.
- A graph with no complete tour.
- Invalid city counts.
- Unsupported negative travel costs.

## Learning Outcomes
- Understood the Traveling Salesperson Problem.
- Applied dynamic programming to an optimization problem.
- Used bitmasking to represent visited-city sets.
- Reconstructed an optimal tour using parent-state tracking.
- Analyzed exponential time and space complexity.
