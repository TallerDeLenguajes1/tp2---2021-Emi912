#include <stdio.h>
#include <stdlib.h>
#define filas 15

int main(){
    
    int c = rand()% 11 + 5;
    int *par = (int *)malloc(filas * sizeof(int));
    int ** matriz = (int **)malloc(c * sizeof(int *));

    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(filas * sizeof(int));
        for (int j = 0; j < c; j++)
        {
            matriz[i][j] = rand() % 900 + 99;
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < filas; i++)
    {
        int auxpares = 0;
        for (int j = 0; j < c; j++)
        {
            if (matriz[i][j] % 2 == 0)
            {
                auxpares++;
            }
        }
        printf("La fila [%d] tiene %d pares \n", i + 1, auxpares);
        *(par + i) = auxpares;
    }
    
    //Muestro el vector formado con la cantidad de pares
    printf(" \nVector formado por la cantidad de pares \n");
    for (int i = 0; i < filas; i++)
    {
        printf("  %d  ", *(par + i));
    }
    
free(matriz);
free(par);


    return 0;   
}