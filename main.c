#include <stdio.h>
#include <stdlib.h>
// including our sort library
#include "sort.h"

int main()
{
    // case 1

    // taking input from the user
    int n;
    printf("Enter size for array : ");
    scanf("%d", &n);
    int arr[n];
    int i;
    printf("Enter numbers to sort : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // using our custom sort function
    sort(arr, n);

    // case 2
    // we already have an array and we need to sort it
    int arr[] = {4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // using our custom sort function
    sort(arr, n);

    return 0;
}