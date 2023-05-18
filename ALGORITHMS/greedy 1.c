#include <stdio.h>

void findSmallest(int digit, int sum)
{

	if (sum == 0)
	{
    if (digit == 1)
    {
            printf("Smallest number is 0");
    }
    else
    {
    printf("Not possible");
    }
	}


	if (sum > 9 * digit)
	{
		printf("Not possible");
		return;
	}


	int res[digit];

	sum = sum - 1;

	for (int i = digit - 1; i > 0; i--)
	{

		if (sum > 9)
		{
			res[i] = 9;
			sum = sum-9;
		}
		else
		{
			res[i] = sum;
			sum = 0;
		}
	}

	res[0] = sum + 1;

	printf("Smallest number is ");
	for (int i = 0; i <digit; i++)
		printf("%d", res[i]);
}

int main()
{
	int sum,digit;
	printf("Enter the value of digit sum from a number\n");
	scanf("%d",&sum);
	printf("Enter the number of digits in the number\n");
	scanf("%d",&digit);
	findSmallest(digit,sum);
	return 0;
}

