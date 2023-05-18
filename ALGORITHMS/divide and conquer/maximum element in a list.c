#include <stdio.h>

// Function to find the maximum element in an array
int findMax(int arr[], int start, int end) {
   // If there is only one element, return it
   if (start == end) {
      return arr[start];
   }
   // Divide the array into two parts
   int mid = (start + end) / 2;
   // Recursively find the maximum element in each part
   int leftMax = findMax(arr, start, mid);
   int rightMax = findMax(arr, mid + 1, end);
   // Return the maximum of the two elements
   if (leftMax > rightMax) {
      return leftMax;
   } else {
      return rightMax;
   }
}

// Driver function
int main() {
   int n;
   printf("Enter the size of the array: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array:\n");
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   int max = findMax(arr, 0, n - 1);
   printf("The maximum element in the array is %d\n", max);
   return 0;
}
