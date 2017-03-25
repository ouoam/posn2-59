// thank
// https://www.coursera.org/learn/algorithmic-toolbox/lecture/23LRJ/algorithm

#include <climits>
#include <iostream>


using namespace std;

int tableMax[20][20], tableMin[20][20], n = 0, minf, maxf;

inline int myPlus(int a, int b) { return a + b; }
inline int myMulti(int a, int b) { return a * b; }
inline int myMinus(int a, int b) { return a - b; }

// thank
// http://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c
void find(int i, int j, int k, int (*op)(int, int)) {
	int temp1 = op(tableMax[j][j + k], tableMax[j + k + 1][i + j + 1]);
	int temp2 = op(tableMin[j][j + k], tableMax[j + k + 1][i + j + 1]);
	int temp3 = op(tableMax[j][j + k], tableMin[j + k + 1][i + j + 1]);
	int temp4 = op(tableMin[j][j + k], tableMin[j + k + 1][i + j + 1]);
	minf = min(minf, min(min(temp1, temp2), min(temp3, temp4)));
	maxf = max(maxf, max(max(temp1, temp2), max(temp3, temp4)));
}

int main() {
	char in[50];
	cin >> in;
	while (in[n] != 0) {
		if (n % 2 == 0) {
			tableMax[n / 2][n / 2] = in[n] - '0';
			tableMin[n / 2][n / 2] = in[n] - '0';
		} else {
			tableMax[n / 2 + 1][n / 2] = in[n];
			tableMin[n / 2 + 1][n / 2] = in[n];
		}
		n++;
	}
	n = n / 2 + 1;
	for (int i = 0; i < n; i++) {
		int n1 = n - i;
		for (int j = 0; j < n1; j++) {
			maxf = INT_MIN;
			minf = INT_MAX;
			for (int k = 0; k <= i; k++) {
				switch (tableMax[j + k + 1][j + k]) {
				case '+':
					find(i, j, k, myPlus);
					break;
				case '-':
					find(i, j, k, myMinus);
					break;
				case '*':
					find(i, j, k, myMulti);
					break;
				}
			}
			tableMax[j][i + j + 1] = maxf;
			tableMin[j][i + j + 1] = minf;
		}
	}
	cout << tableMax[0][n - 1];
}