//INSERTION SORT ALGORITHM
//GOAL OF ALGORTIHM IS TO SORT VALUES A PAIR BY COMPARING THE CURRENT VALUE AND THE PAIR BEFORE IT BY STARTING AT THE SECOND ELEMENT FIRST

#include <string.h>
#include <stdio.h>

int data[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};     //Global Int Array

int main(int argc, char const *argv[]) {

  int i = 0;
  int k = 0;
  int kthValue = 0;                                 //The K-th element which dictates the range of values to begin sorting

  int N = (sizeof(data)) / (sizeof(int));           //Size of the Array

  for(i=1; i<N; i++){                               //Iterates through every value in array
    kthValue = data[i];                             //Defines the kth value, used for swapping
    k = i;                                          //Defines the index of the kth value

    while(k>0 && data[k-1] > kthValue){             //Condition for replacing value
      data [k] = data[k-1];                         //Makes the value at index k the larger of the two values
      k--;                                          //Reduces K by 1, since index k is always the highest current value
    }

    data[k] = kthValue;                             //Completes the swap by making the value before index k the smaller value
  }

  return 0;
}
