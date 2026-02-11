#include <stdio.h>

int linearSearch(int a[], int n,  int val) {

    for(int i=0; i<n; i++) {
        if (a[i] == val)
        {
            return i;
        } 
    }
    return -1;

}

int main() {
    int a[1000];
    int n, val;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }   

    printf("Enter the value to search: ");
    scanf("%d", &val);

    int result = linearSearch(a, n, val);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
}