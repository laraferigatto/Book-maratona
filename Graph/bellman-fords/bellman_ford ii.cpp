#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
  int V, E, s, a, b, w;
  vector<vii> AdjList;


  freopen("in_06.txt", "r", stdin);

  scanf("%d %d %d", &V, &E, &s);

  AdjList.assign(V, vii()); 
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &a, &b, &w);
    AdjList[a].push_back(ii(b, w));
  }

  
  vi dist(V, INF); dist[s] = 0;
  for (int i = 0; i < V - 1; i++)  
    for (int u = 0; u < V; u++)                        
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];       
        dist[v.first] = min(dist[v.first], dist[u] + v.second);         
      }

  bool hasNegativeCycle = false;
  for (int u = 0; u < V; u++)                         
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[v.first] > dist[u] + v.second)              
        hasNegativeCycle = true;    
    }
  printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

  if (!hasNegativeCycle)
    for (int i = 0; i < V; i++)
      printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

  return 0;
}