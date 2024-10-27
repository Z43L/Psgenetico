#include "psgenetico.h"
void ejecutarMovimientos(char *poblacion, pushswap ps) {
    int i = 0;
    while (poblacion[i]) {
        if (poblacion[i] == 'r' && poblacion[i+1] == 'a' && ps.size_a > 1) {
            realizar_ra(ps.stacka, ps.size_a);
            i += 2;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'b' && ps.size_b > 1) {
            realizar_rb(ps.stackb, ps.size_b);
            i += 2;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'r' && poblacion[i + 2] == 'a' && ps.size_a > 1) {
            realizar_rra(ps.stacka, ps.size_a);
            i += 3;
        }
        else if (poblacion[i] == 'r' && poblacion[i+1] == 'r' && poblacion[i + 2] == 'b' && ps.size_b > 1) {
            realizar_rrb(ps.stackb, ps.size_b);
            i += 3;
        }
        else if (poblacion[i] == 'p' && poblacion[i+1] == 'a' && ps.size_b > 0) {
            realizar_pa(&ps);
            i += 2;
        }
        else if (poblacion[i] == 'p' && poblacion[i+1] == 'b' && ps.size_a > 0) {
            realizar_pb(&ps);
            i += 2;
        }
        else {
            i++;
        }
    }
}
