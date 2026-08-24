class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = float(height)
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.blooming = False

    def bloom(self) -> None:
        print(f"[asking the {self.name.lower()} to bloom]")
        self.blooming = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self.blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(
        self, name: str,
        height: float,
        age: int,
        diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.diameter = diameter

    def produce_shade(self) -> None:
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{self.height}cm long and {self.diameter}cm wide.")

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        season: str,
        nutritional: int,
    ) -> None:
        super().__init__(name, height, age)
        self.season = season
        self.nutritional = nutritional

    def grow(self, days: int) -> None:
        print(f"[make tomato grow and age for {days} days]")
        growth = float(2.1)
        nutri = 1
        self.height += growth * days
        self.nutritional += nutri * days

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.season}")
        print(f"Nutritional value: {self.nutritional}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "Red")
    rose.show()
    rose.bloom()
    rose.show()
    print("")
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    oak.produce_shade()
    print("")
    print("=== Vegetable")
    tomato = Vegetable("Tomate", 5.0, 10, "April", 0)
    tomato.show()
    tomato.grow(20)
    tomato.show()
