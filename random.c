#include "psgenetico.h"
unsigned long long get_tsc_seed() {
    unsigned int lo, hi;
    // Ensamblador para leer el registro TSC (Timestamp Counter)
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int custom_rand(unsigned long long rand_seed)
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (rand_seed / 65536) % 32768;
}

unsigned long long read_tsc(void)
{
    unsigned int lo, hi;

    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));

    return ((unsigned long long)hi << 32) | lo;
}

// Función para calcular la frecuencia del procesador
double calcular_frecuencia_cpu()
{
    unsigned long long start, end;
    double tiempo_espera = 1.0; // Esperar 1 segundo
    volatile double tiempo_inicio = 0.0;

    start = read_tsc();

    while (tiempo_inicio < 1000000000.0)
    {
        tiempo_inicio += 1.0;
    }

    end = read_tsc();

    return (end - start) / tiempo_espera;
}

double medir_tiempo(double duracion_segundos)
{
    unsigned long long start, end;
    double frecuencia_cpu = calcular_frecuencia_cpu();
    volatile double tiempo_transcurrido = 0.0;

    start = read_tsc();

    while (tiempo_transcurrido < frecuencia_cpu * duracion_segundos)
    {
        tiempo_transcurrido += 1.0;
    }

    end = read_tsc();

    return (end - start) / frecuencia_cpu;
}