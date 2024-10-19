#include "psgenetico.h"

int hastaCuantoAsOrdenado(pushswap ps ,char *poblacion, int i)
{
    ejecutarMovimientos(poblacion[i], ps);
	i = -1;
    while(ps.stacka[i] <ps.stacka[i+1])
    {
        i++;
    }
		
	return i;
}
int hastaCuantoAsOrdenadoMejor(pushswap ps ,char *poblacion)
{
    ejecutarMovimientos(&poblacion, ps);
	int i = -1;
    while(ps.stacka[i] <ps.stacka[i+1])
    {
        i++;
    }
		
	return i;
}
int issorted(pushswap ps)
{
    int i = -1;
    
	while(ps.stacka[i] <ps.stacka[i+1])
    {
        i++;
        if(ps.stacka[i] > ps.stacka[i+1] )
            return -1;
    }
		
	return i;
}
int lenstack(pushswap ps)
{
    int i = 0;
    while(ps.stacka[i])
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
char *quienEsMejor(char **poblacion,pushswap ps,int i)
{
    
	int mejoresIndividuos = hastaCuantoAsOrdenado(ps,poblacion[i],i);
	char *mejoresPoblaciones = poblacion[i];
    char *segundaMejorPoblacion= poblacion[i-1];
    int segundoMejorIndividuo = hastaCuantoAsOrdenado(ps,poblacion[i], i);
    
    
    if(mejoresIndividuos > segundoMejorIndividuo)
		mejoresPoblaciones = segundaMejorPoblacion;
	
        i++;
	return mejoresPoblaciones;
}
