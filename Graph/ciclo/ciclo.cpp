#include <bits/stdc++.h>
using namespace std;
vector <int> adjlist[110000];
//map <string, vector<string> > adjlist;
bool vist[110000];
bool ativos[110000];
map <string, int> aux;
int cont;
void dfs(int v)
{
    vist[v] = 1;
    ativos[v] = 1;
    for (int i = 0; i < adjlist[v].size() ; i++)
    {
        int u = adjlist[v][i];
        if(ativos[u])
        {
            cont++;
        }
        if(!vist[u])
        {
            dfs(u);
        }
    }
    ativos[v] = 0;
}

int main()
{
    string nome1, nome2;
    int a = 0;
    map <string,int >::iterator it;
    while(cin >> nome1 >> nome2)
    {
        if(aux.find(nome1) == aux.end())
        {
            aux[nome1] = a++;
        }
        if(aux.find(nome2) == aux.end())
        {
            aux[nome2] = a++;
        }
        adjlist[aux[nome1]].push_back(aux[nome2]);

    }
    cont=0;
    for (int i = 0; i < a; ++i)
    {
        if(!vist[i])
            dfs(i);
    }
    printf("%d\n", cont);

}