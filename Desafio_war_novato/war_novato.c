#include <stdio.h>
#include <string.h>

//-Define a quantidade limite de cadastros
#define QTD_CADASTRO 5


//-struct Territorios com as caracteristicas desejadas
struct Territorio{
    char nome[30];
    char cor[10];
    int tropa;
};

//-Estrutura principal
int main(){

     //Chamada da struct territorio respeitando o limite de cadastros.
    struct Territorio territorio[QTD_CADASTRO];                    
    int i;
    //-Loop de repetição respeitando a quantidade de cadastros
    printf("===== Sistema de cadastro de territórios ====\n\n");
    for(i = 0; i < QTD_CADASTRO; i++){
        printf("Cadastro %d:\n",i + 1);

        printf("Digite o nome da Território:\n");
        fgets(territorio[i].nome, 30, stdin);

        printf("Digite a Cor da sua Tropa:\n");
        fgets(territorio[i].cor, 10, stdin);

        printf("Digite a quantidade da sua tropa:\n");
        scanf("%d", &territorio[i].tropa);

        territorio[i].nome[strcspn(territorio[i].nome,"\n")] = '\0';
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0';

        //-Espera o usuário pressionar Enter
        getchar();                                              

        printf("\n");
    }
    //-Exibição dos dados cadastrados
    printf("=======================================\n");
    printf("-----  MAPA DO MUNDO -ESTADO ATUAL -----\n");
    printf("=======================================\n\n");
    for(i = 0 ; i < QTD_CADASTRO; i++){
        printf("Territorio %d:\n", i + 1);
        printf("-Nome: %s", territorio[i].nome);
        printf("-Dominado por: Exercito %s", territorio[i].cor);
        printf("-Tropa: %d\n", territorio[i].tropa);
        printf("====================================\n\n");
    }
    return 0;
}
