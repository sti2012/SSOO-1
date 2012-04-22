#include <stdio.h>

int main()
{
	int menu;
	printf("1 - Leer\n2 - Escribir\n3 - NADA\n\nSelecciona menu: _\b");
	scanf("%d", &menu);
	FILE *fp;

	if (menu == 1)
	{
		fp = fopen(".\\test.txt", "r");

	}

/*
	else if (menu == 2)
	{
		fp = fopen(".\\test.txt", "w+");

	}
*/	

	else printf("\nError!\n");

	fclose(fp);
	system("pause");
	return 0;
}




/*
	// char filename = "test.txt";
	// char mode = "r";

	FILE *fopen(const char *filename, const char *mode)

	http://www.cprogramming.com/tutorial/cfileio.html
	http://www.thinkage.ca/english/gcos/expl/c/lib/fopen.html

*/