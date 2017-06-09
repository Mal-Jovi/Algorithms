//SELECTION SORT ALGORITHM
//FINDS THE SMALLEST VALUE AND PUTS AT THE SMALLEST INDEX, AFTER IT PUSHES THE SMALLEST INDEX UP ONE AND REPEATS

#include <string.h> 
#include <stdio.h>

int data[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};     //Global Int Array

void swap(int x, int y){                            //Swaps x and y

  int tmp = 0;

  tmp = data[x];
  data[x] = data[y];
  data[y] = tmp;
}

int main(int argc, char const *argv[]) {            //Main Function

  int N = (sizeof(data)) / (sizeof(int));
  int i = 0;
  int k = 0;

  for(i=0; i<N; i++){                               //Iterates through the array N times

    int min = data[i];
    int minIndex = i;

    for(k=i; k<N; k++){                             //Iterates through the array from the proper starting point
      if(data[k] < min){
        min = data[k];
        minIndex = k;
      }
    }

    if(minIndex != i) swap(i, minIndex);            //Swaps the array
  }

  for(k=0; k<N; k++){                               //Prints all values in the array
    printf("%d\t", data[k]);
  }

  return 0;
}
