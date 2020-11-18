#include <stdio.h>
#include <stdlib.h>
#include "impresora.h"
#include "cola360.h"

Cola *crearCola(int max) {
    Cola *nuevaCola;
    //crear la cola y el arreglo
    nuevaCola = (Cola *)malloc(sizeof(Cola));
    nuevaCola->arrCola = (Documento *)calloc(max,sizeof(Documento));
    //INICIALIZAR
    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t= -1;
    return nuevaCola;
}

int validarEspacio(Cola cola){
    if ((cola.h==0 && cola.t == cola.max-1) || (cola.t+1 == cola.h))
    {
        printf("no hay espacio");
        return 0;
    }
    return 1;
}

void insertar(Cola *cola, Documento documento) {
    if (cola->h ==-1)
        cola->h= 0;//INICIO DE LA FILA

       if(cola->t == cola->max-1)
       cola->t = -1;

    cola->t++;
    cola->arrCola[cola->t]=documento;
}

void listar(Cola cola){
   int i;
   printf("\nCOLA:");
   if (!validarVacio(cola)){
       if (cola.h <= cola.t){
       for (i=cola.h; i<=cola.t ; i++)
       {
           printf("\n%d",i+1);
           listar_documento(cola.arrCola[i]);

       }

       }else {
       for (i=cola.h; i<cola.max; i++)
       {
           printf("\n%d",i+1);
           listar_documento(cola.arrCola[i]);
       }

       for (i=0; i<=cola.t; i++)
       {
            printf("\n%d",i+1);
            listar_documento(cola.arrCola[i]);
       }
   }
   }
   else
        printf("  No hay datos...");
}
int validarVacio(Cola cola)
{
    return cola.h == -1;
}
Documento borrar(Cola *cola)
{
    Documento aux=cola->arrCola[cola->h];
    if (cola->h == cola->t)
    cola->h = cola->t = -1;
    else if (cola->h == cola->max-1)
    cola->h = 0;
    else
    cola->h++;
    return aux;
}


