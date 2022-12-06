void creararchivo(){//para que el programa se empieze en zeros (con los archivos vacios)
	/*
	if(!(arch=fopen("prodid.txt", "w"))){//este se abre con a nomas ya que al momento de insertar un nuevo producto inmediatamente se inserta aqui tambien, por lo tanto no se repite
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	fclose(arch);
	*/
	if(!(arch=fopen("copiaid.txt", "w"))){//para guardar las copia de prodid
		printf("Error al intentar leer archivo");
		exit(1);//se cierra el archivo
	}
	fclose(arch);//se cierra el archivo
	if(!(arch=fopen("copiacad.txt", "w"))){//para guardar las copia de prodcad
		printf("Error al intentar leer archivo");
		exit(1);
	}
	fclose(arch);//se cierra el archivo
	if(!(arch=fopen("copialleg.txt", "w"))){//para guardar las copia de prodlleg
		printf("Error al intentar leer archivo");
		exit(1);
	}
	fclose(arch);//se cierra el archivo
	/*
	if(!(arch=fopen("eliminados.txt", "w"))){//para guardar los eliminados
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	fclose(arch);
	*/
}


void prod_cad(productos* aux){//funcion para losproductos ordenados por fecha de caducidad
	if(!(arch=fopen("prodcad.txt", "a"))){//se abre el archivo de prodcad en modo a de añadir
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	//se escribe en el archivo
	fprintf(arch, "%d\t", aux->id);//se imprime en el archivo la id
    fprintf(arch, "%s\t", aux->nombre);//se imprime en el archivo el nombre
    fprintf(arch, "%d\t", aux->cantidad);//se imprime en el archivo la cantidad
    fprintf(arch, "%s\t", aux->fechallegada);//se imprime en el archivo la fecha de llegada
    fprintf(arch, "%s\n", aux->fechacad);//se imprime en el archivo la fecha de caducidad
	fclose(arch);//se cierra el archivo
}

void prod_lleg(productos* aux){//funcion para losproductos ordenados por fecha de llegada
	if(!(arch=fopen("prodlleg.txt", "a"))){//se abre el archivo de prodlleg en modo a de añadir
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	//se escribe en el archivo
    fprintf(arch, "%d\t", aux->id);//se imprime en el archivo la id
    fprintf(arch, "%s\t", aux->nombre);//se imprime en el archivo el nombre
    fprintf(arch, "%d\t", aux->cantidad);//se imprime en el archivo la cantidad
    fprintf(arch, "%s\t", aux->fechallegada);//se imprime en el archivo la fecha de llegada
    fprintf(arch, "%s\n", aux->fechacad);//se imprime en el archivo la fecha de caducidad
	fclose(arch);//se cierra el archivo
}

void prod_id(productos* nuevo){//funcion para losproductos ordenados por id
	if(!(arch=fopen("prodid.txt", "a"))){//este se abre con a nomas ya que al momento de insertar un nuevo producto inmediatamente se inserta aqui tambien, por lo tanto no se repite
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	//se escribe en el archivo
	fprintf(arch, "%d\t", nuevo->id);//se imprime en el archivo la id
    fprintf(arch, "%s\t", nuevo->nombre);//se imprime en el archivo el nombre
    fprintf(arch, "%d\t", nuevo->cantidad);//se imprime en el archivo la cantidad
    fprintf(arch, "%s\t", nuevo->fechallegada);//se imprime en el archivo la fecha de llegada
    fprintf(arch, "%s\n", nuevo->fechacad);//se imprime en el archivo la fecha de caducidad
	fclose(arch);//se cierra el archivo
}
void leerprod_cad(){//funcion para losproductos ordenados por fecha de caducidad
	if(primero==NULL){//se comprueba si existe al menos un producto en la lista
		printf("\nNo hay porductos que mostrar\n");	
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		if(!(arch=fopen("prodcad.txt", "r"))){//se abre el archivo de prodcad en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia el color
		printf("\n\n----------Productos ordenados por caducidad----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia el color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		    //se imprimen
		    printf("%d\t", datos.id);//se saca el id del archivo
		    printf("%s\t", datos.nombre);//se saca la nombre del archivo
		    printf("%d\t", datos.cantidad);//se saca la cantidad del archivo
		    printf("%s\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    printf("%s\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		}
		fclose(arch);//se cierra el archivo
	}
}
void leerprod_eliminados(){//funcion para losproductos eliminados
	if(conteliminado==0){//se comprueba que almenos se haya eliminado un producto
		printf("\nAun no hay productos eliminados\n");
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		if(!(arch=fopen("eliminados.txt", "r"))){//se abre el archivo de eliminados en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia el color
		printf("\n\n----------Productos eliminados----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia el color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		    //se imprimen
		    printf("%d\t", datos.id);//se muestra la id
		    printf("%s\t", datos.nombre);//se muestra el nombre
		    printf("%d\t", datos.cantidad);//se muestra la cantidad
		    printf("%s\t", datos.fechallegada);//se muestra la fecha de llegada
		    printf("%s\n", datos.fechacad);//se muestra la fecha de caducidad
		}
		fclose(arch);//se cierra el archivo
	}
}
void leerprod_lleg(){//funcion para losproductos ordenados por fecha de llegada
	if(primero==NULL){//se comprueba si existe al menos un producto en la lista
		printf("\nNo hay porductos que mostrar\n");	
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		if(!(arch=fopen("prodlleg.txt", "r"))){//se abre el archivo de prodlleg en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia el color
		printf("\n\n----------Productos ordenados por llegada----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia el color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		    //se imprimen
		    printf("%d\t", datos.id);//se muestra la id
		    printf("%s\t", datos.nombre);//se muestra el nombre
		    printf("%d\t", datos.cantidad);//se muestra la cantidad
		    printf("%s\t", datos.fechallegada);//se muestra la fecha de llegada
		    printf("%s\n", datos.fechacad);//se muestra la fecha de caducidad
		}
		fclose(arch);//se cierra el archivo
	}
}

void leerprod_id(){//funcion para los productos ordenados por id
	if(primero==NULL){//se comprueba si existe al menos un producto en la lista
		printf("\nNo hay porductos que mostrar\n");	
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		if(!(arch=fopen("prodid.txt", "r"))){//se abre el archivo de prodid en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia el color
		printf("\n\n----------Productos ordenados por id----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia el color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		    //se imprimen
		    printf("%d\t", datos.id);//se muestra la id
		    printf("%s\t", datos.nombre);//se muestra el nombre
		    printf("%d\t", datos.cantidad);//se muestra la cantidad
		    printf("%s\t", datos.fechallegada);//se muestra la fecha de llegada
		    printf("%s\n", datos.fechacad);//se muestra la fecha de caducidad
		}
		fclose(arch);//se cierra el archivo
	}
}
void cadid(){//se leen los productos proximos a caducar por su id asi que usare el archivo en donde se fuardan por id
	if(primero==NULL){//se comprueba si existe al menos un producto en la lista
		printf("\nNo hay porductos que mostrar\n");	
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		printf("escribe la fecha de caducidad (se mostraran los productos que esten antes o que esten en esta fecha)");
		valfecha("Fecha de llegada: ",datos.fecha);//esta variable solo la cree para recibir la fecha seleccionada
		if(!(arch=fopen("prodid.txt", "r"))){//se abre el archivo de prodid en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia el color
		printf("\n\n----------Productos proximos a caducar (antes o en la fecha indicada) por id----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia el color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
		    //se imprimen
		    //if(strcmp(datos.fechacad,datos.fecha)>=0 && strcmp(datos.fechacad,datos.fecha)<=30){//si cumplen con las condiciones dadas
		    if(strcmp(datos.fecha,datos.fechacad)>=0){//se comprueba que la caducidad sea igual o mayor a la que escojio el usuario
		    	printf("%d\t", datos.id);//se muestra la id
			    printf("%s\t", datos.nombre);//se muestra el nombre
			    printf("%d\t", datos.cantidad);//se muestra la cantidad
			    printf("%s\t", datos.fechallegada);//se muestra la fecha de llegada
			    printf("%s\n", datos.fechacad);//se muestra la fecha de caducidad
			}
		}
		fclose(arch);//se cierra el archivo
	}
}

void leerprod_vendido(){//funcion para los productos ordenados por id
	if(contvendido==0){//se comprueba que al menos este un producto vendido
		printf("\nAun no has vendido productos\n");
	}else{
		lectura datos;//variable del tipo de la estructura de lectura
		if(!(arch=fopen("vendidos.txt", "r"))){//se abre el archivo de vendidos en modo r de lectura
			printf("Error al intentar leer el archivo");//se comprueba si abrio correctamente
			exit(1);//se termina el programa
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//se cambia color
		printf("\n\n----------Productos vendidos----------\n\n");//se imprime encabezado
		printf("Id\tNombre\tCantidad\tLLegada\tCaducidad\tGarantia\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//se cambia color
		while(!feof(arch)){
			fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\t]\t", datos.fechacad);//se saca el fecha de caducidad del archivo
		    fscanf(arch, "%[^\n]\n", datos.fecha);//se saca la garantia del archivo usando la variable extra de lectura
		    //se imprimen
		    printf("%d\t", datos.id);//se muestra la id
		    printf("%s\t", datos.nombre);//se muestra el nombre
		    printf("%d\t", datos.cantidad);//se muestra la cantidad
		    printf("%s\t", datos.fechallegada);//se muestra la fecha de llegada
		    printf("%s\t", datos.fechacad);//se muestra la fecha de caducidad
		    printf("%s\n", datos.fecha);//se muestra la garantia
		}
		fclose(arch);//se cierra el archivo
	}
}
