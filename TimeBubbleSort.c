#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Function ONLY to calculate time */
double bubbleSortTime(int arr[], int n) {
    clock_t start, end;
    start = clock();

    bubbleSort(arr, n);

    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int arr[100], n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double timeTaken = bubbleSortTime(arr, n);

    printf("Sorted array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by Bubble Sort = %f seconds\n", timeTaken);

    return 0;
}
