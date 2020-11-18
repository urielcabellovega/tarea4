#ifndef IMPRESORA_H_INCLUDED
#define IMPRESORA_H_INCLUDED
#define N_HOJAS 20
#define N 4
typedef struct
{
    char *nombre;
    char *tipodoc;
    int nhojas;
    int hojactual;
}Documento;
Documento *creardocumento();
void capturar_datos(Documento *documento);
void capturar_datos(Documento *documento);
void listar_documento(Documento documento);
void imprimiendo_datos(Documento *documento, int *hojas);



#endif // IMPRESORA_H_INCLUDED
