import random

INITIAL_PLAYERS: list[str] = [
    "Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "john",
    "kevin", "Liam",
]


def main() -> None:
    print("=== Game Data Alchemist ===")
    print()

    print(f"Initial list of players: {INITIAL_PLAYERS}")

    all_capitalized: list[str] = [p.capitalize() for p in INITIAL_PLAYERS]
    print(f"New list with all names capitalized: {all_capitalized}")

    already_capitalized: list[str] = [
        p for p in INITIAL_PLAYERS if p == p.capitalize()
    ]
    print(f"New list of capitalized names only: {already_capitalized}")

    print()
    score_dict: dict[str, int] = {
        p: random.randint(1, 999) for p in all_capitalized
    }
    print(f"Score dict: {score_dict}")

    average = round(sum(score_dict.values()) / len(score_dict), 2)
    print(f"Score average is {average}")

    high_scores: dict[str, int] = {
        p: s for p, s in score_dict.items() if s > average
    }
    print(f"High scores: {high_scores}")


main()
