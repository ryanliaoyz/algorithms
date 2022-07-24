//
// Created by Yunze Liao on 7/23/22.
//
// 
#include <iostream>

void merge(int A[], int p, int q, int r) {
	int n_l = q - p + 1; // length of A[p:q]
	int n_r = r - q; // length of A[q+1:r]
	int *L = new int[n_l],
		*R = new int[n_r];

    int i, j;
	for (i = 0; i < n_l; i++) // copy A[p:q] to L
		L[i] = A[p + i];
	for (j = 0; j < n_r; j++) // copy A[q+1:r] to R
		R[j] = A[q + j + 1];

    i = 0; // index of remaining in L
	j = 0; // index of remaining in R
	int k = p; // index of A to fill

    // as long as each of the arrays contains an unmerged element, copy the smaller one to A[p:r] at index k
    while (i < n_l && j < n_r) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i+=1;
		} else {
			A[k] = R[j];
			j+=1;
		}
		k+=1;
	}

    // copy either L or R's remainder to the end of A[p:r]
	while (i < n_l) {
		A[k] = L[i];
		i+=1;
		k+=1;
	}
	while (j < n_r) {
		A[k] = R[j];
		j+=1;
		k+=1;
	}
	
	delete[] L;
	delete[] R;
}
/**
divide: A[p:r] divided to A[p:q], A[q+1:r], D(n) = O(1) since only computing the middle point
conquer: sorting two subarrays recursively, subproblem of size n/2, 2T(n/2)
combine: merge subarrays back, C(n) = O(n)
**/
void merge_sort(int A[], int p, int r) {
	if (p >= r) // base case: only 1 element is always sorted
		return;
	int q = p + (r - p) / 2; // midpoint of A[p:r]
	merge_sort(A, p, q);
	merge_sort(A, q + 1, r);
	merge(A, p, q, r);
	
}

int main() {
    int test[] = {3, 4, 1, 5, 7, 9 ,2, 10, 25, 2};
    merge_sort(test, 0, sizeof(test)/ sizeof(test[0])-1);
    for (int i : test) {
        printf("%d ", i);
    }
    return 0;
}