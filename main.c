#include "psgenetico.h"
#include <string.h>  
int is_number(const char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void liberarPoblacion(char **poblacion)
{
    if (!poblacion) return;  // Verifica si la población ya fue liberada

    for (int i = 0; i < poblacionInicial; i++) {
        free(poblacion[i]);  // Libera cada cadena de movimientos
    }
    free(poblacion);  // Libera el arreglo de punteros
}


long ft_atol(const char *str)
{
    int i = 0;
    long sign = 1;
    long result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i++] - '0');
    }
    return (result * sign);
}

int has_duplicates(int argc, char **argv)
{
    int i = 1, j;
    long val_i, val_j;

    while (i < argc)
    {
        val_i = ft_atol(argv[i]);
        j = i + 1;
        while (j < argc)
        {
            val_j = ft_atol(argv[j]);
            if (val_i == val_j)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


int *initstack(int ac, char **av) {
    int *value = malloc(ac * sizeof(int));
    if (!value) {
        return NULL; // Manejo de error en caso de falla de asignación
    }
    for (int i = 0; i < ac; i++) {
        value[i] = ft_atol(av[i]);
    }
    return value;
}

void moverMinimoArriba(pushswap *ps) {
    if (ps->size_a <= 1) 
        return ;
    char *movimientos_iniciales = malloc(256 * sizeof(char)); // Allocate sufficient memory
    if (!movimientos_iniciales) {
        ft_putstr_fd("Memory allocation error\n", 2);
        return;
    }
    movimientos_iniciales[0] = '\0';
    int min_index = 0;
    for (int i = 1; i < ps->size_a; i++) {
        if (ps->stacka[i] < ps->stacka[min_index]) {
            min_index = i;
        }
    }

    int movimientos_ra = min_index;
    int movimientos_rra = ps->size_a - min_index;
    int k = 0;

    if (movimientos_ra <= movimientos_rra) {
        for (int i = 0; i < movimientos_ra; i++) {
            realizar_ra(ps->stacka, ps->size_a);
            ft_strlcat(movimientos_iniciales, "ra", 2);
            k++;
        }
    } else {
        for (int i = 0; i < movimientos_rra; i++) {
            realizar_rra(ps->stacka, ps->size_a);
            ft_strlcat(movimientos_iniciales, "rra", 3);
            k++;
        }
    }
    
}


int main(int ac, char **av) {
    if (ac < 2)
        return 0;

    int i;
    pushswap ps;
    char **poblacion = NULL;
    char *mejorpoblacion = NULL;
    int posicionInicial = 0;

    ps.size_a = ac - 1;
    ps.size_b = 0;

    ps.stacka = malloc(sizeof(int) * ps.size_a);
    ps.stackb = malloc(sizeof(int) * ps.size_a);
    if (!ps.stacka || !ps.stackb) {
        ft_putstr_fd("Memory allocation error\n", 2);
        return 1;
    }

    // Cargar los valores iniciales en stacka
    for (i = 1; i < ac; i++)
        ps.stacka[i - 1] = atoi(av[i]);

    ft_printf("Loaded stacka: ");
    for (i = 0; i < ps.size_a; i++)
        ft_printf("%d ", ps.stacka[i]);
    ft_printf("\n");

    // Movimientos para posicionar el menor en la posición superior
    moverMinimoArriba(&ps);
    
    // Generar la población inicial después de asegurar que el mínimo está en la posición 0
    poblacion = generarPoblacionInicial(ps);
    if (!poblacion) {
        ft_putstr_fd("Error generating population\n", 2);
        free(ps.stacka);
        free(ps.stackb);
        return 1;
    }

    // Bucle principal de generaciones
    int k = 0;
    while (k < numeroDeGeneraciones && issorted(ps) == 0) {
        ft_printf("Generación: %d\n", k);

        i = 0;
        mejorpoblacion = poblacion[0];
        int maxOrdenado = 0;

        // Evaluar cada población
        while (i < poblacionInicial) {
            int *temp_stacka = malloc(sizeof(int) * ps.size_a);
            int *temp_stackb = malloc(sizeof(int) * ps.size_a);
            if (!temp_stacka || !temp_stackb) {
                ft_putstr_fd("Memory allocation error\n", 2);
                liberarPoblacion(poblacion);
                free(ps.stacka);
                free(ps.stackb);
                return 1;
            }

            memcpy(temp_stacka, ps.stacka, sizeof(int) * ps.size_a);
            pushswap temp_ps = {temp_stacka, temp_stackb, ps.size_a, ps.size_b};

            ejecutarMovimientos(poblacion[i], temp_ps);
            int ordenados = hastaCuantoAsOrdenado(temp_ps);

            if (ordenados > maxOrdenado) {
                maxOrdenado = ordenados;
                mejorpoblacion = poblacion[i];
            }

            free(temp_stacka);
            free(temp_stackb);
            i++;
        }

        if (maxOrdenado < posicionInicial) {
            maxOrdenado = posicionInicial;
        }

        posicionInicial = maxOrdenado;
        ft_printf("La mejor población %s ha ordenado hasta %d elementos\n", mejorpoblacion, posicionInicial);
        int *tmppushswapstacka = malloc(sizeof(int) * ps.size_a);
        int *temp_stackb = malloc(sizeof(int) * ps.size_a);

        if (!tmppushswapstacka || !temp_stackb) {
            ft_putstr_fd("Memory allocation error\n", 2);
            liberarPoblacion(poblacion);
            free(ps.stacka);
            free(ps.stackb);
            return 1;
        }
        memcpy(tmppushswapstacka, ps.stacka, sizeof(int) * ps.size_a);

        pushswap tmppusshap = {tmppushswapstacka, temp_stackb, ps.size_a, ps.size_b};

        int i = 1;
      
        ejecutarMovimientos(mejorpoblacion, tmppusshap);
        while(i < ac)
        {
            ft_printf("%d ", tmppusshap.stacka[i -1]);
            i++;
        }
        if (posicionInicial == ps.size_a) {
            ft_printf("Stacka está completamente ordenada. Fin del programa.\n");
            break;
        }

        
        poblacion = generarPoblacionBasadaEnOrden(ps, poblacion);
        if (!poblacion) {
            ft_putstr_fd("Error generating population\n", 2);
            free(ps.stacka);
            free(ps.stackb);
            return 1;
        }

        k++;
    }

    liberarPoblacion(poblacion);
    free(ps.stacka);
    free(ps.stackb);

    return 0;
}
