#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tam 2000000
vector <int> primes;
ll mp[2000010];
map<ll, int> fat_n, fat_m;
ll get_pot(ll n, ll p)
{
    int res = 0;    
    for (ll i = p ; i <= n ; i *= p)
    {
        res += n/i;       
	}
    return res;
}
void fac()
{
	for (ll i = 2; i < tam; i++)
	{
		if(!mp[i])
		{
			mp[i] = i;
			primes.push_back(i);
		}
		for(ll j = 0; j < primes.size() && primes[j] <= mp[i] && i*primes[j] < tam; j++)
		{
			mp[i*primes[j]] = primes[j];
		}		
	}	
}

bool fun(ll aux, ll n)
{
	ll fact = 0;
	for (ll i = 0; i < primes.size() && aux > 1; i++)
	{				
		while(aux%primes[i] == 0)
		{
			if(fact > 0 && primes[i] != fact)
			{
				if(fat_m[fact] > get_pot(n, fact))
				{
					return 0;
				}	
				else fact = primes[i];			
			}
			else if(fact == 0) fact = primes[i];
			fat_m[primes[i]]++;
			aux = aux/primes[i];		
		}					
	}
	if(aux > 1) {fat_m[aux]++; fact = aux;}
	
	if(fact && fat_m[fact] > get_pot(n, fact))
	{
		return 0;
	}
		
	return 1;
}
	
int main()
{	
	fac();
	ll n, m, f, aux;
	bool flag = 0;	
	while(scanf("%Ld%Ld", &n, &m) != EOF)
	{
		if(!n or n==1)
		{
			if(m == 1 or m == 0)
				printf("%Ld divides %Ld!", m, n);
			else printf("%Ld does not divide %Ld!", m, n);
			puts("");
				
		}
		else if(m==0 or m==1) {printf("%Ld divides %Ld!", m, n);puts("");}
		else
		{
			flag = 1;
			if(m < tam)
			{			
				aux = m;
				int fact = mp[aux];
				while(aux != 1)
				{				
					if(mp[aux] != fact)
					{						
						if(fat_m[fact] > get_pot(n, fact))
						{
							flag = 0;
							break;
						}	
						else fact = mp[aux];				
						
					}
					fat_m[mp[aux]]++;
					aux = aux/mp[aux];
				}
				if(fat_m[fact] > get_pot(n, fact))
				{
					flag = 0;
				}			
			}
			else
			{				
				f = fun(m,n);
				if(f == 0) flag = 0;
			}
			if(flag) printf("%Ld divides %Ld!", m, n);
			else printf("%Ld does not divide %Ld!", m, n);
			puts("");
			fat_m.clear();
			fat_n.clear();
		}
		
	}
}
      
