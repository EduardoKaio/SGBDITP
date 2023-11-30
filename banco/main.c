#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <locale.h>

FILE *tabelas;

typedef struct
{
    int chave_primaria;
    char tipo_coluna;
    char nome_coluna[20];
} Coluna;

typedef struct
{
    char nome_tabela[50];
    int n_colunas;
} Tabela;

int cont = 0;

void criarTabela(Tabela tabela[cont]){
    cont++;

    tabela = malloc(cont * sizeof(int));
    
    if (cont > 1){
        tabela = realloc(tabela, cont * sizeof(int));
    }

    tabelas = fopen("tabelas.txt", "a");
    if(tabelas == NULL){
        printf("Ocorreu um erro ao criar a tabela");
        printf("O erro foi: %s\n", strerror(errno));
    } else {
        printf("Informe o nome da tabela: ");
        scanf("%s", tabela[cont].nome_tabela);  

        fprintf(tabelas, "%s\n", tabela[cont].nome_tabela);

        printf("Informe quantas colunas deseja inserir: ");
        scanf("%i", &tabela[cont].n_colunas);

        Coluna coluna[tabela[cont].n_colunas];

        fprintf(tabelas, "|");

        for(int i=0; i<tabela[cont].n_colunas; i++){
            if (i == 0)
            {
                printf("informe o nome da coluna com a chave primária: ");
                scanf("%s", coluna[i].nome_coluna);
                fprintf(tabelas, " %s |", coluna[i].nome_coluna);
            } else {
                
                printf("Informe o tipo da coluna %i:\n"
                    "[i] - Inteiro\n"
                    "[c] - Caractere\n"
                    "[d] - Decimal\n"
                    "[s] - Texto\n", i+1
                );
                
                scanf(" %c", &coluna[i].tipo_coluna);
                
                while (getchar() != '\n'); // limpar buffer para ler dnv

                printf("Informe o nome da coluna %i: ", i+1);
                fgets(coluna[i].nome_coluna, sizeof(coluna[i].nome_coluna), stdin);

                coluna[i].nome_coluna[strcspn(coluna[i].nome_coluna, "\n")] = 0; // tirar o \n do fgets

                fprintf(tabelas, " %-10s |", coluna[i].nome_coluna);
            }
        }
        fprintf(tabelas, "\n----------------------------------\n");
        fclose(tabelas);
        
        system("cls");//limpar tela
        
        printf("===================================\n");
        printf("Cadastro Concluído\n");
        printf("===================================\n");

        sleep(2);
        
        system("cls");
    }
} 

void criarNovaLinha(){

}

void pesquisarDado(){

}

void listarTabelas(){

}

void listarDados(){

}

void apagarTabela(char nome_tabela[]){

}

void apagarLinha()  {

}


int main()
{
    
    setlocale(LC_ALL, "pt_BR.utf8");
    int opcao;
    Tabela tabela[cont];

    do
    {
        printf("Escolha uma opção:\n"
               "[1] - Criar uma nova tabela\n"
               "[2] - Criar uma nova linha na tabela\n"
               "[3] - Pesquisar valor em uma tabela\n"
               "[4] - Listar todas as tabelas\n"
               "[5] - Listar todos os dados de uma tabela\n"
               "[6] - Apagar uma tabela\n"
               "[7] - Apagar uma linha de uma tabela\n"
               "[0] - Sair \n"
        );

        scanf("%i", &opcao);
        char nome_tabela[50];

        switch (opcao)
        {
        case 1:
            criarTabela(tabela);
            break;
        
        case 2:
            criarNovaLinha(tabela);
            break;
        
        case 3:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 51, stdin);
            
            pesquisarDado();
            break;
        
        case 4:
            listarTabelas();
            break;
        
        case 5:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 51, stdin);
            
            listarDados();
            break;
        
        case 6:
            // char nome_tabela[20]; //exemplo
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 51, stdin);
            
            apagarTabela(nome_tabela);
            
            break;
        
        case 7:
            // char nome_tabela[20]; //exemplo
            
            int chave_primaria;
            printf("Digite o nome da tabela: ");
            scanf("\n");
            fgets(nome_tabela, 51, stdin);
            
            printf("Digite a chave primária da linha: ");
            scanf("%i", &chave_primaria);

            apagarLinha();
            break;
        
        case 0:
            break;

        default:
            printf("Selecione uma opção válida\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}