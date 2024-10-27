#include "psgenetico.h"
void realizar_rb(int *stackb, int size_b) {
    if (size_b > 1) {
        int temp = stackb[0];
        int i = 0;
        while (i < size_b - 1) {
            stackb[i] = stackb[i + 1];
            i++;
        }
        stackb[size_b - 1] = temp;
    }
}