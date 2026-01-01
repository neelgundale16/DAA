#include <stdio.h>

int main () {

    int i, j, temp, n;
    int arr[20];

    printf("Enter number of elements: ");
    scanf("%d" , &n);

    printf("Enter the elements : ");
    for (i=0; i<n; i++) {
        scanf("%d" , &arr[i]);
    }

    // Bubble Sort Algorithm
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {

            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array is : ");
    for(i=0; i<n; i++){
        printf("%d " , arr[i]);
        
    }
}