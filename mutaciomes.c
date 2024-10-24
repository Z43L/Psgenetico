#include "psgenetico.h"
int encontrarMenor(int arr[], int size)
{
    if (size == 0)
    {
        return -1;  // Manejo de error para array vacío
    }

    int menor = arr[0];  // Inicializa el valor menor con el primer elemento

    for (int i = 1; i < size; i++)  // Recorre el array desde el segundo elemento
    {
        if (arr[i] < menor)
        {
            menor = arr[i];  // Actualiza el menor si encuentra un valor más pequeño
        }
    }

    return menor;  // Retorna el número más pequeño
}

int hastaCuantoAsOrdenado(pushswap ps, char *poblacion)
{
    ejecutarMovimientos(poblacion, ps);  // Ejecuta los movimientos en la población

    // 1. Encuentra el índice del número más pequeño
    int min_index = 0;
    for (int i = 1; i < ps.size_a; i++) {
        if (ps.stacka[i] < ps.stacka[min_index]) {
            min_index = i;
        }
    }

    // 2. Verifica que la pila está ordenada de menor a mayor a partir del número más pequeño
    int i = min_index;
    while (i < ps.size_a - 1 && ps.stacka[i] <= ps.stacka[i + 1]) {
        i++;
    }

    // 3. Si llegamos al final de la pila, verificamos desde el inicio hasta el índice del menor número
    if (i == ps.size_a - 1) {
        i = 0;
        while (i < min_index && ps.stacka[i] <= ps.stacka[i + 1]) {
            i++;
        }

        // Si el bucle terminó en el índice justo antes del menor número, está ordenada
        if (i == min_index - 1) {
            return ps.size_a;  // La pila está completamente ordenada
        }
    }

    // Retorna el índice hasta donde está ordenado
    return i;
}


int hastaCuantoAsOrdenadoMejor(pushswap ps, char *poblacion)
{
    ejecutarMovimientos(poblacion, ps);
    int i = 0;  // Cambiar de -1 a 0
    while (i < ps.size_a - 1 && ps.stacka[i] < ps.stacka[i + 1])
    {
        i++;
    }
    return i;
}

int issorted(pushswap ps) {
    for (int i = 1; i < ps.size_a - 1; i++) {
        if (ps.stacka[i] > ps.stacka[i -1])
            return -1;  // Stack is not sorted
    }
    return 1;  // Stack is sorted
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
