#include <stdio.h>
#include <stdlib.h>
struct elemento
{
char letra;
struct elemento *izq,*dcha;
};
typedef struct elemento nodo;
// Declaración de funciones - Funciones prototipo
char leer_caracter(void);
nodo * crear_nodo (char);
void inserta_nodo (nodo *,char);
void pre_orden(nodo *);
void in_orden(nodo *);
void post_orden(nodo *);
int main(void)
{
nodo *arbol=NULL;
char letra;
letra = leer_caracter();
while (letra!='.')
{
if (arbol==NULL)
 arbol=crear_nodo (letra);
else
 inserta_nodo (arbol,letra);

letra = leer_caracter();
}
printf ("Recorrido del árbol");
printf ("\nPre-Orden: ");
pre_orden (arbol);
printf ("\nIn-Orden: ");
in_orden(arbol);
printf ("\nPost-Orden: ");
post_orden (arbol);
printf ("\n");
system ("pause");
return 0;
}
// Lee un caracter desde el teclado limpiando el buffer
char leer_caracter(void)
{
char letra;
printf ("Introduzca un carácter (FIN=.):" );
fflush (stdin);
scanf ("%c",&letra);
fflush (stdin);
return letra;
}
// Crea un nodo en memoria heap (dinámica)
// Almacena el caracter en el campo correspondiente
// Establece las ramas a NULL
// Y devuelve la referencia al mismo
nodo * crear_nodo (char letra)
{
nodo *p;
p=(nodo*)malloc(sizeof(nodo));
if (p==NULL)
 printf ("Memoria dinámica insuficiente\n");
else
{
p->letra=letra;
p->izq=p->dcha=NULL;
}
return p;
}
// Función recursiva
// La estructura condicional determina si
// la función en esta llamada trabajará en la rama izquierda o en la derecha
// En cualquier de los dos casos la función recursiva se define así:
// Caso 1 - Solución inmediata - Fin de la recursividad
// Si la rama que corresponde está a NULL crea el nodo y enlaza en ella
// Caso 2 - Solución recursiva -
// Si la rama que le corresponde tiene un subárbol
// la solución consiste en insertar el nodo en ese subarbol (recursividad)
void inserta_nodo (nodo *p,char letra)
{
if (letra < p->letra)
{
if (p->izq == NULL)
 p->izq=crear_nodo(letra);
else
 inserta_nodo (p->izq,letra);
}
else
if (p->dcha == NULL)
 p->dcha=crear_nodo(letra);
else
 inserta_nodo (p->dcha,letra);
}
// Funciones recursivas para el recorrido de un árbol
void pre_orden(nodo *p)
{
if (p!=NULL)
{
printf ("%c ",p->letra);
pre_orden(p->izq);
pre_orden(p->dcha);
}
}
void in_orden(nodo *p)
{
if (p!=NULL)
{
in_orden(p->izq);
printf ("%c ",p->letra);
in_orden(p->dcha);
}
}
void post_orden(nodo *p)
{
if (p!=NULL)
{
post_orden(p->izq);
post_orden(p->dcha);
printf ("%c ",p->letra);
}
}
