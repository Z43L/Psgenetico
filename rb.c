#include "psgenetico.h"
void realizar_rb(int *stackb, int size_b)
{
    if (size_b > 1) // Solo rota si hay más de un elemento
    {
        int temp = stackb[0]; // Guardar el primer elemento
        for (int i = 0; i < size_b - 1; i++)
            stackb[i] = stackb[i + 1]; // Mover todos los elementos hacia arriba
        stackb[size_b - 1] = temp; // Colocar el primer elemento al final
    }
    else
    {
        ft_printf("Error: Not enough elements to perform rb\n");
    }
}
