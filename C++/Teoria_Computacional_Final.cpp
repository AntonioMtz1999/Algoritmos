//Gabriel Alonso Ramos Carrillo
//177001
//Programas Teoria Computacional
//19/08/23
#include <conio.h> //getch()
#include <stdio.h> //scanf y printf
#include <stdlib.h> //system
#include <locale.h> //código de idioma
#include <math.h> //para funciones trigonometricas
#include <time.h> //funcíón time
#include <string.h> //funcíón time
#include <iostream> 
using namespace std;
int n, a, numero, res1, number, number2, result=0, x, x1, resta, ignorar, ignorar1, resultado; //Variables globales
int str[10], str1[10]; //Global cadenas

void enteroACad(int a, char cad[]){ //funcion para convertir entero a cadena
	int nroDig = 0; //varible local
	int aux = a; //variable local que guarda el valor de a
	while(aux>0){ //Bucle para guardar el numero
		aux = aux/10; //dependiendo de los decimales, centesimas, milesimas
		nroDig++;
	}
	cad[nroDig] = '\0'; //posicion final es null
	aux=a; //mantiene el valor original de la variable global
	int pos = nroDig-1, dig;
	while(pos>=0){ //hace algo parecido al bucle de arriba
		dig = aux%10;
		aux=aux/10;
		cad[pos] = dig + '0';
		pos--;
	}
	
}

void mayor(char cad[]){ //funcion que nos ordena nuestros numeros guardados en una cadena de mayor a menor
	for(int i = 0; i < 4; i++){ //primer for para el numero que se va comparar
		for(int j = i + 1; j < 4; j++){ //segundo for que movera los numeros
			if(cad[i] < cad[j]){
				int temporal = cad[j]; //guardara el numero para seguirlo comparando y no perderlo
				cad[j] = cad[i];
				cad[i] = temporal;
			}
		}
	}
}

void menor(char cad[]){ //funcion que nos ordena nuestros numeros guardados de menor a mayor
	for(int i = 0; i < 4; i++){
		for(int j = i + 1; j < 4; j++){
			if(cad[i] > cad[j]){ //en escencia es el mismo codigo de la funcion de arriba
				int temporal = cad[j];//solo cambia ek signo de mayor a menor
				cad[j] = cad[i];
				cad[i] = temporal;
			}
		}
	}
}

int collatz(){ //funcion para la conjetura de collatz
	printf("\nIngresa un numero:\n");
	scanf("%d",&n); //se lee el valor del entero
	printf("\n");
	do { //empieza el ciclo
			if(n%2==0){ //se checa si el numero tiene residuo igual a 0 para marcarlo como un par
				n=n/2; //si es par el numero ingresado se divide entre 2
			//return N;
			printf("n es: %d\n", n);
			}
			else{ //si es impar
				n=(n*3)+1; //simplemente se hace esta operación
				printf("otro n es: %d\n", n);
				//N*=fact(N-1);
			}
	}while (n!=1);  //termina el ciclo
	//nPr=(fact(N))/(fact(N-R));
	//return nPr;
}

int kaprekar(){
	char cad[4], res[4], cad1[4], cad2[4]; //variables cadenas locales
	int i=0;
	printf("\nIngresa un numero que sea de 4 digitos:\nEj. 0001, 1999, 3457\n");
	scanf("%d",&a); //se ingresa el entero
	printf("\n");
	enteroACad(a, cad); //se llama a la funcion que convierte el entero en una cadena
	strcpy(cad1, cad); //se copia el valor de la cadena que contiene el numero original a otra cadena
	strcpy(cad2, cad); //se copia el valor de la cadena que contiene el numero original a otra cadena
	do{
		if(i==0) //solo es un if de control, para saber que apenas inicio el bucle
			printf("\n--------------------\n");
		else{ //aqui es donde comienza lo importante. esto comenzara a la segunda vuelta siempre
			strcpy(cad1, res); //copia el valor del resultado a esta cadena - luego se usara la funcion mayor
			strcpy(cad2, res);//copia el valor del resultado a esta cadena -- luego se usara la funcion menor
		}
		mayor(cad1); //se llama a la funcion mayor para arreglar los valores
		cout<<"\nMayor es : "<<cad1; //se revisa los cambios a la cadena
		menor(cad2);//se llama a la funcion menor para arreglar los valores
		cout<<"\nMenor es : "<<cad2;//se revisa los cambios a la cadena
		res1 = atoi(cad1)-atoi(cad2); //se hace una operacion para convertir 
		//las cadenas en enteros con el mayor y el menor y restarlos
		cout<<"\nEl res es : "<< res1 << "\n\n"; //el resultado de la resta de arriba
		enteroACad(res1, res); //el resultado se ingresa a una cadena
		i=1;
		getch();
	}while(res1 != 6174); //se hara hasta que el resulado sea 6174
return 0;
}
	
