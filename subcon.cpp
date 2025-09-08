#include <iostream>
#include <cstdlib>

void Combinar(int ini, int res, int *alfabeto, int n, int* conjunto, int tam);

int main(int argn, char **args)
{
	int card = atoi(args[1]);
	int *inte = new int [card];
	int *conjunto = new int [card];

	for(int k=0; k<card; k++)
		inte[k]=k+1;

	for(int k=0; k<=card; k++)
		Combinar(0, k, inte, card, conjunto, 0);

	return 0;
}

void Combinar(int ini, int res, int *alfabeto, int n, int* conjunto, int tam)
{
	if (res==0)
	{
		std::cout << "{";
		for(int i=0; i<tam; i++)
		{
			std::cout << conjunto[i];
			if(i+1==tam)
				std::cout << "";
			else
				std::cout << ",";
		}
		std::cout << "}" << std::endl;
		return;
	}
	for(int k=ini; k<n; k++)
	{
		conjunto[tam]=alfabeto[k];
		Combinar(k+1, res-1, alfabeto, n, conjunto, tam+1);
	}
}
