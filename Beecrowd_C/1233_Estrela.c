#include <stdio.h>
#include <stdlib.h>

// Função para calcular a função totiente de Euler
long calcular_totiente(long N) {
    long resultado = N;
    for (long p = 2; p * p <= N; p++) {
        if (N % p == 0) {
            while (N % p == 0) {
                N /= p;
            }
            resultado -= resultado / p;
        }
    }
    if (N > 1) {
        resultado -= resultado / N;
    }
    return resultado;
}

int main(){

    long estrela_size = 1;
    long *estrela = (long *)malloc(estrela_size * sizeof(long));
    if(!estrela){
        return 1;
    }

    long N;
    while(scanf("%ld", &N) != EOF){
        
        long ciclos_distintos = calcular_totiente(N) / 2;

        estrela_size++;
        long *estrela_temp = (long *)realloc(estrela, estrela_size * sizeof(long));
        if(!estrela_temp){
            free(estrela);
            return 1;
        }

        estrela = estrela_temp;
        estrela[estrela_size-1] = ciclos_distintos;
    }

    for (int i = 1; i < estrela_size; i++){
        printf("%ld\n", estrela[i]);
    }

    free(estrela);

    return 0;
}