#include <queue>
#include <stdio.h>

void print(int matrix[100][100], int n) {
	printf("----START----\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("-----END-----\n");
}

struct position {
	int x, y, i;
};

int main() {
	int matrix[100][100];
	std::queue<position> myqueue;
	position temp, temp2;
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			matrix[i][j] = 0;
		}
	}
	temp.x = x;
	temp.y = y;
	temp.i = 1;
	myqueue.push(temp);
	while (!myqueue.empty()) {
		temp2 = myqueue.front();
		if (!(temp2.x > n || temp2.y > n || temp2.x < 1 || temp2.y < 1) &&
				matrix[temp2.x][temp2.y] == 0) {
			matrix[temp2.x][temp2.y] = temp2.i;

			temp.i = temp2.i + 1;

			temp.x = temp2.x - 1;
			temp.y = temp2.y;
			myqueue.push(temp);

			temp.x = temp2.x + 1;
			temp.y = temp2.y;
			myqueue.push(temp);

			temp.x = temp2.x;
			temp.y = temp2.y - 1;
			myqueue.push(temp);

			temp.x = temp2.x;
			temp.y = temp2.y + 1;
			myqueue.push(temp);
		}
		myqueue.pop();
	}
	print(matrix, n);
	return 0;
}
