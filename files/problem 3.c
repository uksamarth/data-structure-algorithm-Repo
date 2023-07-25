#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high-1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        int pi = i+1;

        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main() {
    int x;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &x);

    FILE *input_file, *log_file;
    input_file = fopen("input.txt", "r");
    log_file = fopen("log.txt", "a");

    if (input_file == NULL) {
        printf("Error opening input file.");
        exit(1);
    }

    if (log_file == NULL) {
        printf("Error opening log file.");
        exit(1);
    }

    int numbers[x];
    for (int i = 0; i < x; i++) {
        fscanf(input_file, "%d", &numbers[i]);
    }

    fclose(input_file);

    // Sort the array and compute time required
    clock_t start, end;
    double time_taken;
    start = clock();

    // Sort the array using the specified sorting technique
    // Uncomment the desired technique
    // insertion_sort(numbers, x);
    quick_sort(numbers, 0, x-1);

    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Write the sorting technique, value of x, and time taken to log file
    fprintf(log_file, "Sorting technique: Quick Sort\n");
    fprintf(log_file, "Value of x: %d\n", x);
    fprintf(log_file, "Time taken: %f seconds\n\n", time_taken);
    fclose(log_file);

    printf("Time taken to sort %d elements using Quick Sort: %f seconds.\n", x, time_taken);
    return 0;
}

