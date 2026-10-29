#include <stdio.h>

#define TAM 10

void copiarNotas(float origem[], float destino[]) {
    for (int i = 0; i < TAM; i++) {
        destino[i] = origem[i];
    }
}

void exibirNotas(float notas[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%.1f ", notas[i]);
    }
    printf("\n");
}

void bubbleSort(float notas[]) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (notas[j] < notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

void quickSort(float notas[], int inicio, int fim) {
    int i = inicio;
    int j = fim;
    float pivo = notas[(inicio + fim) / 2];

    while (i <= j) {
        while (notas[i] > pivo) {
            i++;
        }

        while (notas[j] < pivo) {
            j--;
        }

        if (i <= j) {
            float temp = notas[i];
            notas[i] = notas[j];
            notas[j] = temp;
            i++;
            j--;
        }
    }

    if (inicio < j) {
        quickSort(notas, inicio, j);
    }

    if (i < fim) {
        quickSort(notas, i, fim);
    }
}


    if (inicio < j) {
        quickSort(notas, inicio, j);
    }

    if (i < fim) {
        quickSort(notas, i, fim);
    
}

int main(void) {
    float originais[TAM] = {
        7.5, 9.0, 5.5, 8.0, 6.5,
        10.0, 4.0, 8.5, 7.0, 6.0
    };

    float bubble[TAM];
    float quick[TAM];

    copiarNotas(originais, bubble);
    copiarNotas(originais, quick);

    printf("Notas originais:\n");
    exibirNotas(originais);

    bubbleSort(bubble);
    printf("\nNotas ordenadas pelo Bubble Sort:\n");
    exibirNotas(bubble);

    quickSort(quick, 0, TAM - 1);
    printf("\nNotas ordenadas pelo Quick Sort:\n");
    exibirNotas(quick);

    return 0;
}

