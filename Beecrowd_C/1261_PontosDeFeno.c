#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados da lista =============================

typedef struct {
    int length;
    char *word;
    long value;
} TData;

typedef struct TNode {
    TData info;
    struct TNode *next;
} TNode;

typedef struct {
    TNode *first;
    TNode *last;
    int size;
} TList;

void initList(TList *list) {
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
}

void printList(TList *list) {
    TNode *current = list->first;
    while (current != NULL) {
        char *printString = current->info.word;
        printf("%s", printString);
        if (current->next) {
            printf("\n");
        }
        current = current->next;
    }
    printf("\n");
}

int insertList(TList *list, TData x) {
    TNode *current = (TNode *)malloc(sizeof(TNode));
    if (!current) {
        return 1;
    }

    current->info = x;
    current->next = NULL;

    if (list->last == NULL) {
        list->first = list->last = current;
    } else {
        list->last->next = current;
        list->last = current;
    }

    list->size++;
    return 0;
}

void free_list(TList *list){
    TNode *current = list->first;
    while (current != NULL) {
        TNode *temp = current;
        current = current->next;
        free(temp->info.word);
        free(temp);
    }
}

int palavraInLista(TList *list, char *palavra){
    for(TNode *current = list->first; current != NULL; current = current->next){
        TData currentData = current->info;
        if(strcmp(currentData.word, palavra) == 0){
            return currentData.value;
        }
    }
    
    return 0;
}

int main() {
    TList list;
    initList(&list);

    char last = 0;
    int maior_palavra = 0, menor_palavra = 17;
    char word[201];
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < m; i++){
        long value;
        
        scanf(" %[^ ]", word);
        getchar();

        TData x;
        x.length = strlen(word);
        x.word = (char *)malloc((x.length + 1) * sizeof(char));
        if (!x.word) {
            return 1;
        }

        strcpy(x.word, word);

        //insertList(&list, x);

        // Verificar maior e menor palavra
        if(x.length < menor_palavra){
            menor_palavra = x.length;
        }else if(x.length > maior_palavra){
            maior_palavra = x.length;
        }
    }

    int salario = 0;

    for(int i = 0; i < n; i++) {
        char *word;

        while(1){
            if(last == '.'){ break; }
    
            if (scanf(" %[^ ]", word) == 1) {
                last = getchar();
            } else{
                last = getchar();
                continue;
            }

            // Verifica se a palavra esta entre as registradas
            if(strlen(word) > maior_palavra || strlen(word) < menor_palavra){ continue; }

            // Compara com as palavras salvas
            salario += palavraInLista(&list, word);
        }
        printf("%d\n", salario);
        salario = 0;
    }

    free_list(&list);

    return 0;
}