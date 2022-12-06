void portada(){//funcion para mostrar en pantalla el dibujo que sale al principio
	int aux=0;
	FILE *archivo = fopen("portada.txt", "r");//se abre el archivo portada en modo r
	
	for(int i=0; i<58; i++){//se recorre un for para recorrer el archivo por filas
		for(int j=0; j<53; j++){////se recorre un for para recorrer el archivo por columnas
			fscanf(archivo, "%d\t", &aux);//se escanea el digito que se encuentra exactamente en esas coordendas
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);//se usa el color que coincida con el numero conseguido
			printf("%c", 177);//se muestra un caracter que es como un cuadrado que al rellenar casi toda una cordenada es bueno para mostrar el color
		}
		printf("\n");//se pone un salto de linea
	}
	
	fclose(archivo);//se cierra el archivo
}

void portadadatos(){//esta funcion solo sirve para mostrar mis datos
	gotoxy(65, 15);//se cambian las coordenadas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);//cambio de color
	printf("Universidad Politecnica de San Luis Potosi");
	gotoxy(65, 17);//se cambian las coordenadas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);//cambio de color
	printf("Programacion 2 Control de Almacen");
	gotoxy(65, 19);//se cambian las coordenadas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);//cambio de color
	printf("Victor Alfonso Covarrubias Solis, 177294");
	gotoxy(65, 23);//se cambian las coordenadas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);//cambio de color
	printf("Cualquier tecla para inciar...");
	getch();//se espera que el usuario presione una tecla
}
