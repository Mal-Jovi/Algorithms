#include <stdio.h>

int main(int argc, char const *argv[]) {

  int data[4] = {2, 1, 4, 3};                     //Data Array
  int tmp[4];                                     //Tmp Array

  int n = sizeof(data)/sizeof(int);               //Size of Array

  int mid = n/2;                                  //Mid Index
  int left = 0;                                   //Left Index
  int right = mid + 1;                            //Right Index

  int i = 0;

  printf("LEFT: %d\n", left);
  printf("MID: %d\n", mid);
  printf("RIGHT: %d\n", right);

  for(i=0; i<n; i++){
    printf("%d", data[i]);
  }

  while(tmpRight <= right){

  }

  return 0;
}
