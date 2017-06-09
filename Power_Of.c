#include <string.h>
#include <stdio.h>

int powerOf(int base, int power){

  if(power == 0) return 1;

  if(power>1) return (base * powerOf(base, power-1));

}

int main(int argc, char const *argv[]) {

  printf("%d\n", powerOf(7,2));

  return 0;
}
