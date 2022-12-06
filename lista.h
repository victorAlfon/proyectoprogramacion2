void mostrarlista(){//mostrar la lista de inicio a fin
	struct productos *aux;
    int i=0;//se iguala a 
    aux = primero;//se coloca al inicio de la lista
    printf("Lista de productos\n");
    while(aux!=NULL){//mientas no llege al final de la lista
	    printf("Id: %d\tNombre: %s\tCantidad: %d\tFecha de llegada: %s\tCaducidad: %s\n", aux->id, aux->nombre, aux->cantidad,aux->fechallegada, aux->fechacad);
		aux=aux->siguiente;//avanza la lista
	    i++;//aumenta i
    }
    if(i==0){//si i es 0 significa que no avanzo nada
		printf("\nNo hay porductos que mostrar\n");//la lista esat vacia
	}
}

void rellenalista(){//creacion de lista
	struct productos *nuevo;//puntero para los nuevos nodos
	FILE *arch2;//puntero para el archivo id
	FILE *arch3;//puntero para el archivo eliminados
	FILE *arch4;//puntero para el archivo vendidos
	lectura datos;//variable del tipo de la estructura de lectura
	lectura dates;//variable del tipo de la estructura de lectura
	lectura datis;//variable del tipo de la estructura de lectura
	int idd=0;//variable para guardar la id mas alta sacada del archivo id
	int validacion=0;//es la variablle que guarda el retorno de rellfecha
	if(!(arch=fopen("prodid.txt", "r"))){//abrire el de ordenados por id para llenar la lista una vez empieze el programa
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch)){//se checa que no llegue al fin el archivo
		fscanf(arch, "%d\t", &datos.id);//se saca el id del archivo
	    fscanf(arch, "%[^\t]\t", datos.nombre);//se saca la nombre del archivo
	    fscanf(arch, "%d\t", &datos.cantidad);//se saca la cantidad del archivo
	    fscanf(arch, "%[^\t]\t", datos.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch, "%[^\n]\n", datos.fechacad);//se saca el fecha de caducidad del archivo
	    validacion=rellfecha(datos.fechacad);//checare la de caducidad se podrian las dos (esto solo sirve para cuando se rellena la lista al principio para que no se llene con datos basura)
	    if(validacion==1){//see entra si la validacion fue correcta
	    	nuevo = (struct productos *) malloc (sizeof(struct productos));//se reserva memoria para el nuevo producto
			if (nuevo==NULL) printf( "No hay memoria disponible!\n");
			if(!(arch2=fopen("id.txt", "r"))){//este archivo nomas sirve para que no se repitan las id se abre en modo r de lectura
				printf("Error al intentar leer el archivo");
				exit(1);//se termina el programa
			}
			while(!feof(arch2)){//mientras no se acabe el archivo
				fscanf(arch2, "%d\n", &idd);//se saca el id del archivo
			}
			fclose(arch2);//se cierra el archivo
			idcont=idd+1;//a idcont se le asigna el valor de la ultima id mas 1 para que el siguiente nodo tenga la siguiente id
			//se colocan los datos del archivo
			nuevo->id=datos.id;//se le pone la id que se saca del archivo
			strcpy(nuevo->nombre,datos.nombre);//se le pone de nombre el nombre que se saca del archivo
			nuevo->cantidad=datos.cantidad;//se le pone la cantidad que se saca del archivo
			strcpy(nuevo->fechallegada,datos.fechallegada);//se le pone la fecha de llegada que se saca del archivo
			strcpy(nuevo->fechacad,datos.fechacad);//se le pone la fecha de caducidad que se saca del archivo
			nuevo->siguiente = NULL;//el siguiente del nuevo apunta a null
			if (primero==NULL){//si la lista esta vacia
				primero = nuevo;//el nuevo es el primero
				ultimo = nuevo;//el nuevo es el ultimo
				nuevo->anterior = NULL;//el anterior del nuevo apunta a null
			}
			else{
				nuevo->anterior=ultimo;//el anterrior de el nuevo es el ultimo
				ultimo->siguiente = nuevo;//el siguiente del ultimo es el nuevo
				ultimo = nuevo;//el nuevo nodo es el ultimo
			}
			validacion=0;//le vuelvo a dar el valor de 0
		}
	}
	fclose(arch);//se cierra el archivo
	//ahora que ya se tienen los nodos con la informacion sacada del archivo entonces ahora se contaran el numero de eliminados ya que si este es 0 no me mostrara los eliminados de la anterior sesion hasta que eliminie uno
	if(!(arch3=fopen("eliminados.txt", "r"))){//se abre el de eliminados en modo r de lectura
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch3)){//se checa que no llegue al fin el archivo
		fscanf(arch3, "%d\t", &dates.id);//se saca el id del archivo
	    fscanf(arch3, "%[^\t]\t", dates.nombre);//se saca la nombre del archivo
	    fscanf(arch3, "%d\t", &dates.cantidad);//se saca la cantidad del archivo
	    fscanf(arch3, "%[^\t]\t", dates.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch3, "%[^\n]\n", dates.fechacad);//se saca el fecha de caducidad del archivo
	    validacion=rellfecha(dates.fechacad);//checare la de caducidad se podrian las dos (esto solo sirve para cuando se rellena la lista al principio para que no se llene con datos basura)
	    if(validacion==1){//se entra si la validacion fue correcta
			validacion=0;//le vuelvo a dar el valor de 0
			conteliminado++;//para que el programa sepa que ya existen eliminados
		}
	}
	fclose(arch3);//se cierra el archivo
	validacion=0;//le vuelvo a dar el valor de 0
	//ahora que ya se checo si habia eliminados tambien se checa si ya hay productos vendidos
	if(!(arch4=fopen("vendidos.txt", "r"))){//se abre el de vendidos en modo r de lectura
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch4)){//se checa que no llegue al fin el archivo
		fscanf(arch4, "%d\t", &datis.id);//se saca el id del archivo
	    fscanf(arch4, "%[^\t]\t", datis.nombre);//se saca la nombre del archivo
	    fscanf(arch4, "%d\t", &datis.cantidad);//se saca la cantidad del archivo
	    fscanf(arch4, "%[^\t]\t", datis.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch4, "%[^\t]\t", datis.fechacad);//se saca el fecha de caducidad del archivo
	    fscanf(arch4, "%[^\n]\n", datis.fecha);//se saca la garantia (use la variable extra que tambien use al momento de pedir una fecha para mostrar los que estan prontos a caducar)
	    validacion=rellfecha(datis.fechacad);//checare la de caducidad se podrian las dos (esto solo sirve para cuando se rellena la lista al principio para que no se llene con datos basura)
	    if(validacion==1){//se entra si la validacion fue correcta
			validacion=0;//le vuelvo a dar el valor de 0
			contvendido++;//para que el programa sepa que ya existen eliminados
		}
	}
	fclose(arch4);//se cierra el archivo
}

