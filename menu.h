void menu(int x, int y, int &opc){//funcion para mover la flechita del menu
	char tecla='\0';//funcion para guardar la tecla
	opc=1;//funcion para guardar el numero de opcion
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//cambio de color
	gotoxy(x,y);//para cambiar las coordenadas
	printf("%c",16);//el 16 es el nuemro ascci de la flechita
	do{
		if(kbhit()){//revisa si hay una tecla pulsada
			tecla=getch();//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//cambio de color
			gotoxy(x,y);//para cambiar las coordenadas dependiendo de la tecla
			printf("%c", 16);//impresion de la flecha en las nuevas coordenadas
			if(opc>1&&tecla==72){//Flecha arriba
				y--;//se resta y
				opc--;//se resta opc
			}
			if(opc<11&&tecla==80){//Flecha abajo
				y++;//se aumenta y
				opc++;//se aumenta la opc
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//cambio de color
			gotoxy(x,y);//cambio de posicion dependiendo de las flechas
			printf("%c",16);//impresion de la flecha en las nuevas coordenadas
		}
	}while(tecla!=13);//13--> si es enter se sale
}

void menuProyecto(){//funcion para mostrar el menu
	int opc =0;//variable para checar que opcion es
	int x=0;//variable para las coordenadas en x
	int y=0;//variable para las coordenadas en y
	int seguro=0;//para saber si tomo la desicion correcta;
	
	while(opc != 11){//mientras la opcion no sea 11 seguira funcionando esto no impide que funcione la opcion 11 ya que es la de salir
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//cambia de color
		x = 25;//se mueve a 25 en x
		y = 5;//se mueve a 5 en y
		system("cls");//se limpia la pantalla
		gotoxy(x,y);//se usan las coordenadas establecidas
		printf("1. Alta de productos con su respectiva informacion complementaria.\n");
		gotoxy(x,++y);//se mueve en y
		printf("2. Baja de productos (de forma logica).\n");
		gotoxy(x,++y);//se mueve en y
		printf("3. Listado de productos por identificador.\n");
		gotoxy(x,++y);//se mueve en y
		printf("4. Listado de productos por fecha de caducidad.\n");
		gotoxy(x,++y);//se mueve en y
		printf("5. Listado de productos por fecha de entrada.\n");
		gotoxy(x,++y);//se mueve en y
		printf("6. Reporte de productos proximos a caducar ordenados por identificador.\n");
		gotoxy(x,++y);//se mueve en y
		printf("7. Reporte de productos proximos a terminarse.\n");
		gotoxy(x,++y);//se mueve en y
		printf("8. vender producto (restar cantidad de este).\n");
		gotoxy(x,++y);//se mueve en y
		printf("9. productos eliminados.\n");
		gotoxy(x,++y);//se mueve en y
		printf("10. productos vendidos.\n");
		gotoxy(x,++y);//se mueve en y
		printf("11. Salir del sistema.\n");
		gotoxy(x,++y);//se mueve en y
		menu(22,5,opc);//se mandan coordenadas y la opcion a la funcion menu
		system("cls");//se limpia la pantalla
		gotoxy(10,4);//se mueven las coordenadas
		switch(opc){//un switch con opc
			case OPC1://dependiendo de opc se usa uno de los valores de la variable global de enumeracion menu
				printf("Seguro que quieres insertar? 1-si, otro numero no");//se comprueba si esta seguro el usuario de seguir ya que esta opcion afecta mucho el almacen
				fflush(stdin);//se limpio la entrada
				scanf("%d", &seguro);//se verifica la respuesta
				if(seguro==1){//si el usuario esta seguro se continua con la opcion
					insertar();//se llama la funcion de insertar	
					seguro=0;//se vuelve a poner seguro como 0
				}
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC2://opcion 2
				printf("Seguro que quieres eliminar? 1-si, otro numero no");//tambien se vuelve a verificar al borrar productos
				fflush(stdin);
				scanf("%d", &seguro);
				if(seguro==1){
					eliminarprod();//se llama la funcion de eliminarprod
					seguro=0;//seguro vuelve a ser 0
				}
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC3://opcion 3
				leerprod_id();//se llama la funcion de leer por id
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC4://opcion 4
				leerprod_cad();//se llama la funcion de leer por caducidad
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC5://opcion 5
				leerprod_lleg();//se llama la funcion de leer por llegada
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC6://opcion 6
				cadid();//se llama la funcion de leer por id productos que estan a punto de caducar
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC7://opcion 7
				proxaterminar();//se llama la funcion de leer productos que estan a punto de terminarse
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC8://opcion 8
				printf("Seguro que quieres vender? 1-si, otro numero no");//se verifica que en verdad se quiera vender
				fflush(stdin);//se limpia la entrada
				scanf("%d", &seguro);
				if(seguro==1){//se checa si se quiere continuar
					vender();//se llaama la funcion de vender productos
					seguro=0;//seguro vuelve a ser 0
				}
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC9://opcion 9
				leerprod_eliminados();//se llama la funcion para leer los productos eliminados
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC10://opcion 10
				leerprod_vendido();//se llama la funcion para leer los productos vendidos
				getch();//se espera que el usuario presione una teclka para continuar
				break;//se termina la ocpion
			case OPC11://opcion 11
				system("color 60");//se cambia el color del fondo y de la fuente
				printf("Almacen cerrado");
				exit(0);//se termina el programa
		}
	}
}
