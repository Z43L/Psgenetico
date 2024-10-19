#ifndef PSGEN_H
# define PSGEN_H

#define poblacionInicial 1000
#define minMovimientos 300
#define maxMovimientos 550

typedef struct s_pushswap
{
    int *stacka;
    int *stackb;
    int size_a;
    int size_b;
} pushswap;

void realizar_ra(int *stacka, int size_a);
void realizar_rb(int *stackb, int size_b);
void realizar_rra(int *stacka, int size_a);
void realizar_rrb(int *stackb, int size_b);
void realizar_pa(int *stacka, int size_a, int *stackb, int size_b);
void realizar_pb(int *stacka, int size_a, int *stackb, int size_b);
char ***generarPoblacionInicial(int semilla);
char ***generarPoblacionDelMejor(int semilla , int posicionMejorInicial, int i);
int intlenmenos3(int mxMovimientos);
int intlen(int semilla);




#endif
