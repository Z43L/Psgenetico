void realizar_rb(int *stackb, int size) {
    if (size > 1) {
        int temp = stackb[0];
        for (int i = 0; i < size - 1; i++) {
            stackb[i] = stackb[i + 1];
        }
        stackb[size - 1] = temp;
    }
}
