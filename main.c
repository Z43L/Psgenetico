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
void imprimirMejorPoblacion(char *mejorpoblacion)
{
    int i = 0;
    ft_printf("Mejor combinación de movimientos:\n");
    while (mejorpoblacion[i])
    {
        ft_printf("%s\n", mejorpoblacion[i]); 
        i++;
    }
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

int initstack(char **av)
{
    int i = 0;
    long value = ft_atol(av[i]);

    if (value < INT_MIN || value > INT_MAX)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    return value;
}
int main(int ac, char **av)
{
    if (ac < 2)
        return (0);

    int i = 1;
    int j = 0;
    int k = 0;
    pushswap ps;
    
    char **poblacion;
    char *mejorpoblacion;

    ps.size_a = ac - 1;
    ps.size_b = 0;

    // Asignación de memoria para stacka y stackb
    ps.stacka = malloc(sizeof(int) * ps.size_a);
    ps.stackb = malloc(sizeof(int) * ps.size_a); 
    if (!ps.stacka || !ps.stackb)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        return (1);
    }

    // Convertir los argumentos a enteros y cargarlos en stacka
    i = 1;
    while (i < ac)
    {
        ps.stacka[i - 1] = atoi(av[i]);
        i++; 
    }

    ft_printf("Loaded stacka: ");
    for (int i = 0; i < ps.size_a; i++) {
        ft_printf("%d ", ps.stacka[i]); 
    }
    ft_printf("\n");

    // Bucle principal: ejecutar generaciones hasta que esté ordenado o se alcancen las generaciones máximas
    while (k < numeroDeGeneraciones && issorted(ps) != 1)
    {
        i = 0;
        while (i < poblacionInicial)
        {
            poblacion = generarPoblacionInicial();
            if (!poblacion) {
                ft_putstr_fd("Error generating population\n", 2);
                return (1);
            }

            j = 0;
            mejorpoblacion = poblacion[0];  // Inicialmente, el primer individuo es el mejor

            while (poblacion[j])
            {
                ejecutarMovimientos(poblacion[j], ps);
                int numerodeMovimientosOrdenados = hastaCuantoAsOrdenado(ps, poblacion[j]);

                if (issorted(ps) == 1) 
                {
                    ft_printf("Stacka está completamente ordenada. Movimientos usados:\n");
                    imprimirMejorPoblacion(poblacion[j]);
                    liberarPoblacion(poblacion);

                    free(ps.stacka);
                    free(ps.stackb);
                    return 0;
                }

                // Comparar si el nuevo individuo está más ordenado
                if (j > 0 && numerodeMovimientosOrdenados < hastaCuantoAsOrdenado(ps, mejorpoblacion))
                {
                    mejorpoblacion = poblacion[j];  // Actualizar la mejor población
                }

                j++;
            }

            // Liberar la memoria de la población actual
            liberarPoblacion(poblacion);

            // Generar una nueva población basada en el mejor individuo
            int posicionInicial = hastaCuantoAsOrdenado(ps, mejorpoblacion);
            poblacion = generarPoblacionDelMejor(posicionInicial, mejorpoblacion);  // Actualizar población

            i++;
        }

        imprimirMejorPoblacion(mejorpoblacion);  // Imprime la mejor población después de cada generación

        if (issorted(ps) == 1) // Verifica si la pila está ordenada después de cada generación
        {
            ft_printf("Stacka está completamente ordenada. Fin del programa.\n");
            free(ps.stacka);
            free(ps.stackb);
            return 0;
        }

        k++;
    }

    
    return 0;
}
