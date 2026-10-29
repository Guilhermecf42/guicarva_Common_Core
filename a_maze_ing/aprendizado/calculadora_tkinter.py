import tkinter as tk

# Criando a janela principal
janela = tk.Tk()
janela.title("Layout de Calculadora")
janela.geometry("350x450")

calulo_exe = False
sinal = False

def clique_botao(texto: str):
    global calulo_exe
    global sinal
    sinais = ["+", "-", "*", "/"]
    if calulo_exe:
        tela.delete(0, tk.END)
        calulo_exe = False
    digitos = tela.get()
    quantidade = len(digitos)
    if not digitos and texto in ["+", "*", "/"]:
        return
    elif not digitos and texto == "-":
        tela.insert(tk.END, texto)
    elif texto in sinais and digitos[quantidade - 1] in sinais:
        tela.delete(quantidade - 1)
        tela.insert(tk.END, texto)
    else:
        tela.insert(tk.END, texto)

def deletar():
    tela.delete(0, tk.END)

def resultado():
    global calulo_exe
    texto = tela.get()
    total = eval(texto)
    tela.delete(0, tk.END)
    tela.insert(0, total)
    calulo_exe = True

def backspace():
    digitos = tela.get()  
    tela.delete(len(digitos) - 1)


# 1. Campo de Exibição (Tela da Calculadora)
# O columnspan=4 faz a tela ocupar o espaço de 4 colunas horizontais
tela = tk.Entry(janela, font=("Arial", 20), justify="right")
tela.grid(row=0, column=0, columnspan=4, padx=10, pady=10, sticky="nsew")

# 2. Definição dos Botões e suas Posições (Linha, Coluna)
# Criamos uma lista de tuplas com: (Texto do Botão, Linha, Coluna)
botoes = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('0', 4, 1), ('+', 4, 3),
]

botao_del = tk.Button(janela, text="C", font=("Ariel", 14), width=5, height=2, command=deletar)
botao_del.grid(row=4, column=0, padx=5, pady=5)

botao_bs = tk.Button(janela, text="BackSpace", font=("Ariel", 14), width=12, height=2, command=backspace)
botao_bs.grid(row=5, column=0, columnspan=2, padx=5, pady=5)

botao_enter = tk.Button(janela, text="=", font=("Ariel", 14), width=5, height=2, command=resultado)
botao_enter.grid(row=4, column=2, padx=5, pady=5)

# 3. Criando e posicionando os botões usando um laço de repetição (for)
for (texto, linha, coluna) in botoes:
    botao = tk.Button(janela, text=texto, font=("Ariel", 14), width=5, height=2, command=lambda x=texto: clique_botao(x))
    # Coloca cada botão em sua respectiva linha e coluna
    botao.grid(row=linha, column=coluna, padx=5, pady=5)

janela.mainloop()