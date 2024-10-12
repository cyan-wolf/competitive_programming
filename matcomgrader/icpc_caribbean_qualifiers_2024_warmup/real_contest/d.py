
# FAILED

def is_valid(config):
    return sum(config) == 100

def gen_cofigs(total_score):
    configs = []

    for i in range(9):
        score = total_score
        config = []

        # 1000 -> 100 -> 10 -> 1
        if i == 0:    
            config.append(score // 1000)
            score %= 1000
            config.append(score // 100)
            score %= 100
            config.append(score // 10)
            score %= 10
            config.append(score)

        # 100 -> 10 -> 1
        elif i == 1:
            config = [0] + config
            config.append(score // 100)
            score %= 100
            config.append(score // 10)
            score %= 10
            config.append(score)

        # 10 -> 1
        elif i == 2:
            config = [0, 0] + config
            config.append(score // 10)
            score %= 10
            config.append(score)

        # 1000 -> 100 -> 1
        elif i == 3:
            config.append(score // 1000)
            score %= 1000
            config.append(0)
            config.append(score // 10)
            score %= 10
            config.append(score)

        # 1000 -> 1
        elif i == 4:
            config.append(score // 1000)
            score %= 1000
            config = config + [0, 0]
            config.append(score)
        
        # 100 -> 1
        elif i == 5:
            config.append(0)
            config.append(score // 100)
            score %= 100
            config.append(0)
            config.append(score)

        # 1000 -> 100
        elif i == 6:
            config.append(score // 1000)
            score %= 1000
            config.append(0)
            config.append(score // 100)
            score %= 100
            config.append(0)


        # 1000 -> 10
        elif i == 7:
            config.append(score // 1000)
            score %= 1000
            config.append(0)
            config.append(score // 10)
            score %= 10
            config.append(0)

        # 1
        else:
            config = [0, 0, 0] + config
            config.append(score)

        if is_valid(config):
            configs.append(config)
    
    return configs

def print_solution(score):
    configs = gen_cofigs(score)

    if len(configs) == 0:
        print("NO SOLUTION")
        return

    print_config(configs[0])

def print_config(config):
    labels = [
        f"Perfect: {config[0]}",
        f"Great: {config[1]}",
        f"Good: {config[2]}",
        f"Bad: {config[3]}",
    ]
    print("\n".join(labels))
    

def main():
    score = int(input())
    print_solution(score)


if __name__ == "__main__":
    main()
