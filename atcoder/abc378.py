
# ACCEPTED
def solution_a():
    balls = (int(d) for d in input().split())
    ball_count = {}

    for b in balls:
        ball_count.setdefault(b, 0)
        ball_count[b] += 1

    pairs = 0

    for b in ball_count:
        pairs += ball_count[b] // 2

    print(pairs)

# ACCEPTED
def solution_b():
    n = int(input())
    garbage = [[int(d) for d in input().split()] for _ in range(n)]

    q = int(input())
    queries = [[int(d) for d in input().split()] for _ in range(q)]

    for g, day_out in queries:
        freq, offset = garbage[g - 1]

        curr_offset = day_out % freq
        day_next = None

        if curr_offset <= offset:
            # Wait the difference in offsets.
            day_next = day_out + (offset - curr_offset)
        else:
            # Wait until d % freq == 0, then wait the offset.
            day_next = day_out + (-day_out % freq) + offset

        print(day_next)

# ACCEPTED
def solution_c():
    _ = input()
    stream = (int(d) for d in input().split())

    last_seen = {}

    output = []
    pos = 1

    for num in stream:
        if num in last_seen:
            output.append(str(last_seen[num]))

        else:
            output.append("-1")
            
        last_seen[num] = pos
        pos += 1

    print(" ".join(output))

if __name__ == "__main__":
    #solution_a()
    #solution_b()
    solution_c()
