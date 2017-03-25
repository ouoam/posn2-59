#include <iostream>
using namespace std;

int main() {
	int value;
	cin >> value;
	cout << value / 10 + value % 10 / 5 + value % 5;
}