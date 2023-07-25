#include<stdio.h>


void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}



int main()
{
    FILE *fptr;
    FILE *fsorted;
    int num;
    int arr[1000];
    int x;

    fptr = fopen ("input.txt","r");
    fsorted = fopen ("sankalp.txt","w");


    printf("Enter how many numbers to be sorted\n");
    scanf("%d",&x);
    int i=0;
    for(i=0;i<x;i++)
    {
        fscanf(fptr,"%d",&arr[i]);
    }
    fclose(fptr);

    bubbleSort(arr,x);

    fprintf(fsorted,"Sorted array:\n");
    for(i=0;i<x;i++)
    {
        fprintf(fsorted,"%d\t",arr[i]);
    }
    printf("Sorted array has been written to file\n");

    fclose(fsorted);
    return 0;

}
