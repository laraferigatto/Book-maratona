#include <bits/stdc++.h>
using namespace std;
int pd[110][1010];
int n, m;
string a, b;
int valor[110], peso[110];
int fun( int i, int disp)
{
	if(i == n) return 0;
	if(pd[i][disp] != -1) return pd[i][disp];
	if(disp - peso[i] < 0) return pd[i][disp] = fun(i+1, disp);
	return pd[i][disp] = max(fun(i+1, disp), valor[i] + fun(i+1, disp - peso[i]));
}

int main()
{
	int t,w;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(pd, -1, sizeof pd);
		scanf("%d%d", &n, &w);
		for(int j = 0; j < n; j++)
		{
			scanf("%d%d", &valor[j], &peso[j]);					
		}
		printf("Galho %d:\nNumero total de enfeites: %d\n\n", i+1, fun(0,w));
	}
}
