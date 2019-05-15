#include <stdio.h>
#include <stdlib.h>

int cont=0;
int tab[8][8]={{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

void mostra(){
	int i,j;
	printf("Solução %d:\n\n", ++cont);
	for (i=0;i<8;i++){
		for (j=0;j<8;j++){
			printf("%2d ",tab[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
}

void back(int nivel, int lin, int col){
	if (lin<0 lin>7 col<0 col>7) return;
	if (tab[lin][col]!=0) return;
	tab[lin][col]=nivel;
	if (nivel==64){
		mostra();
		tab[lin][col]=0;
		return;
	}
	back(nivel+1,lin-2,col-1);
	back(nivel+1,lin-2,col+1);
	back(nivel+1,lin-1,col-2);
	back(nivel+1,lin-1,col+2);
	back(nivel+1,lin+1,col-2);
	back(nivel+1,lin+1,col+2);
	back(nivel+1,lin+2,col-1);
	back(nivel+1,lin+2,col+1);
	tab[lin][col]=0;
}

int main(){
	back(1,0,0);
}
