from typing import Tuple
import sys


class MazeConfig:
    def __init__(self) -> None:
        self.width: int = 0
        self.height: int = 0
        self.entry: Tuple[int, int] = (0, 0)
        self.exit_cell: Tuple[int, int] = (0, 0)
        self.output_file: str = "maze.txt"
        self.perfect: bool = True


def parse_config(filename: str) -> MazeConfig:
    config = MazeConfig()
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            for line in file:
                line = line.strip()
                if not line or line.startswith('#'): continue
                if '=' not in line: continue
                key, value = line.split('=', 1)
                key, value = key.strip(), value.strip()
                if key == "WIDTH": config.width = int(value)
                elif key == "HEIGHT": config.height = int(value)
                elif key == "ENTRY":
                    vals = value.split(',')
                    config.entry = (int(vals[0]), int(vals[1]))
                elif key == "EXIT":
                    vals = value.split(',')
                    config.exit_cell = (int(vals[0]), int(vals[1]))
                elif key == "OUTPUT_FILE": config.output_file = value
                elif key == "PERFECT": config.perfect = value.lower() == "true"
    except Exception as e:
        print(f"Erro ao ler a configuração: {e}")
        sys.exit(1)
    return config

def check_config(config: MazeConfig) -> None:
    if config.width < 0 or config.height < 0:
        print("Lagura ou altura negativas!")
        sys.exit(1)
    entry: bool = True
    exit: bool = True
    x, y = config.entry
    if x < 0 or y < 0 or x >= config.width or y >= config.height: entry = False
    x, y = config.exit_cell
    if x < 0 or y < 0 or x >= config.width or y >= config.height: exit = False
    if not entry and not exit:
        print("Entrada e saida fora do labirinto!")
        sys.exit(1)
    elif not entry:
        print("Entrada fora do labirinto!")
        sys.exit(1)
    elif not exit:
        print("Saida fora do labirinto!")
        sys.exit(1)
    if config.entry == config.exit_cell:
        print("Entrada e saida no mesmo lugar!")
        sys.exit(1)

def export_maze(cells: dict, config: MazeConfig) -> None:
    try:
        with open(config.output_file, 'w', encoding='utf-8') as file:
            for y in range(config.height):
                row_hex = ""
                for x in range(config.width):
                    bit_n = 1 if cells[(x, y)]["N"] else 0
                    bit_e = 2 if cells[(x, y)]["E"] else 0
                    bit_s = 4 if cells[(x, y)]["S"] else 0
                    bit_w = 8 if cells[(x, y)]["W"] else 0
                    row_hex += format(bit_n + bit_e + bit_s + bit_w, 'x')
                file.write(row_hex + "\n")
            file.write("\n")
            file.write(f"{config.entry[0]},{config.entry[1]}\n")
            file.write(f"{config.exit_cell[0]},{config.exit_cell[1]}\n")
            file.write("NSEW\n")
    except Exception as e:
        print(f"Erro ao salvar arquivo hexadecimal: {e}")