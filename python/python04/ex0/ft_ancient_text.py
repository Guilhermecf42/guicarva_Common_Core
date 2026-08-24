"""Exercise 0: Ancient Text Recovery - read and display a file."""
import sys
import typing


def main() -> None:
    """Read the file given on the command line and display it."""
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    filename = sys.argv[1]
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    file: typing.IO[str]
    try:
        file = open(filename, "r")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return

    try:
        content = file.read()
        print("---")
        print(content)
        print("---")
    except OSError as e:
        print(f"Error reading file '{filename}': {e}")
    finally:
        file.close()
        print(f"File '{filename}' closed.")


main()
