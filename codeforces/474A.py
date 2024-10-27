
# ACCEPTED

def decode(direction, presses):
    KEYBOARD = [
        "qwertyuiop[]\\",
        "asdfghjkl;'",
        "zxcvbnm,./",
    ]

    offset = 1 if direction == 'L' else -1

    message = []

    for key in presses:
        
        for row in KEYBOARD:
            for i in range(len(row)):
                if row[i] == key:
                    message.append(row[i + offset])

    return "".join(message)


def main():
    print(decode(input(), input()))


main()