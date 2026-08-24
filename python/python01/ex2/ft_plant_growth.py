class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        rate_growth: float = 0.0,
    ) -> None:
        self.name = name
        self.height = height
        self.age = age
        self.rate_growth = rate_growth

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age} days old")

    def age_oneday(self) -> None:
        self.age += 1

    def grow(self) -> None:
        self.height += self.rate_growth


if __name__ == "__main__":
    rose = Plant("Rose", 25.0, 30, 0.8)
    initial_height = rose.height
    print("=== Garden Plant Growth ===")
    rose.show()
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.age_oneday()
        rose.grow()
        rose.show()
    total_growth = rose.height - initial_height
    print(f"Growth this week: {total_growth:.1f}cm")
