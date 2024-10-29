
# ACCEPTED

def print_best_config(score):
    for perfect in range(100, -1, -1):
        for great in range(100, -1, -1):
            for good in range(100, -1, -1):
                for bad in range(100, -1, -1):
                    value_eq_score = (perfect * 1000 + great * 100 + good * 10 + bad) == score
                    arrows_are_100 = (perfect + great + good + bad) == 100

                    if value_eq_score and arrows_are_100:
                        print(f"Perfect: {perfect}")
                        print(f"Great: {great}")
                        print(f"Good: {good}")
                        print(f"Bad: {bad}")
                        return
                    
    print("NO SOLUTION")

def main():
    score = int(input())
    print_best_config(score)

if __name__ == "__main__":
    main()
