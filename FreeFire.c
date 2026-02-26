//nivel novato free fire

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criando a struct do cadastro
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item_mochila;

// Função para adicionar item
void adicionar_item(Item_mochila *mochila, int *num_itens) {

    if (*num_itens >= 10) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("Digite o nome do item: ");
    scanf("%29s", mochila[*num_itens].nome);

    printf("Digite o tipo do item: ");
    scanf("%19s", mochila[*num_itens].tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &mochila[*num_itens].quantidade);

    (*num_itens)++;

    printf("Item adicionado com sucesso!\n");
}

// Remover item da mochila
void remover_item(Item_mochila *mochila, int *num_itens) {
    char nome_remover[30];
    int i, j;

    printf("Digite o nome do item a ser removido: ");
    scanf("%29s", nome_remover);

    for (i = 0; i < *num_itens; i++) {
        if (strcmp(mochila[i].nome, nome_remover) == 0) {

            for (j = i; j < *num_itens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*num_itens)--;

            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item nao encontrado!\n");
}

// Exibir itens
void exibir_itens(Item_mochila *mochila, int num_itens) {
    if (num_itens == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    printf("---------------------------------------------\n");
    printf("||  SUA MOCHILA TEM OS SEGUINTES ITENS:     ||\n");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < num_itens; i++) {

        printf("\nNome: %s || Tipo: %s || Quantidade: %d \n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
               if (i == num_itens - 1) {
                   printf("---------------------------------------------\n");
               }
    
    }
}

// Buscar item (parcial) - essa função permite buscar digitando parte do nome!
void buscar_item(Item_mochila *mochila, int num_itens) {
    char nome_buscar[30];
    int encontrou = 0;

    printf("Digite o nome (ou parte do nome): ");
    scanf("%29s", nome_buscar);

    for (int i = 0; i < num_itens; i++) {
        if (strstr(mochila[i].nome, nome_buscar) != NULL) {

            printf("\nItem encontrado!\n");
            printf("Nome: %s, Tipo: %s, Quantidade: %d\n",
                   mochila[i].nome,
                   mochila[i].tipo,
                   mochila[i].quantidade);

            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("Nenhum item corresponde a essa busca.\n");
}

//aplicando as funções e o menu
int main() {
    Item_mochila mochila[10];
    int num_itens = 0;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Exibir itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_item(mochila, &num_itens);
                break;
            case 2:
                remover_item(mochila, &num_itens);
                break;
            case 3:
                exibir_itens(mochila, num_itens);
                break;
            case 4:
                buscar_item(mochila, num_itens);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
