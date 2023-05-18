#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int num1 = mid - left + 1;
    int num2 = right - mid;

    int L[num1], R[num2];

    for (i = 0; i < num1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < num2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < num2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int num;
    printf("Enter the size of the array: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, num - 1);

    printf("Sorted array: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

