#include<stdio.h>

struct link {
  int a, b;
} way[2002];

main() {
  int t, n, m, k, a, b, cou;
  bool city[1002];
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d", &n, &m, &k);
    for (int j = 0; j < n; j++) {
      city[j] = false;
    }
    for (int j = 0; j < m; j++) {
      scanf("%d %d", &a, &b);
      way[j].a = a;
      way[j].b = b;
    }
    for (int j = 0; j < k; j++) {
      scanf("%d", &a);
      city[a - 1] = true;
      for (int k = 0; k < m; k++) {
        if (way[k].a == a) {
          city[way[k].b - 1] = true;
        } else if (way[k].b == a) {
          city[way[k].a - 1] = true;
        }
      }
    }
    cou = 0;
    for (int j = 0; j < n; j++) {
      if (city[j]) {
        cou++;
      }
    }
    printf("%d\n",cou);
  }
}
