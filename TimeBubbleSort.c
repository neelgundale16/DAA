#include <stdio.h>
#include <windows.h>

struct timeval {
    long tv_sec;
    long tv_usec;
};

int gettimeofday(struct timeval* tp, void* tzp) {
    FILETIME ft;
    unsigned __int64 tmpres = 0;
    const unsigned __int64 EPOCH = 116444736000000000ULL;

    GetSystemTimeAsFileTime(&ft);

    tmpres |= ft.dwHighDateTime;
    tmpres <<= 32;
    tmpres |= ft.dwLowDateTime;

    tmpres -= EPOCH;
    tmpres /= 10;

    tp->tv_sec = (long)(tmpres / 1000000UL);
    tp->tv_usec = (long)(tmpres % 1000000UL);

    return 0;
}

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

int main() {
    int arr[100], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct timeval tv;
    long t1, t2;

    gettimeofday(&tv, NULL);
    t1 = tv.tv_usec;

    bubbleSort(arr, n);

    gettimeofday(&tv, NULL);
    t2 = tv.tv_usec;

    double timeTaken = (t2 - t1) / 1000000.0;

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by Bubble Sort = %f seconds\n", timeTaken);

    return 0;
}
