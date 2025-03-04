#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (numbers[mid] == value)
      return mid;
    else if (numbers[mid] < value)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1; // If the value is not found
}

void printArray(int numbers[], int sz) {
  int i;
  printf("Number array: ");
  for (i = 0; i < sz; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

int main(void) {
  int i, numInputs;
  int average;
  int value;
  int index;
  int *numArray = NULL;
  int countOfNums;
  FILE *inFile = fopen("input.txt", "r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &countOfNums);
    numArray = (int *)malloc(countOfNums * sizeof(int));
    average = 0;
    for (i = 0; i < countOfNums; i++) {
      fscanf(inFile, " %d", &value);
      numArray[i] = value;
      average += numArray[i];
    }

    printArray(numArray, countOfNums);
    value = average / countOfNums;
    index = search(numArray, 0, countOfNums - 1, value);
    if (index >= 0) {
      printf("Item %d exists in the number array at index %d!\n", value, index);
    } else {
      printf("-1!\n");
    }

    free(numArray);
  }

  fclose(inFile);

  return 0;
}
