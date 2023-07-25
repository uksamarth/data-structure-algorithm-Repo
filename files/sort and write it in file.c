/**
 * C program to input numbers from file and write even,
 * odd and prime numbers to separate file.
 */

#include <stdio.h>
#include <stdlib.h>
sorted_array(int arr[]);

int main()
{
    /* File pointer to hold reference to different files */
    FILE * fPtrIn,
         * fptrsort;

    int num, success;
    int arr[1000];

    /*
     * Open all files to perform read/write.
     */
    fPtrIn   = fopen("input.txt", "r");
    fptrsort = fopen("output,txt","w");


    /* fopen() return NULL if unable to open file in given mode. */
    if(fPtrIn == NULL || fptrsort == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }


    /* File open success message */
    printf("File opened successfully. Reading integers from file. \n\n");

    // Read an integer and store read status in success.
    while (fscanf(fPtrIn, "%d", &num) != -1)
    {
        int i=0;
        scanf("%d",&arr[i]);
        i++;
        /*sorted array(int num);
        if (isPrime(num))
            fprintf(fptrsort, "%d\n", num);*/

    }


    sorted_array(int arr[]);

    /* Done with all files, hence close all. */
    fclose(fPtrIn);
    fclose(fptrsort);

    printf("Data written to files successfully.");


    return 0;
}

void sorted array(int arr[],int i)
{
    int i,j,n,num;
    int a;
    for (i = 0; i < n; ++i)
        {

            for (j = i + 1; j < n; ++j)
            {

                if (arr[i] > arr[j])
                {

                    a =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;

                }

            }

        }

}
