
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

def solution_d():
    def is_valid(grid, pos):
        r, c = pos

        if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == '.':
            return True
        else:
            return False

    def get_neighbors(grid, pos):
        r, c = pos

        nbrs = [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]
        return (nbr for nbr in nbrs if is_valid(grid, nbr))

    height, width, move_amt = [int(d) for d in input().split()]
    grid = [list(input()) for _ in range(height)]

    visited = [[False for _ in range(width)] for _ in range(height)]

    possible_paths = {"result": 0}
    
    for r in range(height):
        for c in range(width):
            start = grid[r][c]

            if start == '.':
                # Perform DFS
                def dfs(cur_r, cur_c, depth):
                    visited[cur_r][cur_c] = True

                    if depth == move_amt:
                        possible_paths["result"] += 1
                        return

                    nbrs = get_neighbors(grid, (cur_r, cur_c))

                    for nbr in nbrs:
                        nr, nc = nbr

                        if not visited[nr][nc]:
                            dfs(nr, nc, depth + 1)

                    visited[cur_r][cur_c] = False

                dfs(r, c, 0)
                    
    print(possible_paths["result"])

if __name__ == "__main__":
    #solution_a()
    #solution_b()
    #solution_c()
    solution_d()
