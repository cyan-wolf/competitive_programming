"""
Get the shortest path between two nodes using BFS.
"""

from collections import deque

def find_shortest_path(graph: list[list[int]], source: int, target: int) -> list[int]:
    # Tracks the first found predecessor of each node.
    # The source has no predecessor.
    pred: dict[int, int | None] = { source: None }

    q = deque([source])

    while len(q) > 0:
        node = q.pop()

        if node == target:
            break

        for nbr in graph[node]:
            if nbr not in pred:
                pred[nbr] = node
                q.appendleft(nbr)

    # Edge-case where target was not reachable from `source`.
    if target not in pred:
        return []

    path = []
    curr = target

    while curr is not None:
        path.append(curr)
        curr = pred[curr]

    return path[::-1]


def main():
    graph = [
        [1, 2, 5],      # 0
        [0, 3, 4],      # 1
        [0],            # 2
        [1, 6],         # 3
        [1, 6],         # 4
        [0],            # 5
        [3, 4, 7],      # 6
        [6],            # 7
    ]

    print(find_shortest_path(graph, source=0, target=6))


main()