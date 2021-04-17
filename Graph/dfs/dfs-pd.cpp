#include <bits/stdc++.h>
using namespace std;
int linha, coluna;
vector <int> g[100100];
int excit[100100];
int pd[100100][2];
int f(int v, bool bos)
{
    if(pd[v][bos] != -1 ) return pd[v][bos];
    if(bos)
    {
        int resp = 0;
        for(auto to : g[v])
        {
            resp += f(to, false);
        }
        return pd[v][bos] = resp;
;
    }
    else
    {
        int resp1=0;
        int resp2 = excit[v];
        for(auto to : g[v])
        {
            resp1 += f(to, false);
            resp2 += f(to, true);
        }

        return pd[v][bos] = max(resp1, resp2);

    }
}
int main()
{
    memset(pd, -1, sizeof (pd));
   int n; scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
       scanf("%d", &excit[i]);
   }

   for(int i = 1; i < n; i++)
   {
       int x; scanf("%d", &x);
       x--; g[x].push_back(i);
   }

   printf("%d\n", f(0,false) );
}