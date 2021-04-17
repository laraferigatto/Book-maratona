#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
int pd[5010][5010];
int main()
{	
	scanf("%d ", &n);
	cin >> a;
	b = a;
	reverse(b.begin(),b.end());
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if(!j || !i)
				pd[i][j] = 0;
			else if(a[i-1] == b[j-1])
				pd[i][j] = pd[i-1][j-1] +1;
			else
			{
				pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
				
			}			
		}
	}
	
	
	printf("%d\n", n - pd[n][n] ); 
}