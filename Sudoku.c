/*- S U D O K U -*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



int i, j, k, n, m, aux;
int sudoku[9][9], correcto = 1, r, r2;
int numero[9], random = 0;

int main(){
	int aux;
	int exit = 0;
	
	while(!exit)
			{

				menu();
				printf("\nRespuesta: ");
				scanf("%d", &aux);
				
				switch (aux)
				{
					case 1:
						reglas();
						break;
					
					case 2:
						comenzarJuego();
						break;
						
					case 3:
						exit = 1;
						break;
						
						default: printf("\nOpcion no valida!");
				}
			}
			
		return 0;
}



	int menu(){
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		system("cls");
		system("Color 7");
		
		SetConsoleTextAttribute(hConsole, 4);
		printf(" - - - - - - ");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" S U D O K U ");
		SetConsoleTextAttribute(hConsole, 4);
		printf(" - - - - - - \n");
		SetConsoleTextAttribute(hConsole, 7);
		printf("\nMenu: ");
		
		printf("\n1. Reglas del Juego");
		printf("\n2. Comenzar el Juego");
		printf("\n3. Salir");
		
		
		//Reseteamos la variable "Sudoku"
		for(i=0;i<9;i++)
		{
			numero[i] = 0;
			for(j=0;j<9;j++)
			{
				sudoku[i][j] = 0;
			}
		}
	}
	
	
	int reglas()
	{
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		
		system("cls");
		
		SetConsoleTextAttribute(hConsole, 4);
		printf("- - - ");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" REGLAS ");
		SetConsoleTextAttribute(hConsole, 4);
		printf(" - - - \n");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" 1. Cada bloque es de 3x3 y contiene un numero aleatorio \n 2. NO  se pueden repetir numeros tanto de forma horizontal como vertical \n 3. Hay que completar las casillas vacías con los números del 1 al 9\n 4. NO HAY VIDAS Tenes una oportunidad unica \n");
		
		printf("____________________________________________________________ \n\n Seleccione:  \n 1.Menu \n ");
		scanf("%d", &aux);
		
		//RESPUESTA INCORRECTA
		do{
			if(aux != 1)
			{
				printf("La respuesta ingresada NO es correcta\n Intentelo Nuevamente: \n");
				printf("Seleccione \n 1.Menu \n Respuesta: ");
				scanf("%d", &aux);
			}	
			
		}while (aux!= 1);
	}
	
	
	int comenzarJuego(){
		
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
		
		system("cls");
		
		int guia[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int ubiX[9], h;
		int ubiY[9];
		
		//primero hacemos un rand para la ubicacion
			//0 ubicacion
			ubiX[0] = rand() % 2;
			ubiY[0] = rand() % 2;
			
			//1era ubicacion
			ubiX[1] = rand() % 2 + 3;	//Determinamos entre que numero estara
			ubiY[1] = rand() % 2;
			
			//2da ubicacion
			ubiX[2] = rand() % 2 + 6;
			ubiY[2] = rand() % 2;
			
			//- - - -
			
			//3era ubicacion
			ubiX[3] = rand() % 2;
			ubiY[3] = rand() % 2 + 3;
			
			//4ta ubicacion
			ubiX[4] = rand() % 2 + 3;	
			ubiY[4] = rand() % 2 + 3;
			
			//5ta ubicacion
			ubiX[5] = rand() % 2 + 6;
			ubiY[5] = rand() % 2 + 3;
			
			//- - - -
			
			//6ta ubicacion
			ubiX[6] = rand() % 2;
			ubiY[6] = rand() % 2 + 6;
			
			//7ma ubicacion
			ubiX[7] = rand() % 2 + 3;	
			ubiY[7] = rand() % 2 + 6;
			
			//8tava ubicacion
			ubiX[8] = rand() % 2 + 6;
			ubiY[8] = rand() % 2 + 6;
			
			
			
	//y ahora un rand para el numero
	
	
			
	srand (time(NULL));	
	for(i = 0;i<9;i++)
	{
		int yaexiste = 0;
		do
		{
			yaexiste = 0;
			random = rand() % 9 + 1;
			for(j=0;j<9;j++)
			{
				if(random == numero[j])
					yaexiste = 1;
			}
		} while(yaexiste);
		numero[i] = random;
	}
	
		
	//Almacenamos los numero en la variable Sudoku
	for(i=0;i<9;i++)
	{
		sudoku[ubiX[i]][ubiY[i]] = numero[i];	
	}
		
		
		printf("\n TABLERO: \n\n");
		printf(" - ");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" | ");
		for(i=0;i<9;i++)
		{
			if(i == 0)
			{
				for(h=0;h<9;h++)
				{
					SetConsoleTextAttribute(hConsole, 8);
					printf(" %d ", guia[h]);
					
					if(h == 2 || h == 5)
					{
						SetConsoleTextAttribute(hConsole, 7);
						printf(" | ");
					}
					
					
				}
				printf("\n");
				SetConsoleTextAttribute(hConsole, 7);
				printf("--------------------------------------\n");
			}
		
			for(j=0;j<9;j++)
			{	
			
				if(i == 0 && j == 0|| i == 1 && j == 0|| i == 2 && j == 0|| i == 3 && j == 0 || i == 4 && j == 0 || 
					i == 5&& j == 0 || i == 6 && j == 0 || i == 7&& j == 0 || i == 8&& j == 0)
				{
					SetConsoleTextAttribute(hConsole, 8);
					printf(" %d ", guia[i]);
					
				}
				
					SetConsoleTextAttribute(hConsole, 7);
					if(i == 0 && j == 0|| i == 1 && j == 0|| i == 2 && j == 0|| i == 3 && j == 0 || i == 4 && j == 0 || 
					i == 5&& j == 0 || i == 6 && j == 0 || i == 7&& j == 0 || i == 8&& j == 0)
					{
						printf(" | ");
					}
				

				//Ahora vamos hacer que solo los numeros por default tengan color
//				if(ubiX[i] == j  && ubiY[i] == i)
//				{
//					SetConsoleTextAttribute(hConsole, 3);
//					printf(" %d ", sudoku[i][j]);
//				}
//			
//				else 
//				{
					
					SetConsoleTextAttribute(hConsole, 7);
					printf(" %d ", sudoku[i][j]);
//				}
	
				SetConsoleTextAttribute(hConsole, 7);

	
				if(j == 2 || j == 5)
				{
					printf(" | ");
					
				}
				
			}
			printf("\n");
			if(i == 2 || i == 5)
			{
				printf("--------------------------------------");
				printf("\n");
			}
		}
		
		
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
				if(sudoku[i][j] == 0)
				{
					printf("Ingrese un numero a la \nFILA: %d \nCOLUMNA: %d\n Respuesta: ", i + 1, j + 1);
					scanf("%d", &aux);
						
					//Respuesta Incorrecta	
						
					do{
						if(aux < 1 || aux > 9)
						{
							printf("La respuesta ingresada NO es correcta\n Intentelo Nuevamente: \n");
							printf("Ingrese un numero a la \nFILA: %d \nCOLUMNA: %d\n Respuesta: ", i + 1, j + 1);
							scanf("%d", &aux);
						}
					}while(aux < 1 || aux > 9);	
					
					
					sudoku[i][j] = aux;

					//Tablero
						printf(" - ");
						printf(" | ");
						for(n=0;n<9;n++)
						{
							if(n == 0)
							{
								//numeros de arriba
								for(h=0;h<9;h++)
								{
									SetConsoleTextAttribute(hConsole, 8);
									printf(" %d ", guia[h]);
									
									if(h == 2 || h == 5)
									{
										SetConsoleTextAttribute(hConsole, 7);
										printf(" | ");
									}
									
									
								}
								printf("\n");
								SetConsoleTextAttribute(hConsole, 7);
								printf("--------------------------------------\n");
							}
							
							for(m=0;m<9;m++)
							{	
								if(n == 0 && m == 0|| n == 1 && m == 0|| n == 2 && m == 0|| n == 3 && m == 0 || n == 4 && m == 0 || 
								n == 5&& m == 0 || n == 6 && m == 0 || n == 7&& m == 0 || n == 8&& m == 0)
								{
									SetConsoleTextAttribute(hConsole, 8);
									printf(" %d ", guia[n]);							
								}
	
								SetConsoleTextAttribute(hConsole, 7);
								
								if(n == 0 && m == 0|| n == 1 && m == 0|| n == 2 && m == 0|| n == 3 && m == 0 || n == 4 && m == 0 || 
								n == 5&& m == 0 || n == 6 && m == 0 || n == 7&& m == 0 || n == 8&& m == 0)
								{
									printf(" | ");
								}
								
								//Ahora vamos hacer que solo los numeros por default tengan color
//								if(ubiX[0] == m && ubiY[0] == n ||
//									ubiX[1] == m && ubiY[1] == n ||
//									ubiX[2] == m && ubiY[2] == n ||
//									ubiX[3] == m && ubiY[3] == n ||
//									ubiX[4] == m && ubiY[4] == n ||
//									ubiX[5] == m && ubiY[5] == n ||
//									ubiX[6] == m && ubiY[6] == n ||
//									ubiX[7] == m && ubiY[7] == n ||
//									ubiX[8] == m && ubiY[8] == n 
//								)
//								{
//									SetConsoleTextAttribute(hConsole, 3);
//									printf(" %d ", sudoku[n][m]);
//								}
//								
//								else 
//								{
									SetConsoleTextAttribute(hConsole, 7);	
									printf(" %d ", sudoku[n][m]);
//								}
//								
//								SetConsoleTextAttribute(hConsole, 7);
//				
								if(m == 2 || m == 5)
								{
									printf(" | ");
									
								}
								
							}
							printf("\n");
							if(n == 2 || n == 5)
							{
								printf("--------------------------------------");
								printf("\n");
							}
						}
				}		
		}
	}
	
		
	int tableroCorrecto = 1;
	
	//CORRECCION
	
	//Corroboramos las filas
	
	for(i=0;i<9;i++)
	{
		int numeros[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		for(j=0;j<9;j++)
		{
			numeros[sudoku[i][j]] = 0;
		}
		
		for (k=1;k<10;k++)
		{
			if (numeros[k] == 1)
			{
				correcto = 0;
				tableroCorrecto = 0;
			}
		}		
	}
	
	//Corroboramos las Columas
	
	for(j=0;j<9;j++)
	{
		int numeros[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		for(i=0;i<9;i++)
		{
			numeros[sudoku[i][j]] = 0;
		}
		
		for (k=1;k<10;k++)
		{
			if (numeros[k] == 1)
			{
				correcto = 0;
				tableroCorrecto = 0;
			}
		}
	}
	

	
	
// PERDIO	

	if(correcto == 0)
	{
		system ("COLOR 4F");
		printf("\n\t \t PERDISTE!\n\n");
		printf("Seleccione: \n 1. Ver Errores \n 2. Menu\n Respuesta: ");
		scanf("%d", &r);
		
		
		//RESPUESTA INCORRECTA
		do{
			if(r < 1 || r > 2)
			{
				printf("La respuesta ingresada NO es correcta\n Intentelo Nuevamente: \n");
				printf("Seleccione: \n 1. Ver Errores \n 2. Menu\n Respuesta: ");
				scanf("%d", &r);
			}
		}while(r < 1 || r > 2);
		
		
		if(r == 1)
		{
			
		//Filas	
			for(i=0;i<9;i++)
			{
				int numeros[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				for(j=0;j<9;j++)
				{
					numeros[sudoku[i][j]] = 0;
				}
				
				for (k=1;k<10;k++)
				{
					if (numeros[k] == 1)
					{
						correcto = 0;
						tableroCorrecto = 0;
					}
				}
					if(correcto == 0)
					{
						printf("La FILA %d no cumple con lo solicitado\n", i);
					}	
			}
		
		//Columas
		
			for(j=0;j<9;j++)
			{
				int numeros[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				for(i=0;i<9;i++)
				{
					numeros[sudoku[i][j]] = 0;
				}
		
				for (k=1;k<10;k++)
				{
					if (numeros[k] == 1)
					{
						correcto = 0;
						tableroCorrecto = 0;
					}
				}
					if(correcto == 0)
					{
						printf("La COLUMNA %d no cumple con lo solicitado\n", j);
					}
			}
			
			
			printf("____________________________________________________________________________________________________  \n\n Seleccione: 1.Menu \n Respuesta: ");
			scanf("%d", &r);
			
			do{
				if(r != 1)
				{
					printf("La respuesta ingresada NO es correcta\n Intentelo Nuevamente: \n ");
					printf("Seleccione: 1.Menu \n Respuesta: ");
					scanf("%d", &r);	
				}
			}while(r > 1 || r < 1);
			
			if(r == 1)
			{
				return 0;
			}
		}
	
		if(r == 2)
		{
			return 0;
		}
	
	}

//GANÓ

	if(tableroCorrecto == 1)
	{
		int exit = 0;
		system ("COLOR 2F");
		printf("\n\t\tFelicidades usted a ganado el juego!\n") 	;
		
		printf("Seleccione \n 1. Menu  Respuesta: ");
		scanf("%d", &r2);
		
		//Respuesta Incorrecta
		do{
			if(r2 != 1)
			{
				printf("La respuesta ingresada NO es correcta\n Intentelo Nuevamente: \n ");
			}
				printf("Seleccione \n 1. Menu \n Respuesta: ");
				scanf("%d", &r2);	
			
		}while(r2 != 2);
		
		if(r2 == 1)
		{
			return 0;
		}

		
		
		
	}
	
}
