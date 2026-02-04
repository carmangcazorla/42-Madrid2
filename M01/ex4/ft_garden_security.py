class SecurePlant:
    """Represents a plant with name, height and age."""
    def __init__(self, name, height, age):
        self.name = name
        self._height = height
        self._age = age

    def set_height(self, height):
        """Set and secure plant height"""
        if height >= 0:
            self._height = height
            print("Height updated: ", self._height, "cm", " [OK]", sep="")
        else:
            print(
                "Invalid operation attempted: height ",
                height, "cm", " [REJECTED]", sep=""
                )
            print("Security: Negative height rejected")

    def set_age(self, age):
        """Set and secure plant age"""
        if age >= 0:
            self._age = age
            print("Age updated:", self._age, "days", "[OK]")
        else:
            print(
                "Invalid operation attempted: age",
                age, "days", "[REJECTED]"
                )
            print("Security: Negative age rejected")

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age


print("=== Garden Security System ===")

plant1 = SecurePlant("Rose", 20, 40)
print("Plant created:", plant1.name)

plant1.set_height(25)
plant1.set_age(30)
plant1.set_height(-5)

print(
    "Current plant: ", plant1.name, " (", plant1.get_height(),
    "cm, ", plant1.get_age(), " days)", sep=""
    )
