#include "stdio.h"
#define DEBUG 0
/*Do thi*/
typedef struct {
    int A[100][100];
    int n;
}Graph;

int main(){
    //khai bao
    Graph G;
    int n, m, a, b, c, d;
	int hang[100], stacdxh[100];
    //khoi tao
    scanf("%d%d", &n, &m);
		
    for (d=1;d<=n;d++){
    	hang[d]=-1;
    	stacdxh[d] = 0;
        for (c=1;c<=n;c++)
            G.A[d][c] = 0;
            
    }
    G.n = n;

    //nhap dl
    for (d=0;d<m;d++) {//dong
        scanf("%d%d", &a, &b);
        G.A[a][b] = 1;
        stacdxh[b]++;
    }

	int lanlap = 0, sldddxh = 0;
	do{
		//xep hang cac dinh pahi dc xh o lan lap nay
		for (d=1;d<=n;d++) {
			if (hang[d]==-1 && stacdxh[d]==0){
				hang[d] = lanlap;
				sldddxh++;
			}				
		}
		
		//giam chi so stacdxh cho anh cua cac dinh vua duoc xh
		for (d=1;d<=n;d++) {
			if (hang[d]==lanlap){ //d la dinh vua duoc xh
				for (c=1;c<=n;c++){
					if (G.A[d][c])//c la anh cua d ~ co cung d-->c
						stacdxh[c]--;
				}
			}				
		}

		lanlap++;
	}while (sldddxh < n);//tat ca cac dinh deu da duoc xh

	for (d=1;d<=n;d++) 
	printf("\n%d", hang[d]);
}

