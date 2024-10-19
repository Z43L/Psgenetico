#include "psgenetico.h"
char **generarPoblacionInicial(int semilla)
{	
    char ***poblacion;
	int i =0;
	while(i <= poblacionInicial)
    {	
        int j =0;
		int movimientos = intlenmenos3(maxMovimientos);
		while(movimientos < 300)
			movimientos = intlenmenos3(maxMovimientos);
		while(j < movimientos)
        {
            if(intlen(semilla) <= '1' && intlen(semilla) >= '0')
				poblacion[i][j] = "ra";
            else if(intlen(semilla) <= '3')
				poblacion[i][j] = "rb";
            else if(intlen(semilla) <= '5' && intlen(semilla) >= '4')
				poblacion[i][j] = "rra";
            else if(intlen(semilla) <= '7')
				poblacion[i][j] = "rrb";
            else if(intlen(semilla) == '4' || intlen(semilla)== '6')
				poblacion[i][j] = "pb";
            else if(intlen(semilla) <= '9' && intlen(semilla) >= '8')
				poblacion[i][j] = "pa";
			j++;
        }
        i++;
    }
    return poblacion;
}

char **generarPoblacionDelMejor(int semilla , int posicionMejorInicial, int i)
{
    char ***nuevaPoblacion;
	while(i < poblacionInicial)
    {   
		int j = 0;
		
		int movimientos = intlenmenos3(maxMovimientos);
		while(movimientos < 300)
			movimientos = intlenmenos3(maxMovimientos);
		while(j < movimientos)
        {
            if(intlen(semilla) <= '1' && intlen(semilla) >= '0')
				nuevaPoblacion[i][posicionMejorInicial] = "ra";
			if(intlen(semilla) <= '3')
				nuevaPoblacion[i][posicionMejorInicial] = "rb";
			if(intlen(semilla) <= '5' && intlen(semilla) >= '4')
				nuevaPoblacion[i][posicionMejorInicial] = "rra";
			if(intlen(semilla) <= '7')
				nuevaPoblacion[i][posicionMejorInicial] = "rrb";
			if(intlen(semilla) == '4' || intlen(semilla)== '6')
				nuevaPoblacion[i][posicionMejorInicial] = "pb";
			if(intlen(semilla) <= '9' && intlen(semilla) >= '8')
				nuevaPoblacion[i][posicionMejorInicial] = "pa";
			j++;
			posicionMejorInicial++;
        }
        i++;
    }
    return nuevaPoblacion;
}
