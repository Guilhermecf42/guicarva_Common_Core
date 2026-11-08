import random
import tkinter as tk
from collections import deque
from typing import List, Tuple, Dict, Optional
from parse_config import export_maze, MazeConfig


class MazeGenerator:
    def __init__(self, width: int, height: int) -> None:
        self.width: int = width
        self.height: int = height
        self.cells: Dict[Tuple[int, int], Dict[str, bool]] = {}

    def generate(self, perfect: bool) -> Dict[Tuple[int, int], Dict[str, bool]]:
        self.cells = {
            (x, y): {"N": True, "S": True, "E": True, "W": True}
            for y in range(self.height) for x in range(self.width)
        }
        visited = [[False for _ in range(self.width)] for _ in range(self.height)]

        def set_42() -> list[tuple[int,int]]:
            block = []
            m_w, m_h = self.width // 2, self.height // 2
            start_w, start_h = (self.width // 2) - 3, (self.height // 2) - 2
            for i in range(7):
                if i not in [1, 3]:
                    block.append((start_w + i, start_h + 0))
            for i in range(7):
                if i not in [1, 3, 4, 5]:
                    block.append((start_w + i, start_h + 1))
            for i in range(7):
                if i not in [3]:
                    block.append((start_w + i, start_h + 2))
            for i in range(7):
                if i not in [0, 1, 3, 5, 6]:
                    block.append((start_w + i, start_h + 3))
            for i in range(7):
                if i not in [0, 1, 3]:
                    block.append((start_w + i, start_h + 4))

            return block
        
        def get_neighbors(x: int, y: int) -> List[Tuple[int, int, str, str]]:
            neighbors = []
            directions = [(0, -1, "N", "S"), (0, 1, "S", "N"), (-1, 0, "W", "E"), (1, 0, "E", "W")]
            for dx, dy, dir_go, dir_back in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < self.width and 0 <= ny < self.height and not visited[ny][nx]:
                    neighbors.append((nx, ny, dir_go, dir_back))
            return neighbors

        start_x, start_y = 0, 0
        visited[start_y][start_x] = True
        stack = [(start_x, start_y)]

        block = set_42()
        for bx, by in block:
            visited[by][bx] = True


        while stack:
            cx, cy = stack[-1]
            neighbors = get_neighbors(cx, cy)
            
            if neighbors:
                nx, ny, dir_go, dir_back = random.choice(neighbors)
                self.cells[(cx, cy)][dir_go] = False
                self.cells[(nx, ny)][dir_back] = False
                visited[ny][nx] = True
                stack.append((nx, ny))
            else:
                stack.pop()

        for x in range(self.width):
            self.cells[(x, 0)]["N"] = True
            self.cells[(x, self.height - 1)]["S"] = True
        for y in range(self.height):
            self.cells[(0, y)]["W"] = True
            self.cells[(self.width - 1, y)]["E"] = True

        if not perfect:
            self._criar_loops_pacman()

        return self.cells

    def _criar_loops_pacman(self) -> None:
        tentativas = (self.width * self.height) // 5
        for _ in range(tentativas):
            rx = random.randint(0, self.width - 2)
            ry = random.randint(0, self.height - 2)
            direcao = random.choice(["E", "S"])
            if direcao == "E" and rx + 1 < self.width:
                self.cells[(rx, ry)]["E"] = False
                self.cells[(rx + 1, ry)]["W"] = False
            elif direcao == "S" and ry + 1 < self.height:
                self.cells[(rx, ry)]["S"] = False
                self.cells[(rx, ry + 1)]["N"] = False


class MazeVisualizer:
    def __init__(self, config: MazeConfig) -> None:
        self.config: MazeConfig = config
        self.generator: MazeGenerator = MazeGenerator(config.width, config.height)
        self.cells: Dict[Tuple[int, int], Dict[str, bool]] = {}
        self.solucao: List[Tuple[int, int]] = []

        self.wall_color: str = "cyan"
        
        self.cell_size: int = 20
        self.margin: int = 30
        
        self.root = tk.Tk()
        self.root.title("A-Maze-ing Graphical Visualizer")
        
        canvas_w = config.width * self.cell_size + (self.margin * 2)
        canvas_h = config.height * self.cell_size + (self.margin * 2)
        
        self.canvas = tk.Canvas(self.root, width=canvas_w, height=canvas_h, bg="#111111")
        self.canvas.pack()

        self.root.bind("<r>", lambda event: self.action_regenerate())
        self.root.bind("<c>", lambda event: self.action_change_color())
        self.root.bind("<s>", lambda event: self.draw_resolution())
        
        instructions = "Comandos: [R] Gerar Novo Labirinto  |  [C] Mudar Cor das Paredes"
        lbl = tk.Label(self.root, text=instructions, fg="white", bg="#222222", font=("Arial", 10))
        lbl.pack(fill=tk.X)

        self.action_regenerate()

    def draw_resolution(self) -> None:

        mapa = self.generator.cells 
        inicio = self.config.entry
        fim = self.config.exit_cell

        VETORES_DIRECAO = {
            "N": (0, -1),
            "S": (0, 1),
            "E": (1, 0),
            "W": (-1, 0)
        }
        fila = deque([(inicio, [inicio])])
        visitados = {inicio}
        while fila:
            pos_atual, caminho_atual = fila.popleft()
            if pos_atual == fim:
                break
            x, y = pos_atual
            if pos_atual not in mapa:
                continue   
            caminhos_disponiveis = mapa[pos_atual]
            for direcao, pode_passar in caminhos_disponiveis.items():
                if not pode_passar:
                    dx, dy = VETORES_DIRECAO[direcao]
                    vizinho = (x + dx, y + dy)
                    if vizinho not in visitados:
                        visitados.add(vizinho)
                        fila.append((vizinho, caminho_atual + [vizinho]))

        if caminho_atual and len(caminho_atual) > 1:
            pontos_linha = []

            for x, y in caminho_atual:
                centro_x = self.margin + (x * self.cell_size) + (self.cell_size // 2)
                centro_y = self.margin + (y * self.cell_size) + (self.cell_size // 2)

                pontos_linha.append(centro_x)
                pontos_linha.append(centro_y)

            self.canvas.create_line(pontos_linha, fill="#149AD8", width=4, capstyle="round", joinstyle="round")




    def draw(self) -> None:
        self.canvas.delete("all")
        
        for (x, y), walls in self.cells.items():
            x1 = self.margin + x * self.cell_size
            y1 = self.margin + y * self.cell_size
            x2 = x1 + self.cell_size
            y2 = y1 + self.cell_size

            color = self.wall_color
            
            if (x, y) == self.config.entry:
                self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#00FF00", outline="")
            elif (x, y) == self.config.exit_cell:
                self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#FFCC00", outline="")
            if all(walls[i] for i in ["N", "S", "E", "W"]):
                self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#E21313", outline="")
            if walls["N"]: self.canvas.create_line(x1, y1, x2, y1, fill=color, width=2)
            if walls["S"]: self.canvas.create_line(x1, y2, x2, y2, fill=color, width=2)
            if walls["E"]: self.canvas.create_line(x2, y1, x2, y2, fill=color, width=2)
            if walls["W"]: self.canvas.create_line(x1, y1, x1, y2, fill=color, width=2)


    def action_regenerate(self) -> None:
        self.cells = self.generator.generate(self.config.perfect)
        if self.config.entry[0] == 0: self.cells[self.config.entry]["W"] = False
        if self.config.exit_cell[0] == self.config.width - 1: self.cells[self.config.exit_cell]["E"] = False
        
        self.draw()
        export_maze(self.cells, self.config)

    def action_change_color(self) -> None:
        cores = ["cyan", "magenta", "red", "yellow", "white", "orange", "#00FF66"]
        self.wall_color = random.choice([c for c in cores if c != self.wall_color])
        self.draw()

    def run(self) -> None:
        self.root.mainloop()