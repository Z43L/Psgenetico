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
    int i = 0;
    int newMaxMovimientos = mxMovimientos / 1000;
	while(newMaxMovimientos > 100)
		i++;
    return newMaxMovimientos;
}
