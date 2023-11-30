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

void criarTabela(Tabela tabela){
    FILE *tabelas;
    
    tabelas = fopen("tabelas.txt", "a");
    if(tabelas == NULL){
        printf("Ocorreu um erro ao criar a tabela");
        printf("O erro foi: %s\n", strerror(errno));
    } else {
        printf("Informe o nome da tabela: ");
        scanf("%s", tabela.nome_tabela);  

        fprintf(tabelas, "Tabela:%s", tabela.nome_tabela);

        printf("Informe quantas colunas deseja inserir: ");
        scanf("%i", &tabela.n_colunas);

        fprintf(tabelas, " Colunas:%i\n", tabela.n_colunas);

        Coluna coluna[tabela.n_colunas];

        fprintf(tabelas, "|");

        for(int i=0; i<tabela.n_colunas; i++){
            if (i == 0)
            {
                printf("informe o nome da coluna com a chave primária: ");
                scanf("%s", coluna[i].nome_coluna);
                fprintf(tabelas, " i %s |", coluna[i].nome_coluna);
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

                fprintf(tabelas, " %c %-10s |", coluna[i].tipo_coluna, coluna[i].nome_coluna);
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

int procurarTabela(char nome_tabela[50]){
    FILE *tabelas;
    
    Tabela tabela;
    int achou_tabela=0;
    char search[100];
    sprintf(search, "Tabela:%s", nome_tabela);
    
    tabelas = fopen("tabelas.txt", "r");

    if (tabelas == NULL) {
        printf("Erro na leitura do arquivo");
        printf("O erro foi: %s\n", strerror(errno));
    } else {

        while (fscanf(tabelas, "%99s", tabela.nome_tabela) != EOF) {


            if (strcmp(tabela.nome_tabela, search) == 0) {
                printf("Achou a tabela: %s\n", nome_tabela);
                achou_tabela = 1;
                break;  
            }
        }

        if (achou_tabela==0) {
            printf("Tabela nao encontrada.\n");
        }
        fclose(tabelas);
    }

    return achou_tabela;
}

void criarNovaLinha(char nome_tabela[50]){
    int achou_tabela = procurarTabela(nome_tabela);

    if (achou_tabela == 0) {

        printf("f\n");
        return;
    }

    // FILE *tabelas = fopen("tabelas.txt", "a");

    // if (tabelas == NULL) {
    //     printf("Erro na abertura do arquivo para adicao: %s\n", strerror(errno));
    //     return;
    // }

    // printf("Informe os valores para as colunas:\n");

    // char valores_colunas[tabela.n_colunas][50];

    // for (int i = 0; i < tabela.n_colunas; i++) {
    //     printf("%s: ", tabela.nome_tabela);
    //     scanf("%s", valores_colunas[i]);
    // }

    // // Escreve a nova linha no arquivo
    // fprintf(tabelas, "%s", tabela.nome_tabela);

    // for (int i = 0; i < tabela.n_colunas; i++) {
    //     fprintf(tabelas, " %s", valores_colunas[i]);
    // }

    // fprintf(tabelas, "\n");

    // printf("Nova linha adicionada na tabela: %s\n", nome_tabela);

    // fclose(tabelas);

    
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
    Tabela tabela;

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
            printf("Informe a tabela que deseja adicionar uma linha: ");
            scanf("%s", nome_tabela);
            criarNovaLinha(nome_tabela);
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