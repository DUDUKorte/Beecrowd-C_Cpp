#include <stdio.h>
#include <stdlib.h>

int **matrix;

enum Direction {SUL = 0, OESTE = 1, NORTE = 2, LESTE = 3};
enum Direction  current_direction = 0;

char direction_char[] = {'S', 'O', 'N', 'L'};

int pos_x = 0, pos_y = 0;

// seta pra beixo - 0
// seta pra esquerda - 1
// seta pra cima - 2
// seta pra direita - 3

int points = 0;

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

void move_robo(int n, int m)
{
    matrix[pos_y][pos_x] = '.';

    switch (current_direction)
    {
    case SUL:
        // verificar se é possível mover
        if(pos_y + 1 >= n){
            // Não pode mover
        }else if(matrix[pos_y + 1][pos_x] == '#'){
            // Não pode mover
        }else{
            pos_y++;
        }

        break;
    case OESTE:
        // verificar se é possível mover
        if(pos_x - 1 < 0){
            // Não pode mover
        }else if(matrix[pos_y][pos_x - 1] == '#'){
            // Não pode mover
        }else{
            pos_x--;
        }

        break;
    case NORTE:
        // verificar se é possível mover
        if(pos_y - 1 < 0){
            // Não pode mover
        }else if(matrix[pos_y - 1][pos_x] == '#'){
            // Não pode mover
        }else{
            pos_y--;
        }

        break;
    case LESTE:
        // verificar se é possível mover
        if(pos_x + 1 >= m){
            // Não pode mover
        }else if(matrix[pos_y][pos_x + 1] == '#'){
            // Não pode mover
        }else{
            pos_x++;
        }

        break;
    }

    // Verificar pontuação
    if(matrix[pos_y][pos_x] == '*'){
        points++;
    }

    matrix[pos_y][pos_x] = direction_char[current_direction];
}

void print_matrix(int n, int m){
    printf("===================================\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    printf("===================================\n");
}

int main()
{

    int n, m, s;
    
    while(scanf("%d %d %d", &n, &m, &s) && n + m + s != 0){

        points = 0;

        allocate_matrix(n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char in_cell = getchar();

                if (in_cell == '\n')
                {
                    j--;
                    continue;
                }

                matrix[i][j] = in_cell;

                if (in_cell != '*' && in_cell != '.' && in_cell != '#')
                {
                    pos_y = i;
                    pos_x = j;

                    switch (in_cell)
                    {
                    case 'N':
                        current_direction = NORTE;
                        break;
                    case 'O':
                        current_direction = OESTE;
                        break;
                    case 'L':
                        current_direction = LESTE;
                        break;
                    case 'S':
                        current_direction = SUL;
                        break;
                    }
                }
            }
        }

        //print_matrix(n, m);

        for (int i = 0; i < s; i++)
        {
            char in_command = getchar();
            if (in_command == '\n')
            {
                i--;
                continue;
            }

            if (in_command == 'E')
            {
                current_direction = (current_direction - 1 + 4) % 4;
                matrix[pos_y][pos_x] = direction_char[current_direction];
                //print_matrix(n, m);
            }
            else if (in_command == 'D')
            {
                current_direction = (current_direction + 1) % 4;
                matrix[pos_y][pos_x] = direction_char[current_direction];
                //print_matrix(n, m);
            }
            else if (in_command == 'F')
            {
                move_robo(n, m);
                //print_matrix(n, m);
            }
        }

        printf("%d\n", points);
    }

    free_matrix(n, m);

    return 0;
}
