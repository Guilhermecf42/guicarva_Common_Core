class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height)
        self.set_age(age)

    def get_name(self) -> str:
        return self._name

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, new_height: float) -> None:
        if new_height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            if self._height != 0:
                print(f"Height updated: {new_height}cm")
            self._height = float(new_height)

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            if self._age != 0:
                print(f"Age updated: {new_age} days")
            self._age = int(new_age)

    def show(self) -> None:
        print(f"{self._name}: {self._height:.1f}cm, {self._age} days old")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15.0, 10)
    print("Plant created: ", end="")
    rose.show()
    print("")
    rose.set_height(25)
    rose.set_age(30)
    print("")
    rose.set_height(-25)
    rose.set_age(-30)
    print("")
    print("Current state: ", end="")
    rose.show()
