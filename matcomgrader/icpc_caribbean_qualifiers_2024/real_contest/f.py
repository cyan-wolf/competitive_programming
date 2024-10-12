
# ACCEPTED

def print_sums_after_movements(points, vecs):
    sum_x = 0
    sum_y = 0
    for p in points:
        sum_x += p[0]
        sum_y += p[1]

    for i in range(len(vecs)):
        sum_x += vecs[i][0] * len(points)
        sum_y += vecs[i][1] * len(points)

        print(sum_x, sum_y)

def main():
    point_amt, vec_amt = [int(d) for d in input().split()]

    points = [[int(d) for d in input().split()] for _ in range(point_amt)]
    vecs = [[int(d) for d in input().split()] for _ in range(vec_amt)]

    print_sums_after_movements(points, vecs)

if __name__ == "__main__":
    main()
