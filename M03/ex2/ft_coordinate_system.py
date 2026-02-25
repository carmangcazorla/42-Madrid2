import math


def create_position(x, y, z):
    """Create a coordinate position as a tuple."""
    return (x, y, z)


def calculate_distance(p1, p2):
    """Calculate the distance between two coordinates in 3D space."""
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    return math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)


def parse_coordinates(coordinate):
    """Create a coordinate tuple from a string."""
    try:
        parts = coordinate.split(',')
        x = int(parts[0])
        y = int(parts[1])
        z = int(parts[2])
        return (x, y, z)
    except ValueError as e:
        print("Error parsing coordinates:", e)
        print("Error details - Type:", e.__class__.__name__, ", Args:", e.args)
        return None


def coordinate_system():
    """Demonstrate the use of coordinate systems."""
    print("=== Game Coordinate System ===\n")

    position = create_position(10, 20, 5)
    print("Position created:", position)

    origin = (0, 0, 0)
    dist = calculate_distance(origin, position)
    print("Distance between", origin, "and", position, ":", dist)

    print('\nParsing coordinates: "3,4,0"')
    parsed = parse_coordinates("3,4,0")

    if parsed:
        print("Parsed position:", parsed)
        dist2 = calculate_distance(origin, parsed)
        print("Distance between", origin, "and", parsed, ":", dist2)

    print('\nParsing invalid coordinates: "abc,def,ghi"')
    parse_coordinates("abc,def,ghi")

    print("\nUnpacking demonstration:")
    if parsed:
        x, y, z = parsed
    print("Player at x=", x, ", y=", y, ", z=", z, sep="")
    print("Coordinates: X=", x, ", Y=", y, ", Z=", z, sep="")


if __name__ == "__main__":
    coordinate_system()
