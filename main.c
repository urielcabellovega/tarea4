#include <stdio.h>
#include <stdlib.h>
#include "impresora.h"
#include "cola360.h"
int main()
{
    int opcion,numero;
    Documento aux;
    int num = 0;
    int *ptr_num;
    ptr_num=&num;

    Cola *cola;
    cola =crearCola(N);
    Documento *undocumento;


    srand (time(NULL));

    do
    {
        opcion=desplegarMenu("\n1.- Mandar a imprimir\n2.-Seguir imprimiendo y listar la cola de impresion\n3.-Salir",3);
        switch(opcion)
        {
        case 1:

            if(validarEspacio(*cola))
                {

                    numero = rand() % 101;
                    if(numero<=50)
                    {
                        undocumento = creardocumento();
                        capturar_datos(undocumento);
                        insertar(cola,*undocumento);
                        listar(*cola);
                    }
                    else
                    {
                        printf("\nNo se puede generar la impresion, N mayor a 50\n");
                        undocumento=NULL;
                    }

                }

                else
                {
                    printf("\nNo hay espacio en la cola de impresion\n");


                }

            break;
        case 2:
            undocumento=NULL;


            break;
        default:
            opcion=3;
            undocumento=NULL;




            break;


        }

        if(undocumento!=NULL || !validarVacio(*cola))
        {
            aux = borrar(cola);
                if(aux.nhojas!=0)
                {
                    imprimiendo_datos(&aux,ptr_num);

                    printf("\nHojas :%d/100\n",*ptr_num);
                    if(aux.nhojas>0& *ptr_num<100)
                    {
                        insertar(cola,aux);
                        listar(*cola);
                    }

                    else
                    {
                        if(*ptr_num==100)
                        {
                            printf("\nNo hay hojas\n");
                            return 0;
                        }

                    }
                }

        }

    }while(opcion!=3);







    return 0;


}
