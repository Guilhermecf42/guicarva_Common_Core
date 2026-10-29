import abc
import typing


class DataProcessor(abc.ABC):

    def __init__(self, name: str) -> None:
        self.name: str = name
        self.buffer: list[tuple[int, str]] = []
        self.processed: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:

    def store(self, item: str) -> None:
        self.buffer.append((self.processed, item))
        self.processed += 1

    def output(self) -> tuple[int, str]:
        if not self.buffer:
            raise IndexError(f"No data left in {self.name}")
        return self.buffer.pop(0)

    def remaining(self) -> int:
        return len(self.buffer)


class NumericProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Numeric Processor")

    def validate(self, data: typing.Any) -> bool:
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


class DataStream:

    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            handled = False
            for proc in self.processors:
                if proc.validate(element):
                    try:
                        proc.ingest(element)
                        handled = True
                    except ValueError as e:
                        print(f"DataStream error - {e}")
                        handled = True
                    break
            if not handled:
                print(
                    "DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return
        for proc in self.processors:
            print(
                f"{proc.name}: total {proc.processed} items processed, "
                f"remaining {proc.remaining()} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")

    print()
    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    numeric = NumericProcessor()
    text = TextProcessor()
    logs = LogProcessor()

    print()
    print("Registering Numeric Processor")
    stream.register_processor(numeric)

    batch: list[typing.Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {"log_level": "INFO", "log_message": "User wil is connected"},
        ],
        42,
        ["Hi", "five"],
    ]
    print()
    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print()
    print("Registering other data processors")
    stream.register_processor(text)
    stream.register_processor(logs)
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print()
    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    logs.output()
    stream.print_processors_stats()


main()
