"""
Dijkstra's Algorithm - solves the Single-Source Shortest Path (SSSP) problem in graphs with non-negative edge weights.
"""

import heapq

def dijkstra(graph: list[list[tuple[int, int]]], source: int, target: int) -> int:
    distances = [float('inf') for _ in range(len(graph))]
    distances[source] = 0
    
    pq = [(0, source)]

    while len(pq) > 0:
        curr_dist, curr_node = heapq.heappop(pq)

        # We are taking a stale / overly-long path, skip.
        if curr_dist > distances[curr_node]:
            continue

        for nbr, weight in graph[curr_node]:
            # Add on the weight to get to this node to the already accumulated 
            # distance from `source` to the previous node (`distances[curr_node]`).
            new_dist = distances[curr_node] + weight

            # If the newly computed distance is shorter than the already recorded distance 
            # (`distances[nbr]`) then save it and add it to the priority queue.
            if new_dist < distances[nbr]:
                distances[nbr] = new_dist
                heapq.heappush(pq, (int(new_dist), nbr))

    return int(distances[target])


def main():
    graph = [
        [(1, 10), (2, 1), (3, 1)],  # 0
        [(0, 10), (2, 1), (4, 5)],  # 1
        [(0, 1), (1, 1)],           # 2
        [(0, 1), (5, 2)],           # 3
        [(1, 5), (7, 1)],           # 4
        [(3, 2), (6, 100)],         # 5
        [(5, 100)],                 # 6
        [(4, 1)],                   # 7
    ]

    print(dijkstra(graph, source=0, target=6))


main()
