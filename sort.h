#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Swap Function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort (assuming n is given -> 20 numbers unsorted)
void bubble_sort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // program

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Bubble Sort): %f seconds \n", time_spend);
}

// Selection Sort

void selection_sort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // program

    int i, j;
    int min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Selection Sort): %f seconds \n", time_spend);
}

// Insertion Sort

void insertion_sort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // program

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Insertion Sort): %f seconds \n", time_spend);
}

// Merge Sort

void merge(int arr[], int s, int m, int e)
{
    int temp[e - s + 1];

    int i = s, j = m + 1, k = 0;

    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = arr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        k += 1;
        i += 1;
    }

    while (j <= e)
    {
        temp[k] = arr[j];
        k += 1;
        j += 1;
    }

    for (i = s; i <= e; i += 1)
    {
        arr[i] = temp[i - s];
    }
}

void merge_sort(int arr[], int s, int e)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // main program

    if (s < e)
    {
        int m = (s + e) / 2;
        merge_sort(arr, s, m);
        merge_sort(arr, m + 1, e);
        merge(arr, s, m, e);
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Merge Sort): %f seconds \n", time_spend);
}

// Quick Sort

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = (low - 1);

    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // main program
    if (low < high)
    {
        int par = partition(arr, low, high);
        quick_sort(arr, low, par - 1);
        quick_sort(arr, par + 1, high);
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Quick Sort): %f seconds \n", time_spend);
}

// Heap Sort

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {

        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // main program
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Heap Sort): %f seconds \n", time_spend);
}

// Standard Library

// Compare -> Determines which element has greater value
// Arguments : m and n are pointers to elements that need to be compared.
// Returns 0 if same, -1 if a < b and +1 if a > b
int compare(const void *m, const void *n)
{
    int *a, *b;
    a = (int *)m;
    b = (int *)n;
    if (*a < *b)
    {
        return -1;
    }
    if (*a == *b)
    {
        return 0;
    }
    if (*a > *b)
    {
        return 1;
    }

    return 0;
}

void stdlib_qsort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // program

    qsort(arr, n, sizeof(int), &compare);

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Standard C qSort): %f seconds \n", time_spend);
}

// Cyclic Sort -> works only for n continous numbers (for example -> 5 4 3 2 1)
// Otherwise -> gives seg fault.
void cyclic_sort(int arr[], int n)
{
    double time_spend = 0.0;

    // timer begin
    clock_t begin = clock();

    // program
    int i = 0;
    while (i < n)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {
            swap(&arr[i], &arr[correct]);
        }
        else
        {
            i++;
        }
    }

    // timer end
    clock_t end = clock();

    // calculation
    time_spend += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed Time (Cyclic Sort): %f seconds \n", time_spend);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sort(int arr[], int size)
{
    printf("Array before sorting : ");
    printArray(arr, size);
    int choice;

    printf("\n 1. Bubble Sort \n");
    printf("\n 2. Selection Sort \n");
    printf("\n 3. Insertion Sort \n");
    printf("\n 4. Merge Sort \n");
    printf("\n 5. Quick Sort \n");
    printf("\n 6. Heap Sort \n");
    printf("\n 7. Standard qsort built in C \n");
    printf("\n 8. Cyclic sort \n");
    printf("\n 9. Exit \n");
    printf("\n Select Sorting Option : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubble_sort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) -> O(n^2) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? Yes \n");
        break;

    case 2:
        selection_sort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) ->  O(nlogn) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? Yes \n");
        break;

    case 3:
        insertion_sort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) -> O(n^2) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? Yes \n");
        break;
    case 4:
        merge_sort(arr, 0, size - 1);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) ->  O(nlogn) \n");
        printf("Space Complexity (Worst Case) -> O(n) \n");
        printf("Stable? Yes \n");
        break;
    case 5:
        quick_sort(arr, 0, size - 1);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) -> O(n^2) \n");
        printf("Space Complexity (Worst Case) -> O(logn) \n");
        printf("Stable? No \n");
        break;
    case 6:
        heap_sort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) -> O(logn) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? No \n");
        break;
    case 7:
        stdlib_qsort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) ->  O(nlogn) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? Yes \n");
        break;
    case 8:
        // works only for n continous numbers
        cyclic_sort(arr, size);
        printf("Array after Sorting : ");
        printArray(arr, size);
        printf("Time Complexity (Worst Case) ->  O(n^2) \n");
        printf("Space Complexity (Worst Case) -> O(1) \n");
        printf("Stable? No, works only for continous numbers \n");
        break;

    case 9:
        printf("Thank you for using our sorting library! \n");
        exit(0);
        break;

    default:
        printf("Enter valid choice! \n");
        break;
    }

    return 0;
}
#endif
