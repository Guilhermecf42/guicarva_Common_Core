import abc
import typing


class DataProcessor(abc.ABC):

    def __init__(self, name: str) -> None:
        """Create a processor with an empty internal buffer."""
        self.name: str = name
        self.buffer: list[tuple[int, str]] = []
        self.processed: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        """Return True if this processor can ingest the given data."""

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        """Store the given data, raise an exception if it is invalid."""

    def store(self, item: str) -> None:
        """Append one converted item to the buffer with its rank."""
        self.buffer.append((self.processed, item))
        self.processed += 1

    def output(self) -> tuple[int, str]:
        """Extract and remove the oldest item with its processing rank."""
        if not self.buffer:
            raise IndexError(f"No data left in {self.name}")
        return self.buffer.pop(0)

    def remaining(self) -> int:
        """Return how many items are still stored in the processor."""
        return len(self.buffer)


class NumericProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Numeric Processor")

    def validate(self, data: typing.Any) -> bool:
        """Return True for numbers or sequences of numbers."""
        if isinstance(data, bool):
            return False
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list) and data:
            for item in data:
                if isinstance(item, bool):
                    return False
                if not isinstance(item, (int, float)):
                    return False
            return True
        return False

    def ingest(
        self, data: int | float | typing.Sequence[int | float]
    ) -> None:
        """Convert numbers into strings and store them."""
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, (int, float)):
            self.store(str(data))
            return
        for item in data:
            self.store(str(item))


class TextProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Text Processor")

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list) and data:
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, str):
            self.store(data)
            return
        for item in data:
            self.store(item)


class LogProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Log Processor")

    def is_log(self, data: typing.Any) -> bool:
        if not isinstance(data, dict) or not data:
            return False
        for key, value in data.items():
            if not isinstance(key, str) or not isinstance(value, str):
                return False
        return True

    def validate(self, data: typing.Any) -> bool:
        if self.is_log(data):
            return True
        if isinstance(data, list) and data:
            for item in data:
                if not self.is_log(item):
                    return False
            return True
        return False

    def convert(self, entry: dict[str, str]) -> str:
        return ": ".join(entry.values())

    def ingest(
        self, data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            self.store(self.convert(data))
            return
        for entry in data:
            self.store(self.convert(entry))


def main() -> None:
    print("=== Code Nexus - Data Processor ===")

    numeric = NumericProcessor()
    print()
    print("Testing Numeric Processor...")
    print(f" Trying to validate input '42': {numeric.validate(42)}")
    print(f" Trying to validate input 'Hello': {numeric.validate('Hello')}")
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest("foo")  # type: ignore[arg-type]
    except ValueError as e:
        print(f" Got exception: {e}")
    numbers = [1, 2, 3, 4, 5]
    print(f" Processing data: {numbers}")
    numeric.ingest(numbers)
    print(" Extracting 3 values...")
    for _ in range(3):
        rank, value = numeric.output()
        print(f" Numeric value {rank}: {value}")

    text = TextProcessor()
    print()
    print("Testing Text Processor...")
    print(f" Trying to validate input '42': {text.validate(42)}")
    words = ["Hello", "Nexus", "World"]
    print(f" Processing data: {words}")
    text.ingest(words)
    print(" Extracting 1 value...")
    rank, value = text.output()
    print(f" Text value {rank}: {value}")

    logs = LogProcessor()
    print()
    print("Testing Log Processor...")
    print(f" Trying to validate input 'Hello': {logs.validate('Hello')}")
    entries = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
    ]
    print(f" Processing data: {entries}")
    logs.ingest(entries)
    print(" Extracting 2 values...")
    for _ in range(2):
        rank, value = logs.output()
        print(f" Log entry {rank}: {value}")


main()
