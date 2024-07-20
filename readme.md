# SGBD ITP - Sistema de Gerenciamento de Banco de Dados Simplificado

Este projeto consiste em implementar um Sistema de Gerenciamento de Banco de Dados (SGBD) simplificado baseado no modelo relacional, desenvolvido como parte da disciplina de Introdução a Técnicas de Programação (ITP).

## Funcionalidades

1. **Criar uma Tabela**
    - Usuário deve informar o nome da tabela.
    - Os tipos de dados para as colunas poderão ser os tipos primitivos em C (`char`, `int`, `float`, `double`) e strings.
    - Os valores deverão ser armazenados em arquivo.
    - Na criação da tabela deverá ser solicitado um nome de coluna para ser a chave primária.
    - A chave primária deverá ser obrigatoriamente do tipo inteiro sem sinal.

2. **Listar Todas as Tabelas**
    - Mostrar para o usuário as tabelas existentes.

3. **Criar uma Nova Tupla (Linha ou Registro) na Tabela**
    - Usuário deve informar o nome da tabela.
    - Sistema deve solicitar os valores de cada uma das colunas.
    - Sistema deve verificar a chave primária.
    - Em uma tabela deve existir um e apenas um valor de chave primária. Se o usuário informar uma chave que já existe, o sistema deve emitir uma mensagem de erro e não deve inserir o registro.

4. **Listar Todos os Dados de uma Tabela**
    - Usuário deve informar qual a tabela para serem listados os dados.
    - Os dados deverão ser obtidos a partir do arquivo que armazena o conteúdo da tabela.

5. **Pesquisar Valor em uma Tabela**
    - Usuário deverá informar o nome da tabela onde realizará a pesquisa.
    - Sistema deverá fornecer as colunas disponíveis na tabela e o usuário deverá selecionar uma delas.
    - Sistema deverá solicitar o valor para pesquisar, disponibilizando algumas opções:
        - Valores maior que o valor informado.
        - Valores maior ou igual que o valor informado.
        - Valores igual ao valor informado.
        - Valores menor que o valor informado.
        - Valores menor ou igual que o valor informado.
        - Valores próximo ao valor informado (se aplica apenas se a coluna for do tipo string).

6. **Apagar uma Tupla (Registro ou Linha) de uma Tabela**
    - Usuário deve informar o nome da tabela e a chave primária da tupla a ser apagada.

7. **Apagar uma Tabela**
    - Usuário deverá fornecer o nome da tabela a ser apagada.

## Requisitos

- Linguagem de Programação: C
- Sistema de Arquivos para armazenamento de dados

## Como Usar

1. **Clonar o Repositório**

    ```sh
    git clone https://github.com/seu-usuario/sgbd-itp.git
    cd sgbd-itp
    ```

2. **Compilar o Projeto**

    ```sh
    cd banco
    gcc -o main main.c table.c file.c search.c
    ```

3. **Executar o Projeto**

    ```sh
    ./main
    ```

## Estrutura de Arquivos

- `banco/main.c`: Arquivo principal contendo a implementação do SGBD simplificado.
- `banco/table.c`: Arquivo contendo as funções relacionadas às tabelas.
- `banco/file.c`: Arquivo contendo as funções relacionadas ao gerenciamento de arquivos.
- `banco/search.c`: Arquivo contendo as funções de pesquisa.

## Contribuição

1. Faça um fork do projeto.
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -m 'Adiciona nova feature'`).
4. Faça um push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.

## Licença

Distribuído sob a licença MIT. Veja `LICENSE` para mais informações.

---

Feito com ❤️ por Kaio
