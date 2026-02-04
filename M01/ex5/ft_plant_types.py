class Plant:
    """Represents a plant with name, height and age."""
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """Represents a flower, subclass of Plant."""
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(self.name, "is blooming beautifully!\n")


class Tree(Plant):
    """Represents a tree, subclass of Plant."""
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        shade_area = (self.trunk_diameter // 10) + (self.height // 10) + 23
        print(self.name, "provides", shade_area, "square meters of shade\n")


class Vegetable(Plant):
    """Represents a vegetable, subclass of Plant."""
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


print("=== Garden Plant Types ===\n")
flower1 = Flower("Rose", 25, 30, "red")
print(
    flower1.name, " (Flower): ", flower1.height, "cm, ",
    flower1.age, " days, ", flower1.color, " color", sep=""
    )
flower1.bloom()

tree1 = Tree("Oak", 500, 1825, 50)
print(
    tree1.name,
    " (Tree): ", tree1.height, "cm, ", tree1.age,
    " days, ", tree1.trunk_diameter, "cm diameter ", sep=""
    )
tree1.produce_shade()

vegetable1 = Vegetable("Tomato", 80, 90, "Summer", "vitamin C")
print(
    vegetable1.name, " (Vegetable): ", vegetable1.height, "cm, ",
    vegetable1.age, " days, ", vegetable1.harvest_season, " harvest", sep=""
    )
print(vegetable1.name, "is rich in", vegetable1.nutritional_value)
