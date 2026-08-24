"""Exercise 2: Stream Management - use stdin, stdout and stderr."""
import sys
import typing


def read_archive(filename: str) -> str:
    """Read and display the file content, return it as a string."""
    print(f"Accessing file '{filename}'")

    file: typing.IO[str]
    try:
        file = open(filename, "r")
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        sys.stderr.flush()
        return ""

    content = ""
    try:
        content = file.read()
        print("---")
        print(content)
        print("---")
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error reading file '{filename}': {e}\n")
        sys.stderr.flush()
    finally:
        file.close()
        print(f"File '{filename}' closed.")
    return content


def transform(content: str) -> str:
    """Add a '#' at the end of each line."""
    new_content = ""
    for line in content.splitlines():
        new_content += line + "#\n"
    return new_content


def ask_file_name() -> str:
    """Read a file name from stdin without using input()."""
    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    return sys.stdin.readline().strip()


def save_archive(filename: str, content: str) -> None:
    """Write the content to the given file."""
    print(f"Saving data to '{filename}'")

    file: typing.IO[str]
    try:
        file = open(filename, "w")
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        sys.stderr.flush()
        print("Data not saved.")
        return

    try:
        file.write(content)
        print(f"Data saved in file '{filename}'.")
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error writing file '{filename}': {e}\n")
        sys.stderr.flush()
        print("Data not saved.")
    finally:
        file.close()


def main() -> None:
    """Recover a file, transform it and optionally save the result."""
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    print("=== Cyber Archives Recovery & Preservation ===")
    content = read_archive(sys.argv[1])
    if not content:
        return

    new_content = transform(content)
    print()
    print("Transform data:")
    print("---")
    print(new_content)
    print("---")

    new_name = ask_file_name()
    if not new_name:
        print("Not saving data.")
        return
    save_archive(new_name, new_content)


main()
