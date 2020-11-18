#ifndef COLA360_H_INCLUDED
#define COLA360_H_INCLUDED
typedef struct {
    int max; // tama�o de la cola
    int h;
    int t;
    Documento *arrCola; //arreglo cola
} Cola;

Cola *crearCola(int max);
int validarEspacio(Cola cola);
void insertar(Cola *cola, Documento documento);
void listar(Cola cola);
int validarVacio(Cola cola);
Documento borrar(Cola *cola);

#endif // COLA360_H_INCLUDED
