#include <stdio.h>

int binarySearchInsert(int arr[], int n, int key) {
    int st = 0;
    int dr = n - 1;

    while (st <= dr) {
        int mid = st + (dr - st) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            st = mid + 1;
        } else {
            dr = mid - 1;
        }
    }
    return st;
}

int main() {
    printf("--- Ex 1: Cautare Binara Modificata ---\n");
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int cheiDeCautat[] = {23, 10, 1, 100};

    for (int i = 0; i < 4; i++) {
        int key = cheiDeCautat[i];
        int poz = binarySearchInsert(arr, n, key);

        if (poz < n && arr[poz] == key) {
            printf("Cheia %d gasita la indexul: %d\n", key, poz);
        } else {
            printf("Cheia %d NU a fost gasita. Ar trebui inserata la indexul: %d\n", key, poz);
        }
    }

    return 0;
}
