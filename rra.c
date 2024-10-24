#include "psgenetico.h"
void realizar_rra(int *stacka, int size_a)
{
    if (size_a > 1) // Solo rota si hay más de un elemento
    {
        int temp = stacka[size_a - 1];
        for (int i = size_a - 1; i > 0; i--)
            stacka[i] = stacka[i - 1];
        stacka[0] = temp;
    }
    else
    {
        ft_printf("Error: Not enough elements to perform rra\n");
    }
}
