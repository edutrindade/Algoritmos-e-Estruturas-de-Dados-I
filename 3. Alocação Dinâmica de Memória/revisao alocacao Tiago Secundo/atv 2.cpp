#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include<stdlib.h>


int** alocarMatriz(int Linhas,int Colunas){

  int i,j;

  int **m = (int**)malloc(Linhas * sizeof(int*));

  for (i = 0; i < Linhas; i++){
       m[i] = (int*) malloc(Colunas * sizeof(int));
       for (j = 0; j < Colunas; j++){
            m[i][j] = 0;
       }
  }
return m;
}

void liberarMatriz(int ** mat){
    free(mat);
}



main(){

    int ** m = alocarMatriz(3,3);

    int i,j;

    for ( i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3; j++){
            scanf("%d", &m[i][j]);
        }
    }

    for ( i = 0 ; i < 3 ; i++){
            printf("\n");
        for(j = 0 ; j < 3; j++){
            printf("[%d]", m[i][j]);
        }
    }

    liberarMatriz(m);

}