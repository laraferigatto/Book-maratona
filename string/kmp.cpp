#include <bits/stdc++.h>
using namespace std;
int pd[1010][1010];
int n, m;
string a, b;
int fun( int i, int j)
{
	if(n == i || m == j)
		return 0;
	if(pd[i][j] != -1) 
		return pd[i][j];
	if(a[i] == b[j])
		return pd[i][j] = 1 + fun(i+1, j+1);
	return pd[i][j] = max(fun(i+1, j), fun(i,j+1));
}

int main()
{
	cin >> a >> b;
	memset(pd, -1, sizeof pd);
	n = a.size();
	m = b.size();
	int tam = fun(0,0);
	cout << (n+m) - tam << endl;
}
