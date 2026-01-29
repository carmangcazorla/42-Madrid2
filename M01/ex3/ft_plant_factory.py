class plant:
    def __init__(name, heigth, age):
        self.name = name
        self.heigth = heigth
        self.age = age

print("=== Plant Factory Output ===")
total_plants = 0

def print_createdplants():
        print(f"Created: {self.name} ({self.heigth}cm, {self.age} days)")
        total_plants += 1
plant1 = plant(rose, 25, 30)
print_createdplants()
plant2 = plant(Oak, 200, 365)
print_createdplants()
plant3 = plant(Cactus, 5, 90)
print_createdplants()
plant4 = plant(Sunflower, 80, 45)
print_createdplants()
plant5 = plant(Fern, 15, 120)

print("Total plants created: {total_plants}")