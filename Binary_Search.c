#include <string.h>
#include <stdio.h>

  int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(int argc, char const *argv[]) {

  int N = sizeof(data) / sizeof(int);
  int k = 0;

  scanf("%d", &k);

  printf("%d\n", k);

  return 0;
}
