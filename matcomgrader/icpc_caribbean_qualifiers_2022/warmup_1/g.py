
# ACCEPTED

def main():
    people_amt, train_fare, taxi_fare = [int(d) for d in input().split()]
    print(min(people_amt * train_fare, taxi_fare))

if __name__ == "__main__":
    main()
