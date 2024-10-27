#include "psgenetico.h"
void realizar_rrb(int *stackb, int size_b) {
    if (size_b > 1) {
        int temp = stackb[size_b - 1];
        int i = size_b - 1;
        while (i > 0) {
            stackb[i] = stackb[i - 1];
            i--;
        }
        stackb[0] = temp;
    }
}