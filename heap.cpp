#include "heap.h"
#include <iostream>

using namespace std;

int MaxHeap::getLeftChildIndex(int p_iParentIndex) {
  return 2 * p_iParentIndex + 1;
}

int MaxHeap::getLeftChild(int p_iParentIndex) {
  return this->m_zfData[this->getLeftChildIndex(p_iParentIndex)];
}

int MaxHeap::hasLeftChild(int p_iParentIndex) {
  return this->getLeftChildIndex(p_iParentIndex) < this->m_zfData.size();
}

int MaxHeap::getRightChildIndex(int p_iParentIndex) {
  return 2 * p_iParentIndex + 2;
}

int MaxHeap::hasRightChild(int p_iParentIndex) {
  return this->getRightChildIndex(p_iParentIndex) < this->m_zfData.size();
}

int MaxHeap::getRightChild(int p_iParentIndex) {
  return this->m_zfData[this->getRightChildIndex(p_iParentIndex)];
}

int MaxHeap::getParentIndex(int p_iChildIndex) {
  return (p_iChildIndex - 1) / 2;
}

bool MaxHeap::hasParent(int p_iChildIndex) {
  return this->getParentIndex(p_iChildIndex) >= 0;
}

float MaxHeap::parent(int p_iChildIndex) {
  return this->m_zfData[this->getParentIndex(p_iChildIndex)];
}

int MaxHeap::size() {
  return m_zfData.size();
}

void MaxHeap::swapValues(int p_iIndexA, int p_iIndexB) {
  float temp = this->m_zfData[p_iIndexA];
  this->m_zfData[p_iIndexA] = this->m_zfData[p_iIndexB];
  this->m_zfData[p_iIndexB] = temp;
}

void MaxHeap::heapifyUp() {
  int index = this->m_zfData.size() - 1;
  while (this->hasParent(index) && this->parent(index) < this->m_zfData[index]) {
    this->swapValues(index, this->getParentIndex(index));
    index = this->getParentIndex(index);
  }
}

void MaxHeap::heapifyDown(int index) {
  int swapChildIndex = -1;
  if (this->hasLeftChild(index) && this->getLeftChild(index) > this->m_zfData[index]) {
    swapChildIndex = this->getLeftChildIndex(index);
  }
  if (this->hasRightChild(index) && this->getRightChild(index) > this->m_zfData[index]) {
    if (this->getRightChild(index) > this->m_zfData[swapChildIndex]) {
      swapChildIndex = this->getRightChildIndex(index);
    }
  }
  if (swapChildIndex != -1) {
    this->swapValues(index, swapChildIndex);
    this->heapifyDown(swapChildIndex);
  }
}

void MaxHeap::push(float p_fVal) {
  this->m_zfData.push_back(p_fVal);
  this->heapifyUp();
}

float MaxHeap::pop() {
  if (this->m_zfData.size() == 0) throw EmptyHeapException("pop");
  float value = this->m_zfData[0];
  this->swapValues(0, this->m_zfData.size() - 1);
  this->m_zfData.pop_back();
  this->heapifyDown(0);
  return value;
}

void MaxHeap::printArray() {
  cout << "array of size " << this->size() << ": ";
  for (auto it = m_zfData.begin(); it < m_zfData.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}
