#include "psgenetico.h"

void ejecutarMovimientos(char *poblacion, pushswap ps)
{
    int i = 0;
    while (poblacion[i])
    {
        ft_printf("Performing move: %s\n", poblacion[i]);
        if (poblacion[i]== 'r'&&poblacion[i+1]=='a')
        {
            realizar_ra(ps.stacka, ps.size_a);
            i++;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1]== 'b')
        {
            realizar_rb(ps.stackb, ps.size_b);
            i++;
        }
        else if (poblacion[i]=='r' &&poblacion[i+1] =='r' &&poblacion[i +2] == 'a')
        {
            realizar_rra(ps.stacka, ps.size_a);
            i +=2;
        }
        else if (poblacion[i]=='r' &&poblacion[i+1] =='r' &&poblacion[i +2] == 'b')
        {
            realizar_rrb(ps.stackb, ps.size_b);
            i += 2;
        }
        else if (poblacion[i]== 'p'&&poblacion[i+1]=='a')
        {
            realizar_pa(ps.stacka, ps.size_a, ps.stackb, ps.size_b);
            i++;
        }
        else if (poblacion[i]== 'p'&&poblacion[i+1]=='b')
        {
            realizar_pb(ps.stacka, ps.size_a, ps.stackb, ps.size_b);
            i++;
        }
        i++;
    }
}
