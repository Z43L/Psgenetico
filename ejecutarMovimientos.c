#include "psgenetico.h"

void ejecutarMovimientos(char **poblacion, pushswap ps)
{
    int i = 0;
	while(poblacion[i])
    {
        int j = 0;
		while(poblacion[i][j])
	    {
            if(poblacion[i][j] == "ra")
				realizar_ra(ps.stacka,ps.size_a);
            else if(poblacion[i][j] == "rb")
				realizar_rb(ps.stackb,ps.size_b);
            else if(poblacion[i][j] == "rra")
				realizar_rra(ps.stacka,ps.size_a);
            else if(poblacion[i][j] == "rrb")
				realizar_rrb(ps.stackb, ps.size_b);
            else if(poblacion[i][j] == "pa")
				realizar_pa(ps.stacka,ps.size_a,ps.stackb, ps.size_b);
            else if(poblacion[i][j] == "pb")
				realizar_pb(ps.stacka,ps.size_a,ps.stackb, ps.size_b);
			j++;
        }
        i++;
    }
}