void insertar(){//funcion para insertar productos
	struct productos *nuevo,*aux1,*aux2, *aux;//los auxiliares son para cambiar el orden de los productos y aux para recorrer la lista
	int n=0;//variable para saber que escogio el usiario
	//variables para ordenar datos
	char cad[20];//variable para guardar fechas de caducidad
	char lleg[20];//variable para guardar fechas de llegada
	char nom[20];//variable para guardar nombres
	int cant;//variable para guardar cantidades
	int identidad=0;//variable para guardar ids
	bool bandera;//para saber si las fechas son correctas
	do{
		nuevo = (struct productos *) malloc (sizeof(struct productos));//se reserva memoria para el nuevo producto
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");//si no se reservo la memoria se notifica
		printf("\nNuevo producto:\n\n");
		nuevo->id=idcont;//se le asigna el valor que idcont tenga en ese momento, si es el primer elemento recibira el numero 1
		if(!(arch=fopen("id.txt", "a"))){//este archivo nomas sirve para que no se repitan las id se abre en modo a de añadir
			printf("Error al intentar leer el archivo");
			exit(1);//se termina el programa
		}
		fprintf(arch, "%d\n", idcont++);//idcont aumenta cada vez que se pone un nuevo nodo
		fclose(arch);//se cierra el archivo
		fflush(stdin);//libero la entrada del teclado
		validaNombre("Nombre del producto: ", nuevo->nombre);//se manda a validar el nombre
		nuevo->cantidad=validaCantidad("Cantidad de producto: ");//se manda a validar la cantidad
		valfecha("Fecha de llegada: ",nuevo->fechallegada);//se manda a validar la fecha
		do{//ciclo do para que se repita mientras las fechas sean erroneas
			bandera=true;//se le asigna el verdadero a bandera
			valfecha("Fecha de caducidad: ",nuevo->fechacad);//se manda a validar la fecha
			if(strcmp(nuevo->fechallegada, nuevo->fechacad)>=0){//si la de llegada es mayor o igual ala de caducidad se repetira
				bandera=false;//se hace falsa
				printf("La fecha de caducidad no puede ser antes o igual que la fecha de llegada");//se advierte
			}
		}while(bandera==false);//si es falso se repite
		nuevo->siguiente = NULL;//el siguiente del nuevo apunta a null
		if (primero==NULL){//si la lista esta vacia
			primero = nuevo;//el nuevo es el primero
			ultimo = nuevo;//el nuevo es el ultimo
			nuevo->anterior = NULL;//el anterior del nuevo apunta a null
		}
		else{
			nuevo->anterior=ultimo;//el anterrior de el nuevo es el ultimo
			ultimo->siguiente = nuevo;//el siguiente del ultimo es el nuevo
			ultimo = nuevo;//el nuevo nodo es el ultimo
		}
		prod_id(nuevo);//llamada a la funcion prod_id para que se inserten los productos ordenados por id
		
		printf("\n\nDesea insertar otro elemento ? 1=si ");// se pregunta si se desea continuar
		scanf("%d",&n);//se lee la respuesta
	}while(n==1);//si la respuesta es si entonces se repite
	//esta parte del cogigo sirve para el archivo de ordenados por fecha de caducidad
	if(!(arch=fopen("prodcad.txt", "w"))){//este se abre con a nomas ya que al momento de insertar un nuevo producto inmediatamente se inserta aqui tambien, por lo tanto no se repite
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	fclose(arch);//se cierra el archivo
	aux1=primero;//se coloca al inicio de la lista
    while(aux1!=NULL){//mientras no llege al final
	    aux2=aux1->siguiente;//se igual al siguiente de aux1
	    while(aux2!=NULL){//minetras no llege al final
		    if(strcmp(aux1->fechacad, aux2->fechacad)>0){	
				//se guardan los datos en otras variables
				strcpy(cad,aux1->fechacad);//se guarda el dato
				strcpy(lleg,aux1->fechallegada);//se guarda el dato
				strcpy(nom,aux1->nombre);//se guarda el dato
				identidad=aux1->id;//se guarda el dato
				cant=aux1->cantidad;//se guarda el dato
				//se pegan en el siguiente elemento
				strcpy(aux1->fechacad,aux2->fechacad);//obtiene el dato del otro
				strcpy(aux1->fechallegada,aux2->fechallegada);//obtiene el dato del otro
				strcpy(aux1->nombre,aux2->nombre);//obtiene el dato del otro
				aux1->id=aux2->id;//obtiene el dato del otro
				aux1->cantidad=aux2->cantidad;//obtiene el dato del otro
				//despues las variables que guardaron datos se los dan a la otra
				strcpy(aux2->fechacad,cad);//y el otro obtiene el valor que era del otro y fue guardado
				strcpy(aux2->fechallegada,lleg);//y el otro obtiene el valor que era del otro y fue guardado
				strcpy(aux2->nombre,nom);//y el otro obtiene el valor que era del otro y fue guardado
				aux2->id=identidad;//y el otro obtiene el valor que era del otro y fue guardado
				aux2->cantidad=cant;//y el otro obtiene el valor que era del otro y fue guardado
			}
			aux2=aux2->siguiente;//avanza a el siguiente
		}
		aux1=aux1->siguiente;//avanza a el siguiente
	}
	//despues de ordenarlos por fecha de caducidad se vuelve a leer la lista desde el principio y mientras se lee se va insertando en el archivo de por fecha de caducidad
	aux=primero;//comienza desde el principio
    while(aux!=NULL){
    	prod_cad(aux);//llamada a la funcion prod_cad para que se inserten los productos ordenados por fecha de caducidad
		aux=aux->siguiente;//avanza la lista
    }
    //ahora se ordenan de nuevo pero por fecha de llegada
    if(!(arch=fopen("prodlleg.txt", "w"))){//este se abre con a nomas ya que al momento de insertar un nuevo producto inmediatamente se inserta aqui tambien, por lo tanto no se repite
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	fclose(arch);//se cierra el archivo
    aux1=primero;//se coloca al inicio de la lista
    while(aux1!=NULL){//mientras n llege al final
	    aux2=aux1->siguiente;//es igual al siguiente de aux1
	    while(aux2!=NULL){//mientras no llege al final
		    if(strcmp(aux1->fechallegada, aux2->fechallegada)>0){//lo unico que cambia con respecto a el otro ordenamiento es esta comparacion
				//se guardan los datos en otras variables	
				strcpy(cad,aux1->fechacad);//se guarda el dato
				strcpy(lleg,aux1->fechallegada);//se guarda el dato
				strcpy(nom,aux1->nombre);//se guarda el dato
				identidad=aux1->id;//se guarda el dato
				cant=aux1->cantidad;//se guarda el dato
				//se pegan en el siguiente elemento
				strcpy(aux1->fechacad,aux2->fechacad);//obtiene el dato del otro
				strcpy(aux1->fechallegada,aux2->fechallegada);//obtiene el dato del otro
				strcpy(aux1->nombre,aux2->nombre);//obtiene el dato del otro
				aux1->id=aux2->id;//obtiene el dato del otro
				aux1->cantidad=aux2->cantidad;//obtiene el dato del otro
				//despues las variables que guardaron datos se los dan a la otra
				strcpy(aux2->fechacad,cad);//y el otro obtiene el valor que era del otro y fue guardado
				strcpy(aux2->fechallegada,lleg);//y el otro obtiene el valor que era del otro y fue guardado
				strcpy(aux2->nombre,nom);//y el otro obtiene el valor que era del otro y fue guardado
				aux2->id=identidad;//y el otro obtiene el valor que era del otro y fue guardado
				aux2->cantidad=cant;//y el otro obtiene el valor que era del otro y fue guardado
			}
			aux2=aux2->siguiente;//avanza a el siguiente
		}
		aux1=aux1->siguiente;//avanza a el siguiente
	}
	//despues de ordenarlos por fecha de caducidad se vuelve a leer la lista desde el principio y mientras se lee se va insertando en el archivo de por fecha de caducidad
	aux=primero;//comienza desde el principio
    while(aux!=NULL){//mientras no sea el ultimo
    	prod_lleg(aux);//llamada a la funcion prod_lleg para que se inserten los productos ordenados por fecha de llegada
		aux=aux->siguiente;//avanza la lista
    }
}

void eliminaralfinal(){//funcion para eliminar al final
	struct productos *eliminar2, *previo;//se crean punteros del tipo de la lista
	eliminar2=primero;//se coloca al inicio
	while(eliminar2!=ultimo){//mientraas no sea el ultimo
		previo=eliminar2;//se iguala a el otro
		eliminar2=eliminar2->siguiente;//se iguala a su siguiente
	}
	previo->siguiente=NULL;//el siguiente de su anterior apunta a null
	ultimo = previo;//y se termina volviendo el ultimo
	free(eliminar2);//se elimina el nodo
}

void eliminar(char nom[]){//funcion para eliminar de la lista y de los archivos
	conteliminado++;//se aumenta para saber si ya se elimino algo
	struct productos *aux, *aux2, *aux3;//variables para eliminar el producto de la lista
	struct productos *eliminar;//puntero para guardar el nodo que se eliminara y liberar su memoria
	bool bandera=true;//booleano para saber si en verdad existe el producto
	lectura data;//se crea variable de tipo lectura para la lectura de los archivos
	//aparte de la variable arch usare mas punteros de tipo archivo
	FILE *arch2;
	FILE *arch3;
	FILE *arch4;
	FILE *arch5;//para los eliminados
	//hay que eliminarlo de la lista
	aux=primero;
	while(aux!=NULL){//mientras no sea el ultimo
		if(strcmp(aux->nombre,nom)==0){//se compara el nombre de al nodo con el nombre que recibio
			printf("Producto que sera eliminado\n");
    		printf("Id: %d, Nombre: %s, Cantidad: %d, Fecha de llegada: %s, Caducidad: %s\n", aux->id, aux->nombre, aux->cantidad,aux->fechallegada, aux->fechacad);//se muestran los datos
    		break;//se termina si lo encuentra
		}
		if(aux->siguiente==NULL){//si aux no es el ultimo elemento
			printf("El producto que escribiste no existe");
			bandera=false;//la bandera se hace falsa
			break;//se termina el while
		}
		aux=aux->siguiente;//avanza aux
    }
    //ya que se encontro el nodo con esa infrmacion se eliminara
    if(bandera==true){//si el producto no existiera no habria razon para hacer lo que sigue
    	if(aux==primero&& aux==ultimo){//si solo existe un nodo
    		eliminar=primero;//se elimina el unico nodo
    		primero=NULL;//ninguno es primero
    		ultimo=NULL;//ninguno es ultimo
    		free(eliminar);//se elimina el nodo
		}else{
			if(aux==primero){//si sigue siendo el primer elemento entonces se elimina el primer elemento
				eliminar=primero;//se coloca al principio
				primero=primero->siguiente;//ahora el siguiente del primero es ek primero
				primero->anterior=NULL;//ahora el anterior del que ahora es primero apunta a null
				free(eliminar);//se elimina el nodo
			}else{//si no es el primer elemento entonces se eliminara uno de en medio o el final
				if(aux==ultimo){//primero se checa si es el ultimo
					eliminaralfinal();//si esel ultimo se hace uso de la funcion eliminar al final que ya tenia
				}else{//si esta en medio de el primero y el ultimo
					aux2=aux->siguiente;//se conecta con el siguiente de aux
					aux3=aux->anterior;//se conecta con el anterior de aux
					aux3->siguiente=aux->siguiente;//se conecta el siguiente con el siguiente
					aux2->anterior=aux->anterior;//se conecta el anterior con el anterior
					free(aux);//se elimina el nodo
				}
			}
		}
	    //ahora se elimina de los archivos para que no se muestre el producto
		if(!(arch=fopen("prodid.txt", "r"))){//se abre archivo prodid en modo r  de leer
			printf("Error al intentar leer el archivo");
			exit(1);//se termina el programa
		}
		if(!(arch2=fopen("prodcad.txt", "r"))){//se abre archivo prodcad en modo r  de leer
			printf("Error al intentar leer archivo");
			exit(1);//se termina el programa
		}
		if(!(arch3=fopen("prodlleg.txt", "r"))){//se abre archivo prodlleg en modo r  de leer
			printf("Error al intentar leer el archivo");
			exit(1);//se termina el programa
		}
		if(!(arch4=fopen("copiaid.txt", "a"))){//se abre archivo copiaid en modo a  de añadir
			printf("Error al intentar leer archivo");
			exit(1);//se termina el programa
		}
		//abro el archivo para guardar los eliminados
		if(!(arch5=fopen("eliminados.txt", "a"))){//se abre archivo eliminados en modo a  de añadir
			printf("Error al intentar leer el archivo");
			exit(1);//se termina el programa
		}
		
		while(!feof(arch)){//mientras el archivo no llege a su fin
			//primero el archivo prodid
			fscanf(arch, "%d\t", &data.id);//se saca el id del archivo
		    fscanf(arch, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
		    fscanf(arch, "%d\t", &data.cantidad);//se saca la cantidad del archivo
		    fscanf(arch, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
		    if(strcmp(data.nombre,nom)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
		    	//se escribe en el archivo
			    fprintf(arch4, "%d\t", data.id);
			    fprintf(arch4, "%s\t", data.nombre);
			    fprintf(arch4, "%d\t", data.cantidad);
			    fprintf(arch4, "%s\t", data.fechallegada);
			    fprintf(arch4, "%s\n", data.fechacad);
			}else{//si es el producto eliminado se gurdara en el nuevo archivo de eliminados
				fprintf(arch5, "%d\t", data.id);
			    fprintf(arch5, "%s\t", data.nombre);
			    fprintf(arch5, "%d\t", data.cantidad);
			    fprintf(arch5, "%s\t", data.fechallegada);
			    fprintf(arch5, "%s\n", data.fechacad);
			}
		}
		//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
		fclose(arch);//se cierra el archivo
		fclose(arch4);//se cierra el archivo
		fclose(arch5);//se cierra el archivo de los eliminados
		remove("prodid.txt");//se elimina el archivo
		rename("copiaid.txt", "prodid.txt");//se cambia el nombre de uno por el otro
		//ahora se elimina de otro archivo
		if(!(arch4=fopen("copiacad.txt", "a"))){//se abre archivo copiacad en modo a  de añadir
			printf("Error al intentar leer archivo");
			exit(1);//se termina el programa
		}
		while(!feof(arch2)){//mientras el archivo no llege a su fin
			//primero el archivo prodid
			fscanf(arch2, "%d\t", &data.id);//se saca el id del archivo
		    fscanf(arch2, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
		    fscanf(arch2, "%d\t", &data.cantidad);//se saca la cantidad del archivo
		    fscanf(arch2, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch2, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
		    if(strcmp(data.nombre,nom)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
		    	//se escribe en el archivo
			    fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
			    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
			    fprintf(arch4, "%d\t", data.cantidad);//se imprime en el archivo la cantidad
			    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
			    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
			}
		}
		//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
		fclose(arch2);//se cierra el archivo
		fclose(arch4);//se cierra el archivo
		remove("prodcad.txt");//se elimina el archivo
		rename("copiacad.txt", "prodcad.txt");//se cambia el nombre de uno por el otro
		//ahora el ultimo archivo
		if(!(arch4=fopen("copialleg.txt", "a"))){//se abre archivo copialleg en modo a  de añadir
			printf("Error al intentar leer archivo");
			exit(1);//se termina el programa
		}
		while(!feof(arch3)){//mientras el archivo no llege a su fin
			//primero el archivo prodid
			fscanf(arch3, "%d\t", &data.id);//se saca el id del archivo
		    fscanf(arch3, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
		    fscanf(arch3, "%d\t", &data.cantidad);//se saca la cantidad del archivo
		    fscanf(arch3, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
		    fscanf(arch3, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
		    if(strcmp(data.nombre,nom)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
		    	//se escribe en el archivo
				fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
			    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
			    fprintf(arch4, "%d\t", data.cantidad);//se imprime en el archivo la cantidad
			    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
			    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
			}
		}
		//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
		fclose(arch3);//se cierra el archivo
		fclose(arch4);//se cierra el archivo
		remove("prodlleg.txt");//se elimina el archivo
		rename("copialleg.txt", "prodlleg.txt");//se cambia el nombre de uno por el otro
	}
}

void eliminarprod(){//funcion que elimina productos
	struct productos *nav;//para navegar en la lista
	char nom[20];//variable para guardar el nombre del producto que se quiere eliminar
	bool bandera=true;//variable para ver si el nombre es el de un producto
	int cuenta=0;//variable para que el while se detenga al encontrar el producto
	if(primero==NULL){//se checa que almenos exista un producto
		printf("No existen productos");
	}else{
		mostrarlista();//primero se muestran los productos para que el usuario sepa cual eliminar
		do{
			printf("Cual es el nombre del producto que deseas eliminar?");//se pregunta por el nombre del producto que se desea eliminar
			scanf("%s", nom);//se guarda el nombre
			nav=primero;//se coloca el puntero al inicio de la lista
			while(cuenta==0){//se checa que cuenta sea igual a 0
				if((strcmp(nom, nav->nombre))==0){//se comparan los nombres para ver si uno concuerda
					bandera=false;//si el producto existe ya no se repetira
					cuenta++;//aumenta cuenta
				}else{
					nav=nav->siguiente;//avanza la lista
					if(nav==NULL){//se checa si se acaba la lista
						break;//se termina el ciclo do while
					}
				}
			}
			if(bandera==true){//se checa si la bandera es verdadera
				printf("el producto no existe\n");
			}
		}while(bandera==true);//se repetira hasta que el usuario ponga un producto que exista
		eliminar(nom);//se manda a eliminar el producto con el nombre escogido
	}
}
void proxaterminar(){//funcion para mostrar los productos que estan a punto de terminarse
	struct productos *aux;//puntero del tipo de la lista
    int i=0;//variable para ver si se encontro aunque sea un producto con la cantidad
    int prod=0;
    aux = primero;//se coloca el puntero al inicio de la lista
    prod=validaCantidad("Que cantidad de producto? (se mostraran los productos que tengan esta cantidad o una menor): ");//se valida la cantidad
    printf("Lista de productos proximos a terminarse\n");//impresion de encabezado
    while(aux!=NULL){
    	if(aux->cantidad<=prod){//se checa que la cantidad de el producto sea menor a 10, si lo es entonces se mostrara ya que esta a punto de acabarse
    		printf("Id: %d\tNombre: %s\tCantidad: %d\tFecha de llegada: %s\tCaducidad: %s\n", aux->id, aux->nombre, aux->cantidad,aux->fechallegada, aux->fechacad);//se muestran los datos
		}
		aux=aux->siguiente;//se avanza a el siguiente nodo
	    i++;//aumenta i
    }
    if (i==0){//se checa si i es 0
		printf("\nno existen productos que cumplan con los requisitos\n");	
	}
}

void cambiacantidad(char *nombre, int cantidad){//funcion para cambiar la cantidad en los archivos
	lectura data;//se crea variable de tipo lectura para la lectura de los archivos
	//aparte de la variable arch usare mas punteros de tipo archivo
	FILE *arch2;
	FILE *arch3;
	FILE *arch4;

	if(!(arch=fopen("prodid.txt", "r"))){//se abre archivo prodid en modo r  de leer
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	if(!(arch2=fopen("prodcad.txt", "r"))){//se abre archivo prodcad en modo r  de leer
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	if(!(arch3=fopen("prodlleg.txt", "r"))){//se abre archivo prodlleg en modo r  de leer
		printf("Error al intentar leer el archivo");
		exit(1);//se termina el programa
	}
	if(!(arch4=fopen("copiaid.txt", "a"))){//se abre archivo copiaid en modo a  de añadir
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch)){//mientras el archivo no llege a su fin
		//primero el archivo prodid
		fscanf(arch, "%d\t", &data.id);//se saca el id del archivo
	    fscanf(arch, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
	    fscanf(arch, "%d\t", &data.cantidad);//se saca la cantidad del archivo
	    fscanf(arch, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
	    if(strcmp(data.nombre,nombre)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
	    	//se escribe en el archivo
		    fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", data.cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}else{//si es el producto modificado se pone en el archivo con la cantidad ya cambiada
			fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}
	}
	//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
	fclose(arch);//se cierra el archivo
	fclose(arch4);//se cierra el archivo
	remove("prodid.txt");//se elimina el archivo
	rename("copiaid.txt", "prodid.txt");//se cambia el nombre de uno por el otro
	//ahora se elimina de otro archivo
	if(!(arch4=fopen("copiacad.txt", "a"))){//se abre archivo copiacad en modo a  de añadir
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch2)){//mientras el archivo no llege a su fin
		//primero el archivo prodid
		fscanf(arch2, "%d\t", &data.id);//se saca el id del archivo
	    fscanf(arch2, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
	    fscanf(arch2, "%d\t", &data.cantidad);//se saca la cantidad del archivo
	    fscanf(arch2, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch2, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
	    if(strcmp(data.nombre,nombre)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
	    	//se escribe en el archivo
		    fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", data.cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}else{//si es el producto modificado se pone en el archivo con la cantidad ya cambiada
			fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}
	}
	//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
	fclose(arch2);//se cierra el archivo
	fclose(arch4);//se cierra el archivo
	remove("prodcad.txt");//se elimina el archivo
	rename("copiacad.txt", "prodcad.txt");//se cambia el nombre de uno por el otro
	//ahora el ultimo archivo
	if(!(arch4=fopen("copialleg.txt", "a"))){//se abre archivo copialleg en modo a  de añadir
		printf("Error al intentar leer archivo");
		exit(1);//se termina el programa
	}
	while(!feof(arch3)){//mientras el archivo no llege a su fin
		//primero el archivo prodid
		fscanf(arch3, "%d\t", &data.id);//se saca el id del archivo
	    fscanf(arch3, "%[^\t]\t", data.nombre);//se saca la nombre del archivo
	    fscanf(arch3, "%d\t", &data.cantidad);//se saca la cantidad del archivo
	    fscanf(arch3, "%[^\t]\t", data.fechallegada);//se saca el fecha de llegada del archivo
	    fscanf(arch3, "%[^\n]\n", data.fechacad);//se saca el fecha de caducidad del archivo
	    if(strcmp(data.nombre,nombre)!=0){//si no son iguales entonces se pasan a el arhcivo copia para que solo tenga los que se van a quedar
	    	//se escribe en el archivo
		    fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", data.cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}else{//si es el producto modificado se pone en el archivo con la cantidad ya cambiada
			fprintf(arch4, "%d\t", data.id);//se imprime en el archivo la id
		    fprintf(arch4, "%s\t", data.nombre);//se imprime en el archivo el nombre
		    fprintf(arch4, "%d\t", cantidad);//se imprime en el archivo la cantidad
		    fprintf(arch4, "%s\t", data.fechallegada);//se imprime en el archivo la fecha de llegada
		    fprintf(arch4, "%s\n", data.fechacad);//se imprime en el archivo la fecha de caducidad
		}
	}
	//se remueve el archivo que tiene todos los datos y al que tiene todos menos el escogido se le da el nombre de el anterior
	fclose(arch3);//se cierra el archivo
	fclose(arch4);//se cierra el archivo
	remove("prodlleg.txt");//se elimina el archivo
	rename("copialleg.txt", "prodlleg.txt");//se cambia el nombre de uno por el otro
}

void vender(){//funcion para vender productos
	struct productos *nav;//puntero del tipo de la lista para poder navegar en ella
	char nombre[20];//variable para guardar ek nombre
	int cant=0;//para guardar la cantidad que se vendera
	int cont=0;//contador para comprobar que se haya vendido
	char garant[50];//variable para la garantia
	int valida=0;//variable para recibir el retorno de la validacion de garantia
	bool bandera=true;//variable que checa si el producto se vendio y por lo tanto si el nombre era correcto, si no lo era se pide de nuevo
	if(primero==NULL){//se comprueba que por lo menos exista un producto
		printf("Por el momento no existen productos para vender :(");
	}else{
		mostrarlista();//se muestra la lista para que se pueda escoger
		do{
			printf("Producto a vender: ");//se pregunta el nombre
			scanf("%s", nombre);//se lee el nombre
			nav=primero;//se coloca el puntero al inicio de la lista
			while(cont==0){//se comprueba que cont sea 0
				if((strcmp(nombre, nav->nombre))==0){//si el nombre del producto concuerda con el que escribio el usuario entonces se muestra y se vende
					printf("Producto seleccionado: ");
					printf("Id: %d, Nombre: %s, Cantidad: %d, Fecha de llegada: %s, Caducidad: %s\n", nav->id, nav->nombre, nav->cantidad,nav->fechallegada, nav->fechacad);//se muestran los datos del producto
					cant=validaventa("Cantidad: ", nav->cantidad);//se llama ala funcion para validar que sea una cantidad razonable
					nav->cantidad=nav->cantidad-cant;//se cambia el valor de la canridad al restarle la cantidad que puso el usuario
					cambiacantidad(nav->nombre, nav->cantidad);//se hace el cambio en los archivos
					do{
						fflush(stdin);//se limpia la entrada
						printf("Escribe la garantia del producto, en cantidad solo puede ir del 1 al 9\nEn cuanto a tiempo esta puede ser de dias, semanas, meses o years(años en ingles porque eso si lo lee)\nejemplos: 1 dia, 2 dias, 1 year, 2 years: ");
						scanf("%[^\n]", garant);//se lee de esta manera para capturar espacios
						valida=validagarant(garant);//se valida
					}while(valida==0);//se repite si la garantia esta mal
					if(!(arch=fopen("vendidos.txt", "a"))){//se abre archivo vendidos en modo a  de añadir
						printf("Error al intentar leer archivo");
						exit(1);//se termina el programa
					}
					fprintf(arch, "%d\t", nav->id);//se imprime la id en el archivo
					fprintf(arch, "%s\t", nav->nombre);//se imprime el nombre en el archivo
					fprintf(arch, "%d\t", cant);//se imprime la nueva cantidad en el archivo
					fprintf(arch, "%s\t", nav->fechallegada);//se imprime la fecha de llegada en el archivo
					fprintf(arch, "%s\t", nav->fechacad);//se imprime la fecha de caducidad en el archivo
					fprintf(arch, "%s\n", garant);//se imprime la garantia en el archivo
					fclose(arch);//se cierra el archivo
					printf("Vendido!!");//se muestra que ya se vendio
					contvendido++;//incrementa la variable global de vendidos
					if(nav->cantidad==0){//si la resta hiso que el producto se quede sin existencias este se debe eliminar
						eliminar(nombre);//se manda a eliminar el producto que tenga el nombre del producto con 0 de cantidad
					}
					cont++;//aumenta cont
					bandera=false;//bandera se hace falsa
				}else{
					nav=nav->siguiente;//avanza la lista
					if(nav==NULL){//si ya se acabo la lista
						break;//se termina el while
					}
				}
			}
			if(bandera==true){//se checa si la bandera es verdadera
				printf("el producto no existe\n");
			}
		}while(bandera==true);//se repetira hasta que el usuario ponga un producto que exista
	}
}

