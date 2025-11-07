# TLE

def main():
    n = int(input())

    first_letters = set()
    words = []

    for _ in range(n):
        word = input()

        first_letters.add(word[0])
        words.append(word)

    one_was_valid = False

    for word in words:
        if all(c in first_letters for c in word):
            one_was_valid = True
            break

    print('Y' if one_was_valid else 'N')

main()
