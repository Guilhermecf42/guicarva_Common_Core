class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = float(height)
        self.age_days = age_days
        self.stats = self.Stats()

    class Stats:
        def __init__(self) -> None:
            self.grow_calls = 0
            self.age_calls = 0
            self.show_calls = 0
            self.shade_calls = 0

        def display(self) -> None:
            print(f"Stats: {self.grow_calls} grow, {self.age_calls} age, "
                  f"{self.show_calls} show")

    @staticmethod
    def is_older_than_year(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def grow(self, amount: float = 1.0) -> None:
        self.height += amount
        self.stats.grow_calls += 1

    def age(self, days: int = 1) -> None:
        self.age_days += days
        self.stats.age_calls += 1

    def show(self) -> None:
        self.stats.show_calls += 1
        print(f"{self.name}: {self.height:.1f}cm, {self.age_days} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age_days: int,
                 color: str, is_blooming: bool = False) -> None:
        super().__init__(name, height, age_days)
        self.color = color
        self.is_blooming = is_blooming

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self.is_blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age_days: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age_days)
        self.trunk_diameter = float(trunk_diameter)
        self.stats = self.TreeStats()

    class TreeStats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()

        def display(self) -> None:
            super().display()
            print(f"{self.shade_calls} shade")

    def produce_shade(self) -> None:
        self.stats.shade_calls += 1
        print(f"Tree {self.name} now produces a shade of {self.height:.1f}cm "
              f"long and {self.trunk_diameter:.1f}cm wide.")

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter:.1f}cm")


class Seed(Flower):
    def __init__(self, name: str, height: float, age_days: int,
                 color: str, seed_count: int = 0) -> None:
        super().__init__(name, height, age_days, color)
        self.seed_count = seed_count

    def bloom(self, seeds_produced: int = 42) -> None:
        super().bloom()
        self.seed_count = seeds_produced

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.seed_count if self.is_blooming else 0}")


def display_plant_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.stats.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plafnt.is_older_than_year(400)}")
    print("")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_plant_stats(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
    rose.bloom()
    rose.show()
    display_plant_stats(rose)
    print("")
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_plant_stats(oak)

    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_plant_stats(oak)
    print("")
    print("=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.bloom(42)
    sunflower.show()
    display_plant_stats(sunflower)
    print("")
    print("=== Anonymous")
    anon_plant = Plant.create_anonymous()
    anon_plant.show()
    display_plant_stats(anon_plant)
