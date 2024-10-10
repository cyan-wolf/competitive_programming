
def calc_last_odd_nums(n):
    odd_seq = [1, 3, 5, 7, 9]
    sum_5 = sum(odd_seq)

    div_5 = n // 5
    rem_5 = n % 5

    return div_5 * sum_5 + sum(odd_seq[:rem_5])

def main():
    n  = int(input())
    print(calc_last_odd_nums(n))

if __name__ == "__main__":
    main()
