#include <stdio.h>

inline int maxNum(int a, int b) { return a > b ? a : b; }

class Tree {
private:
	struct node {
		int val;
		node *left, *right;
		node(int val) {
			this->val = val;
			this->left = NULL;
			this->right = NULL;
		}
	} * root;

	node *treeAdd(node *thisN, int val) {
		if (!thisN)
			return new node(val);

		if (val <= thisN->val) {
			thisN->left = treeAdd(thisN->left, val);
		} else {
			thisN->right = treeAdd(thisN->right, val);
		}
		return thisN;
	}

	void treeIn(node *thisN) {
		if (!thisN)
			return;
		treeIn(thisN->left);
		printf("%d ", thisN->val);
		treeIn(thisN->right);
	}

	void treePre(node *thisN) {
		if (!thisN)
			return;
		printf("%d ", thisN->val);
		treePre(thisN->left);
		treePre(thisN->right);
	}

	void treePost(node *thisN) {
		if (!thisN)
			return;
		treePost(thisN->left);
		treePost(thisN->right);
		printf("%d ", thisN->val);
	}

	int treeSize(node *thisN) {
		if (!thisN)
			return 0;
		return 1 + treeSize(thisN->left) + treeSize(thisN->right);
	}

	int treeDeep(node *thisN) {
		if (!thisN)
			return 0;
		return 1 + maxNum(treeDeep(thisN->left), treeDeep(thisN->right));
	}

	int treeMin(node *thisN) {
		if (!thisN->left)
			return thisN->val;
		treeMin(thisN->left);
	}

	int treeMax(node *thisN) {
		if (!thisN->right)
			return thisN->val;
		treeMax(thisN->right);
	}

	bool treeFind(node *thisN, int val) {
		if (!thisN)
			return false;
		if (thisN->val == val)
			return true;
		if (val <= thisN->val) {
			if (treeFind(thisN->left, val))
				return true;
		} else {
			if (treeFind(thisN->right, val))
				return true;
		}
		return false;
	}

public:
	inline void add(int val) { this->root = treeAdd(this->root, val); }
	inline void inOrder() { treeIn(this->root); }
	inline void preOrder() { treePre(this->root); }
	inline void postOrder() { treePost(this->root); }
	inline int size() { return treeSize(this->root); }
	inline int deep() { return treeDeep(this->root); }
	inline int min() { return treeMin(this->root); }
	inline int max() { return treeMax(this->root); }
	inline bool find(int val) { return treeFind(this->root, val); }
};

int main() {
	int data[] = {8, 6, 1, 2, 7, 3, 4, 9, 0, 5}, n = 10, i;
	Tree a;
	for (i = 0; i < n; i++) {
		a.add(data[i]);
	}
	printf("\nIn   : ");
	a.inOrder();
	printf("\nPre  : ");
	a.preOrder();
	printf("\nPost : ");
	a.postOrder();
	printf("\nSize : %d", a.size());
	printf("\nDeep : %d", a.deep());
	printf("\nMin  : %d", a.min());
	printf("\nMax  : %d", a.max());
	printf("\nFind : %s", a.find(1) == true ? "true" : "false");
	return 0;
}
