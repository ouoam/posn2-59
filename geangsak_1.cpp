#include <climits>
#include <iostream>
#include <stdio.h>


using namespace std;

int tableMax[20][20], tableMin[20][20], n = 0;

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

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
	for (int k = 0; k < n; k++) {
		int n1 = n - 1 - k;
		for (int i = 0; i < n1; i++) {
			int maxn = INT_MIN;
			int minn = INT_MAX;
			int temp;
			for (int j = 0; j <= k; j++) {
				switch (tableMax[i + 1 + j][i + j]) {
					case '+':
						temp = tableMax[i][i + j] + tableMax[i + 1 + j][i + 1 + k];
						break;
					case '-':
						temp = tableMax[i][i + j] - tableMax[i + 1 + j][i + 1 + k];
						break;
					case '*':
						temp = tableMax[i][i + j] * tableMax[i + 1 + j][i + 1 + k];
						break;
				}
				minn = min(minn, temp);
				maxn = max(maxn, temp);
				switch (tableMax[i + 1 + j][i + j]) {
					case '+':
						temp = tableMin[i][i + j] + tableMax[i + 1 + j][i + 1 + k];
						break;
					case '-':
						temp = tableMin[i][i + j] - tableMax[i + 1 + j][i + 1 + k];
						break;
					case '*':
						temp = tableMin[i][i + j] * tableMax[i + 1 + j][i + 1 + k];
						break;
				}
				minn = min(minn, temp);
				maxn = max(maxn, temp);
				switch (tableMax[i + 1 + j][i + j]) {
					case '+':
						temp = tableMax[i][i + j] + tableMin[i + 1 + j][i + 1 + k];
						break;
					case '-':
						temp = tableMax[i][i + j] - tableMin[i + 1 + j][i + 1 + k];
						break;
					case '*':
						temp = tableMax[i][i + j] * tableMin[i + 1 + j][i + 1 + k];
						break;
				}
				minn = min(minn, temp);
				maxn = max(maxn, temp);
				switch (tableMax[i + 1 + j][i + j]) {
					case '+':
						temp = tableMin[i][i + j] + tableMin[i + 1 + j][i + 1 + k];
						break;
					case '-':
						temp = tableMin[i][i + j] - tableMin[i + 1 + j][i + 1 + k];
						break;
					case '*':
						temp = tableMin[i][i + j] * tableMin[i + 1 + j][i + 1 + k];
						break;
				}
				minn = min(minn, temp);
				maxn = max(maxn, temp);
			}
			tableMax[i][i + 1 + k] = maxn;
			tableMin[i][i + 1 + k] = minn;
		}
	}
	// cout << "Min : " << tableMin[0][n - 1] << endl;
	// cout << "Max : " << tableMax[0][n - 1] << endl;
	cout << tableMax[0][n - 1];
}