int rusa(){
	printf("Ingrese el primer numero\n");
	scanf("%i", &number);
	printf("Ingrese el segundo numero\n");
	scanf("%i", &number2);
	while(number >=1){ //se revisa que el numero sea mayor igual a 1
		if(number%2!=0){ //si el numero no es par se hace
			result += number2; //la siguiente suma para determinar el valor del resultado
		}
		number = number/2; //se divide el numero entre dos
		number2 = number2*2; //se multiplica el segundo numero para la suma que nos dara el resultado deseado de la multiplicacon
	}
	printf("The result is: %i", result);
}

int egipcia(){
	int y, exp =0;
	printf("\nIngresa un numero:\n");
	scanf("%d",&x);
	printf("\nIngresa un numero:\n");
	scanf("%d",&x1);
	printf("\n\n");
	do{ //se crea un bucle do-while
		y=pow(2,exp); // se hara que la variable y este aumentando a un exponente de 2, 1, 2, 4, 8, 16...
		str[exp] = y; //se guarda el valor de el binaro en esta cadena
		str1[exp] = x*y; //se multiplica el numero con la base. por ejemplo 15*2 = 30
		printf("\nImprime str: %d\t", str[exp]);
		printf("\tImprime str1: %d\n", str1[exp]);
		exp++;
	}while(y < x1 ); //se hara hasta que la variable 2 sea menor al segundo numero ingresado por ejemplo
	//para cuando 32 sea menor al segundo numero ingresado que es 37
	resta = x1 - str[exp-2]; //el valor de la resta
	ignorar = exp-2; //se guara el valor del limite de la cadena, por ej
	//si teniamos los numeros 1, 2, 4, 8 16, 32, 64, con este ignorar se ignorara al 64
	resultado += str1[ignorar];  //se suma el valor que este guardado en la posicion que sea el numero ignorar de arriba
	ignorar1 = ignorar; //se guarda el valor de nuesro limite
	do{ //se hace un bucle que terminara hata que ya no queden numeros que restar. Por ej
	//el segundo numero ingresado fue 37 se le resto 32. entonces es //5
		int i=0, mayor = 0, mayor1; //nuestras varibles de control
		while(str[i]>=mayor && str[i]<=resta){ //nuestro while que revisara que se sumen los numeros correctos
		// ej si nuestro primer numero fue 15 y el segundo 37. se sumaran el 480, el 60 y el 15 para dar un valor de 555
			mayor = str[i]; //se buscan los numeros que hay que resta para que el 37 llegue a 0
			mayor1 = str1[i]; //se encuentran los numeros a sumar para dar con el 555
			i++;
		}
	resultado += mayor1;
	resta -= mayor ;
	}while(resta != 0);
	printf("\n\tResultado deseado: %d\n", resultado );
}


void Info(){
	printf("Gabriel Alonso Ramos Carrillo \n"); //funcion que nos da el nombre del integrante del equipo que trabajo c++
	printf("177001 \n");
	printf("Teoria Computacional \n");
	printf("T35B \n");
	printf("Invierno 2023 \n");
	system("hostname"); //despliega el equipo
	system("whoami"); //despliega el nombre de usuario
	setlocale (LC_CTYPE, "Spanish");
	system ("color 0b"); //color de fondo y fuente
}

main(){  //programa principal
	char opcion=0;
	do { //empieza el ciclo
	system("cls"); //limpia la pantalla
	Info();
	printf("\nMENU DE OPCIONES:\n");
	printf("a.-Conjetura Collatz \n");
	printf("b.-Constante de Kaprekar \n");
	printf("c.-Multiplicacion Egipcia \n");
	printf("d.-Multiplicacion Rusa \n");
	printf("x.- Salir\n");
	printf("\n"); //linea en blanco
	printf("Seleccionar una operación\n");
	fflush(stdin); //vacia el cache de entrada para que no capture el enter
	scanf("%c",&opcion);
	printf("\n"); //linea en blanco
	switch (opcion){ //decisión múltiple
		case 'a': printf("Conjetura Collatz\n");
				n=0;
				collatz();
				getch();
			break; //salga del switch
		case 'b':	printf("\nConstante de Kaprekar\n");
				kaprekar();
				getch();
			break; //salga del switch
		case 'c': printf("Egipcia\n");
				egipcia();
				getch();
			break; //salga del switch
		case 'd': printf("Rusa\n");
				rusa();
				getch();
			break; //salga del switch
		case 'x': printf("Matane...");
			break; //salga del switch
		default: printf("Seleccionaste una opción inválida...");
	}
	printf("\n"); //linea en blanco
	printf("Presione cualquier tecla...\n"); //linea en blanco
	printf("\n"); //linea en blanco
	getch(); 
	}while (opcion!='x');  //termina el ciclo
}
