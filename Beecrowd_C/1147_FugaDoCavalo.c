#include <stdio.h>
#include <stdlib.h>

int **matrix;

int allocate_matrix(int n, int m)
{
    matrix = (int **)malloc(n * sizeof(int *));
    if (!matrix)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (!matrix[i])
        {
            return 1;
        }

        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = '.';
        }
    }

    return 0;
}

int free_matrix(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int n, int m){
    printf("===================================\n");

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    printf("===================================\n");
}

int verificar_diagonais_sup(int xi, int yi, int n, int m){
    // Verificar adjacentes do peão e registrar na matriz
    if(!(yi - 1 < 0)){ // Consegue ir pra baixo
        if(!(xi + 1 >= m)){ // Consegue ir pra direita
            if(matrix[yi-1][xi+1] == 'P'){
                return 1;
            }
        }
        if(!(xi - 1 < 0)){ // Consegue ir pra esquerda
            if(matrix[yi-1][xi-1] == 'P'){
                return 1;
            }
        }
    }
    
    return 0;
}

int verificar_movimentos(int pos_1, int pos_2, int n, int m, int vertical){
    int pos_validas = 0;

    for(int i = -1; i <= 1; i+=2){
        printf("i = %d\n", i);
        
            // Verificar se a posição é válida
            if(pos_1 + (2*i) < 0 || pos_1 + (2*i) >= n){
                continue;
            }
        for(int j = -1; j <= 1; j+=2){
            // Verificar se a posição é válida
            if(pos_2 + j < 0 || pos_2 + j >= m){
                continue;
            }

            //matrix[pos_2 + j][pos_1 + (2*i)] == '.'
            if(!verificar_diagonais_sup(vertical ? pos_2 + j : pos_1 + (2*i), vertical ? pos_1 + (2*i) : pos_2 + j, n, m)){
                pos_validas++;
                matrix[vertical ? pos_1 + (2*i) : pos_2 + j][vertical ? pos_2 + j : pos_1 + (2*i)] = 'o';
            }else{
                matrix[vertical ? pos_1 + (2*i) : pos_2 + j][vertical ? pos_2 + j : pos_1 + (2*i)] = 'x';
            }
            // TODO: Verificar se for P, então precisa verificar os adjacentes
            // BUG: Se um peão for posto em sua diagonal esquerda ou direita após sua colocação, ele será sobrescrito com A
            
            printf("x = %d y = %d value = %c\n", pos_1 + (2 * i), pos_2 + j, matrix[pos_2 + j][pos_1 + (2 * i)]);
        }
    }

    return pos_validas;
}

int main()
{
    // NA MATRIX:
    // . --> Nada
    // P --> Peão
    // A --> Onde o peão pode comer
    int pos_x, pos_y;
    int moves = 0;
   
    // Inicar tabuleiro
    int n = 8, m = 8;
    allocate_matrix(n, m);
   
    // Var do while
    int running = 1;

    while(running){
        for(int i = 0; i < 9; i++){
            char tmp_pos[3];
            scanf("%s", tmp_pos);

            // Verificar se é para parar
            if(tmp_pos[0] == '0'){
                running = 0;
                break;
            }
        
            if(i == 0){ // Leitura posição do cavalo
                pos_y = tmp_pos[0] - '1'; // -1 pos do vetor
                pos_x = tmp_pos[1] - 'a'; // -1 pos do vetor
                continue;
            }
        
            // Registrar posição do peão na matriz
            int tmp_pos_y = tmp_pos[0] - '1';
            int tmp_pos_x = tmp_pos[1] - 'a';
            matrix[tmp_pos_y][tmp_pos_x] = 'P';

        }

        // Verificar se o cavalo pode escapar
        // +- 2 no y e +- 1 no x
        // +- 2 no x e +- 1 no y

        moves += verificar_movimentos(pos_x, pos_y, n, m, 0);
        moves += verificar_movimentos(pos_y, pos_x, n, m, 1);
    
        print_matrix(n, m);
        printf("Moves = %d\n", moves);
    }

    free_matrix(n, m);
    return 0;
}