#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m;

// Estrutura de dados da lista =============================

typedef struct {
    int value;
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
        printf("%d\n", current->info.value);
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
        int modA = a->info.value % m;
        int modB = b->info.value % m;

        if (modA < modB) {
            *tail = a;
            a = a->next;
        } else if (modA > modB) {
            *tail = b;
            b = b->next;
        } else {
            if ((a->info.value % 2 != 0) && (b->info.value % 2 == 0)) {
                *tail = a;
                a = a->next;
            } else if ((a->info.value % 2 == 0) && (b->info.value % 2 != 0)) {
                *tail = b;
                b = b->next;
            } else if ((a->info.value % 2 != 0) && (b->info.value % 2 != 0)) {
                if (a->info.value > b->info.value) {
                    *tail = a;
                    a = a->next;
                } else {
                    *tail = b;
                    b = b->next;
                }
            } else {
                if (a->info.value < b->info.value) {
                    *tail = a;
                    a = a->next;
                } else {
                    *tail = b;
                    b = b->next;
                }
            }
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

    int n;

    while(scanf("%d %d", &n,&m) && n + m != 0){
        //if(pass == 0){ pass = 1; } else{ printf("\n"); }
        
        for(int i = 0; i < n; i++) {
            int currentInt;
            scanf("%d", &currentInt);

            TData x;
            x.value = currentInt;

            insertList(&list, x);
        }

        mergeSort(&list.first);
        printf("%d %d\n", n, m);
        printList(&list);
        free_list(&list);
        initList(&list);
    }
    
    printf("0 0\n");

    return 0;
}