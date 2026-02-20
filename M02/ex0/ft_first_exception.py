def check_temperature(temp_str):
    print("Testing temperature:", temp_str)
    try:
        number = int(temp_str)
        if number < 0:
            print(
                "Error: ", number,
                "°C is too cold for plants (min 0°C)", sep=""
                )
        elif number > 40:
            print(
                "Error: ", number,
                "°C is too hot for plants (max 40°C)", sep=""
                )
        else:
            print("Temperature ", number, "ºC is perfect for plants!", sep="")
            return number
    except ValueError:
        print("Error: '", temp_str, "' is not a valid number", sep="")


def test_temperature_input():
    print("=== Garden Temperature Checker ===\n")
    check_temperature("25")
    print()
    check_temperature("abc")
    print()
    check_temperature("100")
    print()
    check_temperature("-50")
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
