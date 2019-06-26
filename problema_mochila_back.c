#include <stdio.h>
int M[3][6]={{6,4,8,7,9,10},
{5,10,7,8,9,7},
{5,3,5,8,6,10}};

int Max=20;

void back(int nivel,int soma,int sol[])
{
if (nivel==3 && soma==Max)
   {
   for (int i=0;i<3;i++) printf("%d ",sol[i]);
   printf("\n");
   }   
if (nivel==3) return;
int i;
for (i=0;i<6;i++)
   {
   sol[nivel]=M[nivel][i];
   back(nivel+1,soma+M[nivel][i],sol);
   }
}  

int main() {
  int sol[3];
  back(0,0,sol);
  return 0;
}
