#include "psgenetico.h"

int intlen(int semilla)
{
    int newsemilla = semilla / 10;
    int i = 0;
	while(newsemilla >= '9')
    {
        i++;
    }
    return newsemilla;;

}
int intlenmenos3(int mxMovimientos)
{
    int i = 0;
    int newMaxMovimientos = mxMovimientos / 1000;
	while(newMaxMovimientos > 100)
		i++;
    return newMaxMovimientos;
}
