#include <iostream>
#include <arm_neon.h>

const int m = 3;
const int k = 8;
const int n = 3;


void multiply(float arr1[m][k], float arr2[k][n], float res[m][n]) {

	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < n; j++) {
			res[i][j] = 0;
			for (size_t v = 0; v < k; v++) {
				res[i][j] += arr1[i][v] * arr2[v][j];
			}
		}
	}

}

int main() {

	float arr1[m][k] = {
		{ 1,  2,  3,  4,  5,  6,  7,  8},
		{ 9, 10, 11, 12, 13, 14, 15, 16},
		{17, 18, 19, 20, 21, 22, 23, 24}
	};

	float arr2[k][n] = {
		{1, 2, 3},
		{2, 2, 1},
		{3, 3, 1},
		{4, 1, 2},
		{5, 1, 2},
		{6, 1, 2},
		{7, 3, 1},
		{8, 4, 5}
	};

	float res[m][n];

	multiply(arr1, arr2, res);

	for (size_t i = 0; i < m; i++) {
		for (size_t p = 0; p < n; p++) {
			std::cout << res[i][p] << " ";
		}
		std::cout << "\n";
	}

}