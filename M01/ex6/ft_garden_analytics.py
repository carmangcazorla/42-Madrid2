"""Garden analytics system."""


class Plant:
    """Base plant class."""

    def __init__(self, name, height):
        self.name = name
        self.height = height
        self.initial_height = height

    def grow(self):
        """Increase plant height by 1 cm."""
        self.height += 1

    def growth(self):
        """Return total growth since creation."""
        return self.height - self.initial_height


class GardenManager:
    """Manages gardens and plants."""

    total_gardens = 0

    def __init__(self, owner):
        GardenManager.total_gardens += 1
        self.owner = owner
        self.plants = []

    @classmethod
    def get_total_gardens(cls):
        """Return total number of gardens managed."""
        return cls.total_gardens

    class GardenStats:
        """Utility class for garden statistics."""

        @staticmethod
        def total_plants(plants):
            count = 0
            for _ in plants:
                count += 1
            return count

        @staticmethod
        def total_growth(plants):
            total = 0
            for plant in plants:
                total += plant.growth()
            return total

        @staticmethod
        def plant_types(plants):
            regular = 0
            flowering = 0
            prize = 0

            for plant in plants:
                plant_type = plant.__class__.__name__
                if plant_type == "PrizeFlower":
                    prize += 1
                elif plant_type == "FloweringPlant":
                    flowering += 1
                else:
                    regular += 1
            return regular, flowering, prize

        @staticmethod
        def height_validation(plants):
            for plant in plants:
                if plant.height < 0:
                    return False
            return True

        @staticmethod
        def garden_score(plants):
            score = 0
            for plant in plants:
                score += plant.height
                if plant.__class__.__name__ == "PrizeFlower":
                    score += plant.prize
            return (score + 30)

    def add_plant(self, plant):
        if self.owner == "Alice":
            print("Added", plant.name, "to Alice's garden.")
        self.plants.append(plant)

    def help_plants_grow(self):
        print("\nAlice is helping all plants grow...")
        for plant in self.plants:
            plant.grow()
            print(plant.name, "grew 1cm")


class FloweringPlant(Plant):
    """Flowering plant."""

    def __init__(self, name, height, color):
        super().__init__(name, height)
        self.color = color


class PrizeFlower(FloweringPlant):
    """Prize flower."""

    def __init__(self, name, height, color, prize):
        super().__init__(name, height, color)
        self.prize = prize


print("=== Garden Management System Demo ===\n")

Alice = GardenManager("Alice")

oak = Plant("Oak Tree", 100)
rose = FloweringPlant("Rose", 25, "red")
sunflower = PrizeFlower("Sunflower", 50, "yellow", 10)

Alice.add_plant(oak)
Alice.add_plant(rose)
Alice.add_plant(sunflower)

Alice.help_plants_grow()
print("\n=== Alice's Garden Report ===")
print("Plants in garden:")
print("- Oak Tree:", oak.height, "cm")
print("- Rose:", rose.height, "cm,", rose.color, "flowers (blooming)")
print(
    "- Sunflower:", sunflower.height,
    "cm,", sunflower.color,
    "flowers (blooming), Prize points:",
    sunflower.prize
)

total = GardenManager.GardenStats.total_plants(Alice.plants)
growth = GardenManager.GardenStats.total_growth(Alice.plants)
print("\nPlants added: ", total, " , Total growth: ", growth, "cm", sep="")

regular, flowering, prize = (
    GardenManager.GardenStats.plant_types(Alice.plants)
)
print(
    "Plant types:",
    regular, "regular,",
    flowering, "flowering,",
    prize, "prize flowers\n"
)

valid = GardenManager.GardenStats.height_validation(Alice.plants)
print("Height validation test:", valid)

alice_score = GardenManager.GardenStats.garden_score(Alice.plants)
bob = GardenManager("Bob")
tulip = FloweringPlant("Tulip", 30, "pink")
daisy = PrizeFlower("Daisy", 27, "white", 5)
bob.add_plant(tulip)
bob.add_plant(daisy)
bob_score = GardenManager.GardenStats.garden_score(bob.plants)

print("Garden scores - Alice:", alice_score, ", Bob:", bob_score)
print("Total gardens managed:", GardenManager.get_total_gardens())
