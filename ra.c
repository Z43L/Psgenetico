void realizar_ra(int *stacka, int size) {
    if (size > 1) {
        int temp = stacka[0];
        for (int i = 0; i < size - 1; i++) {
            stacka[i] = stacka[i + 1];
        }
        stacka[size - 1] = temp;
    }
}
