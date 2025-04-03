#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};
void generarPCs(struct compu pcs[], int cantidad);

int main()
{
    srand(time(NULL));
    struct compu pcs[5];
    generarPCs(pcs, 5);
    return 0;
}

void generarPCs(struct compu pcs[], int cantidad)
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    for (int i = 0; i < cantidad; i++)
    {
        pcs[i].velocidad = rand() % 3 + 1;
        pcs[i].anio = rand() % 10 + 2015;
        pcs[i].cantidad_nucleos = rand() % 8 + 1;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }
}
