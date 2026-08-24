import random

ALL_ACHIEVEMENTS: list[str] = [
    "Crafting Genius", "Strategist", "World Savior", "Speed Runner",
    "Survivor", "Master Explorer", "Treasure Hunter", "Unstoppable",
    "First Steps", "Collector Supreme", "Untouchable", "Sharp Mind",
    "Boss Slayer", "Hidden Path Finder",
]

PLAYERS: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]


def gen_player_achievements() -> set[str]:
    count = random.randint(3, len(ALL_ACHIEVEMENTS) - 1)
    return set(random.sample(ALL_ACHIEVEMENTS, count))


def main() -> None:
    print("=== Achievement Tracker System ===")
    print()

    player_sets = {}
    for p in PLAYERS:
        player_sets[p] = gen_player_achievements()

    for player, achievements in player_sets.items():
        print(f"Player {player}: {achievements}")

    print()
    all_distinct: set[str] = set()
    for achievements in player_sets.values():
        all_distinct = all_distinct.union(achievements)
    print(f"All distinct achievements: {all_distinct}")

    common: set[str] = all_distinct.copy()
    for achievements in player_sets.values():
        common = common.intersection(achievements)
    print(f"Common achievements: {common}")

    print()
    others: dict[str, set[str]] = {}
    for player, achievements in player_sets.items():
        rest: set[str] = set()
        for other, other_ach in player_sets.items():
            if other != player:
                rest = rest.union(other_ach)
        others[player] = achievements.difference(rest)
        print(f"Only {player} has: {others[player]}")

    print()
    for player, achievements in player_sets.items():
        missing = set(ALL_ACHIEVEMENTS).difference(achievements)
        print(f"{player} is missing: {missing}")


main()
