#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Lista duplamente encadeada
typedef struct {
    double x, y;
} point;

typedef struct TLine {
    point start_point; // ponto do inicio da linha
    point end_point; // ponto do fim da linha
    struct TLine *prev_line; // linha anterior
    struct TLine *next_line; // linha seguinte
} TLine;

typedef struct TList {
    TLine *head;
    TLine *tail;
    int length;
} TList;

void init_list(TList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

int insert_right(TList *list, point start_pointi, point end_pointi) {
    TLine *novo_no = (TLine*)malloc(sizeof(TLine));
    if(!novo_no) return 1;

    novo_no->start_point = start_pointi;
    novo_no->end_point = end_pointi;
    novo_no->next_line = NULL;
    novo_no->prev_line = list->tail;

    if(list->tail == NULL) {
        list->head = list->tail = novo_no;
    }else{
        list->tail->next_line = novo_no;
        list->tail = novo_no;
    }

    list->length++;
    return 0;
}

void liberar_lista(TList *list) {
    TLine *temp = list->head;
    while (temp) {
        list->head = list->head->next_line;
        free(temp);
        temp = list->head;
    }
}

// Função para calcular a distância entre uma aleta p->q e um ponto r
double PTSeg(point p, point q, point r) {

    point A = {r.x - q.x, r.y - q.y}; // Vetor A ==> q(x,y) --> r(x,y)
    point B = {r.x - p.x, r.y - p.y}; // Vetor B ==> p(x,y) --> r(x,y)
    point C = {q.x - p.x, q.y - p.y}; // Vetor C ==> p(x,y) --> q(x,y)

    double a_norm = pow(A.x, 2.0) + pow(A.y, 2.0);
    double b_norm = pow(B.x, 2.0) + pow(B.y, 2.0);
    double c_norm = pow(C.x, 2.0) + pow(C.y, 2.0);
    double prod_vet = (A.x * B.y - A.y * B.x);

    if (b_norm >= a_norm + c_norm) { return sqrt(a_norm); } // distância entre o final da aleta e o ponto
    else if (a_norm >= b_norm + c_norm) { return sqrt(b_norm); } // distância entre o inicio da aleta e o ponto
    else { return fabs(prod_vet) / sqrt(c_norm); }
}

int main() {
    double L, H;
    int N;

    while (scanf("%d", &N) != EOF) {
        scanf("%lf %lf", &L, &H);

        TList aletaslist;
        init_list(&aletaslist);

        double min_dist = DBL_MAX; // Menor espaço entre as aletas

        for (int i = 0; i < N; i++) {
            double Yi, Xf, Yf;
            scanf("%lf %lf %lf", &Yi, &Xf, &Yf);

            point start_point, end_point;
            if (i % 2 == 0) { // Se i for par --> start_point = (0, yi) e end_point = (xf, yf)
                start_point = (point){0, Yi};
                end_point = (point){Xf, Yf};
            } else { // Se i for ímpar --> start_point = (L, yi) e end_point = (xf, yf)
                start_point = (point){L, Yi};
                end_point = (point){Xf, Yf};
            }

            // Salvar aleta na lista
            insert_right(&aletaslist, start_point, end_point);
        }

        TLine *atual = aletaslist.head;
        TLine *next_aleta = aletaslist.head->next_line;

        // Roda todas as aletas da lista
        while (next_aleta != NULL) {
            point atual_ePoint = atual->end_point; // pf
            point next_sPoint = next_aleta->start_point; // pa
            point next_ePoint = next_aleta->end_point; // pb

            // Cacula a distância entre o ponto final da aleta atual e o segmento da próxima aleta
            double a = PTSeg(next_sPoint, next_ePoint, atual_ePoint);
            double b;

            if (atual->start_point.x == 0) {
                b = L - atual_ePoint.x;
            }else{
                b = atual_ePoint.x;
            }

            // Atualizar o menor espaço entre as aletas
            if ((a < b) && (a < min_dist)) {
                min_dist = a;
            } else if (b < min_dist) {
                min_dist = b;
            }

            // Atualizar a aleta atual e a próxima aleta
            atual = next_aleta;
            next_aleta = next_aleta->next_line;
        }

        
        point atual_ePoint = atual->end_point;
        double b;

        if (atual->start_point.x == 0){ 
            b = L - atual_ePoint.x;
        }else{
            b = atual_ePoint.x;
        }

        if (b < min_dist) { min_dist = b; }

        printf("%.2lf\n", min_dist);

        // Liberar memória da lista
        liberar_lista(&aletaslist);
    }

    return 0;
}