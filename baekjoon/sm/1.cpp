#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2) {
    printf("%d", 7);
  } else {
    printf("%d", 1);
  }

  for (int i=0; i<(n/2) -1; i++) {
    printf("%d", 1);
  }

  return 0;
}