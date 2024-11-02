
# ACCEPTED

def det_status(text):
    stk = list("virus")[::-1]

    has_matched = False
    space_between_matches = False

    for c in text:
        if len(stk) > 0:
            if c == stk[-1]:
                stk.pop()
                has_matched = True

            elif has_matched:
                # The "virus" is not continuous.
                space_between_matches = True

        # Found "virus", stop searching.
        else:
            break
    
    if len(stk) == 0:
        if space_between_matches:
            return "Scattered"
        else:
            return "Simple"

    return "No"

def main():
    test_cases = int(input())

    for _ in range(test_cases):
        text = input()
        print(det_status(text))

if __name__ == "__main__":
    main()
