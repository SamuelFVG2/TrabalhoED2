# Trabalho de Estrutura de Dados II

## Descrição

Este projeto foi desenvolvido para a disciplina de Estrutura de Dados.

O programa realiza a leitura de um arquivo texto contendo departamentos, seus respectivos códigos e palavras-chave associadas.

Após a importação dos dados, o usuário pode realizar consultas por meio de um menu interativo, utilizando duas formas de pesquisa:

- Buscar um departamento pelo nome;
- Buscar um departamento a partir de uma palavra-chave.

O projeto foi desenvolvido utilizando conceitos de Orientação a Objetos, manipulação de arquivos e estruturas de dados baseadas em vetores (`std::vector`).

---

## Estrutura do Projeto

```text
src/
│
├── classes/
│   └── department/
│       ├── department.h
│       └── department.cpp
│
├── arquivo.txt
└── main.cpp
```

---

## Como Compilar e Executar

Clone o repositório:

```bash
git clone https://github.com/SamuelFVG2/TrabalhoED2.git
```

Acesse a pasta do código-fonte:

```bash
cd .\TrabalhoED2\src\
```

Compile o projeto:

```bash
g++ main.cpp ./classes/department/department.cpp -o main
```

Execute o programa:

```bash
.\main.exe
```

---

## Arquivo de Entrada

O programa espera um arquivo chamado `arquivo.txt` contendo registros no seguinte formato:

```text
001 FINANCEIRO INVESTIMENTO RENDA GASTOS DESPESAS LUCRO
002 CONTABILIDADE BALANCO BALANCETE RAZAO ENTRADA SAIDA
```

Cada linha contém:

- Código do departamento;
- Nome do departamento;
- Cinco palavras-chave relacionadas ao departamento.

> **Importante:** Para evitar problemas de codificação (encoding) entre diferentes ambientes de execução, o arquivo de entrada deve conter apenas caracteres sem acentuação.

---

## Funcionamento

Ao executar o programa, será exibido um menu com as seguintes opções:

```text
===== MENU =====
1 - Buscar departamento
2 - Buscar palavra-chave
0 - Sair
```

- **Buscar departamento:** localiza um departamento pelo nome e exibe seu código e suas palavras-chave.
- **Buscar palavra-chave:** localiza o departamento ao qual a palavra pertence.
- **Sair:** encerra a execução do programa.
