#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int arr[100];
    int i;
    int number;
    scanf("%d",&number);
    for (i = 0; i < number; i++) {
        arr[i] = i;
    }
    printf("Factorials:\n");
    for (i = 0; i < number; i++) {
        printf("%d! = %d\n", arr[i], factorial(arr[i]));
    }
    return 0;
}

