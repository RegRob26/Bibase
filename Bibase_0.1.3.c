/*
 * Bibase_0.1.1.c		//Está listo para utilizarse, solo que deberé mejorar la forma en que se muestran los archivos
 * 
 * Caso 2 definido pero no es el definitivo
 * Compilado sobre Linux
 * 
 * Copyright 2020 Emmanuel Robles <emmanuelreg26@gmail.com>
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "cleanwl.h"
void recuadro();
void bienvenida();
int menu_princi(int *);
void segun_menu(int);
int caso_1(int);
void caso_1segun();
int caso_1();
int caso_2segun(int);
int caso_3(int);
void caso_3segun();
int aut();
int lib();
int an();
int ge();
int writelibro();
int writeautor();
int writeanio();
int writegenero();
int usuario(int);
int libre(int);
int librero[3][3] = {0,0,0,0,0,0,0,0,0};


int menprinici, men3, menulibro, global;
int anio, ind, indi, ins, in;
int usu;
char nombre[200] ="Emmanuel" ;
FILE * anio2;
FILE  * autor2; 			
FILE  * libro2;
FILE *genero2;
int main()			//añadido do while para mantener ciclo de bienvenido a Basbli
{
	int key, men;
	
	bienvenida();
	usuario(key);
	do{
	
	menu_princi(&men);
	if(men != -1){
	limpiar_pantalla();
	segun_menu(men);
	}else
		global = -1;
}while(global != -1);	//Este es el while global
	
	limpiar_pantalla();

	recuadro();
	printf("\tGracias por utilizar BasBLi, vuelva pronto\n");	
	recuadro();
	return 0;
}

void recuadro(){
	printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");	
	}

void bienvenida(){
	limpiar_pantalla();
	recuadro();
	printf("\t\t Bienvenido a BasBLi, %s\n", nombre);
	recuadro();
	printf("\n\n\t   Desarrollado por -+-+-+MAPREG+-+-+-\n");
	getchar();
	limpiar_pantalla();
	recuadro();
	printf("Este programa está diseñado para ayudar a organizar una libreria\nY tener un mejor control del inventario.\n");
	printf("\nTrataremos que tu experiencia durante el uso del programa\nsea lo más fácil posible.\n");
	recuadro();
	printf("Presione enter para continuar: ");
	getchar();
	
	}
int usuario(int key){
	
	while(key != 1){
		limpiar_pantalla();
		printf("\nPor favor ingrese el número de usuario proporcionado con el manual del programa:   ");
		scanf("%d", &usu);
		if (usu == 2612){
			printf("\nUsuario correcto \n");
			key = 1;
		}else {
			printf("Ha ingresado un usuario incorrecto, vuelva a intentarlo:  ");
			key = 0;
		}
	}

}

int menu_princi(int *men){ 			//añadido do while con un contador interno para no provocar programa corrupto
	limpiar_pantalla();
	recuadro();
	printf("\t\t	Menú principal del programa \n");
	recuadro();
	printf("1.-Índice general de los libros guardados\n2.-Instrucciones de uso\n3.-Añadir libro\n-1 para salir\n");
	recuadro();
	printf("Opción elegida: ");
	scanf("%d", &menprinici);
	*men = menprinici;
	getchar();

	return *men;
	
	
}

void segun_menu(int men){
	int parosegunme;

	do{
		autor2 = fopen("autor.txt", "a+");
		libro2 = fopen("librog.txt", "a+");
		anio2 = fopen("anio.txt", "a+");
		genero2 =  fopen("gener.txt", "a+");
		limpiar_pantalla();
	switch(men){
		case 1: caso_1(indi);
				if(ind ==-1)
					parosegunme = ind;
				caso_1segun();
				getchar();break;
		case 2:limpiar_pantalla();
			caso_2segun(ins);
				if(ins == -1)
				parosegunme = ins;
				getchar();break;
		case 3: 
				limpiar_pantalla();
				caso_3(men3);
				if(men3 == -1)
				parosegunme = men3;
				caso_3segun();break;
		default: limpiar_pantalla();
			getchar();break;
	}
	}while(parosegunme != -1);
}

int caso_1(int indi){
	
	printf("Ha ingresado al índice de libros guardados.\n");
	printf("Seleccione la opción que desea realizar: \n\n");
	getchar();
	limpiar_pantalla();
	recuadro();
	printf("\t\t\tÍndice \n");
	recuadro();
	printf("\n1.-Nombres del libro\n2.-Mostrar librero\n-1 Para salir\nOpción: ");
	scanf("%d", &indi);
	ind = indi;
	return ind;
}

void caso_1segun(){
	int i,j;
	limpiar_pantalla();
	switch(ind){
		case 1: printf("\nNombre de libros:\n");
				recuadro();
					lib();
					fclose(libro2);
					fclose(autor2);
					fclose(anio2);
					fclose(genero2);
				getchar();break;
		  case 2: printf("Mostrando los espacios en librero:  \n");
		  			recuadro();
					for(i=0;i<3;i+=1){
						for ( j = 0; j < 3; j++)
						{
							printf("%d\t", librero[i][j]);
						}
						printf("\n");
					}	
					getchar();			
		  				break;
		  
		  /*  case 2: printf("Opcion en mantenimiento:  \n");/*
				printf("Los autores registrados en la base son: \n");
				recuadro();
				aut();
				fclose(autor2);
				fclose(libro2);
				fclose(anio2);
				getchar();break;*/
		 case 3: printf("Opcion en mantenimiento:  \n");
		  //~ printf("Libros por año de publicación: ");
				//~ recuadro();
				//~ an();
				//~ fclose(anio2);
				getchar();break;
		case 4: printf("Opcion en mantenimiento:  \n");
				//~ printf("Libros por género literario: \n");
				//~ recuadro();
				//~ ge();
				//~ fclose(genero2);
				getchar();break;
		default: printf("Opción no válida:   ");break;
	}
}
int caso_2segun(int in){
	recuadro();
	printf("Ha ingresado a las instrucciones de uso,a continuación se le darán \nlas principales recomendaciones del desarrollador para el óptimo uso \ndel programa\n");
	recuadro();
	getchar();
	limpiar_pantalla();
	recuadro();
	printf("\tInstrucciones de uso\n");
	recuadro();
	printf("Si desea salir, teclee -1\n\n");
	recuadro();
	printf("\n1.- Para añadir un libro deberá ingresar a la opción 2. Dentro de esta opción deberá incluir de forma seguida los datos que se le solicitan.\n");
	printf("\n2.-Al añadir un libro, el programa detectará que ha terminado de escribir un dato al presionar enter.\n");
	printf("\n3.-Los libros se guardarán en forma de lista ordenada según el usuario ingrese los datos.\n");
	printf("\n4.-Para escribir los datos de los libros es importante que no utilice los siguientes símbolos: * + _ -\nSi las utiliza, el programa no funcionará de manera correcta.");-
	scanf("%d", &in);
	ins = in;
return ins;
}
int aut (){
	
	if (autor2 == NULL ){
		
		perror("Error en la apertura del archivo");
		fclose(autor2);
		return 1;
		
	}
	char no;
	char sep = '+';
	printf("Autor: ");

	while(feof(autor2) == 0){
	
	no = fgetc(autor2);
	if(no == sep){
		printf("\t");	
			an();
		}else printf("%c", no);
		
	}
}

