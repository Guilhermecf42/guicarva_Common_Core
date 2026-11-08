import sys
from a_maze_ing import MazeVisualizer
from parse_config import parse_config

def main() -> None:
    if len(sys.argv) != 2:
        print("Uso correto: python3 a_maze_ing.py config.txt")
        sys.exit(1)

    config = parse_config(sys.argv[1])

    visualizer = MazeVisualizer(config)
    visualizer.run()

if __name__ == "__main__":
    main()