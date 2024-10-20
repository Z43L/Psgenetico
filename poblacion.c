#include "psgenetico.h"
#include <stdlib.h> // For malloc
#include <string.h> // For strcpy

// Generate the initial population
char **generarPoblacionInicial(int semilla)
{    
    char **poblacion;
    int i = 0;
    
    // Allocate memory for poblacion (array of strings)
    poblacion = malloc(poblacionInicial * sizeof(char *));
    for (int k = 0; k < poblacionInicial; k++) {
        poblacion[k] = malloc(300 * sizeof(char *));  // Allocate memory for each move
    }

    while (i <= poblacionInicial)
    {    
        int j = 0;
        int movimientos = intlenmenos3(maxMovimientos);
        while (movimientos < 300)
            movimientos = intlenmenos3(maxMovimientos);
        while (j < movimientos)
        {
            if (intlen(semilla) <= 1)
                strcpy(poblacion[i], "ra");   // Use strcpy to copy the string
            else if (intlen(semilla) <= 3)
                strcpy(poblacion[i], "rb");
            else if (intlen(semilla) <= 5 && intlen(semilla) >= 4)
                strcpy(poblacion[i], "rra");
            else if (intlen(semilla) <= 7)
                strcpy(poblacion[i], "rrb");
            else if (intlen(semilla) == 4 || intlen(semilla) == 6)
                strcpy(poblacion[i], "pb");
            else if (intlen(semilla) <= 9 && intlen(semilla) >= 8)
                strcpy(poblacion[i], "pa");
            j++;
        }
        i++;
    }
    return poblacion;
}

// Generate the population based on the best individual
char **generarPoblacionDelMejor(int semilla, int posicionMejorInicial, int i)
{
    char **nuevaPoblacion;
    
    // Allocate memory for nuevaPoblacion (array of strings)
    nuevaPoblacion = malloc(poblacionInicial * sizeof(char *));
    for (int k = 0; k < poblacionInicial; k++) {
        nuevaPoblacion[k] = malloc(300 * sizeof(char *));  // Allocate memory for each move
    }

    while (i < poblacionInicial)
    {    
        int movimientos = intlenmenos3(maxMovimientos);
        while (movimientos < 300)
            movimientos = intlenmenos3(maxMovimientos);
        while (posicionMejorInicial < movimientos)
        {
            if (intlen(semilla) <= 1)
                strcpy(nuevaPoblacion[i], "ra");   // Use strcpy to copy the string
            else if (intlen(semilla) <= 3)
                strcpy(nuevaPoblacion[i], "rb");
            else if (intlen(semilla) <= 5 && intlen(semilla) >= 4)
                strcpy(nuevaPoblacion[i], "rra");
            else if (intlen(semilla) <= 7)
                strcpy(nuevaPoblacion[i], "rrb");
            else if (intlen(semilla) == 4 || intlen(semilla) == 6)
                strcpy(nuevaPoblacion[i], "pb");
            else if (intlen(semilla) <= 9 && intlen(semilla) >= 8)
                strcpy(nuevaPoblacion[i], "pa");
            posicionMejorInicial++;
        }
        i++;
    }
    return nuevaPoblacion;
}
