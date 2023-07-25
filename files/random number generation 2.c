// C program for generating a
// random number in a given range.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates and prints 'count' random
// numbers in range [lower, upper].
void printRandoms(FILE *fptr, int lower, int upper,
							int count)
{
	int i;
	fptr = fopen("samarth.txt","w");
	for (i = 0; i < count; i++) {
		int num = (rand() % (upper - lower + 1)) + lower;
		printf("%d \t", num);
		fprintf(fptr,"%d\t",num);
	}
	fclose(fptr);
}

// Driver code
int main()
{
	int lower , upper, count = 1;

	FILE *fptr;
	printf("Enter the value of lower\n");
	scanf("%d",&lower);
    printf("Enter the value of upper\n");
	scanf("%d",&upper);
	// Use current time as
	printf("Enter the value of N\n");
	scanf("%d",&count);
	// seed for random generator
	//srand(time(0));


	printRandoms(fptr,lower, upper, count);

	return 0;
}

