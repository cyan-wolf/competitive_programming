"""
https://matcomgrader.com/problem/9825/kekkaishi/
"""

# Rejected: TIME LIMIT EXCEEDED

import heapq


def toggle_pq_entry(entry):
    return (-entry[0], entry[1])


def max_pqpush(pq, entry):
    heapq.heappush(pq, toggle_pq_entry(entry))


def max_pqpeek(pq):
    return toggle_pq_entry(pq[0])


def max_pqpop(pq):
    return toggle_pq_entry(heapq.heappop(pq))


def flush_invalid(pq, seen, is_max):
    is_valid = False

    while not is_valid:
        if len(pq) == 0:
            is_valid = True
            break

        if is_max:
            if max_pqpeek(pq)[1] not in seen:
                max_pqpop(pq)

            else:
                is_valid = True

        else:
            if pq[0][1] not in seen:
                heapq.heappop(pq)

            else:
                is_valid = True


def main():
    test_cases = int(input())

    for _ in range(test_cases):
        op_amt = int(input())

        x_min = []
        x_max = []
        y_min = []
        y_max = []
        z_min = []
        z_max = []

        maxes = [x_max, y_max, z_max]
        mins = [x_min, y_min, z_min]

        total_added = 0
        entities = {}

        for _ in range(op_amt):
            fields = input().split()

            if fields[0] == "ADD":
                x, y, z = [int(s) for s in fields[1:]]
                total_added += 1
                idx = total_added
                entities[idx] = (x, y, z)

                heapq.heappush(x_min, (x, idx))
                heapq.heappush(y_min, (y, idx))
                heapq.heappush(z_min, (z, idx))

                max_pqpush(x_max, (x, idx))
                max_pqpush(y_max, (y, idx))
                max_pqpush(z_max, (z, idx))

            else:
                idx = int(fields[1])
                x, y, z = entities[idx]
                del entities[idx]

                # Check if the entity was the max/min of any dimension.
                for dim_max in maxes:
                    flush_invalid(dim_max, entities, is_max=True)
                    if len(dim_max) == 0:
                        continue

                    if idx == max_pqpeek(dim_max)[1]:
                        max_pqpop(dim_max)

                for dim_min in mins:
                    flush_invalid(dim_min, entities, is_max=False)
                    if len(dim_min) == 0:
                        continue

                    if idx == dim_min[0][1]:
                        heapq.heappop(dim_min)

            if any([len(dim) == 0 for dim in (maxes + mins)]):
                area = 0

            else:
                dx = max_pqpeek(x_max)[0] - x_min[0][0]
                dy = max_pqpeek(y_max)[0] - y_min[0][0]
                dz = max_pqpeek(z_max)[0] - z_min[0][0]

                area = (dx * dy + dy * dz + dx * dz) * 2

            print(area)


main()


