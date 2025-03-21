#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados da lista =============================

typedef struct {
    int length;
    char *word;
    char ShirtSize;
    char *name;
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
        printf("%s %c %s\n", current->info.word, current->info.ShirtSize, current->info.name);
        current = current->next;
    }
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

// Função de ordenação =========================================

void splitList(TNode *head, TNode **front, TNode **back) {
    TNode *slow = head;
    TNode *fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

TNode *merge(TNode *a, TNode *b) {
    TNode *result = NULL;
    TNode **tail = &result;

    while (a != NULL && b != NULL) {
        if (strcmp(a->info.word, b->info.word) < 0) {
            *tail = a;
            a = a->next;
        } else if(strcmp(a->info.word, b->info.word) == 0) {
            // Verica o tamanho da camisa
            if((a->info.ShirtSize - b->info.ShirtSize) > 0){
                *tail = a;
                a = a->next;
            }else if(a->info.ShirtSize == b->info.ShirtSize){
                // Verifica pelo nome
                if(strcmp(a->info.name, b->info.name) < 0){
                    *tail = a;
                    a = a->next;
                }else{
                    *tail = b;
                    b = b->next;
                }
            }else{
                *tail = b;
                b = b->next;
            }
        }else{
            *tail = b;
            b = b->next;
        }
        tail = &((*tail)->next);
    }

    if (a != NULL) {
        *tail = a;
    } else {
        *tail = b;
    }

    return result;
}

void mergeSort(TNode **headRef) {
    TNode *head = *headRef;
    TNode *a;
    TNode *b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

int main() {
    TList list;
    initList(&list);

    char word[201];
    char shirtSize;
    int n, pass = 0;

    while(scanf("%d", &n) && n != 0){
        if(pass == 0){ pass = 1; } else{ printf("\n"); }
        
        for(int i = 0; i < n; i++) {
            // Read Name
            scanf(" %[^\n]", word);

            TData x;
            x.length = strlen(word);
            x.name = (char *)malloc((x.length + 1) * sizeof(char));
            if (!x.name) {
                return 1;
            }

            strcpy(x.name, word);


            scanf("%s %c", word, &shirtSize);
            x.ShirtSize = shirtSize;
            
            x.length = strlen(word);
            x.word = (char *)malloc((x.length + 1) * sizeof(char));
            if(!x.word){
                return 1;
            }
            
            strcpy(x.word, word);

            insertList(&list, x);
        }

        mergeSort(&list.first);
        printList(&list);
        free_list(&list);
        initList(&list);
    }

    return 0;
}