import tkinter as tk

def traduzir_texto():
    # Altera a propriedade 'text' do widget texto
    texto1.config(text="Ola Mundo!")

def comprimentar_usuario():
    #Para pegar o texto digitado, usamos o método .get().
    nome_digitado = entrada.get()# Pega o texto do Entry
    texto_resposta.config(text=f"Bem-vindo(a), {nome_digitado}!")

janela = tk.Tk()# 1. Cria a janela principal
janela.title("meu primeiro app")# 2. Define o título da janela
janela.geometry("400x300")# 3. Define o tamanho inicial (Largura x Altura)

# pack() e um gerador de widgets simples, ele empilha os elementos
# um em cima do outro.

# Criando um texto (Label)
texto1 = tk.Label(janela, text="Hello World!", font=("Arial", 16))
texto1.pack(pady=10)# pady adiciona um espaçamento vertical

# Criando um botão (Button)
botao1 = tk.Button(janela, text="Nao Faz Nada!", bg="blue", fg="white")
botao1.pack(pady=10)

# 'command=nome_funçao' executa um funçao 'def'
# O comando recebe o nome da função (sem os parênteses)
botao2 = tk.Button(janela, text="Traduzir!", command=traduzir_texto)
botao2.pack()

introducao = tk.Label(janela, text="Digite seu nome:")
introducao.pack(pady=5)

#Para o usuário digitar algo, usamos o widget Entry.
entrada = tk.Entry(janela, font=("Arial", 12))
entrada.pack(pady=5)

botao3 = tk.Button(janela, text="Enviar", command=comprimentar_usuario)
botao3.pack(pady=5)

texto_resposta = tk.Label(janela, text="", font=("Arial", 12, "bold"))
texto_resposta.pack(pady=10)

janela.mainloop()# 4. Mantém a janela aberta (roda o programa)
