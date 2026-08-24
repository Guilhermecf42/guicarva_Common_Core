import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        parts = raw.split(",")
        count = 0
        for _ in parts:
            count += 1
        if count != 3:
            print("Invalid syntax")
            continue
        coords: list[float] = []
        valid = True
        for part in parts:
            try:
                coords.append(float(part.strip()))
            except ValueError as e:
                print(f"Error on parameter '{part.strip()}': {e}")
                valid = False
                break
        if valid:
            return (coords[0], coords[1], coords[2])


def distance(
    p1: tuple[float, float, float], p2: tuple[float, float, float]
) -> float:
    return round(
        math.sqrt(
            (p2[0] - p1[0]) ** 2
            + (p2[1] - p1[1]) ** 2
            + (p2[2] - p1[2]) ** 2
        ),
        4,
    )


def main() -> None:
    print("=== Game Coordinate System ===")

    print()
    print("Get a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    print(f"It includes: X={pos1[0]}, Y={pos1[1]}, Z={pos1[2]}")
    origin: tuple[float, float, float] = (0.0, 0.0, 0.0)
    print(f"Distance to center: {distance(origin, pos1)}")

    print()
    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    dist = distance(pos1, pos2)
    print(f"Distance between the 2 sets of coordinates: {dist}")


main()
