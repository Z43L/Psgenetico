#include "psgenetico.h"
int	is_number(const char *str)
{
	int	i;

	i = 0;
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

// ft_atol.c
long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
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

// has_duplicates.c
int	has_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;

	i = 1;
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
    int i =0;
    long value;
    value = ft_atol(av[i]);
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
    int i =1;
    pushswap ps;
    
    while(av[i])
    {
        ps.stacka[i] =   initstack(av);
        i++;
    }
    
    int semilla = read_tsc();
    i = 0;
    int j  = 0;
    int k =0;
    char **poblacion;
    char *mejorpoblacion;
    while(k < numeroDeGeneraciones)
    {
        while(i < poblacionInicial)
        {
            while(issorted(ps) != -1)
            {
                int random = custom_rand(semilla);
                poblacion = generarPoblacionInicial(random);
                j = 0;
                while(poblacion[j])
                {
                
                    ejecutarMovimientos(poblacion, ps);
                    int cuantoAsAvanzado = hastaCuantoAsOrdenado(ps,poblacion, j);

                    mejorpoblacion = quienEsMejor(poblacion, ps, j);
                    j++;
                }
                int posicionInicial = hastaCuantoAsOrdenadoMejor(ps,mejorpoblacion);
                generarPoblacionDelMejor(random, posicionInicial)
            }
            i++;
        }
        k++;
    }

    ft_printf("%s",mejorpoblacion);
    return 0;
    
    
}