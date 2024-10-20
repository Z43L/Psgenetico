void realizar_pb(int *stackb, int *size_b, int *stacka, int *size_a) {
    if (*size_a > 0) {
        for (int i = *size_b; i > 0; i--) {
            stackb[i] = stackb[i - 1];
        }
        stackb[0] = stacka[0];
        (*size_b)++;

        for (int i = 0; i < *size_a - 1; i++) {
            stacka[i] = stacka[i + 1];
        }
        (*size_a)--;
    }
}

