
# ACCEPTED
def solution_a():
    _, freq = [int(d) for d in input().split()]
    timestamps = [int(d) for d in input().split()]

    candies = 1
    elapsed_last_recv = timestamps[0]

    for elapsed in timestamps[1:]:
        if (elapsed - elapsed_last_recv) >= freq:
            candies += 1
            elapsed_last_recv = elapsed

    print(candies)

# Accepted.
def solution_b():
    slots, num_operations = [int(d) for d in input().split()]
    operations = [input().split() for _ in range(num_operations)]
    # The initial positions are supposed to be 1 and 2, but 
    # are made to be 0 and 1 so that they are zero indexed.
    left = 0
    right = 1

    move_total = 0

    for op in operations:
        hand = op[0]
        # Make the destination be zero indexed.
        dest = int(op[1]) - 1

        pos = None
        other_pos = None

        if hand == 'R':
            pos = right
            other_pos = left
        else:
            pos = left
            other_pos = right

        # No need to move.
        if pos == dest:
            continue

        # The number of moves if the hand went right or left.
        dist_right = (dest - pos) % slots
        dist_left = (pos - dest) % slots

        new_pos = pos
        moved_left = False

        # Try to move the hand to the right.
        for _ in range(1, dist_right + 1):
            new_pos = (new_pos + 1) % slots

            # If the hand ever "hits" the other hand while going right,
            # we know that it must go left instead.
            if new_pos == other_pos:
                move_total += dist_left

                # Reset the position to make it as if it moved left.
                new_pos = (pos + dist_left) % slots
                
                # Update the hand positions.
                if hand == 'R':
                    right = dest
                else:
                    left = dest

                moved_left = True
                break

        # The hand was able to move right.
        if not moved_left:
            move_total += dist_right

            # Update hand positions.
            if hand == 'R':
                right = dest
            else:
                left = dest

    print(move_total)


if __name__ == "__main__":
    #solution_a()
    solution_b()


