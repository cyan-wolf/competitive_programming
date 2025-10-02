"""
Given standard U.S. currency denominations (1¢, 5¢, 10¢, 25¢) and an amount, find the minimum number of coins to make the change.
"""

from dataclasses import dataclass

# @dataclass
# class CoinResult:
#     penny: int
#     nickel: int
#     dime: int
#     quarter: int


# O(1)
def det_coins(amt: int) -> int:
    q = amt // 25
    d = (amt := amt % 25) // 10
    n = (amt := amt % 10) // 5
    p = (amt := amt % 5) 

    return q + d + n + p


def main():
    print(det_coins(63))


main()
