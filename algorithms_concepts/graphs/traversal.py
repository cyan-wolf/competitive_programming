"""
Iterative implementation of Depth-First-Search (DFS) and Breadth-First-Search (BFS).
"""

def dfs(graph: list[list[int]], root: int):
    visited = [False for _ in range(len(graph))]
    # Add the root to the stack and mark it as already visited.
    stk = [root]
    visited[root] = True

    while len(stk) > 0:
        # Get the node to process.
        node = stk.pop()
        
        # Process the node.
        print(f"Visited node #{node}")
        
        # Mark all unvisited adjacent nodes for later processing.
        for nbr in graph[node]:
            if not visited[nbr]:
                visited[nbr] = True
                stk.append(nbr)


from collections import deque

def bfs(graph: list[list[int]], root: int):
    visited = [False for _ in range(len(graph))]
    # Add the root to the queue and mark it as already visited.
    q = deque([root])
    visited[root] = True

    while len(q) > 0:
        # Get the node to process.
        node = q.pop()

        # Process the node.
        print(f"Visited node #{node}")

         # Mark all unvisited adjacent nodes for later processing.
        for nbr in graph[node]:
            if not visited[nbr]:
                visited[nbr] = True
                q.appendleft(nbr)


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

    print("DFS:")
    dfs(graph, 0)

    print("\nBFS:")
    bfs(graph, 0)
    

main()