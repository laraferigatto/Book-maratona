//arvore geradora minima
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector <iii> v;
int vet[201000];
int tam[201000];
int find(int u)
{
   if(vet[u] == u)
       return u;
   return find(vet[u]);
}
void unionSet (int a, int b)
{
   a = find(a);
   b = find(b);
   if(tam[a] > tam[b])
   {
       vet[b] = a;
       tam[a] += tam[b];
   }
   else
   {
       vet[a] = b;
       tam[b] += tam[a];
   }
}
int main()
{
   int a, b, c, n,m;
   while(scanf("%d%d", &n, &m), n || m)
   {
       v.clear();
       int total = 0;
       for (int i = 0; i < m; ++i)
       {
           scanf("%d%d%d", &a, &b, &c);
           v.push_back(iii(c, ii(b, a)));
           vet[a] = a;
           vet[b] = b;
           tam[a] = 1;
           tam[b] = 1;
           total += c;
       }
       sort(v.begin(), v.end());
       int soma = 0;
       for (int i = 0; i < v.size(); ++i)
       {
           if(find(v[i].second.first) != find(v[i].second.second))
           {
               unionSet(v[i].second.first, v[i].second.second);
               soma += v[i].first;
           }
       }
       cout << total - soma << endl;

   }

}
