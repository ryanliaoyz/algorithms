//
// Created by Yunze Liao on 7/22/22.
//

// keys : satellite data = record

#include <iostream>

void insertion_sort(int A[], int n) {
    int key, j;
    // initialization: when element is indexed 1, the subarray consist of only one sorted element(indexed 0)
    for (int i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        // maintenance: moving A[i-1,2,3...] to the right until find the proper position of A[i]
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
    // termination: i's value exceeds n
}
int main() {
    int test[] = {3, 4, 1, 5, 7, 9 ,2, 10};
    insertion_sort(test, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    return 0;
}