
# REJECTED: Memory limit exceeded!

def add_swaps(critical_spots, bit_positions, incoming_bit, outgoing_bit, swaps):
    for crit_spot in critical_spots[incoming_bit]:
        for incoming_pos in bit_positions[outgoing_bit]:
            # Generate a tuple pair where the smallest element is always first.
            pair = [crit_spot, incoming_pos]
            pair = (min(pair), max(pair))
            swaps.add(pair)

def det_solution(a, b):
    # Holds the positions of a given bit type.
    bit_positions = {}
    # Holds the position of bits that, when changed, affect the result,
    # for each bit type.
    critical_spots = {}

    for i in range(len(a)):
        bit_positions.setdefault(a[i], [])
        bit_positions[a[i]].append(i + 1)

        if b[i] == '0':
            critical_spots.setdefault(a[i], [])
            critical_spots[a[i]].append(i + 1)

    # This is a set to avoid duplicate moves.
    swaps = set()

    # Perform 1 -> 0 swaps.
    add_swaps(critical_spots, bit_positions, '1', '0', swaps)

    # Perform 0 -> 1 swaps.
    add_swaps(critical_spots, bit_positions, '0', '1', swaps)

    return len(swaps)

def main():
    _ = input()
    a = input()
    b = input()

    print(det_solution(a, b))

if __name__ == "__main__":
    main()

