#include "psgenetico.h"

int hastaCuantoAsOrdenado(int *stacka)
{
    int i = -1;
	int minimoNumeroStacka;
	while(stacka[i] < stacka[i+1])
		i++;
	return i;
}

int numerosDeMovimientosHechos(char *poblacion)
{
    int i =0;
    while(poblacion[i])
    {
        i++;
    }
    return i;
}
char *quienEsMejor(char ***poblacion,pushswap ps)
{
    int i = -1;
	int j = 0;
	int *prestacka;
	int mejoresIndividuos = hastaCuantoAsOrdenado(ps.stacka);
	
	while(poblacion[i])
    {
        
        char mejoresPoblaciones = poblacion[i];
        prestacka = ejecutarMovientos(poblacion[i]);
        if(mejoresIndividuos > mejoresPoblaciones)
				mejoresPoblaciones = mejoresIndividuos;
	}
        i++;
	return mejoresPoblaciones;
}
