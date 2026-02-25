import sys


def command_quest():
    """Show arguments passed to the program and count them."""
    args = sys.argv[0:]
    total_args = len(args)

    print("=== Command Quest ===")

    if total_args == 1:
        print("No arguments provided!")
        print("Program name:", sys.argv[0])
        print("Total arguments:", total_args)
    else:
        print("Program name:", sys.argv[0])
        count = 1
        for arg in args[1:]:
            print("Argument " + str(count) + ":", arg)
            count += 1
        print("Total arguments:", total_args)


if __name__ == "__main__":
    command_quest()
