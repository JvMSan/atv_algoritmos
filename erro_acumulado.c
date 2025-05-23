#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Uso: %s <n> <x> <tipo: float|double|longdouble>\n", argv[0]);
        return 1;
    }

    long n = atol(argv[1]);
    long i;
    long double x = strtold(argv[2], NULL);
    char* tipo = argv[3];

    long double somatorio = 0.0;
    long double esperado = n * x;
    long double erro_relativo_real = 0.0;
    long double erro_relativo_estimado = 0.0;

    if (strcmp(tipo, "float") == 0) {
        float x_f = (float)x;
        float soma_f = 0.0f;
        for (i = 0; i < n; i++) {
            soma_f += x_f;
        }
        somatorio = (long double)soma_f;
        erro_relativo_estimado = n * FLT_EPSILON;
    } else if (strcmp(tipo, "double") == 0) {
        double x_d = (double)x;
        double soma_d = 0.0;
        for (i = 0; i < n; i++) {
            soma_d += x_d;
        }
        somatorio = (long double)soma_d;
        erro_relativo_estimado = n * DBL_EPSILON;
    } else if (strcmp(tipo, "longdouble") == 0) {
        long double soma_ld = 0.0L;
        for (i = 0; i < n; i++) {
            soma_ld += x;
        }
        somatorio = soma_ld;
        erro_relativo_estimado = n * LDBL_EPSILON;
    } else {
        printf("Tipo inválido: use float, double ou longdouble\n");
        return 1;
    }

    erro_relativo_real = fabsl((somatorio - esperado) / esperado);

    printf("Tipo: %s\n", tipo);
    printf("n = %ld\n", n);
    printf("x = %.20Lf\n", x);
    printf("Somatório calculado = %.20Lf\n", somatorio);
    printf("Esperado = %.20Lf\n", esperado);
    printf("Erro relativo real = %.20Le\n", erro_relativo_real);
    printf("Erro relativo estimado = %.20Le\n", erro_relativo_estimado);

    return 0;
}
