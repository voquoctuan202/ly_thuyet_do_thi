#include "stdio.h"
#define DEBUG 1
/*Do thi*/
typedef struct {
    int A[100][100];
    int tg[100];
    int n;
}Graph;

int main(){
    //khai bao
    Graph G;
    int n, a, c, d, x, v, y;
	int stacct[100], saccT[100], t[100], T[100];
	int alpha, omega;
    
	//khoi tao
    scanf("%d", &n);
    alpha = n+1;
	omega = n+2;    
		
    for (d=1;d<=n+2;d++){
    	T[d] = t[d] = -1;
    	stacct[d] = saccT[d] = 0;
        for (c=1;c<=n+2;c++)
            G.A[d][c] = 0;
            
    }
    G.n = n;

    //nhap dl
    for (v=1;v<=n;v++) {//dong
    	if (DEBUG) printf("\nNhap du lieu viec %d\n", v);
        scanf("%d", &G.tg[v]);
        do {
        	scanf("%d", &a);
        	if (a>0){
        		G.A[a][v] = 1;
        		if (DEBUG) printf("Them cung %d-%d\n", a, v);
        		stacct[v]++;
				saccT[a]++;
        	}
        }while (a>0);
    }

	//them cac cung tu alpha toi cac dinh co STA = 0 
	for (d=1;d<=n;d++){
		if (stacct[d]==0){
			//them cung alpha --> d
			G.A[alpha][d] = 1;
			stacct[d]++;
			saccT[alpha]++;
			if (DEBUG) printf("Them cung %d-%d\n", alpha, d);
		}
		
	}
		
	//them cac cung tu cac dinh co SA = 0 toi omega
	for (d=1;d<=n;d++){
		if (saccT[d]==0){
			//them cung d --> omega
			G.A[d][omega] = 1;
			if (DEBUG) printf("Them cung %d-%d\n", d, omega);
			stacct[omega]++;
			saccT[d]++;
		}
	}
	
	if (DEBUG) {
		printf("\nstacct[]:");
		for (d=1;d<=n+2;d++) printf("%4d", stacct[d]);
		printf("\nsaccT[]:");
		for (d=1;d<=n+2;d++) printf("%4d", saccT[d]);
	}
	
	//tinh t
	if (DEBUG) printf("\nBat dau tinh t[]\n");
	
	t[alpha] = 0;
	//giam stacct cua cac anh cua alpha
	for (y=1;y<=n+2;y++){
		if (G.A[alpha][y])//y la anh cua alpha
			stacct[y]--;
	}
			
	for (d=1;d<=n+1;d++){
		//tim 1 x dinh co the tinh t
		for (x=1;x<=n+2;x++){
			if (stacct[x]==0 && t[x]==-1) break;
		}
		
		if (DEBUG) printf("Tim duoc dinh x=%d\n", x);
		//tinh t[x]
		int maxsum = -1;
		for (y=1;y<=n+2;y++){
			if (G.A[y][x])//y la ta cua x
				if (t[y] + G.tg[y] > maxsum)
					maxsum = t[y] + G.tg[y];
		}
		t[x] = maxsum;
		if (DEBUG) printf("t[%d] = %d\n", x, t[x]);
		
		//giam stacct cua cac anh cua x
		for (y=1;y<=n+2;y++){
			if (G.A[x][y])//y la anh cua x
				stacct[y]--;
		}
	}
	
	
	//tinh T
	T[omega] = t[omega];
	//giam saccT cua cac tao_anh cua omega
	for (y=1;y<=n+2;y++){
		if (G.A[y][omega])//y la tao_anh cua omega
			saccT[y]--;
	}
	for (d=1;d<=n+1;d++){
		//tim 1 x dinh co the tinh T
		for (x=1;x<=n+2;x++){
			if (saccT[x]==0 && T[x]==-1) break;
		}
		
		//tinh T[x]
		int minT = 9999999;
		for (y=1;y<=n+2;y++){
			if (G.A[x][y])//y la ANH cua x
				if (T[y] < minT)
					minT = T[y];
		}
		T[x] = minT - G.tg[x];
		
		//giam saccT cua cac tao_anh cua x
		for (y=1;y<=n+2;y++){
			if (G.A[y][x])//y la tao_anh cua x
				saccT[y]--;
		}
	}	
	
	printf("%d\n", t[omega]);
	for (d=1;d<=n+2;d++)
		printf("%d-%d\n", t[d], T[d]);
}

