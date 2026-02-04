class Plant:
    """Represents a plant with name, height and age."""
    def __init__(self, name, height, current_age):
        self.name = name
        self.height = height
        self.current_age = current_age

    def grow(self):
        """Increase plant height by 1 cm."""
        self.height += 1

    def age(self):
        """Increase plant age by 1 day."""
        self.current_age += 1

    def get_info(self):
        """Print plant information."""
        print(
            self.name + ":", self.height,
            "cm,", self.current_age, "days old"
            )


print("=== Day 1 ===")
plant1 = Plant("Rose", 25, 30)
plant1.get_info()
original_height = plant1.height

days = 6
day = 1
for day in range(1, days + 1):
    plant1.grow()
    plant1.age()
    day += 1

print("=== Day 7 ===")
plant1.get_info()

growth = plant1.height - original_height
print("Growth this week: +", growth, "cm", sep="")
