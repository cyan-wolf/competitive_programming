
# ACCEPTED

def is_valid_card(nums):
    card_sum = 0

    for i in range(2, len(nums)+1):
        num = nums[-i]
        if i % 2 == 0:
            num *= 2
            num = num if num < 9 else ((num // 10) + (num % 10))

        card_sum += num

    return (card_sum * 9) % 10 == nums[-1]

def det_placeholder(card_num):
    for i in range(10):
        nums = [int(d) if d != 'x' else i 
            for d in card_num]
        
        if is_valid_card(nums):
            return i

def main():
    _ = input()
    card_num = input()
    print(det_placeholder(card_num))

if __name__ == "__main__":
    main()