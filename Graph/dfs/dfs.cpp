#include <bits/stdc++.h>
using namespace std;

vector <int> adjlist[27];

bool visit[27];
int cont, y =0;
vector <char> resp;

void dfs(int n)
{
    resp.push_back(n+96);
    visit[n] = 1;
    for(int o = 0; o < (int)adjlist[n].size(); ++o)
    {
        int u = adjlist[n][o];
        if(visit[u] == 0)
        {
            dfs(u);
        }
    }


}

int main()
{
    int la, V, E, l, flag = 1, t=1, N;
    char a, b;
    cin >> la;
    for (int i = 0; i < la; ++i)
    {
        cont = 0;

        scanf("%d%d", &V, &E);

        for (int k = 1; k <= V; ++k)
        {
            visit[k] = 0;
            adjlist[k].clear();
        }
        for (int j = 0; j < E; ++j)
        {
            cin >> a >> b;
            adjlist[a-96].push_back(b-96);
            adjlist[b-96].push_back(a-96);
        }

        cout << "Case #" << t << ":" << endl;
        while(flag)
        {
            for (l = 1; visit[l] == 1 and l <= V; ++l);
            if(l <= V)
            {
                cont++;
                dfs(l);
                sort(resp.begin(), resp.end());
                for (int r = 0; r < resp.size(); ++r) {
                    cout << resp[r] << ",";
                }
                cout << endl;
                resp.clear();
            }
            else
            {
                flag = 0;
                cout << cont << " connected components" << endl << endl;
            }

        }

        flag = 1;
        t++;

    }



}


