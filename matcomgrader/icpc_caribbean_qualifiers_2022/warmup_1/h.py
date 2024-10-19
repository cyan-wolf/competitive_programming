
# ACCEPTED

def det_honi_blocks(word):
    honi = "HONI"
    looking_for = 0
    block_amt = 0

    for c in word:
        if c == honi[looking_for]:
            if looking_for == len(honi) - 1:
                block_amt += 1

            looking_for = (looking_for + 1) % len(honi)

    return block_amt

def main():
    word = input()
    print(det_honi_blocks(word))

if __name__ == "__main__":
    main()
