#include "heap.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  MaxHeap oHeap;
  oHeap.push(1);
  oHeap.push(2);
  oHeap.push(3);
  oHeap.push(10);
  oHeap.push(-1);
  oHeap.push(25);
  oHeap.push(20);
  oHeap.push(23);

  cout << "initial start" << endl;
  oHeap.printArray();
  cout << "initial end" << endl;
  cout << endl;

  while (oHeap.size() > 0) {
    cout << oHeap.pop() << endl;
  }

  return 0;
}
