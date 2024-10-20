#include "psgenetico.h"

void ejecutarMovimientos(char **poblacion, pushswap ps)
{
    int i = 0;
    while (poblacion[i])
    {
        if (ft_strncmp(poblacion[i], "ra", 2) == 0)
            realizar_ra(ps.stacka, ps.size_a);
        else if (ft_strncmp(poblacion[i], "rb", 2) == 0)
            realizar_rb(ps.stackb, ps.size_b);
        else if (ft_strncmp(poblacion[i], "rra", 3) == 0)
            realizar_rra(ps.stacka, ps.size_a);
        else if (ft_strncmp(poblacion[i], "rrb", 3) == 0)
            realizar_rrb(ps.stackb, ps.size_b);
        else if (ft_strncmp(poblacion[i], "pa", 2) == 0)
            realizar_pa(ps.stacka, ps.size_a, ps.stackb, ps.size_b);
        else if (ft_strncmp(poblacion[i], "pb", 2) == 0)
            realizar_pb(ps.stacka, ps.size_a, ps.stackb, ps.size_b);

        i++;
    }
}