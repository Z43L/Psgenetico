#include "psgenetico.h"
#include <string.h>  // Include for strlen, strdup

// Utility functions
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

// Define mutation function (example of swapping two random elements)
void mutarIndividuo(char *individuo)
{
    int len = strlen(individuo);  // Get length of individual
    if (len < 2)
        return;  // If too short, no mutation possible

    // Randomly swap two positions
    int pos1 = rand() % len;
    int pos2 = rand() % len;

    char temp = individuo[pos1];
    individuo[pos1] = individuo[pos2];
    individuo[pos2] = temp;
}

// Generate the next generation from the best individual
void generarSiguienteGeneracion(char **poblacion, char *mejorpoblacion, int poblacionSize)
{
    int i;

    // Keep the best population unchanged in the next generation
    poblacion[0] = mejorpoblacion;

    // Mutate and generate the rest of the population
    for (i = 1; i < poblacionSize; i++)
    {
        poblacion[i] = strdup(mejorpoblacion);  // Copy the best individual
        mutarIndividuo(poblacion[i]);           // Apply mutation
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);

    int i = 1, j, k = 0;
    pushswap ps;
    unsigned int semilla = read_tsc();
    char **poblacion;  // Adjusted to char ** to match function parameters
    char *mejorpoblacion;
	int stack_size= lenstack(ps);
    // Initialize memory for ps.stacka
    ps.stacka = malloc(sizeof(int) * stack_size);  // Replace stack_size with actual value
    if (!ps.stacka)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        return (1);
    }

    // Initialize stack
    while (av[i])
    {
        ps.stacka[i] = initstack(av);
        i++;
    }

    // Start genetic algorithm
    while (k < numeroDeGeneraciones)
    {
        while (i < poblacionInicial)
        {
            while (issorted(ps) != -1)
            {
                int random = custom_rand(&semilla);  // Pass semilla as a pointer
                poblacion = generarPoblacionInicial(random);  // Adjusted to match char ** type
                j = 0;
                while (poblacion[j])
                {
                    ejecutarMovimientos(poblacion, ps);  // Pass poblacion as char **
                    mejorpoblacion = quienEsMejor(poblacion, j);  // Pass poblacion as char **
                    generarSiguienteGeneracion(poblacion, mejorpoblacion, poblacionInicial);

                    j++;
                }
            }
            i++;
        }
        k++;
    }

    // Free allocated memory
    free(ps.stacka);

    return 0;
}
