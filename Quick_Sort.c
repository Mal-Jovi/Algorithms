//QUICK SORT ALGORITHM
//Uses Lomuto Partiion Scheme

#include <stdio.h>
#include <string.h>

int nums[10] = {2,3,5,7,9,1,4,8,10,6};
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////Swap Function
/////////////////////////////////////////////////////////////
void swap(int x, int y){

  int tmp = 0;

  tmp = nums[x];

  nums[x] = nums[y];
  nums[y] = tmp;
}
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////Partiion Function
/////////////////////////////////////////////////////////////
int partition(int start, int stop){

  int e = 0;
  int count = 1;
  int j = 0;
  int i = start - 1;
  int pivot = nums[stop];

  for(j=start; j<stop+1; j++){
    printf("Cycle: %d\n", count);
    for(e=0; e<10; e++){
      printf("%d\t", nums[e]);
    }

    if (nums[j] <= pivot) {
      i = i+1;
      if(i != j){
        swap(j, i);
      }
    }

    printf("\nJ : %d\n", j);
    printf("I : %d\n", i);
    printf("\n=================================================\n");
    count++;
  }

  return i;
}
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////Quick Sort Function
/////////////////////////////////////////////////////////////
void quickSort(int start, int stop){

  if (start<stop) {
    int pivot = partition(start,stop);
    quickSort(start, pivot-1);
    quickSort(pivot+1, stop);
  }

  return;
}
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////Main Function
/////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) {

  int i =0;
  int N = sizeof(nums)/sizeof(int);

  quickSort(0, N-1);

  for(i=0; i<10; i++){
    printf("%d\t", nums[i]);
  }
  return 0;
}
