
# ACCEPTED

def add_mod_10(n1, n2):
    return (n1 + n2) % 10

def gen_inconsec_digits(a, b):
    digits = [a, b]
    used = {a, b}

    while len(digits) < 10:
        offset = 2
        new_val = add_mod_10(digits[-1], offset)
        neighbors = {add_mod_10(digits[-1], 1), add_mod_10(digits[-1], -1)}
        
        while new_val in used or new_val in neighbors:
            offset += 1
            new_val = add_mod_10(digits[-1], offset)

        digits.append(new_val)
        used.add(new_val)
    
    return [str(d) for d in digits]

def main():
    a, b = [int(d) for d in input().split()]
    print(" ".join(gen_inconsec_digits(a, b)))

if __name__ == "__main__":
    main()
