#include <queue>
#include <stdio.h>

#define GO_U 1 // 0001 UP
#define GO_R 2 // 0010 RIGHT
#define GO_D 4 // 0100 DOWN
#define GO_L 8 // 1000 LEFT

struct queue {
	int a, b, i, f;
};

int main() {
	int a, b;
	char temp[3], send[102][102];
	std::queue<queue> Q;
	queue Qtemp, Qtemp2;
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			scanf("%s", temp);
			send[i][j] = temp[0];
		}
	}
	for (int i = a; i > 0; i--) {
		send[i][0] = 'N';
	}
	for (int j = b; j > 0; j--) {
		send[0][j] = 'N';
	}
	for (int i = a; i > 0; i--) {
		for (int j = b; j > 0; j--) {
			int temp = 0;
			if (send[i][j] == 'B' || send[i][j] == 'D') {
				temp = temp | GO_D;
			}
			if (send[i][j] == 'B' || send[i][j] == 'R') {
				temp = temp | GO_R;
			}
			if (send[i - 1][j] == 'B' || send[i - 1][j] == 'D') {
				temp = temp | GO_U;
			}
			if (send[i][j - 1] == 'B' || send[i][j - 1] == 'R') {
				temp = temp | GO_L;
			}
			send[i][j] = temp;
		}
	}
	Qtemp.a = 1;
	Qtemp.b = 1;
	Qtemp.i = 1;
	Qtemp.f = 0;
	Q.push(Qtemp);
	while (!Q.empty()) {
		Qtemp2 = Q.front();
		Q.pop();
		if (Qtemp2.a < 1 || Qtemp2.b < 1 || Qtemp2.a > a || Qtemp2.b > b) {
			continue;
		}
		if (send[Qtemp2.a][Qtemp2.b] == 16) {
			break;
		}
		if (send[Qtemp2.a][Qtemp2.b] & GO_U && Qtemp2.f != GO_D) {
			Qtemp.a = Qtemp2.a - 1;
			Qtemp.b = Qtemp2.b;
			Qtemp.i = Qtemp2.i + 1;
			Qtemp.f = GO_U;
			Q.push(Qtemp);
		}
		if (send[Qtemp2.a][Qtemp2.b] & GO_R && Qtemp2.f != GO_L) {
			Qtemp.a = Qtemp2.a;
			Qtemp.b = Qtemp2.b + 1;
			Qtemp.i = Qtemp2.i + 1;
			Qtemp.f = GO_R;
			Q.push(Qtemp);
		}
		if (send[Qtemp2.a][Qtemp2.b] & GO_D && Qtemp2.f != GO_U) {
			Qtemp.a = Qtemp2.a + 1;
			Qtemp.b = Qtemp2.b;
			Qtemp.i = Qtemp2.i + 1;
			Qtemp.f = GO_D;
			Q.push(Qtemp);
		}
		if (send[Qtemp2.a][Qtemp2.b] & GO_L && Qtemp2.f != GO_R) {
			Qtemp.a = Qtemp2.a;
			Qtemp.b = Qtemp2.b - 1;
			Qtemp.i = Qtemp2.i + 1;
			Qtemp.f = GO_L;
			Q.push(Qtemp);
		}
		send[Qtemp2.a][Qtemp2.b] = 16;
	}
	printf("%d\n", Qtemp2.i);
	printf("%d %d\n", Qtemp2.a, Qtemp2.b);
}
