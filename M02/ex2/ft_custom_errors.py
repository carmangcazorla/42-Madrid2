class GardenError(Exception):
    """Base error for garden."""


class PlantError(GardenError):
    """Error related to plants."""


class WaterError(GardenError):
    """Error related to watering."""


def check_plant():
    """Error related to plants"""
    raise PlantError("The tomato plant is wilting!")


def check_water():
    """Error related to watering."""
    raise WaterError("Not enough water in the tank!")


def test_custom_errors():
    """Testing errors"""
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        check_plant()
    except PlantError as e:
        print("Caught PlantError:", e)
    print()

    print("Testing WaterError...")
    try:
        check_water()
    except WaterError as e:
        print("Caught WaterError:", e)
    print()

    print("Testing catching all garden errors...")
    try:
        check_plant()
    except GardenError as e:
        print("Caught a garden error:", e)

    try:
        check_water()
    except GardenError as e:
        print("Caught a garden error:", e)

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
