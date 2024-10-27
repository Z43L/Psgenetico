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
int hastaCuantoAsOrdenado(pushswap ps) {
    if (ps.size_a == 0) return 0;

    // Encontrar el índice del valor mínimo en stacka
    int min_index = 0;
    for (int i = 1; i < ps.size_a; i++) {
        if (ps.stacka[i] < ps.stacka[min_index]) {
            min_index = i;
        }
    }

    // Verificar que el array está ordenado ascendentemente desde min_index
    for (int i = 1; i < ps.size_a; i++) {
        int current_index = (min_index + i) % ps.size_a;
        int prev_index = (min_index + i - 1) % ps.size_a;

        if (ps.stacka[prev_index] > ps.stacka[current_index]) {
            return 0; // No está en orden ascendente
        }
    }

    // Si está ordenado, hacer rotaciones `ra` hasta que el mínimo esté en la posición 0
    while (min_index > 0) {
        realizar_ra(ps.stacka, ps.size_a); // Función para realizar la rotación
        min_index--;
    }

    return 1; // Está ordenado con el mínimo en la posición inicial
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

int issorted(pushswap ps)
{
    for (int i = 0; i < ps.size_a - 1; i++) {
        if (ps.stacka[i] > ps.stacka[i + 1])
            return 0;  // No está ordenado
    }
    return 1;  // Está ordenado
}


int lenstack(int *stack, int ac)
{
    int i = 0;
    while (i < ac&&stack[i] != 0)
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
