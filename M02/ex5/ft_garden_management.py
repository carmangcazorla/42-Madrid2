class GardenError(Exception):
    """Custom exception for garden problems"""


class Plant:
    def __init__(self, name, water_level, sunlight_hours):
        self.name = name
        self.water_level = water_level
        self.sunlight_hours = sunlight_hours


class GardenManager:
    def __init__(self):
        self.plants = []

    def add_plant(self, plant):
        try:
            if plant.name is None or plant.name == "":
                raise GardenError("Plant name cannot be empty!")
            self.plants.append(plant)
            print("Added", plant.name, "successfully")
        except GardenError as e:
            print("Error adding plant:", e)

    def water_plants(self):
        print("Opening watering system")
        try:
            for plant in self.plants:
                print("Watering", plant.name, "- success")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self):
        for plant in self.plants:
            try:
                if plant.water_level < 1:
                    raise GardenError(
                        "Water level " + str(plant.water_level) +
                        " is too low (min 1)"
                    )
                if plant.water_level > 10:
                    raise GardenError(
                        "Water level " + str(plant.water_level) +
                        " is too high (max 10)"
                    )
                if plant.sunlight_hours < 2:
                    raise GardenError(
                        "Sunlight hours " + str(plant.sunlight_hours) +
                        " is too low (min 2)"
                    )
                if plant.sunlight_hours > 12:
                    raise GardenError(
                        "Sunlight hours " + str(plant.sunlight_hours) +
                        " is too high (max 12)"
                    )

                print(
                    plant.name,
                    ": healthy (water: ",
                    plant.water_level,
                    ", sun: ",
                    plant.sunlight_hours,
                    ")", sep=""
                )

            except GardenError as e:
                print("Error checking", plant.name + ":", e)


def main():
    print("=== Garden Management System ===\n")

    manager = GardenManager()

    print("Adding plants to garden...")
    manager.add_plant(Plant("tomato", 5, 8))
    manager.add_plant(Plant("lettuce", 15, 8))
    manager.add_plant(Plant(None, 5, 8))

    print("\nWatering plants...")
    manager.water_plants()

    print("\nChecking plant health...")
    manager.check_plant_health()

    print("\nTesting error recovery...")
    try:
        raise GardenError("Not enough water in tank")
    except GardenError as e:
        print("Caught GardenError:", e)
        print("System recovered and continuing...")

    print("\nGarden management system test complete!")


if __name__ == "__main__":
    main()
