int validaCantidad(const char mensaje[]){//para validar que la cantidad de producto sea real o mayor que 0
	int continuar=0;//variable que sirve para saber si se debe repetir
	bool bandera=true;//para saber si es un numero correcto
	int entero=0;//para guardar la cantidad
	do{//ciclo do-while
		printf("\n%s", mensaje);//se muestra el mensaje recibido
		continuar = scanf("%d", &entero);//se lee la entrada
		if(entero<1){//se checa si es 0 o un nuemro negativo
			printf("Tiene que ser mas de 0");
			bandera=false;//si lo es bandera es falsa
		}else{
			bandera=true;//si la cantidad es aceptable es verdadera
		}
		fflush(stdin);//se limpia la entrada
	}while(continuar != 1 || bandera==false);//se comprueba si alguna de las dos validaciones salio mal
	return entero;//se retorna la cantidad
}

void validaNombre(const char mensaje[], char cadena[]){//para que el usuario no ponga numeros o nombres demasiado largos
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;//variable para saber si se debe repetir
	int i;//variable para el for
	
	while(bandera){//se checa si es verdadera
		printf("%s", mensaje);//se muestra el mensaje recibido
		scanf("%[^\n]", cadena);//se lee el nombre
		fflush(stdin);//se limpia la entrada
		if(strlen(cadena)>20){//se checa que el nombre sea de menos de 20 caracteres
			continue;//si es asi se repite
		}else{
			for(i=0; i<strlen(cadena); i++){//se recorre un for hasta que i sea igual que el tamaño del nombre
				if(isalpha(cadena[i])){//se checa si es una letra y no un digito o caracter especial
					if(i==(strlen(cadena))-1){//si todas fueron letras
						bandera=false;//bandera se hace falsa para terminar el while
					}
				}else{
					break;//se termina el for para repetirse el while
				}
			}
		}
	}
}

