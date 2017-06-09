#include <stdio.h>

int data[4] = {2, 1, 4, 3};                     //Data Array
int tmp[4];                                     //Tmp Array

int n = sizeof(data)/sizeof(int);               //Size of Array

void mergesort(left, mid, right){

int tmp = left;
  if(n=2){
    if(right<left){
      tmp = data[left];
      data[left] = data[right];
      data[right] = tmp;
      return;
    }else{
      return;
    }
  }

}

int main(int argc, char const *argv[]) {

  int mid = n/2;                                  //Mid Index
  int left = 0;                                   //Left Index
  int right = mid + 1;                            //Right Index

  int i = 0;

  printf("LEFT: %d\n", left);
  printf("MID: %d\n", mid);
  printf("RIGHT: %d\n", right);
  printf("\nOriginal Array: ");
  for(i=0; i<n; i++){
    printf("%d", data[i]);
  }

  mergesort(left, mid, right);

  printf("\nSorted Array: ");

  for(i=0; i<n; i++){
    printf("%d ", data[i]);
  }

  return 0;
}
