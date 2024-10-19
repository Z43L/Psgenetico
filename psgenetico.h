#ifndef PSGEN_H
# define PSGEN_H

#define numeroDeGeneraciones 100000
#define poblacionInicial 1000
#define minMovimientos 300
#define maxMovimientos 550
#define INT_MIN -2147483648
#define INT_MAX 2147483648
#include "FT_PRINTF/src/ft_printf.h"
#include "LIBFT/libft.h"
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
char *quienEsMejor(char **poblacion,pushswap ps,int i);
int numerosDeMovimientosHechos(char *poblacion);
void ejecutarMovimientos(char **poblacion, pushswap ps);
int custom_rand(unsigned int *rand_seed);
unsigned long long read_tsc(void);
int hastaCuantoAsOrdenado(pushswap ps, char *poblacion, int i);
int lenstack(pushswap ps);
int issorted(pushswap ps);
int hastaCuantoAsOrdenadoMejor(pushswap ps ,char *poblacion);

#endif
