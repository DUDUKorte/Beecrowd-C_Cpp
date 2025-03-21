#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 61

typedef struct {
    int left;
    int right;
} BootCount;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        BootCount boots[MAX_SIZE] = {0};

        for (int i = 0; i < N; i++) {
            int M;
            char L;
            scanf("%d %c", &M, &L);

            if (L == 'E') {
                boots[M].left++;
            } else if (L == 'D') {
                boots[M].right++;
            }
        }

        int totalPairs = 0;
        for (int i = 30; i <= 60; i++) {
            totalPairs += (boots[i].left < boots[i].right) ? boots[i].left : boots[i].right;
        }

        printf("%d\n", totalPairs);
    }

    return 0;
}