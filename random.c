#include "psgenetico.h"

#if defined(__x86_64__) || defined(__i386__)
// Función para leer el TSC en arquitecturas x86/x86-64 usando ensamblador
unsigned long long get_time_seed(void)
{
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

#elif defined(__arm__) || defined(__aarch64__)
// Función para leer el contador de ciclos en arquitecturas ARM usando ensamblador
unsigned long long get_time_seed(void)
{
    unsigned long long cc;
    asm volatile ("mrs %0, cntvct_el0" : "=r" (cc));  // Leer el contador virtual en ARM
    return cc;
}

#else
#error "Arquitectura no soportada"
#endif

// Función custom_rand para generar números aleatorios con una semilla
int custom_rand(unsigned long long rand_seed)
{
    // Mezclar la semilla con un valor constante para aumentar la entropía
    rand_seed = rand_seed * 6364136223846793005ULL + 1;

    // Aplicar un método de mezcla adicional
    rand_seed ^= (rand_seed >> 21);
    rand_seed ^= (rand_seed << 35);
    rand_seed ^= (rand_seed >> 4);

    // Devolver el número aleatorio con un rango amplio
    return (rand_seed % 32768);
}