#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 9
void muestra(int mat[MAX][MAX]);
int llenasol(int mat[MAX][MAX]);
void creasud(int mat[MAX][MAX],int matllenar[MAX][MAX]);
void muestrasud(int matllenar[MAX][MAX]);
void llenajuego(int matllenar[MAX][MAX]);
main()
{
int a=0,i,j;
int mat[MAX][MAX],matllenar[MAX][MAX];
srand(time(0));
system("clear");
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
mat[i][j]=0;
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
matllenar[i][j]=0;
//muestra(mat);
llenasol(mat);
creasud(mat,matllenar);
llenajuego(matllenar);
return 0;
}
void muestra(int mat[MAX][MAX])
{
int i,j;
printf(" 0 1 2 3 4 5 6 7 8\n");
for(i=0;i<MAX;i++){
if(i==3 || i==6){
printf("\n");
printf(" %d ",i);
}
else
printf(" %d ",i);
for(j=0;j<MAX;j++){
printf("[%d]",mat[i][j]);
if(j==2 || j==5)
printf(" ");
}
printf("\n");
}
}
int llenasol(int mat[MAX][MAX])
{
int i,j,aux,auxa;
int ara[3],arb[3],arc[3];
for(i=0;i<MAX;i++){//llena primera linea aleatoriamente...
mat[0][i]=(rand()%9)+1;
if(i>0){
for(j=i-1;j>=0;j--){
while(mat[0][i]==mat[0][j]){
mat[0][i]=(rand()%9)+1;
j=i-1;
}
}
}
}
//muestra(mat);
//printf("\n");
for(i=0;i<3;i++){//crea y mueve los arreglos
ara[i]=mat[0][i];
mat[1][i+6]=ara[i];
mat[2][i+3]=ara[i];
//printf("[%d]",ara[i]);
}
//printf("\n");
for(i=0;i<3;i++){
arb[i]=mat[0][i+3];
mat[1][i]=arb[i];
mat[2][i+6]=arb[i];
//printf("[%d]",arb[i]);
}
//printf("\n");
for(i=0;i<3;i++){
arc[i]=mat[0][i+6];
mat[1][i+3]=arc[i];
mat[2][i]=arc[i];
//printf("[%d]",arc[i]);
}
//printf("\n");
//muestra(mat);
aux=ara[0];//modifica arreglos
auxa=ara[2];
ara[2]=ara[1];
ara[0]=auxa;
ara[1]=aux;
aux=arb[0];
auxa=arb[2];
arb[2]=arb[1];
arb[0]=auxa;
arb[1]=aux;
aux=arc[0];
auxa=arc[2];
arc[2]=arc[1];
arc[0]=auxa;
arc[1]=aux;
for(i=0;i<3;i++){//mueve los arreglos
mat[3][i]=ara[i];
mat[4][i+6]=ara[i];
mat[5][i+3]=ara[i];
//printf("[%d]",ara[i]);
}
//printf("\n");
for(i=0;i<3;i++){
mat[3][i+3]=arb[i];
mat[4][i]=arb[i];
mat[5][i+6]=arb[i];
//printf("[%d]",arb[i]);
}
//printf("\n");
for(i=0;i<3;i++){
mat[3][i+6]=arc[i];
mat[4][i+3]=arc[i];
mat[5][i]=arc[i];
//printf("[%d]",arc[i]);
}
//muestra(mat);
aux=ara[0];//modifica arreglos
auxa=ara[2];
ara[2]=ara[1];
ara[0]=auxa;
ara[1]=aux;
aux=arb[0];
auxa=arb[2];
arb[2]=arb[1];
arb[0]=auxa;
arb[1]=aux;
aux=arc[0];
auxa=arc[2];
arc[2]=arc[1];
arc[0]=auxa;
arc[1]=aux;
for(i=0;i<3;i++){//mueve los arreglos
mat[6][i]=ara[i];
mat[7][i+6]=ara[i];
mat[8][i+3]=ara[i];
//printf("[%d]",ara[i]);
}
//printf("\n");
for(i=0;i<3;i++){
mat[6][i+3]=arb[i];
mat[7][i]=arb[i];
mat[8][i+6]=arb[i];
//printf("[%d]",arb[i]);
}
//printf("\n");
for(i=0;i<3;i++){
mat[6][i+6]=arc[i];
mat[7][i+3]=arc[i];
mat[8][i]=arc[i];
//printf("[%d]",arc[i]);
}
//muestra(mat);//muestra la solucion.....
//printf("\n");
}
void creasud(int mat[MAX][MAX],int matllenar[MAX][MAX])//llena el juego...
{
int i,j;
matllenar[0][1]=mat[0][1];
matllenar[0][4]=mat[0][4];
matllenar[0][8]=mat[0][8];
matllenar[1][1]=mat[1][1];
matllenar[1][2]=mat[1][2];
matllenar[1][4]=mat[1][4];
matllenar[1][6]=mat[1][6];
matllenar[2][2]=mat[2][2];
matllenar[2][3]=mat[2][3];
matllenar[2][6]=mat[2][6];
matllenar[3][0]=mat[3][0];
matllenar[3][3]=mat[3][3];
matllenar[3][5]=mat[3][5];
matllenar[3][7]=mat[3][7];
matllenar[4][2]=mat[4][2];
matllenar[4][4]=mat[4][4];
matllenar[4][5]=mat[4][5];
matllenar[4][7]=mat[4][7];
matllenar[4][8]=mat[4][8];
matllenar[5][1]=mat[5][1];
matllenar[5][2]=mat[5][2];
matllenar[5][5]=mat[5][5];
matllenar[5][6]=mat[5][6];
matllenar[5][7]=mat[5][7];
matllenar[6][2]=mat[6][2];
matllenar[6][4]=mat[6][4];
matllenar[6][5]=mat[6][5];
matllenar[6][6]=mat[6][6];
matllenar[6][8]=mat[6][8];
matllenar[7][4]=mat[7][4];
matllenar[7][5]=mat[7][5];
matllenar[7][7]=mat[7][7];
matllenar[8][0]=mat[8][0];
matllenar[8][1]=mat[8][1];
matllenar[8][7]=mat[8][7];
muestrasud(matllenar);
}
void muestrasud(int matllenar[MAX][MAX])//muestra juego...
{
int i,j;
printf(" 0 1 2 3 4 5 6 7 8\n");
for(i=0;i<MAX;i++){
if(i==3 || i==6){
printf("\n");
printf(" %d ",i);
}
else
printf(" %d ",i);
for(j=0;j<MAX;j++){
printf("[%d]",matllenar[i][j]);
if(j==2 || j==5)
printf(" ");
}0
printf("\n");
}
}
void llenajuego(int matllenar[MAX][MAX])
{
int i,j;
int matcop[MAX][MAX];
for(i=0;i<MAX;i++)
for(j=0;j<MAX;j++)
matcop[i][j]=matllenar[i][j];
while(matllenar!=0){
printf("\nke coordenada desea llenar?\n");
printf("\nx= ");
scanf("%d",&i);
printf("\ny= ");
scanf("%d",&j);
while(matcop[i][j]!=0){
printf("\nIngrese nuevamente las coordenadas:\n");
printf("\nx= ");
scanf("%d",&i);
printf("\ny= ");
scanf("%d",&j);
}
printf("\nke numero desea ingresar en (%d,%d): ",i,j); 
scanf("%d",&matllenar[i][j]);
system("clear");
muestrasud(matllenar);
}
}