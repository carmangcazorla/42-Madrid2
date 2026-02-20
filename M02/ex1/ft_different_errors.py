def garden_operations():
    print("Testing ValueError...")
    try:
        int("abc")
    except ValueError:
        print("Caught ValueError: invalid literal for int()")
        print()
    print("Testing ZeroDivisionError...")
    try:
        10 / 0
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
        print()
    print("Testing FileNotFoundError...")
    try:
        open("missing.txt")
    except FileNotFoundError:
        print("Caught FileNotFoundError:  No such file 'missing.txt'")
        print()
    print("Testing KeyError...")
    try:
        plants = {}
        plants["missing_plant"]
    except KeyError:
        print("Caught KeyError: 'missing_plant'")
        print()
    print("Testing multiple errors together...")
    try:
        int("abc")
    except (ValueError, ZeroDivisionError):
        print("Caught an error, but program continues!")
    print()


def test_error_types():
    print("=== Garden Error Types Demo ===")
    print()
    garden_operations()
    print()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
