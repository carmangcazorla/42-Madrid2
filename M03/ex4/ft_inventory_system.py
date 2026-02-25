def inventory_value(inventory):
    """Calculate total value of the inventory."""
    total = 0
    for data in inventory.values():
        value = data["quantity"] * data["value"]
        total += value
    return total


def total_items_count(inventory):
    """Calculate total items in inventory."""
    count = 0
    for data in inventory.values():
        count += data["quantity"]
    return count


def found_rare_items(inventory):
    """Find rare items in the inventory."""
    rare_items = []
    for item, data in inventory.items():
        if data["rarity"] == "rare":
            rare_items = item
    return rare_items


def print_inventory(name, inventory):
    """Print inventory details."""
    print("\n===", name + "'s Inventory ===")

    total_value = 0
    total_count = 0

    for item, value in inventory.items():
        item_value = value["quantity"] * value["value"]
        total_value += item_value
        total_count += value["quantity"]

        print(
            item, "(" + value["type"] + ", " + value["rarity"] + "):",
            str(value["quantity"]) + "x @",
            value["value"], "gold each =",
            item_value, "gold"
        )

    print()
    print("Inventory value:", total_value, "gold")
    print("Item count:", total_count, "items")

    print("Categories:", end=" ")
    for item, value in inventory.items():
        print(value["type"] + "(" + str(value["quantity"]) + "), ", end="")


def transfer_potions(alice, bob):
    """Transfer two potions from Alice to Bob."""
    print()
    print("\n=== Transaction: Alice gives Bob 2 potions ===")

    if alice["potion"]["quantity"] >= 2:
        alice["potion"]["quantity"] -= 2
        bob["potion"]["quantity"] += 2
        print("Transaction successful!")
    else:
        print("Transaction failed!")


def inventory_system():
    """Demonstrate a player inventory system using dictionaries."""
    print("=== Player Inventory System ===")

    alice = dict({
        "sword": {
            "type": "weapon",
            "rarity": "rare",
            "quantity": 1,
            "value": 500
            },
        "potion": {
            "type": "consumable",
            "rarity": "common",
            "quantity": 5,
            "value": 50
            },
        "shield": {
            "type": "armor",
            "rarity": "uncommon",
            "quantity": 1,
            "value": 200
            }
    })

    bob = dict({
        "potion": {
            "type": "consumable",
            "rarity": "common",
            "quantity": 0,
            "value": 50
            },
        "magic_ring": {
            "type": "accessory",
            "rarity": "rare",
            "quantity": 1,
            "value": 300
            }
    })

    print_inventory("Alice", alice)

    transfer_potions(alice, bob)

    print("\n=== Updated Inventories ===")
    print("Alice potions:", alice["potion"]["quantity"])
    print("Bob potions:", bob["potion"]["quantity"])

    print("\n=== Inventory Analytics ===")

    alice_value = inventory_value(alice)
    bob_value = inventory_value(bob)

    if alice_value >= bob_value:
        print("Most valuable player: Alice (" + str(alice_value) + " gold)")
    else:
        print("Most valuable player: Bob (" + str(bob_value) + " gold)")

    alice_items = total_items_count(alice)
    bob_items = total_items_count(bob)

    if alice_items >= bob_items:
        print("Most items: Alice (" + str(alice_items) + " items)")
    else:
        print("Most items: Bob (" + str(bob_items) + " items)")

    alice_rare = found_rare_items(alice)
    bob_rare = found_rare_items(bob)
    print("Rarest items: " + str(alice_rare) + ", " + str(bob_rare))


if __name__ == "__main__":
    inventory_system()
