#include "psgenetico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definiciones de funciones externas (ejemplo)
unsigned long long get_tsc_seed();
int custom_rand(unsigned long long seed);


// Función para generar la población inicial
char **generarPoblacionInicial(pushswap ps) {
    char **poblacion = malloc(poblacionInicial * sizeof(char *));
    if (!poblacion) return NULL;

    int i = 0;
    while (i < poblacionInicial) {
        poblacion[i] = malloc(maxMovimientos * sizeof(char));
        if (!poblacion[i]) {
            for (int k = 0; k < i; k++) {
                free(poblacion[k]);
            }
            free(poblacion);
            return NULL;
        }

        unsigned long long semilla = get_tsc_seed();
        int movimientos = custom_rand(semilla) % (maxMovimientos - minMovimientos + 1) + minMovimientos;

        int j = 0;
        char ultimo_movimiento[4] = "";

        while (j < movimientos && j < maxMovimientos - 1) {
            int intento = 0;
            int random;
            char nuevo_movimiento[4] = "";

            do {
                random = custom_rand(semilla + i + j + intento) % 6;
                
                if (random == 0) strcpy(nuevo_movimiento, "ra");
                else if (random == 1) strcpy(nuevo_movimiento, "rb");
                else if (random == 2) strcpy(nuevo_movimiento, "rra");
                else if (random == 3) strcpy(nuevo_movimiento, "rrb");
                else if (random == 4) strcpy(nuevo_movimiento, "pa");
                else if (random == 5) strcpy(nuevo_movimiento, "pb");

                intento++;
            } while ((strcmp(nuevo_movimiento, ultimo_movimiento) == 0 || esMovimientoRedundante(ultimo_movimiento, nuevo_movimiento) || esMovimientoIneficiente(ps, nuevo_movimiento)) && intento < 10);

            int len = strlen(nuevo_movimiento);
            for (int k = 0; k < len; k++) {
                poblacion[i][j++] = nuevo_movimiento[k];
            }
            strcpy(ultimo_movimiento, nuevo_movimiento);
        }
        poblacion[i][j] = '\0';
        i++;
    }
    return poblacion;
}


// Generar un nuevo individuo basándose en el mejor individuo encontrado
void generarNuevoIndividuo(char *individuo, char *mejorpoblante, int posicionMejorInicial, pushswap ps) {
    int c = 0;
    while (c < posicionMejorInicial) {
        individuo[c] = mejorpoblante[c];
        c++;
    }

    unsigned long long semilla = get_tsc_seed();
    int movimientos = determinarNumeroMovimientos(posicionMejorInicial);
    char ultimo_movimiento[4] = "";
    int j = posicionMejorInicial;

    while (j < posicionMejorInicial + movimientos && j < maxMovimientos - 1) {
        char *movimiento = generarMovimientoValido(semilla, ps, ultimo_movimiento, j);
        int len = strlen(movimiento);
        if (j + len >= maxMovimientos) {
            len = maxMovimientos - j - 1; // Evitar exceder el límite
        }
        for (int k = 0; k < len; k++) {
            individuo[j++] = movimiento[k];
        }
        strcpy(ultimo_movimiento, movimiento);
        free(movimiento);
    }
    individuo[j] = '\0';
}


// Determinar el número de movimientos a realizar
int determinarNumeroMovimientos(int posicionMejorInicial) {
    unsigned long long semilla = get_tsc_seed();
    int movimientos = custom_rand(semilla) % (maxMovimientos - minMovimientos + 1) + minMovimientos;
    if (movimientos + posicionMejorInicial > maxMovimientos - 1) {
        movimientos = maxMovimientos - 1 - posicionMejorInicial;
    }
    return movimientos;
}


// Evaluar el orden de un individuo
int evaluarOrden(pushswap *ps, char *individuo) {
    pushswap temp_ps;
    temp_ps.size_a = ps->size_a;
    temp_ps.size_b = ps->size_b;
    temp_ps.stacka = malloc(temp_ps.size_a * sizeof(int));
    temp_ps.stackb = malloc(temp_ps.size_a * sizeof(int));
    if (!temp_ps.stacka || !temp_ps.stackb) {
        free(temp_ps.stacka);
        free(temp_ps.stackb);
        return -1; // Error de memoria
    }
    memcpy(temp_ps.stacka, ps->stacka, temp_ps.size_a * sizeof(int));
    memcpy(temp_ps.stackb, ps->stackb, temp_ps.size_b * sizeof(int));

    ejecutarMovimientos(individuo, temp_ps);
    int ordenados = hastaCuantoAsOrdenado(temp_ps);

    free(temp_ps.stacka);
    free(temp_ps.stackb);
    return ordenados;
}

// Generar la mejor población basándose en la evaluación de orden
char **generarPoblacionBasadaEnOrden(pushswap ps,  char **poblacionActual) {
    char **nuevaPoblacion = malloc(poblacionInicial * sizeof(char *));
    if (!nuevaPoblacion) return NULL;

    int *ordenes = malloc(poblacionInicial * sizeof(int));
    if (!ordenes) {
        free(nuevaPoblacion);
        return NULL;
    }

    // Evaluar el orden de cada individuo en la población actual
    for (int i = 0; i < poblacionInicial; i++) {
        ordenes[i] = evaluarOrden(&ps, poblacionActual[i]);
    }

    // Seleccionar el mejor individuo
    int maxOrden = -1;
    int mejorIndice = 0;
    for (int i = 0; i < poblacionInicial; i++) {
        if (ordenes[i] > maxOrden) {
            maxOrden = ordenes[i];
            mejorIndice = i;
        }
    }

    // Generar nueva población basada en el mejor individuo
    for (int i = 0; i < poblacionInicial; i++) {
        nuevaPoblacion[i] = malloc(maxMovimientos * sizeof(char));
        if (!nuevaPoblacion[i]) {
            liberarPoblacion(nuevaPoblacion);
            free(ordenes);
            return NULL;
        }
        generarNuevoIndividuo(nuevaPoblacion[i], poblacionActual[mejorIndice], maxOrden, ps);
    }

    free(ordenes);
    return nuevaPoblacion;
}

// Función para generar la población basada en el mejor resultado hasta ahora
char **generarPoblacionDelMejor(pushswap ps, int posicionMejorInicial, char *mejorpoblante) {
    char **nuevaPoblacion = malloc(poblacionInicial * sizeof(char *));
    if (!nuevaPoblacion) return NULL;
    
    for (int i = 0; i < poblacionInicial; i++) {
        nuevaPoblacion[i] = malloc(maxMovimientos * sizeof(char));
        if (!nuevaPoblacion[i]) {
            liberarPoblacion(nuevaPoblacion);
            return NULL;
        }
        generarNuevoIndividuo(nuevaPoblacion[i], mejorpoblante, posicionMejorInicial, ps);
    }
    return nuevaPoblacion;
}