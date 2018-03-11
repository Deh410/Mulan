#include <stdio.h>
#define MAX 10

typedef struct{

    int chave;

}ALUNO;

typedef struct{

    ALUNO vetor[MAX];
    int nroElem;

}LISTA;

void initLista(LISTA * lista){ //recebe o ponteiro da lista

    lista -> nroElem = 0;

}

int excluir(LISTA * lista, int cl){         //Suavis works perfectly

    int i;
    int end = buscarChave(lista, cl);

    if(end ==-1){
    return 11;
    }

    if(end != (lista->nroElem-1)){      //roda o if se nao for o ultimo elemento
        for(i=end;i<lista->nroElem;i++){
            lista->vetor[i] = lista->vetor[i+1];
        }
    }
    if(end == lista->nroElem){
        lista->vetor[end].chave = 0;//assumindo que quando for excluido o ultimo elemento ele vira zero
        return 5;
    }
    lista->nroElem--;
    return 5;

}

int buscarChave(LISTA * lista, int cl){ //works perfectly

    int i;
    for(i=0;i<lista->nroElem;i++){

        /*printf("\n\t*%d*", i);
        printf("\n%d",lista->vetor[i].chave);
        */
        if(lista -> vetor[i].chave == cl){
            return i;
        }
        if(lista -> vetor[i].chave > cl){
            return -1;
        }

    }
    return -1;
}

int insercaoOrdenada(LISTA * lista, int cl, int p){
    if(lista -> nroElem == MAX) return 12;
    int end = buscarChave(lista,cl);
    if(end != -1) return 13;
        int i;
            for(i=lista->nroElem;i>=p;i--){        //nao precisa tirar um de nroElem pq ja ta reduzido pela exclusao
                lista->vetor[i+1] = lista->vetor[i];
                if(i == p){
                lista->vetor[i].chave = cl;
                lista->nroElem++;
                return 14;
                }
            }
        return 15;
}

void exibirVetor(LISTA * lista){    //like a charm

    int j;
    for(j=0;j<lista->nroElem;j++){
        printf("\n\nValor do vetor em %d = %d",j,lista->vetor[j].chave);
    }

}

int main(){

    int x , y, z,p;
    LISTA lista;        //inicializa a lista em LISTA
    initLista(&lista);  //envia a ref de lista
    lista.nroElem = 3;
    //printf("\n%d",lista.nroElem);
    lista.vetor[2].chave = 25;
    lista.vetor[0].chave = 9;
    lista.vetor[1].chave = 14;
    printf("\nNumero a ser buscado: ");
    scanf("%d", &x);
    int end = buscarChave(&lista, x);
    //printf("\nValor do retorno do buscar: %d", end);
        if(end != -1){
            printf("\nEncontrado '%d' na posicao %d",x, end);
        }
        if(end == -1){
            printf("\nValor nao encontrado");
        }
    printf("\n\nNumero a ser excluido: ");
    scanf("\n%d", &y);

    int exc = excluir(&lista, y);
        if(exc == 11){
            printf("\nValor a ser excluido nao encontrado");
        }
        if(exc == 5){
            printf("\nValor %d excluido com exito", y);
        }

    //printf("\n%d", lista.nroElem);
    exibirVetor(&lista);
    printf("\n\nValor a ser inserido : ");
    scanf("\n%d", &z);
    printf("\n\nPosicao a ser inserida : ");
    scanf("\n%d", &p);
    int ins = insercaoOrdenada(&lista, z, p);
        if(ins == 12){
            printf("\nVetor esta cheio");
        }
        if(ins == 13){
            printf("\nNao foi possivel inserir");
        }
        if(ins == 14){
            printf("\nO valor %d foi inserido com sucesso", z);
        }
        if(ins == 15){
            printf("\nUeh", z);
        }
    exibirVetor(&lista);
    return 0;

}
