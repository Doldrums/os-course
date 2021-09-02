#include <stdio.h>
int array[100], n, c, d, swap;

void bubble_sort(){
    for (c = 0 ; c < n - 1; c++){
    for (d = 0 ; d < n - c - 1; d++){
      if (array[d] > array[d+1]) {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
}

int main(){
  printf("Enter number of elements\n");
  scanf("%d", &n);
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
  bubble_sort();
  printf("Sorted array:\n");
  for (c = 0; c < n; c++)
     printf("%d\n", array[c]);
  return 0;
}