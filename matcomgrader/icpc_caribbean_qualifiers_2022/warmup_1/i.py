
# ACCEPTED

def det_matching_words(dictionary, key_presses):
    KEYS = [
        set("ABC"),
        set("DEF"),
        set("GHI"),
        set("JKL"),
        set("MNO"),
        set("PQRS"),
        set("TUV"),
        set("WXYZ"),
    ]

    # Assume that all the words match at the start.
    matches = len(dictionary)

    # Checks when a given word does not match.
    for word in dictionary:
        if len(word) != len(key_presses):
            matches -= 1
            continue

        for i in range(len(word)):
            if word[i].upper() not in KEYS[key_presses[i] - 2]:
                matches -= 1
                break

    return matches

def main():
    n = int(input())
    dictionary = [input() for _ in range(n)]
    key_presses = [int(d) for d in input()]

    print(det_matching_words(dictionary, key_presses))

if __name__ == "__main__":
    main()
