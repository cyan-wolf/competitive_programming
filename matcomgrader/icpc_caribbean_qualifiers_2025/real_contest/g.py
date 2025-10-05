"""
https://matcomgrader.com/problem/9834/gotcha-station/
"""

# Rejected: TIME LIMIT EXCEEDED

def flatten_path(pred, end):
    flat_path = set()

    curr = end
    while curr is not None:
        flat_path.add(curr)
        curr = pred[curr]

    return flat_path


def find_all_paths_start_to_end(graph, start, end):
    stk = [(start, {start: None})]
    paths = []

    while len(stk) > 0:
        node, pred = stk.pop()

        if node == end:
            paths.append(pred)

        for nbr in graph[node]:
            if nbr not in pred:
                pred[nbr] = node
                stk.append((nbr, {**pred}))

    return [flatten_path(p, end) for p in paths]


def main():
    test_cases = int(input())

    for _ in range(test_cases):
        stations, connections, start, end = [int(s) for s in input().split()]
        start -= 1
        end -= 1

        graph = [[] for _ in range(stations)]
        for _ in range(connections):
            to, from_ = [int(s) - 1 for s in input().split()]
            graph[to].append(from_)
            graph[from_].append(to)

        paths = find_all_paths_start_to_end(graph, start, end)

        in_all = [True for _ in range(stations)]

        for st in range(stations):
            for path in paths:
                if st not in path:
                    in_all[st] = False

        good_stations = []

        for st in range(stations):
            if in_all[st]:
                good_stations.append(st + 1)

        print(len(good_stations))
        for gst in good_stations:
            print(gst)



main()
