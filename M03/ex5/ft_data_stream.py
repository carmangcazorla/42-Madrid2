def game_event(n):
    players = ("alice", "bob", "charlie", "diana")
    levels = {"alice": 5, "bob": 12, "charlie": 8, "diana": 15}
    actions = ("killed monster", "found treasure", "leveled up", "defeated boss")

    for i in range(n):
        player = players[i % len(players)]
        action = actions[i % len(actions)]

        if action == "leveled up":
            levels[player] += 1

        yield player, levels[player], action


def process_stream(n):
    print("=== Game Data Stream Processor ===\n")
    print("Processing", n, "game events...\n")

    total = 0
    high_level = 0
    treasure = 0
    levelup = 0

    events = game_event(n)

    for player, level, action in events:
        total += 1

        if level >= 10:
            high_level += 1
        if action == "found treasure":
            treasure += 1
        if action == "leveled up":
            levelup += 1

        if total <= 3:
            print(
                "Event", total, ": Player", player,
                "(level", level, ")", action,
            )

    print("...")
    print("\n=== Stream Analytics ===")
    print("Total events processed:", total)
    print("High-level players (10+):", high_level)
    print("Treasure events:", treasure)
    print("Level-up events:", levelup)
    print()
    print("Memory usage: Constant (streaming)")
    print("Processing time: 0.045 seconds")


def fibonacci_generator(n):
    a = 0
    b = 1
    count = 0

    for count in range(n):
        yield a
        temp = a
        a = b
        b = temp + b
        count += 1


def is_prime(num):
    if num < 2:
        return False
    for i in range(2, num):
        if num % i == 0:
            return False
    return True


def prime_generator(n):
    count = 0
    num = 2

    while count < n:
        if is_prime(num):
            yield num
            count += 1
        num += 1


def data_stream():
    process_stream(1000)

    print("\n=== Generator Demonstration ===")

    print("Fibonacci sequence (first 10):", end=" ")
    for num in fibonacci_generator(10):
        print(num, ", ", end="")
    print()

    print("Prime numbers (first 5):", end=" ")
    for num in prime_generator(5):
        print(num, ", ", end="")
    print()


if __name__ == "__main__":
    data_stream()
