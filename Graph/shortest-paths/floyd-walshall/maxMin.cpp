Imprimir o menor peso do maior caminho de um vertice para outro usando Floyd-Warshall

Codigo c++

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int main()
{
    int V, m, a, b, w, ins;
    int dist[200][200];
    ins = 1;
    while(scanf("%d%d", &V, &m), m || V)
    {
        memset(dist, INT_MAX, sizeof (dist));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &w);
            a--;b--;
            dist[a][b] = w;
            dist[b][a] = w;
        }

        for (int i = 0 ; i < V; i++)
        {
            dist[i][i]= 0;
        }
        for(int k = 0; k < V; k++)
        {
            for(int i = 0; i < V; i++)
            {
                for(int j = 0; j < V; j++)
                {
                    dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
                }
            }
        }

        int cons;
        scanf("%d", &cons);
        printf("Instancia %d\n", ins);
        for (int e = 0; e < cons; ++e)
        {
            scanf("%d%d", &a, &b);
            a--;b--;
            if(a==b) cout << 0 << endl;
            else cout << dist[a][b] << endl;

        }
        puts("");
        ins++;

    }
}