#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char nome[30];
    char cor[10];
    int tropa;
}Territorio;


//-Protótipos de função
Territorio* cadastrarTerritorios(int quantidade);
void exibirTerritorio(int quantidade, Territorio *mapa);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa);


int main(){

    //-utiliza o tempo atual para garantir a geração de números aleatorios
    srand(time(NULL));

    //-inicialização do mapa vazio
    Territorio* mapa = NULL;
    int QTD;

    //-coleta a quantidade de Territorios que o usuario deseja cadastrar
    printf("Digite a quantidade de Territórios que deseja:");
    scanf("%d", &QTD);
    getchar();

    //-chamada da função cadastrar territorio respeitando a quantia informada pelo usuario
    mapa = cadastrarTerritorios(QTD);

    //-Chamada da função exibirTerritorios
    exibirTerritorio(QTD,mapa);

    //-criação de um loop para identificar o que o usuario decidira fazer apos o cadastro
    int opcao;
    do{
        printf("Deseja realizar uma batalha?(1-sim / 2-não 0-sair):\n");
        scanf("%d", &opcao);
        getchar();

        //-Codigo executado em caso de ataque
        if(opcao == 1){

            //-índices utilizados para identificar qual territorio ira atacar e qual ira defender
            int indiceAtacante, indiceDefensor;
            //-exibi os status dos territorios antes do ataque ocorrer
            exibirTerritorio(QTD,mapa);
            //-Atribuição dos valores informados pelo usuario ao índice correspondente
            printf("Escolah o número do território atacante:");
            scanf("%d", &indiceAtacante);

            printf("Escolha o número do território defensor:");
            scanf("%d", &indiceDefensor);

            //chamada da função atacar com os parametros correspondente a atacante e defensor
            // -1 é utilizado para que o acesso ao index seja coreto pois as posições no vetor iniciam em 0
            atacar(&mapa[indiceAtacante -1], &mapa[indiceDefensor - 1]);
        }
        //-Exibe os territorios apos o ataque
        exibirTerritorio(QTD,mapa);
    //-finaliza o jogo 
    } while(opcao != 0);

    printf("==================");
    printf("\nSaindo do jogo\n");
    printf("==================");
    printf("\n\n");

    //-chama a função liberarMemoria 
    liberarMemoria(mapa);
 
    printf("Memória liberada com sucesso. Fim de jogo.");
    return 0 ;
}


//-função responsavel pelos cadastros de territorios
Territorio* cadastrarTerritorios(int quantidade){
    Territorio* territorio = (Territorio*)calloc(quantidade,sizeof(Territorio));
    for(int i = 0; i < quantidade; i++){
        printf("Cadastro: %d\n", i+1);
        
        printf("Digite o nome do território:\n");
        fgets(territorio[i].nome, 30, stdin);
        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = '\0';
  

        printf("Dgite a cor do seu território:\n");
        fgets(territorio[i].cor, 10, stdin);
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0';
       

        printf("Digite a quantidade de tropas:\n");
        scanf("%d", &territorio[i].tropa);
        getchar();

    }
    return territorio;
}


//-função responsavel por percorrer o vetor e retornar os valores cadastrados
void exibirTerritorio(int quantidade, Territorio *mapa){
    printf("\n\n------MAPA DOS TERRITóRIOS----\n\n");
    for( int i = 0; i < quantidade; i++){
        printf("Territorio %d:\n", i + 1);
        printf("-Nome: %s\n", mapa[i].nome);
        printf("-Dominado por: Exército %s\n", mapa[i].cor);
        printf("-Tropa: %d\n", mapa[i].tropa);
        printf("====================================\n\n");
    }
}


//- sistema de ataques
void atacar(Territorio *atacante, Territorio *defensor) {
    if(strcmp(atacante -> cor,defensor-> cor) ==0){
        printf("\nNão é possível atacar um territorio da mesma cor!\n");
        return;
    }else if (atacante -> tropa <=0){
        printf("\nO atacante precisa possuir ao menos uma tropa selecione um territorio q cumpra os requisitos:\n\n");
        return ;
    }
    
    int dadoAtacante = (rand()%6) + 1;
    int dadoDefensor = (rand()%6) + 1;

    printf("\n Ataque de %s  Contra %s\n", atacante ->nome, defensor->nome);

    printf("Dado do atacante %d || Dado do defensor %d\n\n", dadoAtacante, dadoDefensor);
    if(dadoAtacante > dadoDefensor){
        printf("Atacante venceu!\n");
        printf("O defensor perdeu uma de suas tropas\n");
        defensor -> tropa -= 1;
    }else{
        printf("Defensor venceu\n");
        printf("O atacante perdeu 2 de suas tropas\n");
        atacante -> tropa -=2;

        if(atacante->tropa <=0){
            printf("O defensor venceu a rodada!\n");
            strcpy(atacante->cor, defensor->cor);
            atacante -> tropa = defensor -> tropa /2;
        }
        if(defensor->tropa <=0){
            printf("O atacante venceu a rodada!\n");
            strcpy(defensor->cor, atacante->cor);
            defensor->tropa =atacante->tropa;
        }
    }
}

//-função para libera a memoria
void liberarMemoria(Territorio *mapa){
    free(mapa);
}