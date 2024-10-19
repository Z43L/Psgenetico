void realizar_rra(int *stacka, int size) {
    if (size > 1) {
        int temp = stacka[size - 1];
        for (int i = size - 1; i > 0; i--) {
            stacka[i] = stacka[i - 1];
        }
        stacka[0] = temp;
    }
}
