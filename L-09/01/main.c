#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int st[MAX];
int n;

void tiparire() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", st[i]);
    }
    printf("\n");
}

int valid(int k) {
    for (int i = 1; i < k; i++) {
        if (st[i] == st[k]) {
            return 0;
        }
    }
    return 1;
}

void back(int k) {
    for (int val = 1; val <= n; val++) {
        st[k] = val;

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
    printf("Generare Permutari ");
    printf("Introduceti n: ");
    scanf("%d", &n);

    back(1);
    return 0;
}
