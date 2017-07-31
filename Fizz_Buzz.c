#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int i = 0;

  for(i=0; i<101; i++){


    int P1 = i%3;
    int P2 = i%5;
    int P3 = P2 + P1;

    if (P3 == 0) {
      printf("(%d)FIZZBUZZ\n", i);
    } else if(P1 == 0){
      printf("(%d)FIZZ\n", i);
    } else if (P2 == 0) {
      printf("(%d)BUZZ\n", i);
    }else{
      printf("(%d)NADA\n", i);
    }
  }
  return 0;
}
