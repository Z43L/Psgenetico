#include "psgenetico.h"

int hastaCuantoAsOrdenado(pushswap ps, char *poblacion)
{
    ejecutarMovimientos(poblacion, ps);
    int i = -1;
    while (ps.stacka[i] < ps.stacka[i+1])
    {
        i++;
    }
    return i;
}

int hastaCuantoAsOrdenadoMejor(pushswap ps, char *poblacion)
{
    ejecutarMovimientos(poblacion, ps);
    int i = -1;
    while (ps.stacka[i] < ps.stacka[i+1])
    {
        i++;
    }
    return i;
}

int issorted(pushswap ps) {
    for (int i = 0; i < ps.size_a - 1; i++) {
        if (ps.stacka[i] > ps.stacka[i + 1])
            return -1;  // Stack is not sorted
    }
    return 0;  // Stack is sorted
}

int lenstack(pushswap ps)
{
    int i = 0;
    while (i < ps.size_a && ps.stacka[i] != 0)
        i++;
    return i;
}

int numerosDeMovimientosHechos(char *poblacion)
{
    int i = 0;
    while (poblacion[i])
    {
        i++;
    }
    return i;
}

char *quienEsMejor(char **poblacion, int i)
{
   char *mejoresPoblaciones = poblacion[i]; // Assuming this stores the best population
    return mejoresPoblaciones;
}
