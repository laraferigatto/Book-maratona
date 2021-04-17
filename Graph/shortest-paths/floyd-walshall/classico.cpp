Problema classico calculo da menor distancia de todos os vertices para todos


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int V, m, a, b, w, ins;
    int dist[200][200];
    ins = 1;
    while(scanf("%d%d", &V, &m), m || V)
    {
        memset(dist, -INT_MAX, sizeof (dist));
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
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    
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