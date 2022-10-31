#include<stdio.h>
#include"ex4-fila-TAD.h"
#include<stdlib.h>

int tamanho_fila(fila A);

struct no
{
    struct pacientes dados;
    struct no *prox;
};

// funcao para criar uma lista dinamica
fila cria_fila()
{
    return NULL;
}

// verifica se a lista esta vazia
int fila_vazia(fila A)
{
    if(A == NULL)
    {
        return 1;
    }

   return 0;
}

int remove_ordenada(fila* A, struct pacientes *elem)
{
    if(fila_vazia(*A) == 1) return 0;

    fila aux = *A;          // percorre
    fila aux1 = *A;                 // guarda antecessor a ser removido

    if(aux == *A && aux->prox == *A)        // caso fila com 1 elemento
    {
        *elem = aux->dados;
        *A = NULL;
        return 1;
    }

    while(aux->prox != *A)
    {
        if(aux->prox->dados.gravidade > aux1->prox->dados.gravidade)
        {
            aux1 = aux;
        }
        aux = aux->prox;
    }

    if(aux->prox==*A)
    {
        if(aux->prox->dados.gravidade > aux1->prox->dados.gravidade)
        {
            aux1 = aux;
        }
    }

    *elem = aux1->prox->dados;
    fila aux2;

    if(aux1->prox == *A)        // tirar ultimo
    {
        aux2 = aux1->prox;
        aux1->prox = aux1->prox->prox;
        *A = aux1;
    }

    else                        // tirar resto
    {
        aux2 = aux1->prox;
        aux1->prox = aux1->prox->prox;
    }
    free(aux2);
    return 1;
}

// insere no final da lista, ou seja, a lista aponta para um novo nó e a lista deve ser ajustada
int insere_final(fila *A, struct pacientes elem)
{
    fila N = (fila)malloc(sizeof(struct no));
    if(N == NULL) return 0;

    N->dados = elem;

    if(fila_vazia(*A)==1)
    {
        N->prox = N;
        *A = N;
    }
    else
    {
        N->prox =(*A)->prox;
        (*A)->prox = N;
        *A = N;
    }
    return 1;
}

// apaga e libera a lista
int apaga_fila(fila *A)
{
    free(*A);
    A = NULL;
    return 1;
}

int get_elem_pos(fila A, int pos, struct pacientes *elem)         // obtem elementos da lista
{
    if(fila_vazia(A)==1)
    {
        return 0;
    }
    int tam;
    tam = tamanho_fila(A);

    if(pos>tam || pos<=0)
    {
        return 0;
    }

    fila aux = A;
    int i;
    aux = aux->prox;

    for(i=1; i<pos; i++)
    {
        aux = aux->prox;
    }
    *elem = aux->dados;

    return 1;
}

int esvazia_fila(fila *A)
{
    if(fila_vazia(*A)==1)
    {
        return 0;
    }

    fila aux = (*A)->prox;
    fila aux1;
    while(aux->prox != *A)
    {
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    *A = NULL;
    return 1;
}

// retorna o tamanho da lista atraves de um contador
int tamanho_fila(fila A)
{
    if(fila_vazia(A) == 1)
    {
        return 0;
    }

    int cont = 1;

    fila aux = A;

    while(aux->prox != A)
    {
        cont++;
        aux = aux->prox;
    }

    return cont;
}
