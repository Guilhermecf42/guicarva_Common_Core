import random
import tkinter as tk
from collections import deque
from typing import List, Tuple, Dict, Optional
from parse_config import export_maze, MazeConfig
from mlx import Mlx
import os


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
            x = self.width #largura(linha)
            y = self.height #Altura(coluna)
            block = []
            if x % 2:
                f_x, t_x = (x // 2) - 3, (x // 2) + 1
            else:
                f_x, t_x = (x // 2) - 4, (x // 2) + 1
            if y % 2:
                f_y, t_y = (y // 2) - 2, (y // 2) - 2
            else:
                f_y, t_y = (y // 2) - 3, (y // 2) - 2
            for i in range(5):
                if i <= 2: block.append((f_x + 0, f_y + i))
                if i == 2: block.append((f_x + 1, f_y + i))
                block.append((f_x + 2, f_y + i))
            for i in range(5):
                if i != 1: block.append((t_x + 0, t_y + i))
                if i not in [1, 3]: block.append((t_x + 1, t_y + i))
                if i != 3: block.append((t_x + 2, t_y + i))
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

        if self.width >= 9 and self.height >= 7:
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
        tentativas = (self.width * self.height) // 1
        for _ in range(tentativas):
            rx = random.randint(0, self.width - 2)
            ry = random.randint(0, self.height - 2)
            direcao = random.choice(["E", "S"])
            cell = self.cells[rx, ry]
            block = (cell == {"N": True, "S": True, "E": True, "W": True})
            block_e = False
            if rx + 1 < self.width:
                cell_e = self.cells[rx + 1, ry]
                block_e = (cell_e == {"N": True, "S": True, "E": True, "W": True})
            block_s = False
            if ry + 1 < self.height:
                cell_s = self.cells[rx, ry + 1]
                block_s = (cell_s == {"N": True, "S": True, "E": True, "W": True})
            if not block:
                if not block_e:
                    if direcao == "E" and rx + 1 < self.width:
                        self.cells[(rx, ry)]["E"] = False
                        self.cells[(rx + 1, ry)]["W"] = False
                elif not block_s:
                    if direcao == "S" and ry + 1 < self.height:
                        self.cells[(rx, ry)]["S"] = False
                        self.cells[(rx, ry + 1)]["N"] = False


class MazeVisualizer:
    def __init__(self, config: MazeConfig) -> None:
        self.config: MazeConfig = config
        self.generator: MazeGenerator = MazeGenerator(config.width, config.height)
        self.cells: Dict[Tuple[int, int], Dict[str, bool]] = {}

        self.wall_color: str = "cyan"

    def make(self) -> None:
        def on_key(key, param):
            if key == 65307:  # ESC
                os._exit(0)

        width = self.config.width
        height = self.config.height
        mlx = Mlx()
        mlx_ptr = mlx.mlx_init()
        win_ptr = mlx.mlx_new_window(mlx_ptr, width * 20, height * 20, "My Window")

        mlx.mlx_key_hook(win_ptr, on_key, None)
        mlx.mlx_hook(win_ptr, 33, 0, lambda p: os._exit(0), None)  # close button

        img_ptr = mlx.mlx_new_image(mlx_ptr, width * 20, height * 20)
        data, bpp, sl, fmt = mlx.mlx_get_data_addr(img_ptr)


        # # Configuração do quadrado
        # x_inicio = 100    # Posição X inicial (coluna)
        # y_inicio = 100    # Posição Y inicial (linha)
        # tamanho = 150     # Tamanho do lado do quadrado (150x150 pixels)
        # cor_vermelha = bytes([0x00, 0x00, 0xFF, 0xFF]) # BGRA

        # # Desenhar o quadrado pixel por pixel
        # for y in range(y_inicio, y_inicio + tamanho):
        #     for x in range(x_inicio, x_inicio + 2):
        #         # Fórmula mágica do offset: (linha * comprimento_da_linha) + (coluna * bytes_por_pixel)
        #         offset = (y * sl) + (x * 4)
        #         data[offset:offset + 4] = cor_vermelha

        # # Enviar a imagem atualizada para a janela
        # mlx.mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0)


        mlx.mlx_loop(mlx_ptr)

    # def draw_resolution(self) -> None:

    #     mapa = self.generator.cells 
    #     inicio = self.config.entry
    #     fim = self.config.exit_cell

    #     VETORES_DIRECAO = {
    #         "N": (0, -1),
    #         "S": (0, 1),
    #         "E": (1, 0),
    #         "W": (-1, 0)
    #     }
    #     fila = deque([(inicio, [inicio])])
    #     visitados = {inicio}
    #     while fila:
    #         pos_atual, caminho_atual = fila.popleft()
    #         if pos_atual == fim:
    #             break
    #         x, y = pos_atual
    #         if pos_atual not in mapa:
    #             continue   
    #         caminhos_disponiveis = mapa[pos_atual]
    #         for direcao, pode_passar in caminhos_disponiveis.items():
    #             if not pode_passar:
    #                 dx, dy = VETORES_DIRECAO[direcao]
    #                 vizinho = (x + dx, y + dy)
    #                 if vizinho not in visitados:
    #                     visitados.add(vizinho)
    #                     fila.append((vizinho, caminho_atual + [vizinho]))

    #     if caminho_atual and len(caminho_atual) > 1:
    #         pontos_linha = []

    #         for x, y in caminho_atual:
    #             centro_x = self.margin + (x * self.cell_size) + (self.cell_size // 2)
    #             centro_y = self.margin + (y * self.cell_size) + (self.cell_size // 2)

    #             pontos_linha.append(centro_x)
    #             pontos_linha.append(centro_y)

    #         self.canvas.create_line(pontos_linha, fill="#149AD8", width=4, capstyle="round", joinstyle="round")




    # def draw(self) -> None:
    #     self.canvas.delete("all")
        
    #     for (x, y), walls in self.cells.items():
    #         x1 = self.margin + x * self.cell_size
    #         y1 = self.margin + y * self.cell_size
    #         x2 = x1 + self.cell_size
    #         y2 = y1 + self.cell_size

    #         color = self.wall_color
            
    #         if (x, y) == self.config.entry:
    #             self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#00FF00", outline="")
    #         elif (x, y) == self.config.exit_cell:
    #             self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#FFCC00", outline="")
    #         if all(walls[i] for i in ["N", "S", "E", "W"]):
    #             self.canvas.create_rectangle(x1+2, y1+2, x2-2, y2-2, fill="#E21313", outline="")
    #         if walls["N"]: self.canvas.create_line(x1, y1, x2, y1, fill=color, width=2)
    #         if walls["S"]: self.canvas.create_line(x1, y2, x2, y2, fill=color, width=2)
    #         if walls["E"]: self.canvas.create_line(x2, y1, x2, y2, fill=color, width=2)
    #         if walls["W"]: self.canvas.create_line(x1, y1, x1, y2, fill=color, width=2)


    # def action_regenerate(self) -> None:
    #     self.cells = self.generator.generate(self.config.perfect)
    #     if self.config.entry[0] == 0: self.cells[self.config.entry]["W"] = False
    #     if self.config.exit_cell[0] == self.config.width - 1: self.cells[self.config.exit_cell]["E"] = False
        
    #     self.draw()
    #     export_maze(self.cells, self.config)

    # def action_change_color(self) -> None:
    #     cores = ["cyan", "magenta", "red", "yellow", "white", "orange", "#00FF66"]
    #     self.wall_color = random.choice([c for c in cores if c != self.wall_color])
    #     self.draw()

    # def run(self) -> None:
    #     self.root.mainloop()