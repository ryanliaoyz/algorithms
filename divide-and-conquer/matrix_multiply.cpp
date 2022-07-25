//
// Created by Yunze Liao on 7/23/22.
//

// use g++ -std=c++11 to compile


#include <iostream>
#include <vector>

using namespace std;

void matrix_mult_iter(vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> >& C, int n) {
	for (int i = 0; i < n; i++) { //compute entries in each of n rows
		for (int j = 0; j < n; j++) { // compute n entries in row i
			for (int k = 0; k < n; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j]; // add in another term of A*B
			}
		}
	}
}

void print_matrix(vector<vector<int> > A) {
	for (auto a : A) {
		for (auto i : a) {
			printf("%d ", i);
		}
		cout << '\n';
	}
}

int main() {
    vector<vector<int> > A = {{1,2,1},
    					   {3,1,2},
    					   {0,2,1}};
    vector<vector<int> > B = {{2,1,3},
    					   {5,2,0},
    					   {3,1,2}};
	vector<vector<int> > C = {{0,0,0},
    					   {0,0,0},
    					   {0,0,0}};
    matrix_mult_iter(A, B, C, 3);
    print_matrix(C);
    return 0;
}