void valfecha(const char mensaje[], char *fecha){//para validar que la fecha si sea real
	bool bandera;//variable para saber si repetirse
	do{
		bandera=true;//inicializacion de bandera
		int cont=0;//inicializacion de contador
		printf("\n%s Debes poner guiones entre los numeros, año-mes-dia, ejemplo=22-01-05\nrecuerda que estamos en el año 2022 asi que no se pueden poner años anteriores a este:\t", mensaje);
		scanf("%s", fecha);
		if(strlen(fecha)>8){//si la fecha tiene mas de 8 caracteres
			printf("pon menos caracteres\n");
			bandera=false;//bandera se hace falsa
		}else{
			if(strlen(fecha)<8){//si la fecha tiene menos de 8 caracteres
				printf("pon mas caracteres\n");
				bandera=false;//bandera se hace falsa
			}else{
				for(int i=0;i<8;i++){//como la fecha tiene 8 elementos se recorre 8 veces
					if(i==0){
						if(fecha[i]>='2' && fecha[i]<='9'){//si es el primer elemento de la fecha enonces es el primer digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
							cont++;//aumenta cont
						}else{
							bandera=false;//bandera se hace falsa
						}
					}
					if(i==1){//si es el segundo elemento de la fecha enonces es el segundo digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
						if(fecha[0]=='2'){
							if(fecha[i]>='2' && fecha[i]<='9'){
								cont++;//aumenta cont
							}else{
								bandera=false;//bandera se hace falsa
							}
						}else{
							if(fecha[0]>='3' && fecha[0]<='9'){//si ya no estamos en años 20 entonces el segundo digito del año puede ser 0 o 1
								if(fecha[i]>='0' && fecha[i]<='9'){
									cont++;//aumenta cont
								}else{
									bandera=false;//bandera se hace falsa
								}
							}
						}
						
					}
					if(i==2 || i==5){//si el elemento es el 3 o el 6 significa que es uno de los guiones
						if(fecha[i]=='-'){//si es el segundo elemento de la fecha enonces es el segundo digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
							cont++;//aumenta cont
						}else{
							bandera=false;//bandera se hace falsa
						}
					}
					if(i==3){//si es el 4 elemento es el primer digito del mes el cual solo puede ser 0 o 1 ya que el ultimo es es el 12
						if(fecha[i]=='1' || fecha[i]=='0' ){
							cont++;//aumenta cont
						}else{
							bandera=false;//bandera se hace falsa
						}
					}
					if(i==4){//si es el quinto elemento entonces debe ser el 2 digito del mes el cual puede ir del 1 al 9 si es un mes del 1 al 9
						if(fecha[3]=='0'){
							if(fecha[i]>='1' && fecha[i]<='9'){
								cont++;//aumenta cont
							}else{
								bandera=false;//bandera se hace falsa
							}
						}else{
							if(fecha[3]=='1'){//si es del 10 al 12 entonces solo puede ir del 0 al 2
								if(fecha[i]>='0' && fecha[i]<='2'){
									cont++;//aumenta cont
								}else{
									bandera=false;//bandera se hace falsa
								}
							}
						}
					}
					if(i==6){//si es el elemento 7 significa que es el primero digito del dia
						if(fecha[3]=='0'){//si el mes es de los primeros 9
							if(fecha[4]=='1' || fecha[4]=='3' || fecha[4]=='5' || fecha[4]=='7' || fecha[4]=='8' || fecha[4]=='4' || fecha[4]=='6' || fecha[4]=='9'){//se checa el mes estos meses tienes 30 o mas dias
								if(fecha[i]>='0' && fecha[i]<='3'){//si es el primer digito del dia debe estar entre 0 y 3 ya que lo maximo que pueden tener estos meses son 30 o 31 dias
									cont++;//aumenta cont
								}else{
									bandera=false;//bandera se hace falsa
								}
							}else{
								if(fecha[4]=='2'){//si es febrero nomas tiene 20 o mas pero no llega a los 30
									if(fecha[i]>='0' && fecha[i]<='2'){//febrero nomas tiene 29 dias asi que el primer digito de dia nomas va de 0 a 2
										cont++;//aumenta cont
									}else{
										bandera=false;//bandera se hace falsa
									}
								}
							}
						}else{
							if(fecha[3]=='1'){//si es de los ultimos 3 meses
								if(fecha[4]=='0' || fecha[4]=='1' || fecha[4]=='2'){//se checa el mes estos meses tienes 30 o mas dias
									if(fecha[i]>='0' && fecha[i]<='3'){//estos 3 meses tambien tienen entre 30 a 31 dias
										cont++;//aumenta cont
									}else{
										bandera=false;//bandera se hace falsa
									}
								}
							}
						}
					}
					if(i==7){//si es el ultimo entonces es el segundo digito del dia este depende demasiado del mes al igual que el anterior
						if(fecha[3]=='0'){//si es de los primeros 9 meses
							if(fecha[4]=='1' || fecha[4]=='3' || fecha[4]=='5' || fecha[4]=='7' || fecha[4]=='8'){//y es enero, marzo, mayo, julio o agosto puede tener hasta 31 dias
								if(fecha[6]=='3'){//y si el primer digito del dia es un 3 significa que ya esta en los dias 30 o 31
									if(fecha[i]=='0' || fecha[i]=='1'){//y estos meses tienen 30 y 31
										cont++;//aumenta cont
									}else{
										bandera=false;//bandera se hace falsa
									}
								}else{
									if(fecha[6]>='1' && fecha[6]<='2'){//el primer digito del dia es  1 o 2
										if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
											cont++;//aumenta cont
										}else{
											bandera=false;//bandera se hace falsa
										}
									}else{
										if(fecha[6]=='0'){//el primer digito del dia es  0
											if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
												cont++;//aumenta cont
											}else{
												bandera=false;//bandera se hace falsa
											}
										}
									}
								}
							}else{
								if(fecha[4]=='4' || fecha[4]=='6' || fecha[4]=='9'){//si es de los meses que solo tienen 30 dias
									if(fecha[6]=='3'){//entonces si ya llego al dia 30
										if(fecha[i]=='0'){//solo se puede quedar hasta el30
											cont++;//aumenta cont
										}else{
											bandera=false;//bandera se hace falsa
										}
									}else{
										if(fecha[6]>='1' && fecha[6]<='2'){//el primer digito del dia es  1 o 2
											if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
												cont++;//aumenta cont
											}else{
												bandera=false;//bandera se hace falsa
											}
										}else{
											if(fecha[6]=='0'){//el primer digito del dia es  0
												if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
													cont++;//aumenta cont
												}else{
													bandera=false;//bandera se hace falsa
												}
											}
										}
									}
								}else{
									if(fecha[4]=='2'){//si es febrero entonces 
										if(fecha[6]=='2'){//si el primer digito del dia es 2
											if(fecha[i]>='0' && fecha[i]<='8'){//entonces el segundo debe ir del 0 al 8 
												cont++;//aumenta cont
											}else{
												bandera=false;//bandera se hace falsa
											}
										}else{
											if(fecha[6]=='1'){//si el primer digito del dia es 1 puede ir del 0 al 9
												if(fecha[i]>='0' && fecha[i]<='9'){
													cont++;//aumenta cont
												}else{
													bandera=false;//bandera se hace falsa
												}
											}else{
												if(fecha[6]=='0'){//si el primer digito del dia es 0 no puede ser 00
													if(fecha[i]>'0' && fecha[i]<='9'){
														cont++;//aumenta cont
													}else{
														bandera=false;//bandera se hace falsa
													}
												}
											}
										}
									}
								}
							}
						}else{
							if(fecha[3]=='1'){//si es del los ultimos 3 meses
								if(fecha[4]=='0' || fecha[4]=='2'){//si es octubre o diciembre
									if(fecha[6]=='3'){//y esta en los dias 30
										if(fecha[i]=='0' || fecha[i]=='1'){//puede tener 30 o 31
											cont++;//aumenta cont
										}else{
											bandera=false;//bandera se hace falsa
										}
									}else{
										if(fecha[6]>='1' && fecha[6]<='2'){//si es 1 o 2
											if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 0 al 9
												cont++;//aumenta cont
											}else{
												bandera=false;//bandera se hace falsa
											}
										}else{
											if(fecha[6]=='0'){//si es 0
												if(fecha[i]>'0' && fecha[i]<='9'){//no puede ser 00
													cont++;//aumenta cont
												}else{
													bandera=false;//bandera se hace falsa
												}
											}
										}
									}
								}else{
									if(fecha[4]=='1'){//si es noviembre
										if(fecha[6]=='3'){//solo puede tener hasta 30
											if(fecha[i]=='0'){
												cont++;//aumenta cont
											}else{
												bandera=false;//bandera se hace falsa
											}
										}else{
											if(fecha[6]>='1' && fecha[6]<='2'){//si es 1 o 2
												if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 0 al 9
													cont++;//aumenta cont
												}else{
													bandera=false;//bandera se hace falsa
												}
											}else{
												if(fecha[6]=='0'){//si es 0
													if(fecha[i]>='0' && fecha[i]<='9'){//no puede ser 00
														cont++;//aumenta cont
													}else{
														bandera=false;//bandera se hace falsa
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(bandera==false){//si sale aunque sea uno falso
			printf("Pusiste %d elementos correctos de 8, alguno te fallo escribela de nuevo", cont);//te dice cuantos errores tuviste
		}
	}while(bandera==false);//se checa si un elemento es erroneo y se pide de nuevo la fecha
}

int validaventa(const char mensaje[], int existencia){//validar que la cantidad que se quiere vender sea dentro de los limites
	int continuar=0;//variable para saber si se debe repetir o no
	int entero=0;//variable para guardar la cantidad
	bool bandera = true;//variable para saber si debe repetirse o no
	do{
		int cont=0;//contador para saber si cambiar bandera o no
		do{
			printf("\n%s", mensaje);//se muestra el mensaje recibido
			continuar = scanf("%d", &entero);//se lee la cantidad
			fflush(stdin);//se limpia la entrada
			}while(continuar != 1);//se checa si era entero
		if(entero<1){//se checa si es 0 o un numero negativo
			printf("Tiene que ser mas de 0");
		}else{
			cont++;//aumenta cont
		}
		if(entero>existencia){//se checa que no sobrepase la existencia del producto
			printf("El numero excede la existencia del producto");
		}else{
			cont++;//aumenta cont
		}
		if(cont==2){//si no tiene ninguna de las dos condiciones entonces el numero esta bien y se puede restar ala cantidad
			bandera=false;//se hace false
		}
	}while(bandera==true);//si bandera es true se repite
	return entero;//se retorna la cantidad
}

int rellfecha(char *fecha){//para validar que la fecha que esta en el archivo se puede poner en ña lista
	int cont=0;//inicializacion de contador
	for(int i=0;i<8;i++){//como la fecha tiene 8 elementos se recorre 8 veces
		if(i==0){
			if(fecha[i]>='2' && fecha[i]<='9'){//si es el primer elemento de la fecha enonces es el primer digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
				cont++;//aumenta cont
			}
		}
		if(i==1){//si es el segundo elemento de la fecha enonces es el segundo digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
			if(fecha[0]=='2'){
				if(fecha[i]>='2' && fecha[i]<='9'){
					cont++;//aumenta cont
				}
			}else{
				if(fecha[0]>='3' && fecha[0]<='9'){
					if(fecha[i]>='0' && fecha[i]<='9'){
						cont++;//aumenta cont
					}
				}
			}
		}
		if(i==2 || i==5){//si el elemento es el 3 o el 6 significa que es uno de los guiones
			if(fecha[i]=='-'){//si es el segundo elemento de la fecha enonces es el segundo digito de la fecha el cual debe ser 2 o mayor porque estamos en el 2022
				cont++;//aumenta cont
			}
		}
		if(i==3){//si es el 4 elemento es el primer digito del mes el cual solo puede ser 0 o 1
			if(fecha[i]=='1' || fecha[i]=='0' ){
				cont++;//aumenta cont
			}
		}
		if(i==4){//si es el quinto elemento entonces debe ser el 2 digito del mes el cual puede ir del 1 al 9 si es un mes del 1 al 9 si es del 10 al 12 entonces solo puee ir del 0 al 2
			if(fecha[3]=='0'){
				if(fecha[i]>='1' && fecha[i]<='9'){
					cont++;//aumenta cont
				}
			}else{
				if(fecha[3]=='1'){
					if(fecha[i]>='0' && fecha[i]<='2'){
						cont++;//aumenta cont
					}
				}
			}
		}
		if(i==6){//si es el elemento 7 significa que es el primero digito del dia
			if(fecha[3]=='0'){
				if(fecha[4]=='1' || fecha[4]=='3' || fecha[4]=='5' || fecha[4]=='7' || fecha[4]=='8' || fecha[4]=='4' || fecha[4]=='6' || fecha[4]=='9'){//se checa el mes estos meses tienes 30 o mas dias
					if(fecha[i]>='0' && fecha[i]<='3'){
						cont++;//aumenta cont
					}
				}else{
					if(fecha[4]=='2'){//si es febrero nomas tiene 20 o mas pero no llega a los 30
						if(fecha[i]>='0' && fecha[i]<='2'){
							cont++;//aumenta cont
						}
					}
				}
			}else{
				if(fecha[3]=='1'){
					if(fecha[4]=='0' || fecha[4]=='1' || fecha[4]=='2'){//se checa el mes estos meses tienes 30 o mas dias
						if(fecha[i]>='0' && fecha[i]<='3'){
							cont++;//aumenta cont
						}
					}
				}
			}
		}
		if(i==7){//si es el ultimo entonces es el segundo digito del dia este depende demasiado del mes al igual que el anterior
			if(fecha[3]=='0'){
				if(fecha[4]=='1' || fecha[4]=='3' || fecha[4]=='5' || fecha[4]=='7' || fecha[4]=='8'){
					if(fecha[6]=='3'){
						if(fecha[i]=='0' || fecha[i]=='1'){
							cont++;//aumenta cont
						}
					}else{
						if(fecha[6]=='1' || fecha[6]=='2'){//el primer digito del dia es  1 o 2
							if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
								cont++;//aumenta cont
							}
						}else{
							if(fecha[6]=='0'){//el primer digito del dia es  0
								if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
									cont++;//aumenta cont
								}
							}
						}
					}
				}else{
					if(fecha[4]=='4' || fecha[4]=='6' || fecha[4]=='9'){
						if(fecha[6]=='3'){
							if(fecha[i]=='0'){
								cont++;//aumenta cont
							}
						}else{
							if(fecha[6]=='1' || fecha[6]=='2'){//el primer digito del dia es  1 o 2
								if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
									cont++;//aumenta cont
								}
							}else{
								if(fecha[6]=='0'){//el primer digito del dia es  0
									if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
										cont++;//aumenta cont
									}
								}
							}
						}
					}else{
						if(fecha[4]=='2'){
							if(fecha[6]=='2'){
								if(fecha[i]>='0' && fecha[i]<='8'){
									cont++;//aumenta cont
								}
							}else{
								if(fecha[6]=='1'){//el primer digito del dia es  1
									if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
										cont++;//aumenta cont
									}
								}else{
									if(fecha[6]=='0'){//el primer digito del dia es  0
										if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
											cont++;//aumenta cont
										}
									}
								}
							}
						}
					}
				}
			}else{
				if(fecha[3]=='1'){
					if(fecha[4]=='0' || fecha[4]=='2'){
						if(fecha[6]=='3'){
							if(fecha[i]=='0' || fecha[i]=='1'){
								cont++;//aumenta cont
							}
						}else{
							if(fecha[6]=='1' || fecha[6]=='2'){//el primer digito del dia es  1 o 2
								if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
									cont++;//aumenta cont
								}
							}else{
								if(fecha[6]=='0'){//el primer digito del dia es  0
									if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
										cont++;//aumenta cont
									}
								}
							}
						}
					}else{
						if(fecha[4]=='1'){
							if(fecha[6]=='3'){
								if(fecha[i]=='0'){
									cont++;//aumenta cont
								}
							}else{
								if(fecha[6]=='1' || fecha[6]=='2'){//el primer digito del dia es  1 o 2
									if(fecha[i]>='0' && fecha[i]<='9'){//puede ir del 10 al 19 y el 20 al 29
										cont++;//aumenta cont
									}
								}else{
									if(fecha[6]=='0'){//el primer digito del dia es  0
										if(fecha[i]>'0' && fecha[i]<='9'){//no puede aver dia 00 tiene que ir del 01 al 09
											cont++;//aumenta cont
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(cont==8){
		return 1;//si la fecha es normal retorna 1
	}else{
		return 0;//si esta mal retorna 0
	}
}

int validagarant(char garant[]){//para que el usuario no ponga numeros o nombres demasiado largos
	bool bandera=true;//para saber si algo esta mal
	int contn=0;//para contar caracteres
	int contl=0;//para contar letras
	int contc=0;//para contar caracteres totales
	if(garant[0]>'0' && garant[0]<='9'){//se checa que el primer caracter sea un numero del 1 al 9
		contn++;//aumenta el contador de caracteres
	}
	if(garant[1]==' '){//se checa que el segundo caracter sea un espacio
		contn++;//aumenta el contador de caracteres
	}
	if(contn==2){//se comprueba que el primer digito sea un numero y el segundo un espacio
		if(garant[2]=='d'){//si es dia
			if(garant[3]=='i'){
				contl++;//aumenta el contador de letras
			}
			if(garant[4]=='a'){
				contl++;//aumenta el contador de letras
			}
			if(contl!=2){//se checa que el nuemro de letras sea el correcto 
				bandera=false;//bandera se hace falsa
			}else{
				if(garant[0]!='1'){//se checa si solo es un dia
					if(garant[5]!='s'){//si es mas de un dia entonces es dias y no dia
						bandera=false;//bandera se hace falsa
					}
					if(strlen(garant)>6){//si tiene mas caracteres de los que deberia esta mal
						bandera=false;//bandera se hace falsa
					}
				}else{
					if(strlen(garant)>5){//si tiene mas elementos de los que deberia
						bandera=false;//bandera se hace falsa
					}
				}
			}
		}else{
			if(garant[2]=='s'){//si es semana
				if(garant[3]=='e'){
					contl++;//aumenta el contador de letras
				}
				if(garant[4]=='m'){
					contl++;//aumenta el contador de letras
				}
				if(garant[5]=='a'){
					contl++;//aumenta el contador de letras
				}
				if(garant[6]=='n'){
					contl++;//aumenta el contador de letras
				}
				if(garant[7]=='a'){
					contl++;//aumenta el contador de letras
				}
				if(contl!=5){//se checa que el nuemro de letras sea el correcto 
					bandera=false;
				}else{
					if(garant[0]!='1'){//se checa si solo es una semana
						if(garant[8]!='s'){//si es mas de una semana entonces es semanas y no semana
							bandera=false;//bandera se hace falsa
						}
						if(strlen(garant)>9){//si tiene mas elementos de los que deberia
							bandera=false;//bandera se hace falsa
						}
					}else{
						if(strlen(garant)>8){//si tiene mas elementos de los que deberia
							bandera=false;//bandera se hace falsa
						}
					}
				}
			}else{
				if(garant[2]=='m'){//si es mes
					if(garant[3]=='e'){
						contl++;//aumenta el contador de letras
					}
					if(garant[4]=='s'){
						contl++;//aumenta el contador de letras
					}
					if(contl!=2){//se checa que el nuemro de letras sea el correcto 
						bandera=false;
					}else{
						if(garant[0]!='1'){//se checa si solo es un mes
							if(garant[5]!='e'){//si es mas de un mes entonces es meses y no mes
								bandera=false;//bandera se hace falsa
							}
							if(garant[6]!='s'){//si es mas de un mes entonces es meses y no mes
								bandera=false;//bandera se hace falsa
							}
							if(strlen(garant)>7){//si tiene mas elementos de los que deberia
								bandera=false;//bandera se hace falsa
							}
						}else{
							if(strlen(garant)>5){//si tiene mas elementos de los que deberia
								bandera=false;//bandera se hace falsa
							}
						}
					}
				}else{
					if(garant[2]=='y'){//si es año
						if(garant[3]=='e'){
							contl++;//aumenta el contador de letras
						}
						if(garant[4]=='a'){
							contl++;//aumenta el contador de letras
						}
						if(garant[5]=='r'){
							contl++;//aumenta el contador de letras
						}
						if(contl!=3){//se checa que el nuemro de letras sea el correcto
							bandera=false;
						}else{
							if(garant[0]!='1'){//se checa si un año
								if(garant[6]!='s'){//si es mas de un año entonces es años y no año
									bandera=false;//bandera se hace falsa
								}
								if(strlen(garant)>7){//si tiene mas elementos de los que deberia
									bandera=false;//bandera se hace falsa
								}
							}else{
								if(strlen(garant)>6){//si tiene mas elementos de los que deberia
									bandera=false;//bandera se hace falsa
								}
							}
						}
					}
				}
			}
		}
	}else{
		bandera=false;//bandera se hace falsa
	}
	if(bandera==false){//si algun elemento esta mal se notifica ya que la garantia se pedira de nuevo
		printf("\nEscribiste algo mal\n");
		return 0;//si esta mal la garantia retorna 0
	}else{
		if(contl>1){//otra validacion extra
			return 1;//si la garantia es correcta retorna 1
		}
	}

}
