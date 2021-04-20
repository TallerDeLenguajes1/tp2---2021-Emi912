#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pc
{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
};

struct pc funciondevuelve(struct pc dato, char *tipo);
void cargarpcs(struct pc *dato, int cantidad, char *tipo);
void mostrarpcs(struct pc *dato, int cantidad, char *tipo);
void pcvieja(struct pc *dato, int cantidad);
void masrapida(struct pc *dato, int cantidad);

int main(){
char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

int cantidad;
struct pc *arreglodin;
struct pc computadora;
printf("Ingrese la cantidad de pcs que va a ingresar");
scanf("%d", &cantidad);

arreglodin = (struct pc *)malloc(cantidad * sizeof(struct pc));
computadora = funciondevuelve(computadora, &tipos[0][0]);

cargarpcs(arreglodin, cantidad, &tipos[0][0]);
mostrarpcs(arreglodin, cantidad, &tipos[0][0]);
pcvieja(arreglodin, cantidad);
masrapida(arreglodin, cantidad);



    return 0;
}

struct pc funciondevuelve(struct pc dato, char *tipo){
    dato.anio = rand() % 17 + 2000;
    dato.cantidad = rand() % 5 + 1;
    dato.velocidad = rand() % 4 + 1;
    dato.tipo_cpu = (char*)malloc(sizeof(char) * 10);
    strcpy(dato.tipo_cpu, tipo + rand() % (6 + 1) * 10);

return dato;
}

void cargarpcs(struct pc *dato, int cantidad, char *tipo){
    for (int i = 0; i < cantidad; i++)
    {
        (dato + i)->anio = rand() % 17 + 2000;
        (dato + i)->cantidad = rand() % 5 + 1;
        (dato + i)->velocidad = rand() % 4 + 1;
        (dato + i)->tipo_cpu = (char*)malloc(sizeof(char) * 10);
        strcpy((dato+i)->tipo_cpu, tipo + rand() % (6 + 1) * 10);
    }
    
}

void mostrarpcs(struct pc *dato, int cantidad, char *tipo){
    for (int i = 0; i < cantidad; i++)
    {
        printf("///////// PC ///////// \n");
        printf("Anio de fabricacion: %d\n", (dato + i)->anio);
        printf("Cantidad de nucleos: %d\n", (dato + i)->cantidad);
        printf("Velocidad en GHZ: %d\n", (dato + i)->velocidad);
        printf("Tipo de cpu: %s\n", (dato + i)->tipo_cpu);
    }
}


void pcvieja(struct pc *dato, int cantidad){
    int aux = 9000;
    int aux2;
    for (int i = 0; i < cantidad; i++)
    {
        if (aux > (dato+i)->anio)
        {
        aux = dato->anio + i;
        aux2 = i;
        }
    }

    printf("\n///////// PC VIEJA ///////// \n");
    printf("Anio de fabricacion: %d\n", (dato + aux2)->anio);
    printf("Cantidad de nucleos: %d\n", (dato + aux2)->cantidad);
    printf("Velocidad en GHZ: %d\n", (dato + aux2)->velocidad);
    printf("Tipo de cpu: %s\n", (dato + aux2)->tipo_cpu);
}

void masrapida(struct pc *dato, int cantidad){
int aux = 0;
int aux2;

for (int i = 0; i < cantidad; i++)
{
    if (aux < (dato+i)->velocidad)
    {
        aux = (dato+i)->velocidad;
        aux2 = i;
    }
}
    printf("\n///////// PC MAS RAPIDA ///////// \n");
    printf("Anio de fabricacion: %d\n", (dato + aux2)->anio);
    printf("Cantidad de nucleos: %d\n", (dato + aux2)->cantidad);
    printf("Velocidad en GHZ: %d\n", (dato + aux2)->velocidad);
    printf("Tipo de cpu: %s\n", (dato + aux2)->tipo_cpu);
}