
# ACCEPTED

def det_cubes_to_remove(cubes):
    matches = 0
    unpaired_red = 0
    unpaired_blue = 0

    for c in cubes:
        if c == '0':
            if unpaired_blue > 0:
                unpaired_blue -= 1
                matches += 1

            else:
                unpaired_red += 1

        else:
            if unpaired_red > 0:
                unpaired_red -= 1
                matches += 1

            else:
                unpaired_blue += 1

    return 2 * matches

def main():
    cubes = input()
    print(det_cubes_to_remove(cubes))

if __name__ == "__main__":
    main()

