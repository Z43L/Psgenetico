#include "psgenetico.h"

int intlen(int num)
{
    
    int length = 0;
    if (num == 0)
        return 1;
    while (num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}
int intlenmenos3(int mxMovimientos)
{
    // Reduce mxMovimientos by dividing by 1000
    int newMaxMovimientos = mxMovimientos / 1000;

    // Ensure the value does not drop below zero
    if (newMaxMovimientos < 0)
        return 0;

    return newMaxMovimientos;
}
