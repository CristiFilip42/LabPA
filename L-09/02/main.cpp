#include <stdio.h>

#define MAX 100

int st[MAX];
int n, k;
int totalSolutii = 0;

void tiparire() {
    totalSolutii++;
    for (int i = 1; i <= k; i++) {
        printf("%d ", st[i]);
    }
    printf("\n");
}

int valid(int p) {
    if (p > 1 && st[p] <= st[p-1]) return 0;
    return 1;
}

void back(int p) {
    int start = (p == 1) ? 1 : st[p-1] + 1;

    for (int val = start; val <= n; val++) {
        st[p] = val;

        if (valid(p)) {
            if (p == k) {
                tiparire();
            } else {
                back(p + 1);
            }
        }
    }
}

int main() {
    printf("Generare Combinari");
    printf("n = "); scanf("%d", &n);
    printf("k = "); scanf("%d", &k);

    back(1);
    printf("Total solutii: %d\n", totalSolutii);
    return 0;
}
