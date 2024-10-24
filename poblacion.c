#include "psgenetico.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Función para generar la población inicial
char **generarPoblacionInicial()
{
    // Asignación de memoria para la población
    char **poblacion = malloc(poblacionInicial * sizeof(char *));
    if (!poblacion) {
        ft_putstr_fd("Memory allocation error for population\n", 2);
        return NULL;  // Manejo de error de asignación
    }

    for (int i = 0; i < poblacionInicial; i++) {
        poblacion[i] = malloc(300 * sizeof(char));  // Asignación para cada secuencia de movimientos
        if (!poblacion[i]) {
            ft_putstr_fd("Memory allocation error for individual moves\n", 2);
            // Si la asignación falla, libera la memoria asignada previamente
            for (int j = 0; j < i; j++) {
                free(poblacion[j]);
            }
            free(poblacion);
            return NULL;  // Retorna NULL en caso de error
        }
    }

    // Lógica para generar la población inicial (como ya tienes en tu código)
    for (int i = 0; i < poblacionInicial; i++) {
        unsigned long long semilla = get_time_seed();  // Genera la semilla inicial
        int movimientos = custom_rand(semilla) % (maxMovimientos - minMovimientos + 1) + minMovimientos;

        int j = 0;
        while (j < movimientos) {
            int random = custom_rand(semilla + i + j) % 6;
            switch (random) {
                case 0:
                    strcpy(poblacion[i] + j, "ra");
                    j += 2;
                    break;
                case 1:
                    strcpy(poblacion[i] + j, "rb");
                    j += 2;
                    break;
                case 2:
                    strcpy(poblacion[i] + j, "rra");
                    j += 3;
                    break;
                case 3:
                    strcpy(poblacion[i] + j, "rrb");
                    j += 3;
                    break;
                case 4:
                    strcpy(poblacion[i] + j, "pb");
                    j += 2;
                    break;
                case 5:
                    strcpy(poblacion[i] + j, "pa");
                    j += 2;
                    break;
            }
        }
        poblacion[i][j] = '\0';  // Termina la cadena
    }

    return poblacion;
}

// Función para generar la nueva población a partir del mejor individuo
char **generarPoblacionDelMejor(int posicionMejorInicial, char *mejorpoblante)
{
    char **nuevaPoblacion = malloc(poblacionInicial * sizeof(char *));
    
    for (int i = 0; i < poblacionInicial; i++) {
        nuevaPoblacion[i] = malloc(300 * sizeof(char));

        // Copia la mejor secuencia inicial
        strncpy(nuevaPoblacion[i], mejorpoblante, posicionMejorInicial);
        nuevaPoblacion[i][posicionMejorInicial] = '\0';  // Asegura que la cadena esté terminada

        unsigned long long semilla = get_time_seed();
        int movimientos = custom_rand(semilla) % (maxMovimientos - minMovimientos + 1) + minMovimientos;

        // Añade movimientos adicionales hasta alcanzar la longitud deseada
        int j = posicionMejorInicial;
        while (j < movimientos) {
            int random = custom_rand(semilla + i + j) % 6;  // Modifica la semilla en cada paso para mayor variabilidad
            switch (random) {
                case 0:
                    strcpy(nuevaPoblacion[i] + j, "ra");
                    j += 2;
                    break;
                case 1:
                    strcpy(nuevaPoblacion[i] + j, "rb");
                    j += 2;
                    break;
                case 2:
                    strcpy(nuevaPoblacion[i] + j, "rra");
                    j += 3;
                    break;
                case 3:
                    strcpy(nuevaPoblacion[i] + j, "rrb");
                    j += 3;
                    break;
                case 4:
                    strcpy(nuevaPoblacion[i] + j, "pb");
                    j += 2;
                    break;
                case 5:
                    strcpy(nuevaPoblacion[i] + j, "pa");
                    j += 2;
                    break;
            }
        }
        nuevaPoblacion[i][j] = '\0';  // Termina la cadena
    }

    return nuevaPoblacion;
}
