class Plant:
    """Represents a plant with name, height and age."""
    plant_count = 0

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_info(self):
        """Print plant information."""
        print(
            "Created: ", self.name, " (", self.height,
            "cm, ", self.age, " days)", sep=""
        )
        Plant.plant_count += 1


print("=== Plant Factory Output ===")

plant1 = Plant("Rose", 25, 30)
plant1.get_info()

plant2 = Plant("Oak", 200, 365)
plant2.get_info()

plant3 = Plant("Cactus", 5, 90)
plant3.get_info()

plant4 = Plant("Sunflower", 80, 45)
plant4.get_info()

plant5 = Plant("Fern", 15, 120)
plant5.get_info()

print("\nTotal plants created:", Plant.plant_count)
