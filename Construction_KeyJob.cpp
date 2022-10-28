#include<stdio.h>
typedef struct{
	int A[100][100];
	int time[100];
	int n;
}Graph;

void init_graph(Graph *G,int n){
	G->n=n;
	int i,j;
	for(i=1;i<=n+2;i++)
		for(j=1;j<=n+2;j++)
			G->A[i][j]=0;
}
int main(){
	Graph G;
	int i,n,j,a,alpha,omega,y;
	int indeg_t[100],indeg_T[100],t[100],T[100];
	scanf("%d",&n);
	alpha =n+1;
	omega =n+2;
	init_graph(&G,n);
	for(i=1;i<=n+2;i++){
		t[i]= -1;
		T[i]=-1;
		G.time[i]=0;
		indeg_t[i]=0;
		indeg_T[i]=0;
	}
	
	for(i=1;i<=n;i++){
		scanf("%d",&G.time[i]);
		do{
			scanf("%d",&a);
			if(a>0){
				G.A[a][i]=1;
				indeg_t[i]++;
				indeg_T[a]++;
			}
		}while(a>0);
	}
	for(i=1;i<=n;i++){
		if(indeg_t[i]==0){
			G.A[alpha][i]=1;
			indeg_t[i]++;
			indeg_T[alpha]++;
		}
	}

	for(i=1;i<=n;i++){
		if(indeg_T[i]==0){
			G.A[i][omega]=1;
			indeg_t[omega]++;
			indeg_T[i]++;
		}
	}
	t[alpha]=0;
	for(i=1;i<=n+2;i++){
		if(G.A[alpha][i]==1)
			indeg_t[i]--;
	}
	for(i=1;i<=n+1;i++){
		for (j=1;j<=n+2;j++){
			if (indeg_t[j]==0 && t[j]==-1) break;
		}
		int maxsum=-1;
		for(y=1;y<=n+2;y++){
			if(G.A[y][j]){
				if (t[y] + G.time[y] > maxsum)
					maxsum = t[y] + G.time[y];
			}
		}
		t[j] = maxsum;
		for (y=1;y<=n+2;y++){
			if (G.A[j][y])
				indeg_t[y]--;
		}
	}
	
	T[omega] = t[omega];
	for (i=1;i<=n+2;i++){
		if (G.A[i][omega])
			indeg_T[i]--;
	}
	for (i=1;i<=n+1;i++){
		for (j=1;j<=n+2;j++){
			if (indeg_T[j]==0 && T[j]==-1) break;
		}
		int minT = 9999999;
		for (y=1;y<=n+2;y++){
			if (G.A[j][y])
				if (T[y] < minT)
					minT = T[y];
		}
		T[j] = minT - G.time[j];
		for (y=1;y<=n+2;y++){
			if (G.A[y][j])
				indeg_T[y]--;
		}
	}	
	for(i=1;i<=n+2;i++)
		if(t[i]==T[i])
			printf("%d\n",i);
	
}
