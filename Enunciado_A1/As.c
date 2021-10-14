/*bibliotecas do projeto*/
#include "As.h"
#include "Funcoes_aux.h"
#include "Ficheiros_dados.h"
/*bibliotecas do projeto*/
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int FA1 (int** maze, int l, int c, int lin, int col) { /*identifica o tipo da cécula de indicada*/
    int A1= out(l, c, lin, col);    /*a função out vai retornar o numero da célula correspondente às coordenadas (l,c)*/    
    if(A1 != -2){
    A1 = maze[l][c];}
    return A1;
}

int FA2 (int** maze, int l, int c, int lin, int col) { /*indica se algum vizinho da célula indicada é uma célula branca*/
    if ((out(l, c, lin, col)==-2)) return -2;   /*verificação se a célula não está fora do tabuleiro*/
    /*verificação do tipo das células vizinhas e se estas cumprem a condição de ser branca*/
    if ((out(l+1, c, lin, col)!=-2 && maze[l+1][c]==0) || (out(l, c+1, lin, col)!=-2 && maze[l][c+1]==0) || (out(l-1, c, lin, col)!=-2 && maze[l-1][c]==0) || (out(l, c-1, lin, col)!=-2 && maze[l][c-1]==0)){ 
        return 1;}
    return 0;
}

int FA3 (int** maze, int l, int c, int lin, int col) { /*indica se algum vizinho da célula indicada é uma célula cizenta*/
    if ((out(l, c, lin, col)==-2)) return -2;   /*verificação se a célula não está fora do tabuleiro*/
    /*verificação do tipo das células vizinhas e se estas cumprem a condição de ser cizenta*/
    if ((out(l+1, c, lin, col)!=-2 && maze[l+1][c]>=1) || (out(l, c+1, lin, col)!=-2 && maze[l][c+1]>=1) || (out(l-1, c, lin, col)!=-2 && maze[l-1][c]>=1) || (out(l, c-1, lin, col)!=-2 && maze[l][c-1]>=1)){
    return 1;}
    return 0;
}

int FA4 (int** maze, int l, int c, int lin, int col) { /*indica se algum vizinho da célula indicada é uma célula preta*/
    if ((out(l, c, lin, col)==-2)) return -2;   /*verificação se a célula não está fora do tabuleiro*/
    /*verificação do tipo das células vizinhas e se estas cumprem a condição de ser preta*/
    if ((out(l+1, c, lin, col)!=-2 && maze[l+1][c]==-1) || (out(l, c+1, lin, col)!=-2 && maze[l][c+1]==-1) || (out(l-1, c, lin, col)!=-2 && maze[l-1][c]==-1) || (out(l, c-1, lin, col)!=-2 && maze[l][c-1]==-1)){
    return 1;}
    return 0;
}

int FA5 (int** maze, int l, int c, int lin, int col) { /*indica se a célula de entrada é quebrável*/
    if (out(l, c, lin, col)==-2) return -2;
    else if (maze[l][c]<=0) return -1;
    /*vê se as duas células vizinhas na vertical e depois na horizontal são brancas*/
    else if ((out(l-1, c, lin, col) != -2) && (out(l+1, c, lin, col)!=-2) && maze[l-1][c]==0 && maze[l+1][c]==0){
        return 1;}
    else if ((out(l, c+1, lin, col) !=-2) && (out(l, c-1, lin, col) !=-2) && maze[l][c-1]==0 && maze[l][c+1]==0){
        return 1;}
    else {
        return 0;}
}

 int FA6 (int** maze, int l, int c, int lin, int col, int l2, int c2,short fim){  /*para duas células de entrada a função indica se pertencem à mesma sala do labirinto*/
        maze[l][c] = -6;
        if(maze[l2][c2] != -6){
            /*utiliza a rescursividade para procurar um caminho livre da primeira célula à segunda, se encontrar quer dizer que pertence à mesma sala*/
            if((lin >= l+1) && (maze[l+1][c] == 0) && (fim == 0)){  /*cima*/
                fim = FA6(maze, l+1, c, lin, col, l2, c2, fim);}
            if((col >= c+1) && (maze[l][c+1] == 0 && fim == 0)){    /*direita*/
                fim = FA6(maze, l, c+1, lin, col, l2, c2, fim);
                }
            if((l >= 1) && (maze[l-1][c] == 0 && fim == 0)){        /*baixo*/
                fim = FA6(maze, l-1, c, lin, col, l2, c2,fim);
                }
            if((c >= 1) && (maze[l][c-1] == 0 && fim == 0)){        /*esquerda*/
                fim = FA6(maze, l, c-1, lin, col, l2, c2,fim);
                }
            if(fim==0){
                return 0;   /*não pertencem à mesma sala*/
                }
            else{
                return 1;   /*pertencem à mesma sala*/
            }
        }
        else {
            return 1;   /*as células são iguais e por isso pertencem à mesma sala*/
            }
 }