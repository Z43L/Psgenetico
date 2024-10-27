#include "psgenetico.h"



// Función para verificar si un movimiento es redundante respecto al anterior
int esMovimientoRedundante(char *ultimo_movimiento, char *nuevo_movimiento) {
    if ((ft_strncmp(ultimo_movimiento, "ra",2) == 0 && ft_strncmp(nuevo_movimiento, "rra",3) == 0) ||
        (ft_strncmp(ultimo_movimiento, "rra", 3) == 0 && ft_strncmp(nuevo_movimiento, "ra",2) == 0) ||
        (ft_strncmp(ultimo_movimiento, "rb",2) == 0 && ft_strncmp(nuevo_movimiento, "rrb",3) == 0) ||
        (ft_strncmp(ultimo_movimiento, "rrb", 3) == 0 && ft_strncmp(nuevo_movimiento, "rb", 2) == 0)) {
        return 1;
    }
    return 0;
}
int maxElemento(int *stack, int size) {
    int max = stack[0];
    for (int i = 1; i < size; i++) {
        if (stack[i] > max) {
            max = stack[i];
        }
    }
    return max;
}

// Función para verificar si un movimiento es innecesario dada la situación actual de las pilas
int esMovimientoIneficiente(pushswap ps, char *movimiento) {
    if (ft_strncmp(movimiento, "pa", 2) == 0 && ps.size_b == 0) {
        return 1; // No se puede hacer 'pa' si la pila B está vacía
    }
    if (ft_strncmp(movimiento, "pb", 2) == 0 && ps.size_a == 0) {
        return 1; // No se puede hacer 'pb' si la pila A está vacía
    }
    if (ft_strncmp(movimiento, "ra", 2) == 0 && ps.stacka[ps.size_a - 1] == maxElemento(ps.stacka, ps.size_a)) {
        return 1; // Evitar 'ra' si el elemento más grande ya está en la parte inferior
    }
    return 0;
}

void añadiraPoblacionteteo( char *poblacion,char *movimiento )
{
    size_t i = 0;
    if(i < ft_strlen(movimiento))
    {
        ft_strlcat(poblacion, movimiento, ft_strlen(movimiento));
    }
}
char *randommovimiento(int semilla,int i , int  j, int intento )
{
    char *nuevo_movimiento = malloc(sizeof(char *) * 4);
    int random = custom_rand(semilla + i + j + intento) % 6;
    if (random == 0) strcpy(nuevo_movimiento, "ra");
    else if (random == 1) strcpy(nuevo_movimiento, "rb");
    else if (random == 2) strcpy(nuevo_movimiento, "rra");
    else if (random == 3) strcpy(nuevo_movimiento, "rrb");
    else if (random == 4) strcpy(nuevo_movimiento, "pa");
    else if (random == 5) strcpy(nuevo_movimiento, "pb");
    return nuevo_movimiento;
}

int tenecesito(pushswap ps , char *movimiento, char *poblacion, int masorden)
{
    char *tmpmovimiento = movimiento;
    char *tmpoblacion = poblacion;
    pushswap tempushwat = ps;
    añadiraPoblacionteteo(  tmpoblacion, tmpmovimiento);
    if(hastaCuantoAsOrdenado(tempushwat) > masorden)
    {    
        añadiraPoblacionteteo( poblacion, movimiento);
        return 0;
    }
    else
    {
        tenecesito(ps, movimiento, poblacion, masorden);

    }
    return 1;
}

char *generarMovimientoValido(unsigned long long semilla, pushswap ps, char *ultimo_movimiento, int indice) {
    char *movimiento;
    int intento = 0;
    do {
        movimiento = randommovimiento(semilla, indice,ft_strlen(ultimo_movimiento) , intento);
        intento++;
    } while ((strcmp(movimiento, ultimo_movimiento) == 0 || esMovimientoRedundante(ultimo_movimiento, movimiento) || esMovimientoIneficiente(ps, movimiento)) && intento < 10);
    return movimiento;
}