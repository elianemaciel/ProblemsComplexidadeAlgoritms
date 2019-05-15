#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;
int tab[8][8]={{0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0}};

void mostra()
{
int i,j;
printf("Solução %d:\n\n",++cont);
for (i=0;i<8;i++){
   for (j=0;j<8;j++)
      printf("%2d ",tab[i][j]);
   printf("\n\n");
   }
printf("\n\n");
}

void back(int nivel, int lin, int col)
{
if (lin<0 || lin>7 || col<0 || col>7) return;
if (tab[lin][col]!=0) return;    
tab[lin][col]=nivel;
if (nivel==64) 
   {
   mostra();
   tab[lin][col]=0;
   return;
   }
if (cont>=100) return;
back(nivel+1,lin-2,col-1);
if (cont>=100) return;
back(nivel+1,lin-2,col+1);
if (cont>=100) return;
back(nivel+1,lin-1,col-2);
if (cont>=100) return;
back(nivel+1,lin-1,col+2);
if (cont>=100) return;
back(nivel+1,lin+1,col-2);
if (cont>=100) return;
back(nivel+1,lin+1,col+2);
if (cont>=100) return;
back(nivel+1,lin+2,col-1);
if (cont>=100) return;
back(nivel+1,lin+2,col+1);
if (cont>=100) return;
tab[lin][col]=0;
}    

int main()
{
    time_t t1,t2;
    time(&t1);
    
   back(1,0,0); 
    /* Trecho a ter o tempo medido */
    
    time(&t2);
    printf("tempo total: %d segundos \n", (int) t2-t1);
    system("pause");   
}
