
# ACCEPTED

import itertools

def get_losing_pairing(results):
    used_knight_indices = [pair[0] for pair in results]
    used_dragon_indices = [pair[1] for pair in results]

    unused_pair = [None, None]

    for i in range(3):
        if i not in used_knight_indices:
            unused_pair[0] = i
        if i not in used_dragon_indices:
            unused_pair[1] = i

    return tuple(unused_pair)

def print_solution(atks, defs):
    knights = []
    dragons = []

    # Pair the strength/defense values with their indices.
    for i in range(3):
        knights.append((atks[i], i))
        dragons.append((defs[i], i))

    result = None

    # Check every possible combination of 2 knights and 2 dragons
    # to see if it's possible for the knights to beat the dragons.
    for k1, k2 in itertools.permutations(knights, 2):
        for d1, d2 in itertools.permutations(dragons, 2):
            if k1[0] > d1[0] and k2[0] > d2[0]:
                result = [(k1, d1), (k2, d2)]
                break
    
    # If no result was found, it is impossible.
    if result is None:
        print("IMPOSSIBLE")

    else:
        # Turn the `result` list into a list of pairs of indices, 
        # since the strength/defense data isn't necessary anymore.
        result = [(pair[0][1], pair[1][1]) for pair in result]

        # Generate the missing pairing.
        result.append(get_losing_pairing(result))

        # Turn the `result` list of pairings into the output 
        # format required by the problem.
        result = {k: d for k, d in result}
        result_str = " ".join([str(result[i] + 1) for i in range(3)])
        
        print("POSSIBLE")
        print(result_str)

    
def main():
    atks = [int(d) for d in input().split()]
    defs = [int(d) for d in input().split()]

    print_solution(atks, defs)

if __name__ == "__main__":
    main()

