#ifndef PSGEN_H
# define PSGEN_H

#define numeroDeGeneraciones 100
#define poblacionInicial 10
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
void realizar_pa(pushswap *ps);
void realizar_pb(pushswap *ps);
char **generarPoblacionInicial();
char **generarPoblacionDelMejor( int posicionMejorInicial,char *mejorpoblante);
int intlenmenos3(int mxMovimientos);
int intlen(int semilla);
char *quienEsMejor(char **poblacion,int i);
int numerosDeMovimientosHechos(char *poblacion);
void ejecutarMovimientos(char *poblacion, pushswap ps);
int custom_rand(unsigned long long rand_seed);
unsigned long long read_tsc(void);
int lenstack(pushswap ps);
int issorted(pushswap ps);
int hastaCuantoAsOrdenado(pushswap ps, char *poblacion);
int hastaCuantoAsOrdenadoMejor(pushswap ps, char *poblacion);
unsigned long long get_time_seed(void);

#endif
