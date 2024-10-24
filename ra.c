#include "psgenetico.h"
void realizar_ra(int *stacka, int size_a)
{
    if (size_a > 1) // Solo rota si hay más de un elemento
    {
        int temp = stacka[0];
        for (int i = 0; i < size_a - 1; i++)
            stacka[i] = stacka[i + 1];
        stacka[size_a - 1] = temp;
    }
    else
    {
        ft_printf("Error: Not enough elements to perform ra\n");
    }
}
