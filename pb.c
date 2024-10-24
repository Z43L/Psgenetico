#include "psgenetico.h"

void realizar_pb(pushswap *ps)
{
    if (ps->size_a > 0) // Verificar que stacka tenga al menos un elemento
    {
        // Desplazar stackb hacia abajo
        for (int i = ps->size_b; i > 0; i--)
            ps->stackb[i] = ps->stackb[i - 1];

        // Mover el primer elemento de stacka a stackb
        ps->stackb[0] = ps->stacka[0];

        // Desplazar stacka hacia arriba
        for (int i = 0; i < ps->size_a - 1; i++)
            ps->stacka[i] = ps->stacka[i + 1];

        ps->size_a--;
        ps->size_b++;
    }
    else
    {
        ft_printf("Error: No elements in stacka to perform pb\n");
    }
}
