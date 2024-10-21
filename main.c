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
void imprimirMejorPoblacion(char **mejorpoblacion)
{
    int i = 0;
    ft_printf("Mejor combinación de movimientos:\n");
    while (mejorpoblacion[i])
    {
        ft_printf("%s\n", mejorpoblacion[i]); 
        i++;
    }
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
    int  j =0;
    int k = 0;
    pushswap ps;
    unsigned int semilla = read_tsc();
    char **poblacion; 
    char *mejorpoblacion;

    ps.size_a = ac - 1;
    ps.size_b = 0;

    
    ps.stacka = malloc(sizeof(int) * ps.size_a);
    ps.stackb = malloc(sizeof(int) * ps.size_a); 
    if (!ps.stacka || !ps.stackb)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        return (1);
    }

    for (i = 1; i < ac; i++)
    {
        ps.stacka[i - 1] = atoi(av[i]); 
    }
    // Print the stack to check if the input is loaded correctly
    ft_printf("Loaded stacka: ");
    for (int i = 0; i < ps.size_a; i++) {
        ft_printf("%d ", ps.stacka[i]); 
    }
    ft_printf("\n");


    while (k < numeroDeGeneraciones)
    {
        while (i < poblacionInicial)
        {
            while (issorted(ps) != -1)
            {
                int random = custom_rand(&semilla);
                poblacion = generarPoblacionInicial(random);
                while (poblacion[j])
                {
                    ejecutarMovimientos(poblacion[j], ps); 
                    int numerodeMovimientosOrdenados = hastaCuantoAsOrdenado(ps, poblacion[j]);
                    mejorpoblacion = poblacion[j];
                    if(numerodeMovimientosOrdenados < hastaCuantoAsOrdenado(ps, poblacion[j -1]))
                        mejorpoblacion =poblacion[j-1]; 
                    j++;
                }
                poblacion[0] = mejorpoblacion;
                int posicioInicial = hastaCuantoAsOrdenado(ps, poblacion[0]);
                generarPoblacionDelMejor(semilla,posicioInicial, 0 ,mejorpoblacion);
            }
            i++;
            imprimirMejorPoblacion(poblacion);

        }
        k++;
    }

    // Free allocated memory
    free(ps.stacka);
    free(ps.stackb);

    return 0;
}
