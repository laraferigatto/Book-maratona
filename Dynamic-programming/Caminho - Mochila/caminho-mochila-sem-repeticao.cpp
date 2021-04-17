#include <bits/stdc++.h>

using namespace std;

int Peso[] = {1,2,5,3,8};
int Valor[] ={5,2,10,8,5};
int PD[100][100]; // item por Disp - A matriz se baseia no estados
vector<int>caminho;
int mochila(int item, int Disp)
{
	if(Disp==0 || item == 5)
	{
		return 0;
	}
	
	if (PD[item][Disp]!=-1)
	{
		return PD[item][Disp]; 
	}
	
	if (Disp-Peso[item] < 0)
	{
		PD[item][Disp] = mochila(item+1,Disp);		
	}else
	{
		PD[item][Disp]=max(mochila(item+1,Disp),Valor[item] + mochila(item+1,Disp - Peso[item]));	
	}
	return PD[item][Disp];	
	
}

void mochilaCaminhoSemRepeticao(int item, int Disp)
{
	if(Disp==0 || item == 5)return;
		
	if (Disp-Peso[item] >= 0)
	{
		if (Valor[item] + mochila(item+1,Disp-Peso[item]) > mochila(item+1,Disp))
		{
			caminho.push_back(Valor[item]);
			mochilaCaminhoSemRepeticao(item+1,Disp-Peso[item]);
			return;
		}
		
	}
    mochilaCaminhoSemRepeticao(item+1,Disp);	
	
}



int main()
{
	memset(PD,-1,sizeof PD);
	printf("%d\n",mochila(0,10));	
	mochilaCaminhoSemRepeticao(0,10);
	for (int i = 0; i < (int)caminho.size(); i++)
	{
		printf("%d ",caminho[i]);
	}
	printf("\n");

}


