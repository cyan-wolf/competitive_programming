
# ACCEPTED

def main():
    _, lang_size = [int(d) for d in input().split()]

    lang = {}

    for _ in range(lang_size):
        word_a, word_b = input().split()
        lang[word_a] = word_b

    prof_words = input().split()
    note_words = []

    for word in prof_words:
        note_word = min(word, lang[word], key=len)
        note_words.append(note_word)

    print(" ".join(note_words))

if __name__ == "__main__":
    main()

