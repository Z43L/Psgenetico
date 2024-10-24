#include "psgenetico.h"
void realizar_pa(pushswap *ps)
{
    if (ps->size_b > 0) // Verificar que stackb tenga al menos un elemento
    {
        // Desplazar stacka hacia abajo
        for (int i = ps->size_a; i > 0; i--)
            ps->stacka[i] = ps->stacka[i - 1];

        // Mover el primer elemento de stackb a stacka
        ps->stacka[0] = ps->stackb[0];

        // Desplazar stackb hacia arriba
        for (int i = 0; i < ps->size_b - 1; i++)
            ps->stackb[i] = ps->stackb[i + 1];

        ps->size_a++;
        ps->size_b--;
    }
    else
    {
        ft_printf("Error: No elements in stackb to perform pa\n");
    }
}

