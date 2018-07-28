#ifndef HEAP_H

#include <vector>
#include <exception>
#include <string>

struct EmptyHeapException : public std::exception {
  std::string m_sDesc;

  EmptyHeapException(std::string desc) {
    this->m_sDesc = desc;
  }

  const char * what () const throw () {
    return (std::string("The heap is empty: ") + m_sDesc).c_str();
  }
};

class MaxHeap {
private:
  std::vector<float> m_zfData;

  int getLeftChildIndex(int p_iParentIndex);
  int getLeftChild(int p_iParentIndex);
  int getRightChildIndex(int p_iParentIndex);
  int getRightChild(int p_iParentIndex);
  int getParentIndex(int p_iChildIndex);
  int hasLeftChild(int p_iParentIndex);
  int hasRightChild(int p_iParentIndex);
  bool hasParent(int p_iChildIndex);
  float parent(int p_iChildIndex);
  void swapValues(int p_iIndexA, int p_iIndexB);
  void heapifyUp();
  void heapifyDown(int index);

public:
  void push(float p_fVal);
  float pop();
  int size();
  void printArray();
};

#endif
