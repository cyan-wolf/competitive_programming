"""
Calculate the minimum cost from the top left corner of the grid given that:
    - we are given a cost matrix where traveling over each cell has an associated cost
    - we are trying to reach a specific end position
    - we can only move rightwards, downwards, or diagonally (bottom-right)
"""

# O(R * N) where R and C are the number of rows and columns in the matrix respectively.
#
# NOTE: This specific tabular function computes unnecessary rows / columns if `end_position` 
#       is not at the bottom right corner of the grid. It still has the same complexity and 
#       gives the correct result, though.
def min_cost_path_tabular(matrix: list[list[int]], end_position: tuple[int, int]) -> int:
    dp = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    dp[0][0] = matrix[0][0]

    # Fill in the min costs for the cells on the top and left edges of the matrix.
    for r in range(1, len(matrix)):
        dp[r][0] = dp[r - 1][0] + matrix[r][0]

    for c in range(1, len(matrix[0])):
        dp[0][c] = dp[0][c - 1] + matrix[0][c]

    # Compute the min costs for the rest of the cells.
    for r in range(1, len(matrix)):
        for c in range(1, len(matrix[0])):
            dp[r][c] = min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]) + matrix[r][c]

    return dp[end_position[0]][end_position[1]]


# O(R * N) where R and C are the number of rows and columns in the matrix respectively.
def min_cost_path_memo(matrix: list[list[int]], end_position: tuple[int, int]) -> int:
    # position -> min cost at position
    cache: dict[tuple[int, int], int] = {}

    def min_cost(pos: tuple[int, int]) -> int:
        if pos in cache:
            return cache[pos]

        elif pos == (0, 0):
            cost = matrix[0][0]
            cache[pos] = cost
            return cost

        # Compute the cost for a cell on the top edge.
        elif pos[0] == 0:
            cost = min_cost((0, pos[1] - 1)) + matrix[pos[0]][pos[1]]
            cache[pos] = cost
            return cost

        # Compute the cost of a cell on the left edge.
        elif pos[1] == 0:
            cost = min_cost((pos[0] - 1, 0)) + matrix[pos[0]][pos[1]]
            cache[pos] = cost
            return cost

        # Compute the cost of the cell at `pos`.
        else:
            nbrs = [
                (pos[0] - 1, pos[1]),
                (pos[0], pos[1] - 1),
                (pos[0] - 1, pos[1] - 1),
            ]

            cost = min(min_cost(nbrs[0]), min_cost(nbrs[1]), min_cost(nbrs[2])) + matrix[pos[0]][pos[1]]

            cache[pos] = cost
            return cost

    return min_cost(end_position)


def main():
    matrix = [
        [1, 2, 3],
        [4, 8, 2],
        [1, 5, 3],
    ]

    end_position = (1, 1)

    solution_tabular = min_cost_path_tabular(matrix, end_position)
    solution_memo = min_cost_path_memo(matrix, end_position)

    print(f"{solution_tabular} (tabular) = {solution_memo} (memo)")


main()