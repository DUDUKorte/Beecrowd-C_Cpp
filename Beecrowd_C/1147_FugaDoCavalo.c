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
    //printf("===================================\n");

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            //printf("%c", matrix[i][j]);
        }
        //printf("\n");
    }

    //printf("===================================\n");
}

int verificar_diagonais_sup(int xi, int yi, int n, int m){
    //printf("====== verif diagonais\nxi = %d\tyi = %d\n--- sup dir:\tx = %d\t y = %d\n--- sup esq:\tx = %d\t y = %d\n", xi, yi, xi + 1, yi + 1, xi - 1, yi + 1);
    
    // Verificar adjacentes do peão e registrar na matriz
    if(!(yi + 1 >= n)){ // Consegue ir pra baixo
        if(!(xi + 1 >= m)){ // Consegue ir pra direita
            if(matrix[yi+1][xi+1] == 'P'){
                return 1;
            }
        }
        if(!(xi - 1 < 0)){ // Consegue ir pra esquerda
            if(matrix[yi+1][xi-1] == 'P'){
                return 1;
            }
        }
    }
    
    //printf("==== Valida\n");
    
    return 0;
}

int verificar_movimentos(int pos_1, int pos_2, int n, int m, int vertical){
    int pos_validas = 0;

    for(int i = -1; i <= 1; i+=2){
        //printf("i = %d\n", i);
        
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
                //matrix[vertical ? pos_1 + (2*i) : pos_2 + j][vertical ? pos_2 + j : pos_1 + (2*i)] = 'o';
            }else{
                //matrix[vertical ? pos_1 + (2*i) : pos_2 + j][vertical ? pos_2 + j : pos_1 + (2*i)] = 'x';
            }
            // TODO: Verificar se for P, então precisa verificar os adjacentes
            // BUG: Se um peão for posto em sua diagonal esquerda ou direita após sua colocação, ele será sobrescrito com A
            
            //printf("x = %d y = %d value = %c\n", vertical ? pos_2 + j : pos_1 + (2 * i), vertical ? pos_1 + (2 * i) : pos_2 + j, matrix[vertical ? pos_1 + (2 * i) : pos_2 + j][vertical ? pos_2 + j : pos_1 + (2 * i)]);
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
   
    // Var do while
    char pos_cavalo[3];
    int test_case = 1;

    while(scanf("%s", pos_cavalo) != EOF && pos_cavalo[0] != '0'){
        moves = 0;

        // Inicar tabuleiro
        int n = 8, m = 8;
        allocate_matrix(n, m);

        // Salvar posição do cavalo
        pos_y = pos_cavalo[0] - '1'; // -1 pos do vetor
        pos_x = pos_cavalo[1] - 'a'; // -1 pos do vetor

        for(int i = 0; i < 8; i++){
            char tmp_pos[3];
            scanf("%s", tmp_pos);
        
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
    
        matrix[pos_y][pos_x] = 'C';
    
        print_matrix(n, m);
        printf("Caso de Teste #%d: %d movimento(s).\n", test_case++, moves);

        free_matrix(n, m);
    }
    
    //free_matrix(n, m);
    return 0;
}