/*bibliotecas do projeto*/
#include "As.h"
#include "Funcoes_aux.h"
#include "Ficheiros_dados.h"
#include "Grafo.h"
#include "Fila.h"
/*bibliotecas*/
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Filaini(int vertices)
{
    fila = (int **)malloc(vertices * sizeof(int *));
    if (fila == NULL)
    {
        exit(0);
    }
    for (int i = 0; i < vertices; i++)
    {
        fila[i] = (int *)calloc(1, 2 * sizeof(int));
        if (fila[i] == NULL)
        {
            exit(0);
        }
        tamanho = vertices;
        Free = 0;
    }
}
void Filainsert(int no, int custo)
{
    if ((Free + 1) <= tamanho)
    {
        fila[Free][0] = no;
        fila[Free][1] = custo;
        Fixup();
        Free++;
    }
}

void Fixup()
{
    for (int *aux, livre = Free; livre > 0 && fila[(livre - 1) / 2][1] > fila[livre][1]; livre = (livre - 1) / 2)
    {
        aux = fila[livre];
        fila[livre] = fila[(livre - 1) / 2];
        fila[(livre - 1) / 2] = aux;
    }
}

void FixDown()
{
    int N = Free - 1, child, idx = 0;
    int *aux;
    // printf("\nFree:%d\n", Free);
    while ((idx * 2) < N)
    {
        // printf("idx*2->%d N->%d\n", (idx * 2), (N));
        child = (idx * 2) + 1;
        aux = fila[idx];
        if (child == N || fila[child][1] < fila[child + 1][1])
        {
            if (fila[idx][1] < fila[child][1])
            {
                break;
            }
            fila[idx] = fila[child];
            fila[child] = aux;
            idx = child;
        }
        else
        {
            if (fila[idx][1] < fila[child + 1][1])
            {
                break;
            }
            fila[idx] = fila[child + 1];
            fila[child + 1] = aux;
            idx = child + 1;
        }
    }
}

int Proximo_na_fila()
{
    int *aux;
    Free--;
    aux = fila[0];
    fila[0] = fila[Free];
    fila[Free] = aux;
    FixDown();
    return fila[Free][1];
}

void freefila()
{
    for (int i = 0; i < tamanho; i++)
    {
        free(fila[i]);
    }
    free(fila);
}