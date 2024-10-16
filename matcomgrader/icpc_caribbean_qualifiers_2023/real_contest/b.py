
# ACCEPTED

# def det_deviation_slow(matches, speed):
#     elapsed = 0

#     while matches > 0:
#         elapsed += 1

#         working = elapsed % 60
#         broken = (elapsed * speed) % 60

#         if working == broken:
#             matches -= 1

#     return elapsed

def det_deviation(matches, speed):
    # If the speed is 0 then the second watch does not move.
    # Therefore, the working clock matches with the second one every 
    # minute (60 seconds) when it reads second=0.
    if speed == 0:
        return matches * 60

    # If the speed is 1, then both watches are evenly matched.
    # They match every second, so the elapsed seconds = number of matches.
    elif speed == 1:
        return matches
        
    # Check how long it takes for both watches to first match up.
    # This is only allowed to happen on an integer amount of seconds,
    #
    # so we check that this first match is an integer.
    # Then we multiply the time it takes for the first match to happen 
    # by the number of matches we want.
    else:
        for i in range(1, speed + 1):
            # Conceptually, the first match is (60 * i) / (speed - 1) 
            # when it results in an integer.
            # This happens when (60 * i) % (speed - 1) == 0.
            if (60 * i) % (speed - 1) == 0:
                # We know that both the numerator and the denominator 
                # are integers, and that the division results in an integer.
                first_match = int(60 * i) // int(speed - 1)

                return first_match * matches

def main():
    cases = int(input())

    for _ in range(cases):
        matches, speed = [int(d) for d in input().split()]

        print(det_deviation(matches, speed))

if __name__ == "__main__":
    main()
