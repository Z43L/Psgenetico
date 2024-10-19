void realizar_pa(int *stacka, int *size_a, int *stackb, int *size_b) {
    if (*size_b > 0) {
        for (int i = *size_a; i > 0; i--) {
            stacka[i] = stacka[i - 1];
        }
        stacka[0] = stackb[0];
        (*size_a)++;

        for (int i = 0; i < *size_b - 1; i++) {
            stackb[i] = stackb[i + 1];
        }
        (*size_b)--;
    }
}
