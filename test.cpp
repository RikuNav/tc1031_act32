#include <iostream>
#include "priority_queue.h"
#include "heap.h"

int main(int argc, char* argv[]) {
  //int numbers[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55};
  Priority_queue<int> heap(20);

  /*
  for (int i = 0; i < 12; i++) {
    heap.add(numbers[i]);
    std::cout << heap.toString() << "\n";
  }
  */

  heap.push(10);
  std::cout << heap.toString() << "\n";
  heap.push(1);
  std::cout << heap.toString() << "\n";
  heap.push(5);
  std::cout << heap.toString() << "\n";

  std::cout << "remove = " << heap.pop() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.pop() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.pop() << "\n";
  std::cout << heap.toString() << "\n";
  return 0;
}