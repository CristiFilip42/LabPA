#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int st[MAX];
int n;
int solNr = 0;

void tiparire() {
    solNr++;
    printf("Solution %d:\n", solNr);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i] == j) printf("R");
            else printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

int valid(int k) {
    for (int i = 1; i < k; i++) {
        if (st[k] == st[i] || abs(st[k] - st[i]) == abs(k - i)) {
            return 0;
        }
    }
    return 1;
}

void back(int k) {
    for (int col = 1; col <= n; col++) {
        st[k] = col;

        if (valid(k)) {
            if (k == n) {
                tiparire();
            } else {
                back(k + 1);
            }
        }
    }
}

int main() {
    printf("Problema Reginelor ");
    printf("Dimensiune tabla (n): ");
    scanf("%d", &n);

    back(1);
    return 0;
}
