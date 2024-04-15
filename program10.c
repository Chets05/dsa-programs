

#include <stdio.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low + 1; 
    int j = high; 

    while (i <= j) {
        
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        
        while (arr[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    arr[low] = arr[j];
    arr[j] = pivot;
    return j; 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
