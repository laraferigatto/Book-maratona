/* 
    Calcula o menor camino em um grafo, partindo de um vertice inicial 
    o algoritmo calcula o menor caminho para todos os outros vertice do grafo, 
    desde que exista um caminho  entre o par de vetice
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair <int,int> ii;
typedef vector<ii> vi;
vector <ii> adjlist[1010];
int dist[1010];
int V, C;
int dik(int v, int verticeFinal)
{
    priority_queue<ii,vi, greater <ii> > fila;
    dist[v] = 0;
    fila.push(ii(0,v));
    while(!fila.empty())
    {
        ii f = fila.top();
        fila.pop();
        int atual = f.second;
        for (unsigned i = 0; i < adjlist[atual].size(); i++)
        {
            ii u = adjlist[atual][i];
            if(dist[atual] + u.second < dist[u.first])
            {
                dist[u.first] = dist[atual] + u.second;
                fila.push(ii(dist[u.first], u.first));
            }

        }
    }
    return dist[verticeFinal];
}

int main ()
{
    int M, K;
    // quantidade total de verices
    cin >> V;
    for(int i = 0; i <= V; i++)
    {
        dist[i] = INF;
    }
    // numero de arestas
    cin >> M;
    int vertice1, vertice2, distancia;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &vertice1,&vertice2,&distancia);
        // grafo biderecional 
        adjlist[vertice1].push_back(ii(vertice2,distancia));
        adjlist[vertice2].push_back(ii(vertice1,distancia));
        // se fosse unidirecionar seria apenas 
        // adjlist[vertice1].push_back(ii(vertice2,distancia));
    }
    // vertice inicial e final do caminho a ser calculado
    int verticeInicial, verticeFinal;
    cin >> verticeInicial >> verticeFinal; ;
    
    cout << dik(verticeInicial, verticeFinal) << endl;

    
}