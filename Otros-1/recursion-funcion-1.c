#include <stdio.h>

void print_me(int j, int depth)
{
	if (depth < j)
	{
		printf("Recursion! depth = %d | j = %d\n", depth, j);
		print_me(j, ++depth);
	}
}

int main(int argc, char const *argv[])
{
	int num;
	printf("Cuantas veces quieres recursividad?: ");
	scanf("%d", &num);
	print_me(num,0);
	system("pause");
	return 0;
}