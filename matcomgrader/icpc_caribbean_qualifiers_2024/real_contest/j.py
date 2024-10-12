
# ACCEPTED

def gen_message(temperature):
    if temperature < 49:
        return "TOO COLD"
    elif temperature > 60:
        return "TOO HOT"
    else:
        return "ACCEPTED"

def main():
    t = int(input())
    print(gen_message(t))

if __name__ == "__main__":
    main()
