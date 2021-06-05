#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, search, new_size,i;

    printf("size of array: \n");
	scanf(" %d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    for ( i = 0; i < n; i++)
    {
        printf("Enter the arrays:arr[%d]\n", i);
		scanf(" %d", (arr+i));
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Enter the element you want to search\n");
    scanf("%d", &search);
    for ( i = 0; i < n; ++i)
    {
        if (arr[i] == search)
        {
            break;
        }
    }
    if (i==n)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("element found on index %d \n", i);
    }

    printf("Enter the number of  elements you want to increase:\n");
    scanf("%d", &new_size);
    arr = realloc(arr, new_size * sizeof(int));
    for ( i = 0; i <new_size; i++)
    {
        arr[i] = i + 1;
    }
    for ( i = 0; i <new_size; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}