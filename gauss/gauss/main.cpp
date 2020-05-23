#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3




void initialisation (void);
void resolution (void);
void resultats (void);



long int i,j,k;
double Vector[N+1];
double Matrix[N+1][N+1];



void initialisation ()
{
 printf("\n\nVvedenie znacheniy");
 for (i=1; i<=N; i++)
 {
  printf("\nY[%ld]=",i);
  scanf("%lf",&Vector[i]);
 }

 printf("\n\nVvedenie coeffitsiyntov");
 for (i=1; i<=N; i++)
 for (j=1; j<=N; j++)
 {
  printf("\nMatrix[%ld][%ld]=",i,j);
  scanf("%lf",&Matrix[i][j]);
 }
}



void resolution ()

{
 double r;

 for (i=1; i<=N; i++)
 {
  k=i;
  r=fabsl(Matrix[i][i]);
  for (j=i+1; j<=N; j++)
  if (fabsl(Matrix[j][i])>r)
  {
   k=j;
   r=fabsl(Matrix[j][i]);
  }

  if (r==0)
  {
   printf("\nNe imeet edinstvennogo reshenia");
   exit(1);
  }

  if (k!=i)
  {
   r=Vector[k];
   Vector[k]=Vector[i];
   Vector[i]=r;
   for (j=i; j<=N; j++)
   {
    r=Matrix[k][j];
    Matrix[k][j]=Matrix[i][j];
    Matrix[i][j]=r;
   }
  }

  r=Matrix[i][i];
  Vector[i]=Vector[i]/r;
  for (j=i; j<=N; j++)
   Matrix[i][j]=Matrix[i][j]/r;

  for (k=i+1; k<=N; k++)
  {
   r=Matrix[k][i];
   Vector[k]=Vector[k]-r*Vector[i];
   for (j=i; j<=N; j++)
    Matrix[k][j]=Matrix[k][j]-r*Matrix[i][j];
  }
 }

 for (i=N-1; i>0; i--)
 for (j=i+1; j<=N; j++)
  Vector[i]=Vector[i]-Matrix[i][j]*Vector[j];
}



void resultats ()
{
 printf("\nVyvod otveta");
 for (i=1; i<=N; i++)
  printf("\nX[%ld]=%lf",i,Vector[i]);
}



int main ()

{
 initialisation ();
 resolution ();
 resultats ();
}
