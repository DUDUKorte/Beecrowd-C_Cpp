#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    while(scanf("%d", &n) != EOF){

        int *competidores = (int *)malloc(n * sizeof(int));
        int *grid_chegada = (int *)malloc(n * sizeof(int));

        if(!competidores || !grid_chegada){
            return 1;
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &competidores[i]);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &grid_chegada[i]);
        }

        // Verificar aqui quantas ultrapassagens foram feitas
        int ultrapassagens = 0;

        // rodar o grid de chegada
        for(int i = 0; i < n; i++){
            int competidor_atual = grid_chegada[i];

            // achar o competidor atual no grid de largada
            for(int j = 0; j < n; j++){
                if(competidores[j] == competidor_atual){
                    int indice_atual = j;
                    
                    while(indice_atual != i){
                        int temp = competidores[indice_atual];
                        competidores[indice_atual] = competidores[indice_atual - 1];
                        competidores[indice_atual - 1] = temp;
                        indice_atual--;
                        ultrapassagens++;
                    }
                }    
            }
        }

        printf("%d\n", ultrapassagens);

        free(competidores);
        free(grid_chegada);
    }

    return 0;
}
