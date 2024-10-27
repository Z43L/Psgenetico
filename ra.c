#include "psgenetico.h"

void realizar_ra(int *stacka, int size_a) {
    if (size_a > 1) {
        int temp = stacka[0];
        int i = 0;
        while (i < size_a - 1) {
            stacka[i] = stacka[i + 1];
            i++;
        }
        stacka[size_a - 1] = temp;
    }
}
