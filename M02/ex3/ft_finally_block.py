def water_plants(plant_list):
    """Watering plants"""
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None:
                print("Error: Cannot water None - invalid plant!")
                return
            print("Watering", plant)
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    """Watering plants"""
    print("=== Garden Watering System ===\n")
    print("Testing normal watering...")
    water_plants(["tomato", "lettuce", "carrots"])
    print("Watering completed successfully!")
    print()
    print("Testing watering with an error...")
    water_plants(["rose", None])
    print()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
