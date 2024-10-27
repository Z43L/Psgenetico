#ifndef PSGEN_H
# define PSGEN_H

#define numeroDeGeneraciones 10000000
#define poblacionInicial 300
#define minMovimientos 100
#define maxMovimientos 1000
#define INT_MIN -2147483648
#define INT_MAX 2147483648
#include "FT_PRINTF/src/ft_printf.h"
#include "LIBFT/libft.h"
#include <string.h>

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
char **generarPoblacionInicial(pushswap ps);
char **generarPoblacionDelMejor(pushswap ps, int posicionMejorInicial,char *mejorpoblante);
int intlenmenos3(int mxMovimientos);
int intlen(int semilla);
char *quienEsMejor(char **poblacion,int i);
int numerosDeMovimientosHechos(char *poblacion);
void ejecutarMovimientos(char *poblacion, pushswap ps);
int custom_rand(unsigned long long rand_seed);
unsigned long long read_tsc(void);
int lenstack(int *stack, int ac);
int issorted(pushswap ps);
int hastaCuantoAsOrdenado(pushswap ps);
int hastaCuantoAsOrdenadoMejor(pushswap ps, char *poblacion);
unsigned long long get_tsc_seed();
double medir_tiempo(double duracion_segundos);
int esMovimientoRedundante(char *ultimo_movimiento, char *nuevo_movimiento) ;
int maxElemento(int *stack, int size);
int tenecesito(pushswap ps , char *movimiento, char *poblacion, int masorden);
void añadiraPoblacionteteo( char *poblacion,char *movimiento );
int esMovimientoRedundante(char *ultimo_movimiento, char *nuevo_movimiento);
int esMovimientoIneficiente(pushswap ps, char *movimiento);
char *randommovimiento(int semilla,int i , int  j, int intento );
char *generarMovimientoValido(unsigned long long semilla, pushswap ps, char *ultimo_movimiento, int indice);
int determinarNumeroMovimientos(int posicionMejorInicial);
void liberarPoblacion(char **poblacion);
char **generarPoblacionBasadaEnOrden(pushswap ps,  char **poblacionActual);

#endif