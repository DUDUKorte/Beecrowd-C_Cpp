#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long compare(const void *a, const void *b) {
    long *vA = a;
    long *vB = b;
    return *vA - *vB;
}

int main() {
    long *paresList;
    long *imparesList;
    
    paresList = (long *)malloc(sizeof(long));
    imparesList = (long *)malloc(sizeof(long));
    
    int n, par_i = 0, impar_i = 0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int currentInt;
        scanf("%d", &currentInt);
        
        if(currentInt%2 == 0){
            long *tmp_paresList = realloc(paresList, sizeof(paresList) + sizeof(long));
            paresList = tmp_paresList;
            paresList[par_i] = currentInt;
            par_i++;
        }else{
            long *tmp_imparesList = realloc(imparesList, sizeof(imparesList) + sizeof(long));
            imparesList = tmp_imparesList;
            imparesList[impar_i] = currentInt;
            impar_i++;
        }
    }
    
    qsort(paresList, par_i, sizeof(long), compare);
    qsort(imparesList, impar_i, sizeof(long), compare);

    for(int i = 0; i < par_i; i++){
        printf("%ld\n", paresList[i]);
    }
    for(int i = impar_i-1; i >= 0; i--){
        printf("%ld\n", imparesList[i]);
    }

    return 0;
}