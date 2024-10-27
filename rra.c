#include "psgenetico.h"
void realizar_rra(int *stacka, int size_a) {
    if (size_a > 1) {
        int temp = stacka[size_a - 1];
        int i = size_a - 1;
        while (i > 0) {
            stacka[i] = stacka[i - 1];
            i--;
        }
        stacka[0] = temp;
    }
}