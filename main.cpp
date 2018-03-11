#include <stdio.h>
#define MAX 10

tydedef struct{

    int chave;
    int prox;

}REGISTRO;

typedef struct{

    REGISTRO A[MAX];
    int inicio;
    int dispo;

}  LISTA_LIG_EST;

void inicializar(LISTA_LIG_EST * l){    //falta definir se no for fica o MAX ou MAX-1

    l->inicio = -1;
    l->dispo  = 0;
    int i;
    for(i=0;i<MAX;i++){
        l_>A[i].prox = i+1;
    }
    l->A[MAX].prox=-1;

}

int contarElementos(LISTA_LIG_EST *l){

    int cont = 0;
    int i = l->inicio;
    while(i!=-1){
        cont++;
        printf("\n%d",l->A[i].chave);
        i=l->A[i].prox;
    }
    return cont;

}

int n-esimoElemento(LISTA_LIG_EST * l, int n){

    int cont = 0;
    int i = l->inicio;
    while(i!=-1){
        cont++;
        if(cont == n) return i;
        i=l->A[i].prox;
    }
    return -1;

}

int buscaChave(LISTA_LIG_EST * l, int ch, int * ant){

    *ant = -1;      //se for encontrado logo de cara o anterior nao sera ninguem
    int i = l->inicio;
    while(i!=-1){
        if(l->A[i].chave == ch) return i;
        if(l->A[i].chave > ch) return -1;
        *ant = i;
        i=l->A[i].prox;
    }
    return -1;

}

int main(){

    LISTA_LIG_EST l;
    int anterior;
    int chave = 10;
    int end = busChave(&l,chave,&anterior);
    return 0;

}
