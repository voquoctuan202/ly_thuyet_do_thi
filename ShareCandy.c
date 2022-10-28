#include<stdio.h>

typedef struct{
	int A[100][100];
	int n;
}Graph;

void init_graph(Graph *G,int n){
	G->n=n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}
void add_edges(Graph *G,int u,int v){
	G->A[u][v]=1;
}
void RankGraph(Graph *G,int rank[],int indeg[]){
	int count=0,countRank=0,d,c;
	do{
		for(d=1;d<=G->n;d++)
			if(rank[d]==-1 && indeg[d]==0){
				rank[d]=count;
				countRank++;
		}
		for(d=1;d<=G->n;d++){
			if(rank[d]==count){
				for(c=1;c <= G->n;c++)
					if(G->A[d][c]==1){
						indeg[c]--;
					}
				}
			}
		
		count++;
	}while(count < G->n);
}
int main(){
	Graph G;
	int i,n,m,u,v;
	int indeg[100],rank[100];
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=n;i++){
		rank[i]=-1;
		indeg[100]=0;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edges(&G,v,u);
		indeg[u]++;
	}
	RankGraph(&G,rank,indeg);
	int sum=0;
	for(i=1;i<=n;i++){
		printf("%d\n",rank[i]+1);
		sum+=rank[i]+1;
	}
	printf("%d",sum);
	
}
