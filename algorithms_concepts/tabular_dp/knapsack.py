"""
Given a set of n items, where each item i has a weight w_i and a value v_i and a knapsack with a maximum weight capacity W.
"""

def knapsack(weights: list[int], values: list[int], capacity: int) -> int:
    item_amt = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(item_amt + 1)]
    
    for i in range(1, item_amt + 1):
        for curr_capacity in range(1, capacity + 1):
            curr_item_weight, curr_item_value = weights[i - 1], values[i - 1]

            # The value of the knapsack without the current item (one row up, same column).
            val_without_item = dp[i - 1][curr_capacity]

            # The current item is outright too heavy, do not include it.
            if curr_item_weight > curr_capacity:
                dp[i][curr_capacity] = val_without_item

            # Check to see if it's worth including the current item.
            else:
                # Add on the value of the current item to the value of that the knapsack had 
                # without the current item (i - 1) without the weight of the current item (curr_capacity - curr_item_weight).
                val_with_item = curr_item_value + dp[i - 1][curr_capacity - curr_item_weight]

                # Pick the choice that leads to the maximum value.
                dp[i][curr_capacity] = max(val_without_item, val_with_item)
    
    return dp[item_amt][capacity]


def main():
    print(knapsack(
        [3, 2, 6, 5],
        [1, 3, 8, 4],
        10,
    ))


main()