int lib(){
	
	if (libro2 == NULL ){
		
		perror("Error en la apertura del archivo");
		fclose(libro2);
		return 2;
	}
	char li;
	char sepa = '-';
	printf("Título: ");	
	while(feof(libro2) == 0){
	
	li = fgetc(libro2);
		if( li == sepa ){
				printf("\t");
				aut();		
			}else printf("%c", li);
			
			
	}	
}

int an(){
	
	if (anio2 == NULL ){
		
		perror("Error en la apertura del archivo");
		fclose(anio2);
		return 2;
	}
	char a;
	char sepa='*';
	printf("Año: ");
	while(feof(anio2)==0){
	
	a = fgetc(anio2);
		if (a == sepa){
			printf("\t");
			ge();
			
		}else printf("%c", a);
	
	}
}
		
int ge(){
	
	if (genero2 ==NULL){
		perror("Error en la apertura del archivo");
	}
	char g;
	char sepa = '_';
	printf("Género: ");
	while(feof(genero2) ==0){
	
		g =fgetc(genero2);
		if (g == sepa){
			printf("\n");
			lib();


		}else	printf("%c", g);
		
	 }
 }

int caso_3(int menulibro){
	limpiar_pantalla();
	printf("Ha elegido la opción para añadir un libro. \n");
	getchar();
	limpiar_pantalla();
	recuadro();
	printf("\t\tDatos del libro\n");
	recuadro();
	printf("1.-Nombre del libro\n2.-Autor del libro\n3.-Año del libro\n4.-Género\n5.-Reservar espacio en librero\n-1 Para regresar\nOpción: ");
	scanf("%d", &menulibro);
	men3 = menulibro;
	return men3;	
}

void caso_3segun(){
	int reserv, i, j;

	limpiar_pantalla();
	switch (men3){
		
		case 1:printf("Ingresa el nombre del libro: \n");
				recuadro();
				getchar();
				writelibro();
				fclose ( libro2 );break;
		case 2: printf("Ingresa el nombre del autor: \n");
				recuadro();
				getchar();
				writeautor();
				fclose(autor2);break;
		case 3:printf("Ingresa el año del libro: \n");
				recuadro();
				getchar();
				writeanio();
				fclose(anio2);break;
		case 4:printf("Ingresa el género del libro: \n");
				recuadro();
				getchar();
				writegenero();
				fclose(genero2);break;	
		
		case 5: printf("Resevar espacio en el librero: \n");
				reserv = 1;
				fflush(stdin);
					printf("Se ha reservado el espacio en el librero");
				libre(reserv);			
				fflush(stdin);
				getchar();
					break;
		case 6: printf("Vuelva pronto");break;	
}
}

int writelibro()
{
 	char caracter;
	char separador = '-';
 	while((caracter = getchar()) != '\n')
 	{
		fputc(caracter, libro2);
 	}
	fprintf(libro2,"%c", separador);
 	limpiar_pantalla();
 	
 	return 0;
}

int writeautor()
{
 	char caracter;
	char separador = '+';
 	while((caracter = getchar()) != '\n'){
		fputc(caracter, autor2);
 	}
	fprintf(autor2,"%c", separador );
 	limpiar_pantalla();
 	
 	return 0;
}

int writeanio()
{
 	char caracter;
	char separador = '*';

 	while((caracter = getchar()) != '\n')
 	{
		fputc(caracter, anio2);
 	}
	fprintf(anio2,"%c", separador);
 	limpiar_pantalla();
 	
 	return 0;
}

int writegenero()
{
	char caracter;
	char separador = '_';
	while((caracter = getchar()) != '\n')
	{
	fputc(caracter, genero2);
	}
	fprintf(genero2,"%c", separador );
	limpiar_pantalla();
	return 0;
}

int libre( int reserv){
		int i, j;
	
		for(i = 0; i < 3; i +=1){
			for(j= 0; j <3; j+=1){
				if (librero[i][j] == 0){
					librero[i][j] = 1;
					j = 10;
					i = 10;
				}
			}
			printf("\n");
		}
fflush(stdin);
getchar();
return 0;
}