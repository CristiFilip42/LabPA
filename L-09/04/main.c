#include <stdio.h>

#define MAX 100
#define INF 999999

int coins[MAX];
int currentSol[MAX];
int bestSol[MAX];
int n;
int Suma;
int minCoins = INF;

void saveSolution(int currentCount) {
    minCoins = currentCount;
    for (int i = 0; i < n; i++) {
        bestSol[i] = currentSol[i];
    }
}

void back(int k, int currentSum, int count) {
    if (currentSum > Suma) return;
    if (count >= minCoins) return;

    if (currentSum == Suma) {
        saveSolution(count);
        return;
    }

    if (k == n) return;

    currentSol[k] = 1;
    back(k + 1, currentSum + coins[k], count + 1);

    currentSol[k] = 0;
    back(k + 1, currentSum, count);
}

int main() {
    printf("\n--- Problema Restului (Optimizare) ---\n");

    printf("Number of coins: ");
    scanf("%d", &n);

    printf("Change to be returned: ");
    scanf("%d", &Suma);

    printf("Input coin values:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }

    for(int i=0; i<n; i++) bestSol[i] = 0;

    back(0, 0, 0);

    if (minCoins == INF) {
        printf("Nu exista solutie.\n");
    } else {
        printf("Optimal solution (folosind %d monede):\n", minCoins);
        for(int i=0; i<n; i++) {
            if(bestSol[i] == 1) {
                printf("%d ", coins[i]);
            }
        }
        printf("\n");

        printf("Vector binar: ");
        for(int i=0; i<n; i++) printf("%d ", bestSol[i]);
        printf("\n");
    }

    return 0;
}
