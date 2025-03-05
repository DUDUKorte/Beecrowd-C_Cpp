#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados da lista =============================

typedef struct {
    int length;
    char *word;
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
        } else if (strcmp(a->info.word, b->info.word) > 0) {
            *tail = b;
            b = b->next;
        } else {
            *tail = a;
            a = a->next;
            TNode *temp = b;
            b = b->next;
            free(temp->info.word);
            free(temp);
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

void mergeSort(TList *list) {
    TNode *head = list->first;
    TNode *a;
    TNode *b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    list->first = merge(a, b);
}

// Funções auxiliares =========================================

void MYstrlwr(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    TList list;
    initList(&list);

    char word[201];
    char last = 0;

    while (1) {
        if (last == EOF) {
            break;
        }

        if (scanf(" %[A-Za-z]", word) == 1) {
            last = getchar();
        } else {
            last = getchar();
            continue;
        }

        // Converter pra lowercase
        MYstrlwr(word);

        TData x;
        x.length = strlen(word);
        x.word = (char *)malloc((x.length + 1) * sizeof(char));
        if (!x.word) {
            return 1;
        }

        strcpy(x.word, word);

        insertList(&list, x);
    }

    mergeSort(&list);
    printList(&list);
    free_list(&list);

    return 0;
}