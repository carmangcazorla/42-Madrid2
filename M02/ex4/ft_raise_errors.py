class GardenError(Exception):
    """Garden management error"""


def check_plant_health(plant_name, water_level, sunlight_hours):
    """Water and sunligth errors"""
    try:
        if plant_name is None:
            raise GardenError("Error: Plant name cannot be None!\n")
        if water_level < 1:
            raise GardenError(
                "Error: Water level", water_level,
                "is too low (min 1)\n"
                )
        if water_level > 10:
            raise GardenError(
                "Error: Water level" + str(water_level) +
                " is too high (max 10)\n"
                )
        if sunlight_hours < 2:
            raise GardenError(
                "Error: Sunlight hours" + str(sunlight_hours) +
                " is too low (min 2)\n"
                )
        if sunlight_hours > 12:
            raise GardenError(
                "Error: Sunlight hours" + str(sunlight_hours) +
                "is too high (max 12)\n"
                )
        print("Plant", plant_name, "is healthy!\n")
    except GardenError as e:
        print(e)


def test_plant_checks():
    """Testing water and sunligth errors"""
    print("=== Garden Plant Health Checker ===\n")
    print("Testing good values...")
    check_plant_health("tomato", 5, 6)
    print("Testing empty plant name...")
    check_plant_health(None, 5, 6)
    print("Testing bad water level...")
    check_plant_health("tomato", 15, 6)
    print("Testing bad sunlight hours...")
    check_plant_health("tomato", 5, 0)
    print("All error raising tests completed!")


if __name__ == "__main__":
    test_plant_checks()
