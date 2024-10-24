#include "psgenetico.h"
void realizar_rrb(int *stackb, int size_b)
{
    if (size_b > 1) // Solo rota si hay más de un elemento
    {
        int temp = stackb[size_b - 1]; // Guardar el último elemento
        for (int i = size_b - 1; i > 0; i--)
            stackb[i] = stackb[i - 1]; // Mover todos los elementos hacia abajo
        stackb[0] = temp; // Colocar el último elemento al principio
    }
    else
    {
        ft_printf("Error: Not enough elements to perform rrb\n");
    }
}
