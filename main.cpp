#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector> 
#include <algorithm>
using namespace std;

bool isSorted(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false; // Array is not sorted
        }
    }
    return true; // Array is sorted
}

int* generateRandomArray(int arraySize) {
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

void quickSort(int* array, int arraySize, int pivot) {
  if (!isSorted(array, arraySize)) {
    int pivValue = array[pivot];

    std::list<int> leftList;
    std::list<int> rightList;

    // Take each element and compare it to the pivot
    for (int i = 0; i < arraySize; i++) {
        if (array[i] < pivValue) {
          leftList.push_back(array[i]);
        }
        else if (array[i] > pivValue) {
          rightList.push_back(array[i]);
        }
    }
    leftList.push_back(pivValue);

    // Combine elements into a vector
    std::vector<int> combinedArray;
    combinedArray.reserve(leftList.size() + rightList.size());  // Pre-allocate memory

    // Use std::copy to copy elements from both lists
    std::copy(leftList.begin(), leftList.end(), std::back_inserter(combinedArray));
    std::copy(rightList.begin(), rightList.end(), std::back_inserter(combinedArray));

    // Apply list values into array
    for (int i = 0; i < arraySize; i++) {
      array[i] = combinedArray[i];
    }
    quickSort(array, arraySize, (rand() % arraySize));
  };

}

int main() {
  int arrSize = 100;
  int* myArray = generateRandomArray(arrSize);

  // Print the random array
  std::cout << "Random Array: ";
  for (int i = 0; i < arrSize; i++) {
      std::cout << myArray[i] << " ";
  }
  std::cout << std::endl;
  
  int pivot = rand() % arrSize;
  quickSort(myArray, arrSize, pivot);

  // Print the random array
  std::cout << "Sorted Array: ";
  for (int i = 0; i < arrSize; i++) {
      std::cout << myArray[i] << " ";
  }
  
  delete[] myArray; // Free the dynamically allocated memory
  return 0;
  
}
