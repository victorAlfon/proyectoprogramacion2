//librerias de c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void gotoxy(int x, int y){//funcion para que funcion el cambio de coordenadas con gotoxy
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X=x;
	dWPos.Y=y;
	SetConsoleCursorPosition(hcon, dWPos);
}

enum MENU { OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7, OPC8, OPC9, OPC10, OPC11};//variableglobal para el switch del menu

FILE *arch;//variable global para manejo de archivos
int conteliminado=0;//para saber si ya existen productos eliminados
int contvendido=0;//para saber si ya existen productos vendidos

struct productos{//estructura principal (lista)
	int id;//variable para guardar las id
    char nombre[20];//variable para guardar el nombre del producto
    int cantidad;//variable para guardar la cantidad del producto
    char fechacad[9];//variable para guardar la fecha de caducidad
    char fechallegada[9];//variable para guardar la fecha de llegada
    struct productos *siguiente;//puntero para apuntar a el siguiente nodo
    struct productos *anterior;//puntero para apuntar a un nodo anterior
};
typedef struct{//estructura que solo sirve al momento de leer los archivos
	int id;//variable para guardar las id
    char nombre[20];//variable para guardar el nombre del producto
    int cantidad;//variable para guardar la cantidad del producto
    char fechacad[9];//variable para guardar la fecha de caducidad
    char fechallegada[9];//variable para guardar la fecha de llegada
    char fecha[9];//variable extraque sirve para escoger una fecha o para la garantia
}lectura;

struct productos *primero=NULL, *ultimo=NULL;//punteros globales de la lista
int idcont=1;//contador para cambiar la id

//enlaces a las demas partes del proyecto
#include "validaciones.h"
#include "archivos.h"
#include "lista.h"
#include "decorar.h"
#include "menu.h"
