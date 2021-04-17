#include <bits/stdc++.h>
using namespace std;
#define ll long long int


ll c, d , e;
void euclides(ll a, ll b)
{
	ll r = a;
	ll r1 = b;
	ll u = 1;
	ll v = 0;
	ll u1 = 0;
	ll v1 = 1;
        // variáveis auxiliares para efetuar trocas
	ll rs, us, vs, q;

	while (r1 != 0)
	{
		q = (r / r1); // pega apenas a parte inteira
		rs = r;
		us = u;
		vs = v;
		r = r1;
		u = u1;
		v = v1;
		r1 = rs - q *r1;
		u1 = us - q*u;
		v1 = vs - q*v1;
	}
	c = r; d = u; e = v;
	//~ return [r, u, v]; // tais que a*u + b*v = r et r = pgcd (a, b)
}
int main()
{	
	int t = 1;
	ll x, k;
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%Ld%Ld", &x, &k);
		ll f = floor((long double)x/(long double)k);
		ll ce = ceil((long double)x/(long double)k);
		euclides(f,ce);
		//~ cout << f << ' ' << ce << endl;
		//~ cout << c << " " << d << " " << e << endl;
		cout << ((d*x)/c) << ' ' << ((e*x)/c) << endl;
	}
	
	
}