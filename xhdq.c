#include "stdio.h"
#define DEBUG 0
/*Do thi*/
typedef struct {
    int A[100][100];
    int n;
}Graph;

int xephang(Graph* G, int d, int hang[]){
	if (hang[d]>=0) return hang[d];
	int hlnccta=-1, h, x;
	for (x=1; x<=G->n; x++)
		if (G->A[x][d]){
			h = xephang(G, x, hang);
			if (h > hlnccta)
				hlnccta = h;
		}

	hang[d] = hlnccta+1;
	return hlnccta+1;
}

int main(){
    //khai bao
    Graph G;
    int n, m, a, b, c, d;
	int hang[100];
	
    //khoi tao
    scanf("%d%d", &n, &m);
		
    for (d=1;d<=n;d++){
    	hang[d]=-1;
        for (c=1;c<=n;c++)
            G.A[d][c] = 0;
            
    }
    G.n = n;

    //nhap dl
    for (d=0;d<m;d++) {//dong
        scanf("%d%d", &a, &b);
        G.A[a][b] = 1;
    }

	for (d=1;d<=n;d++)
		printf("%d\n", xephang(&G, d, hang));
		
}

