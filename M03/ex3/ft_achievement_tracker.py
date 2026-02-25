def achivement_tracker():
    """Track and analyze player common and unique achievements."""
    print("=== Achievement Tracker System ===\n")

    alice = set([
        "first_kill",
        "level_10",
        "treasure_hunter",
        "speed_demon"
    ])

    bob = set([
        "first_kill",
        "level_10",
        "boss_slayer",
        "collector"
    ])

    charlie = set([
        "level_10",
        "treasure_hunter",
        "boss_slayer",
        "speed_demon",
        "perfectionist"
    ])

    print("Player alice achievements:", alice)
    print("Player bob achievements:", bob)
    print("Player charlie achievements:", charlie)

    print("\n=== Achievement Analytics ===")

    all_unique = alice.union(bob).union(charlie)
    print("All unique achievements:", all_unique)
    print("Total unique achievements:", len(all_unique))

    common_all = alice.intersection(bob).intersection(charlie)
    print("\nCommon to all players:", common_all)

    alice_rare = alice.difference(bob.union(charlie))
    bob_rare = bob.difference(alice.union(charlie))
    charlie_rare = charlie.difference(alice.union(bob))
    rare = alice_rare.union(bob_rare.union(charlie_rare))

    print("Rare achievements (1 player):", rare)

    alice_bob_common = alice.intersection(bob)
    print("\nAlice vs Bob common:", alice_bob_common)

    alice_unique = alice.difference(bob)
    print("Alice unique:", alice_unique)

    bob_unique = bob.difference(alice)
    print("Bob unique:", bob_unique)


if __name__ == "__main__":
    achivement_tracker()
