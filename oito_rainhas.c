#include <stdio.h>
#include <stdlib.h>
int cont=0;
int tab[8]={0,0,0,0,0,0,0,0};

int valida(int c,int i){
	int j;
	for (j=0;j<c;j++)
	{
		if (tab[j]==i) return 0;
		if (tab[j]-j==i-c) return 0;
	}
	return 1;
}


int back(int c){
	int i;
	if (c==8){
		printf("%d - ",++cont);
		for (i=0;i<8;i++) printf("%d ",tab[i]+1);
			printf("\n\n");
			return 1;
	}
	for (i=0;i<8;i++){
		if (valida(c,i)){
			tab[c]=i;
			if (back(c+1)) return 1;
			tab[c]=0;
		}
	}
	return 0;
}

int main(){
	back(0);

}
