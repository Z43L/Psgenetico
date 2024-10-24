#include "psgenetico.h"
void ejecutarMovimientos(char *poblacion, pushswap ps)
{
    int i = 0;
    while (poblacion[i])
    {
        // Verificar los índices antes de acceder a poblacion y realizar operaciones
        ft_printf("Index i: %d, stacka size: %d, stackb size: %d\n", i, ps.size_a, ps.size_b);

        if (poblacion[i] == 'r' && poblacion[i+1] == 'a')
        {
            if (ps.size_a > 1) {
                ft_printf("Performing move: ra\n");
                realizar_ra(ps.stacka, ps.size_a);
            }
            i += 2;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'b')
        {
            if (ps.size_b > 1) {
                ft_printf("Performing move: rb\n");
                realizar_rb(ps.stackb, ps.size_b);
            }
            i += 2;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'r' && poblacion[i + 2] == 'a')
        {
            if (ps.size_a > 1) {
                ft_printf("Performing move: rra\n");
                realizar_rra(ps.stacka, ps.size_a);
            }
            i += 3;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'r' && poblacion[i + 2] == 'b')
        {
            if (ps.size_b > 1) {
                ft_printf("Performing move: rrb\n");
                realizar_rrb(ps.stackb, ps.size_b);
            }
            i += 3;
        }
        else if (poblacion[i] == 'p' && poblacion[i+1] == 'a')
        {
            if (ps.size_b > 0) {
                ft_printf("Performing move: pa\n");
                realizar_pa(&ps);
            }
            i += 2;
        }
        else if (poblacion[i] == 'p' && poblacion[i+1] == 'b')
        {
            if (ps.size_a > 0) {
                ft_printf("Performing move: pb\n");
                realizar_pb(&ps);
            }
            i += 2;
        }
        else
        {
            i++;  // Si no coincide con un movimiento válido, avanzar uno
        }

        // Verificar después de cada operación
        if (ps.size_a < 0 || ps.size_b < 0) {
            ft_printf("Error: Tamaño inválido de stacka o stackb!\n");
            break;
        }
    }
}
