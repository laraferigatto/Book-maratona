include <bits/stdc++.h>

using namespace std;

int Peso[] = {1,2,5,3,8};
int Valor[] = {5,2,10,8,5};
int PD[100]; // Disp
vector<int>caminho;
int mochila(int Disp)
{
	if(Disp==0)
	{
		return 0;
	}
	if (PD[Disp]!=-1)
	{
		return PD[Disp];
	}
	
	int  aux = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Disp-Peso[i] >= 0)
		{
			aux = max(aux,Valor[i] + mochila(Disp - Peso[i]));
		}
		
	}
	PD[Disp]=aux;
	return PD[Disp];
}

void caminhoMochilaComRepeticao(int Disp)
{
	if (Disp==0)return;
	
	int aux = 0, pos=-1;
	
	for (int i = 0; i < 5; i++)
	{
		if (Disp-Peso[i]>=0)
		{
			if (Valor[i]+mochila(Disp-Peso[i])>aux)
			{
				aux = Valor[i]+mochila(Disp - Peso[i]);
				pos = i;
			}		
		}		
	}
	if (pos!=-1)
	{
		caminho.push_back(Valor[pos]);
		caminhoMochilaComRepeticao(Disp-Peso[pos]);
	}
}
int main()
{
	memset(PD,-1,sizeof PD);
	printf("%d\n",mochila(10));
	caminhoMochilaComRepeticao(10);
	for (int i = 0; i < (int)caminho.size(); i++)
	{
		printf("%d ",caminho[i]);
	}
	puts("");
	

}



