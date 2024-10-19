#include "psgenetico.h"

#if defined(__x86_64__) || defined(__i386__)
// Función para leer el TSC en arquitecturas x86/x86-64
unsigned long long read_tsc(void)
{
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}
#elif defined(__arm__) || defined(__aarch64__)
// Función para leer el contador de ciclos en arquitecturas ARM
unsigned long long read_cycle_counter(void)
{
    unsigned int cc;
    // Leer el Performance Monitor Cycle Counter (PMCCNTR) en ARM
    asm volatile ("mrs %0, PMCCNTR_EL0" : "=r" (cc)); // Para ARMv8-A
    return cc;
}
#else
#error "Arquitectura no soportada"
#endif

// Función custom_rand para generar números aleatorios con una semilla
int custom_rand(unsigned int *rand_seed)
{
    *rand_seed = *rand_seed * 1103515245 + 12345;
    return (*rand_seed / 65536) % 32768;
}

