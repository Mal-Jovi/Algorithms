//BUBBLE SORT ALGORITHM
//GOES THROUGH ALL THE TERMS N TIMES, COMPARING EACH TERM PAIRWISE AND SWAPPING THEM ACCORDINGLY, REDUCES THE RANGE BY ONE AFTER EVERY PASS

#include <string.h>
#include <stdio.h>

int data[5] = {1, 3, 5, 4, 2};                   //Global int array

void swap(int x, int y){                            //Swaps x and y

  int tmp = 0;

  tmp = data[x];
  data[x] = data[y];
  data[y] = tmp;
}

int main(int argc, char const *argv[]) {            //Main Function

  int N = (sizeof(data)) / (sizeof(int));           //Element type x size divided by size per element type
  int i = 0;
  int k = 0;

  for(k=0; k<N; k++){                               //Iterates through array N times
    for(i = 0; i<(N - 1 - k); i++){                 //Iterates through elements not already known to be sorted
      if(data[i] > data[i+1]) swap(i, (i+1));       //If the next element is smaller, they current element is swapped with it
    }
  }

  for(k=0; k<N; k++){                               //Prints every element in data
    printf("%d\n", data[k]);
  }

  return 0;
}
