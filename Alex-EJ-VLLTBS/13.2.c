/* 
	Ejercicio 13.2: codificar un programa que muestre por pantalla un
	menú con las siguientes opciones:
		1. Calcular area rectangulo.
		2. Calcular area del triangulo.
		3. Calcular area del circulo.
		4. Calcular longitud de la circunferencia.
		5. Salir.

		Según la opción que elija el usuario el programa le preguntará los
		datos necesarios y le mostrará el cálculo pedido. A continuación volverá
		a imprimir el menú y así sucesivamente hasta que el usuario elija la
		opción de "salir".
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

int main()
{
	int opcion;
	do
	{
		printf("\n1. Calcular area rectangulo.\n2. Calcular area del triangulo.\n3. Calcular area del circulo.\n4. Calcular longitud de la circunferencia.\n5. Salir.\n");
		printf("\nSelecciona el numero de menu [1-5]: ");
		scanf("%d", &opcion);
		if (opcion == 1)
		{
			float lado;
			float area;
			int continuar;
			char respuesta;

			continuar = 1;

			while (continuar == 1)
			{
				 printf("\nIntroduce lado del cuadrado: ");
				 scanf("%f", &lado);
				 area = lado*lado;
				 printf("\nEl area del cuadrado es %.2f.\n", area);
				 printf("Desea continuar [S/N]?");
				 scanf("\n%c", &respuesta);
				 if (respuesta == 'N' || respuesta == 'n')
					 continuar = 0;
			}

		}
		else if (opcion == 2)
		{
			float base;
			float altura;
			float area;
			int continuar;
			char respuesta;

			continuar = 1;

			while (continuar == 1)
			{
				printf("\nIntroduce base del triangulo: ");
				scanf("%f", &base);
				printf("\nIntroduce altura del triangulo: ");
				scanf("%f", &altura);
				area = (base*altura)/2;
				printf("\nEl area del triangulo es %.2f.\n", area);
				printf("Desea continuar [S/N]?");
				scanf("\n%c", &respuesta);
				if (respuesta == 'N' || respuesta == 'n')
					continuar = 0;
			}

		}
		else if (opcion == 3)
		{
			float radio;
			float area;
			int continuar;
			char respuesta;

			continuar = 1;

			while (continuar == 1)
			{
				printf("\nIntroduce radio de la circunferencia: ");
				scanf("%f", &radio);
				area = PI*pow(radio,2);
				printf("\nEl area de la circunferencia es %.2f.\n", area);
				printf("Desea continuar [S/N]?");
				scanf("\n%c", &respuesta);
				if (respuesta == 'N' || respuesta == 'n')
					continuar = 0;
			}

		}
		else if (opcion == 4)
		{
			float radio;
			float area;
			int continuar;
			char respuesta;

			continuar = 1;

			while (continuar == 1)
			{
				printf("\nIntroduce radio de la circunferencia: ");
				scanf("%f", &radio);
				area = 2*PI*radio;
				printf("\nLa longitud de la circunferencia es %.2f.\n", area);
				printf("Desea continuar [S/N]?");
				scanf("\n%c", &respuesta);
				if (respuesta == 'N' || respuesta == 'n')
					continuar = 0;
			}

		}
		else if (opcion == 5)
			printf("\n* Saliendo *\n");
		else
			printf("\n* Ha habido un error. Selecciona un numero de menu *\n");
	}while(opcion != 5);
	system("pause");
	return 0;
}