#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *desc;
    desc = fopen("./primos.txt", "a");
	int j = 2;
	int num = argc;
	int magica = 0;


 while (num > 0)
 {
  for (int i=3; i <= (num / 2); i++)
  {
  if (num%i==0){
     magica = 1;
     break;
     }
}

if (magica == 1){
printf ("\n Este numero nao é primo\n");
magica = 0;
}
else
printf ("\n Este numero é primo\n");


}
	return 0;
}