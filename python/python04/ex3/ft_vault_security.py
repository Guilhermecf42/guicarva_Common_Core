def secure_archive(
    filename: str, action: str = "read", content: str = ""
) -> tuple[bool, str]:
    try:
        if action == "write":
            with open(filename, "w") as file:
                file.write(content)
            return (True, "Content successfully written to file")
        with open(filename, "r") as file:
            return (True, file.read())
    except OSError as e:
        return (False, f"{e}")


def main() -> None:
    print("=== Cyber Archives Security ===")

    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))

    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow"))

    print()
    print("Using 'secure_archive' to read from a regular file:")
    result = secure_archive("ancient_fragment.txt")
    print(result)

    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_fragment.txt", "write", result[1]))


main()
