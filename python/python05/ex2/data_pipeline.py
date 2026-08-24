"""Exercise 2: full data pipeline with duck-typed export plugins."""
import abc
import typing


class DataProcessor(abc.ABC):
    """Common interface for every kind of data processor."""

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
    """Processor handling ints, floats and sequences of both."""

    def __init__(self) -> None:
        """Create the numeric processor."""
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
    """Processor handling strings and lists of strings."""

    def __init__(self) -> None:
        """Create the text processor."""
        super().__init__("Text Processor")

    def validate(self, data: typing.Any) -> bool:
        """Return True for a string or a list of strings."""
        if isinstance(data, str):
            return True
        if isinstance(data, list) and data:
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        """Store the given strings."""
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, str):
            self.store(data)
            return
        for item in data:
            self.store(item)


class LogProcessor(DataProcessor):
    """Processor handling log dictionaries and lists of them."""

    def __init__(self) -> None:
        """Create the log processor."""
        super().__init__("Log Processor")

    def is_log(self, data: typing.Any) -> bool:
        """Return True if data is a dict of string key-value pairs."""
        if not isinstance(data, dict) or not data:
            return False
        for key, value in data.items():
            if not isinstance(key, str) or not isinstance(value, str):
                return False
        return True

    def validate(self, data: typing.Any) -> bool:
        """Return True for a log dict or a list of log dicts."""
        if self.is_log(data):
            return True
        if isinstance(data, list) and data:
            for item in data:
                if not self.is_log(item):
                    return False
            return True
        return False

    def convert(self, entry: dict[str, str]) -> str:
        """Turn a log dict into a single readable string."""
        return ": ".join(entry.values())

    def ingest(
        self, data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        """Convert log entries into strings and store them."""
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            self.store(self.convert(data))
            return
        for entry in data:
            self.store(self.convert(entry))


class ExportPlugin(typing.Protocol):
    """Contract that any export plugin must satisfy through duck typing."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Export the extracted items."""


class CsvExport:
    """Export plugin producing a CSV line."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Print the values as a comma separated line."""
        print("CSV Output:")
        values = []
        for _, value in data:
            values.append(value)
        print(",".join(values))


class JsonExport:
    """Export plugin producing a JSON object."""

    def process_output(self, data: list[tuple[int, str]]) -> None:
        """Print the items as a JSON object keyed by processing rank."""
        print("JSON Output:")
        fields = []
        for rank, value in data:
            fields.append(f'"item_{rank}": "{value}"')
        print("{" + ", ".join(fields) + "}")


class DataStream:
    """Route each element of a stream to a suitable data processor."""

    def __init__(self) -> None:
        """Create a stream with no registered processor."""
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Add a new data processor to the stream."""
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        """Send each element to the first processor accepting it."""
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
        """Print how many items each processor handled and still holds."""
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return
        for proc in self.processors:
            print(
                f"{proc.name}: total {proc.processed} items processed, "
                f"remaining {proc.remaining()} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        """Consume nb items from each processor and export them."""
        for proc in self.processors:
            data: list[tuple[int, str]] = []
            for _ in range(nb):
                if proc.remaining() == 0:
                    break
                data.append(proc.output())
            if data:
                plugin.process_output(data)


def main() -> None:
    """Demonstrate the complete input and output data pipeline."""
    print("=== Code Nexus - Data Pipeline ===")

    print()
    print("Initialize Data Stream...")
    stream = DataStream()
    print()
    stream.print_processors_stats()

    print()
    print("Registering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())

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
    print()
    stream.print_processors_stats()

    print()
    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CsvExport())
    print()
    stream.print_processors_stats()

    second: list[typing.Any] = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {"log_level": "ERROR", "log_message": "500 server crash"},
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days",
            },
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]
    print()
    print(f"Send another batch of data: {second}")
    stream.process_stream(second)
    print()
    stream.print_processors_stats()

    print()
    print("Send 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JsonExport())
    print()
    stream.print_processors_stats()


main()
