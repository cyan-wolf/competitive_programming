
# FAILED: "memory limit exceeded"
# NOTE: This problem might not be doable in Python given the limits.

def build_tree(edges):
    tree = {}

    for edge in edges:
        tree.setdefault(edge[0], set())
        tree.setdefault(edge[1], set())
        tree[edge[0]].add(edge[1])
        tree[edge[1]].add(edge[0])

    return tree

def gen_path_lists_from_root(tree, root):
    paths = {}

    # Iterative DFS: 

    # Simulating call stack.
    stk = [(root, set())] 

    while len(stk) > 0:
        # Get the node to be processes along with 
        # the current path.
        node, path = stk.pop()

        # Make a copy of the current path.
        path = set(path)
        # Add the current node to this path.
        path.add(node)
        paths[node] = path

        nbrs = tree.get(node)

        if nbrs is not None:
            for nbr in nbrs:
                # If this neighbor node is in `paths`,
                # then it has already been visited.
                visited = nbr in paths

                if not visited:
                    # Stack the neighbor node along with the 
                    # current path to be processed later.
                    stk.append((nbr, path))

    return paths

def solve_query(path_lists, query):
    node = query[0]
    pos = query[1] - 1

    return sorted(list(path_lists[node]))[pos]

def main():
    node_amt, query_amt, root = [int(d) for d in input().split()]

    edges = [[int(d) for d in input().split()] for _ in range(node_amt - 1)]
    queries = [[int(d) for d in input().split()] for _ in range(query_amt)]
    
    tree = build_tree(edges)
    path_lists = gen_path_lists_from_root(tree, root)

    for q in queries:
        print(solve_query(path_lists, q))

if __name__ == "__main__":
    main()


# Test inputs:
"""
5 4 2
2 3
4 1
4 5
2 4
1 1
2 1
5 2
1 3
"""

"""
9 6 5
5 1
4 1
6 8
9 3
5 6
2 9
7 4
9 6
2 2
8 3
3 4
7 1
2 1
4 2
"""