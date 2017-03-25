#include <iostream>
using namespace std;

int te(int x, int y) {
    return x + y;
}

int test(int a, int b, int (*func)(int,int)) {
    return func(a,b);
}

int main() {
    int v;
    cin >> v;
    cout << test(v, 10, te);
}