
# ACCEPTED

def to_abbv(word):
    if len(word) <= 10:
        return word
    
    return f"{word[0]}{len(word) - 2}{word[-1]}"

def main():
    n = int(input())

    for _ in range(n):
        word = input()
        print(to_abbv(word))

if __name__ == "__main__":
    main()