#include <bits/stdc++.h>
#define INF 123456789
using namespace std;
int vet[100];
vector <int> adjlist[1000];
queue <int> fila;
int V;
typedef vector <int> vi;


int bfs(int atual, int fim)
{	
	vi dist(V+1, INF);	
	dist[atual] = 0;
	fila.push(atual);
	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int i = 0; i < (int)adjlist[u].size(); i++)
		{
			int v = adjlist[u][i];
			if(dist[v] == INF)
			{
				dist[v] = dist[u] +1;
				fila.push(v);
			}
		}
	}

	return dist[fim];
}

int main ()
{
	int A, b,c;
	while(scanf("%d%d", &V, &A) != EOF)
	{
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d", &b, &c);
			adjlist[b].push_back(c);
			adjlist[c].push_back(b);
		}
		int inicio, fim, proibida;
		scanf("%d%d%d", &inicio, &fim, &proibida);
		adjlist[proibida].clear();
		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < (int)adjlist[i].size(); j++)
			{
				int u = adjlist[i][j];
				if(u == proibida)
				{
					adjlist[i].erase(adjlist[i].begin() + j);
				}
				
			}
			
		}
		
		printf("%d\n", bfs(inicio, fim));
		
		
		for (int i = 0; i <= V; i++)
		{
			adjlist[i].clear();
		}
		
		
		
		
	}
}
