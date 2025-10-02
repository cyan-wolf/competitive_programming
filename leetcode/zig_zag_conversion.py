
def convert(s: str, num_rows: int) -> str:
    going_down = True
    chars_processed = 0

    pos_char_map = {}
    curr_pos = (-1, 0)

    max_col = 0

    while chars_processed < len(s):
        if going_down:
            new_pos = (curr_pos[0] + 1, curr_pos[1])

            if new_pos[0] == num_rows:
                going_down = False
                continue

        else:
            new_pos = (curr_pos[0] - 1, curr_pos[1] + 1)

            if new_pos[0] == -1:
                going_down = True
                continue

            if new_pos[1] > max_col:
                max_col = new_pos[1]

        curr_pos = new_pos
        pos_char_map[curr_pos] = s[chars_processed]
        chars_processed += 1

    joined_rows = "".join(["".join([(pos_char_map[(r, c)] if (r, c) in pos_char_map else "") 
               for c in range(max_col + 1)])
               for r in range(num_rows)])

    return joined_rows


def main():
    s = "P"

    result = convert(s, 3)

    print(result) 


if __name__ == "__main__":
    main()
