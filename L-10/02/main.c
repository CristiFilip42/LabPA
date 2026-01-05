#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activitate;
int compareActivities(const void *a, const void *b) {
    Activitate *act1 = (Activitate *)a;
    Activitate *act2 = (Activitate *)b;
    return (act1->finish - act2->finish);
}

void selectieActivitati(Activitate arr[], int n) {
    qsort(arr, n, sizeof(Activitate), compareActivities);

    printf("Activitatile selectate sunt:\n");

    int i = 0;
    printf("Activitatea %d [%d, %d)\n", arr[i].id, arr[i].start, arr[i].finish);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("Activitatea %d [%d, %d)\n", arr[j].id, arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    printf("Selectia Activitatilor");

    Activitate activitati[] = {
        {1, 1, 4}, {2, 3, 5}, {3, 0, 6}, {4, 5, 7},
        {5, 3, 9}, {6, 5, 9}, {7, 6, 10}, {8, 8, 11},
        {9, 8, 12}, {10, 2, 14}, {11, 12, 16}
    };
    int n = sizeof(activitati) / sizeof(activitati[0]);

    selectieActivitati(activitati, n);

    return 0;
}
