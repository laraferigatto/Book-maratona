#include <bits/stdc++.h>
#define M ((L+R)/2)
using namespace std;

// a segtree por ser recursiva precisa ser declarado com 4n, se for interativa com 2n
struct NO
{
	int soma;
};
NO SEG[400100],aux;
int vet[100100];

NO merge(NO x , NO y)
{
	NO z;
	z.soma = min(x.soma , y.soma);
	return z;
	
}
NO build (int T, int L, int R)
{
	if (L==R)
	{
		SEG[T].soma = vet[L];
		return SEG[T];
	}
	return SEG[T] = merge(build(2*T,L,M), build(2*T+1, M+1, R));
}
NO query(int I,int J, int T, int L, int R)
{
	// fora do intervalo
	if(J < L || R < I)
	{
		aux.soma = 1e9;
		return aux;	
	}	
	if(I <= L && R <= J)
		return SEG[T];	
	
	return merge(query(I,J,2*T,L,M), query(I,J,2*T+1, M+1, R));	
}

NO update(int I, int x, int T, int L, int R)
{
	if(L == R)
		SEG[T].soma = x;
	else if(I <= M)
		SEG[T] = merge(update(I,x,2*T,L,M), SEG[2*T+1]);
	else
		SEG[T] = merge(SEG[2*T],update(I,x,2*T+1,L,M));	
	
	return SEG[T];	
		
}
int main()
{
	int N,q,c,t;
	scanf("%d",&N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&vet[i]);	
	}
	build(1,0,N-1);
	scanf("%d",&q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d",&c,&t);
		printf("%d\n",query(c,t,1,0,N-1).soma);
		
	}
	
}
