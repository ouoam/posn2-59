#include <stdio.h>

struct listnode {
	int dest;
	bool mark;
	listnode *next;
	listnode(listnode *next, int dest, bool mark = false) {
		this->dest = dest;
		this->mark = mark;
		this->next = next;
	}
};

void addlink(listnode *graph[], int scr, int dest, bool mark = false) {
	graph[scr] = new listnode(graph[scr], dest, mark);
	graph[dest] = new listnode(graph[dest], scr, mark); // undirect
}

void printlist(listnode *thisN, bool showmark = false) {
	if (!thisN)
		return;
	if (showmark)
		printf("%d,%d ", thisN->dest, thisN->mark);
	else
		printf("%d ", thisN->dest);
	printlist(thisN->next);
}

void printgraph(listnode *graph[], int n, bool showmark = false) {
	for (int i = 0; i < n; i++) {
		printf("%d => ", i);
		printlist(graph[i], showmark);
		printf("\n");
	}
}

void clearNodeMask(listnode *thisN) {
	if (thisN == NULL)
		return;
	thisN->mark = false;
	clearNodeMask(thisN->next);
}

void clearMask(listnode *graph[], int n) {
	for (int i = 0; i < n; i++) {
		clearNodeMask(graph[i]);
	}
}

void travel(listnode *graph[], listnode *thisN) {
	if (thisN == NULL)
		return;
	if (thisN->mark == true)
		return;
	thisN->mark = true;
	travel(graph, graph[thisN->dest]);
	travel(graph, thisN->next);
}

int countGroup(listnode *graph[], int n) {
	int a, i;
	for (i = a = 0; i < n; i++) {
		if (graph[i] == 0) {
			a++;
			continue;
		}
		if (graph[i]->mark == 1)
			continue;
		travel(graph, graph[i]);
		a++;
	}
	return a;
}

bool check(listnode *graph[], listnode *thisN, int dest) {
	if (thisN == NULL)
		return false;
	if (thisN->mark == true)
		return false;
	thisN->mark = true;
	if (thisN->dest == dest)
		return true;
	if (check(graph, graph[thisN->dest], dest))
		return true;
	if (check(graph, thisN->next, dest))
		return true;
	return false;
}

int main() {
	listnode *graph[10];
	int i, n, m, a, b, scr, dest;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		graph[i] = NULL;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		addlink(graph, a, b);
	}
	// scanf("%d %d", &scr,&dest);
	printgraph(graph, n);
	clearMask(graph, n);
	printf("\nCount Group %d", countGroup(graph, n));
	// clearMask(graph,n);
	// printf("\nHave path %s",check(graph,graph[scr],dest)==true?"true":"false");
}
