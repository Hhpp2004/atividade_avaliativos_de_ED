#include <stdio.h>
#include <stdlib.h>

struct l
{
    int num;
    struct l *prox;
};

typedef struct l lista;

lista *cria_no(int num)
{
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->num = num;
    novo->prox = NULL;
    return novo;
}

lista *entrada_fim(int num, lista *l)
{
    lista *novo = cria_no(num);
    lista *aux = l;
    if (l == NULL)
    {
        l = novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return l;
}

lista *interssecao(lista *l1, lista *l2)
{
    lista *l3 = NULL;
    int num;
    for (lista *aux2 = l2; aux2 != NULL; aux2 = aux2->prox)
    {
        for (lista *aux = l1; aux != NULL; aux = aux->prox)
        {
            if (aux->num == aux2->num)
            {
                num = aux->num;
                l3 = entrada_fim(num, l3);
            }
        }
    }
    return l3;
}

lista* uniao(lista *l1, lista *l2)
{
    lista *l3 = NULL;
    lista *aux = l1, *aux2 = l2;
    while(aux != NULL || aux2 != NULL)
    {        
        while(aux != NULL && (aux2 == NULL || aux->num < aux2->num))
        {
            l3 = entrada_fim(aux->num,l3);
            aux = aux->prox;            
        }
        while(aux2 != NULL && (aux == NULL || aux->num > aux2->num))
        {
            l3 = entrada_fim(aux2->num,l3);
            aux2 = aux2->prox;
        }
        while(aux != NULL && aux2 != NULL && aux->num == aux2->num)
        {
            l3 = entrada_fim(aux->num,l3);
            aux = aux->prox;
            aux2 = aux2->prox;
        }
    }
    return l3;
}


void mostra(lista *l)
{
    lista *aux = l;
    while (aux != NULL)
    {
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}

int main(void)
{
    lista *l1 = NULL;
    lista *l2 = NULL;
    lista *l3 = NULL;
    lista *l4 = NULL;
    int qtd1, qtd2;
    int num;

    scanf("%i %i", &qtd1, &qtd2);

    for (int i = 0; i < qtd1; i++)
    {
        scanf("%i", &num);
        l1 = entrada_fim(num, l1);
    }

    for (int i = 0; i < qtd2; i++)
    {
        scanf("%i", &num);
        l2 = entrada_fim(num, l2);
    }
    l3 = interssecao(l1, l2);
    l4 = uniao(l1, l2);
    mostra(l3);
    printf("\n");
    mostra(l4);
    printf("\n");
    return 0;
}