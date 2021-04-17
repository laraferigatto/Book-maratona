#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tam 500000
bitset<1000100> p;
vector<int>primes;

void fun()
{	
	p.set();
	p[0]=p[1] = 0;
	for (ll i = 2; i <= 1000000; i++)
	{
		if(p[(int)i])
		{
			primes.push_back(i);
			for(ll j = i * i; j <= 1000000; j += i)
			{
				p[(int)j] = 0;
			}
		}
	}
	
}


int main()
{	
	fun();
	swap(primes[1], primes[2]);
	int n;
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	while(scanf("%Ld", &n), n)
	{
				
		int ans = 1;
		int p2=0, i, p5=0;
		for (i = 2; i <= n; i *= 2)
		{
			p2++;
		}
		for (i = 5; i <= n; i *= 5)
		{
			p5++;
		}
		
		for (i = 0; i < p2-p5; i++)
		{
			ans = (ans*2)%10;
		}	
		
		for (i = 2; i < (int)primes.size() ; i++)
		{
			if(primes[i] > n) break;
			for(ll j = primes[i]; j <= n; j*=primes[i])
			ans = (ans * primes[i])%10;
			
		}
		cout << ans << endl;			
		
		
	}
	
	
	
}
      