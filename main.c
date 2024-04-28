#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int size) {
    int i = 0, j = 0, k = 0;
    while (i < size/2 && j < size/2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < size/2) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < size/2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        int* left = (int*)malloc((m - l + 1) * sizeof(int));
        int* right = (int*)malloc((r - m) * sizeof(int));
        for (int i = 0; i < m - l + 1; i++) {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < r - m; i++) {
            right[i] = arr[m + 1 + i];
        }
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, left, right, r - l + 1);
        free(left);
        free(right);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
