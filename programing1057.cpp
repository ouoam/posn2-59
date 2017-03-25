#include <stdio.h>
#include <vector>

/*
void print(std::vector<int> node[],int n){
		printf("----START----\n");
		for (int i = 1; i <= n; i++) {
				printf("%d ==>",i);
				for(std::vector<int>::iterator it = node[i].begin() ; it!=node[i].end(); ++it){
						printf(" %d",*it);
				}
				 printf("\n");
		}
		printf("-----END-----\n");
}
*/

bool find(std::vector<int> node[], bool check[], int i) {
	if (check[i] == true)
		return true;
	check[i] = true;
	for (std::vector<int>::iterator it = node[i].begin(); it != node[i].end();
			 ++it) {
		if (find(node, check, *it)) {
			return true;
		}
	}
	return false;
}

main() {
	int n, m, a, b;
	std::vector<int> node[1002];
	bool check[1002];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			node[i].push_back(b);
		}
	}
	//  print(node,n);
	for (int i = 1; i <= n; i++) {
		for (size_t j = 1; j <= n; j++) {
			check[j] = false;
		}
		printf("%s\n", find(node, check, i) == true ? "YES" : "NO");
	}
}
