#include <stdio.h>
#include <windows.h>
#include "impresora.h"


Documento *creardocumento()
{
    Documento *documento;
    documento =(Documento *)malloc(1*sizeof(Documento));
    documento->nombre=(char *)malloc(30*sizeof(char));
    documento->tipodoc= (char *)malloc(30*sizeof(char));

}

void capturar_datos(Documento *documento)
{
    fflush(stdin);
    printf("\nNombre del documento:\n");
    gets(documento->nombre);
    fflush(stdin);
    printf("\nCual es el numero de hojas del documento??\n");
    scanf("%d",&documento->nhojas);
    fflush(stdin);
    printf("\nCual es el tipo de documento\n");
    gets(documento->tipodoc);
    fflush(stdin);
    documento->hojactual=1;

}
void imprimiendo_datos(Documento *documento, int *ptr_num)
{
    int i;

    printf("\n-------------------------------------------\n");
    if((documento->nhojas)>4)
    {

        for(i=0;i<4;i++)
        {
            listar_documento(*documento);
            Sleep(1000);
            documento->nhojas--;
            documento->hojactual++;
            (*ptr_num )++;
            if((*ptr_num )==100)
            {
                return 0;
            }


        }
        printf("\nSe pasara al siguiente documento debido a que ya se imprimieron cuatro hojas del documento actual\n");
    }
    else
    {
        for(i=0;i<=documento->nhojas+2;i++)
        {
            Sleep(1000);
            printf("\nDocumento: %s\t%s\thoja actual:%d\thojas restantes:%d\n",documento->nombre,
            documento->tipodoc,documento->hojactual,documento->nhojas);
            documento->nhojas--;
            documento->hojactual++;
            (*ptr_num )++;
            if((*ptr_num )==100)
            {
                return 0;
            }
        }
        printf("\nSe termino de imprimir el documento\n");
    }
    printf("\n-------------------------------------------\n");
}

void listar_documento(Documento documento)
{
    printf("Documento: %s\t%s\thoja actual:%i\thojas restantes:%d\n",
           documento.nombre,documento.tipodoc,documento.hojactual,documento.nhojas);

}

