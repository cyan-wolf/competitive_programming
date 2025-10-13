"""
Given an array of coin denominations and a target amount, 
find the minimum number of coins needed to make up that amount. 
You can use each coin as many times as you want.
"""

# NOTE: Tabular DP version saved for C++ version.

def count_fewest_change_memo(denominations: list[int], target_amt: int) -> int:
    cache = {}

    def memo(denominations: list[int], target_amt: int) -> int:
        if target_amt == 0:
            return 0
        
        elif target_amt in cache:
            return cache[target_amt]

        else:
            min_coin_amt = float('inf')
            for d in denominations:
                if target_amt < d:
                    continue
                new_target = target_amt - d
                min_coin_amt = min(min_coin_amt, memo(denominations, new_target) + 1)

            if min_coin_amt == float('inf'):
                raise ValueError(f'cannot build {target_amt} using {denominations}')

            min_coin_amt = int(min_coin_amt)
            cache[target_amt] = min_coin_amt
            return min_coin_amt

    return memo(denominations, target_amt)


def main():
    # print(count_fewest_change_memo([1, 3, 5], 6))
    print(count_fewest_change_memo([1, 5, 10, 100], 15))


main()