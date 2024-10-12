
# ACCEPTED

def sorted_by_ascii_sum(words):
    # To ensure no duplicates while adding.
    ascii_sums = set()
    # To get back the words that have a given ASCII sum.
    ascii_sum_to_word = {}

    for i in range(len(words)):
        ascii_sum = sum((ord(c) for c in words[i]))
        ascii_sums.add(ascii_sum)

        ascii_sum_to_word.setdefault(ascii_sum, [])
        ascii_sum_to_word[ascii_sum].append(words[i])

    # Sort the sums.
    ascii_sums = list(ascii_sums)
    ascii_sums.sort()

    sorted_words = []

    for ascii_sum in ascii_sums:
        matching_words = ascii_sum_to_word[ascii_sum]
        
        for i in range(len(matching_words)):
            sorted_words.append(matching_words[i])

    return sorted_words

def main():
    n = int(input())
    words = [input() for _ in range(n)]

    print("\n".join(sorted_by_ascii_sum(words)))

if __name__ == "__main__":
    main()
