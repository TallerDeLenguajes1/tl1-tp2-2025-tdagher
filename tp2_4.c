#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu
{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
};

void generarPCs(struct compu pcs[], int cantidad);
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main()
{
    srand(time(NULL));

    struct compu pcs[5];
    generarPCs(pcs, 5);

    printf("Lista de PCs:\n");
    listarPCs(pcs, 5);

    printf("\nPC más vieja:\n");
    mostrarMasVieja(pcs, 5);

    printf("\nPC más veloz:\n");
    mostrarMasVeloz(pcs, 5);

    return 0;
}

void generarPCs(struct compu pcs[], int cantidad)
{
    char *tipos[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    for (int i = 0; i < cantidad; i++)
    {
        pcs[i].velocidad = rand() % 3 + 1;
        pcs[i].anio = rand() % 10 + 2015;
        pcs[i].cantidad_nucleos = rand() % 8 + 1;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }
}

void listarPCs(struct compu pcs[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("PC %d: Velocidad: %d GHz, Año: %d, Núcleos: %d, CPU: %s\n",
               i + 1, pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad)
{
    int indice = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (pcs[i].anio < pcs[indice].anio)
        {
            indice = i;
        }
    }
    printf("Velocidad: %d GHz, Año: %d, Núcleos: %d, CPU: %s\n",
           pcs[indice].velocidad, pcs[indice].anio, pcs[indice].cantidad_nucleos, pcs[indice].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad)
{
    int indice = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (pcs[i].velocidad > pcs[indice].velocidad)
        {
            indice = i;
        }
    }
    printf("Velocidad: %d GHz, Año: %d, Núcleos: %d, CPU: %s\n",
           pcs[indice].velocidad, pcs[indice].anio, pcs[indice].cantidad_nucleos, pcs[indice].tipo_cpu);
}
