void realizar_rrb(int *stackb, int size) {
    if (size > 1) {
        int temp = stackb[size - 1];
        for (int i = size - 1; i > 0; i--) {
            stackb[i] = stackb[i - 1];
        }
        stackb[0] = temp;
    }
}
