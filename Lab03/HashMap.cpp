#include "HashMap.h"

int HashMap::Hashfunction(int integer, int _bucketsize) {

  int index = 0;
  index = integer % _bucketsize;
  return index;
}

void HashMap::Add(int integer) {
  if (NeedReHash(numberOfElement, bucketSize)) {
    // TAG: this is Rehash function for both
    std::cout << "=======================\n";
    std::cout << "Rehash applied\n";
    int newBucket = Resize(bucketSize);
    ReHashQuadratic(newBucket);
    ReHashDouble(newBucket);
    SetSize(newBucket);
  }
  QuadraticProbing(integer);
  DoubleHash(integer);
  numberOfElement++;
}

bool HashMap::Find(int integer) {
  bool isFind = false;
  for (int i = 0; i < bucketSize; i++) {
    if (array_Quadratic[i].GetID() == integer) {
      isFind = true;
    }
    if (array_Double[i].GetID() == integer) {
      isFind = true;
    }
  }
  return isFind;
}

void HashMap::Delete(int id) {
  for (int i = 0; i < bucketSize; i++) {
    if (array_Quadratic[i].GetID() == id) {
      array_Quadratic[i].SetID(-1);
    }
    if (array_Double[i].GetID() == id) {
      array_Double[i].SetID(-1);
    }
  }
  numberOfElement--;
}

void HashMap::QuadraticProbing(int integer) {

  int index = Hashfunction(integer, bucketSize);
  if (array_Quadratic[index].GetID() == -1) {
    array_Quadratic[index].SetID(integer);
  } else {
    // TODO: collision
    for (int i = 1;; i++) {
      if (index + i * i < bucketSize) {
        if (array_Quadratic[index + i * i].GetID() == -1) {
          array_Quadratic[index + i * i].SetID(integer);
          break;
        }
      } else {
        int temp = (index + i * i) % bucketSize;
        if (array_Quadratic[temp].GetID() == -1) {
          array_Quadratic[temp].SetID(integer);
          break;
        }
      }
    }
  }
}

void HashMap::DoubleHash(int integer) {
  int R = 5;
  int index = Hashfunction(integer, bucketSize);
  if (array_Double[index].GetID() == -1) {
    array_Double[index].SetID(integer);
  } else {
    // TODO: collision
    for (int i = 1;; i++) {
      int newIndex = (index + (i * (R - (integer % R)))) % bucketSize;
      if (array_Double[newIndex].GetID() == -1) {
        array_Double[newIndex].SetID(integer);
        break;
      }
    }
  }
}

void HashMap::PrintTable() {
  PrintQuadratic();
  PrintDouble();
}

void HashMap::PrintDouble() {
  std::cout << "==========================\n";
  std::cout << "Dobule Probing:\n";
  for (int i = 0; i < bucketSize; i++) {
    std::cout << "Bucket " << i << ": ";
    if (array_Double[i].GetID() != -1) {
      std::cout << array_Double[i].GetID();
    }
    std::cout << "\n";
  }
}

void HashMap::PrintQuadratic() {
  std::cout << "==========================\n";
  std::cout << "Quadratic Probing:\n";
  for (int i = 0; i < bucketSize; i++) {
    std::cout << "Bucket " << i << ": ";
    if (array_Quadratic[i].GetID() != -1) {
      std::cout << array_Quadratic[i].GetID();
    }
    std::cout << "\n";
  }
}

bool HashMap::NeedReHash(int numberOfElement, int numberOfBucket) {
  double loadFactor = (double)numberOfElement / (double)numberOfBucket;
  if (loadFactor > 0.5)
    return true;
  return false;
}

int HashMap::GetSize() { return bucketSize; }

void HashMap::SetSize(int _size) { bucketSize = _size; }

bool HashMap::isPrime(int _number) {
  if (_number == 1)
    return false;
  if (_number == 2)
    return true;
  for (int i = 2; i < sqrt(_number) + 1; i++) {
    if ((_number % i) == 0)
      return false;
  }
  return true;
}

HashMap::HashMap() {
  array_Quadratic = new Node[bucketSize]();
  for (int i = 0; i < bucketSize; i++) {
    array_Quadratic[i].SetID(-1);
  }
  array_Double = new Node[bucketSize]();
  for (int i = 0; i < bucketSize; i++) {
    array_Double[i].SetID(-1);
  }
}

HashMap::~HashMap() {
  delete[] array_Double;
  delete[] array_Quadratic;
}

int HashMap::Resize(int _size) {
  _size = _size * 2 + 1;
  while (true) {
    if (isPrime(_size)) {
      break;
    } else {
      _size = _size + 1;
    }
  }
  return _size;
}

void HashMap::ReHashQuadratic(int _newBucket) {
  Node *temp = new Node[_newBucket]();
  for (int i = 0; i < bucketSize; i++) {
    int temp01 = array_Quadratic[i].GetID();
    int newIndex = Hashfunction(temp01, _newBucket);
    if (temp01 != -1) {

      if (temp[newIndex].GetID() == -1) {
        temp[newIndex].SetID(temp01);
      } else {
        for (int j = 1;; j++) {
          if (temp[newIndex + j * j].GetID() == -1) {
            temp[newIndex + j * j].SetID(temp01);
            break;
          }
        }
      }
    }
  }
  Node *temp01 = array_Quadratic;
  array_Quadratic = temp;
  temp = nullptr;
  delete[] temp01;
}

void HashMap::ReHashDouble(int _newBucket) {
  int R = 5;
  Node *temp = new Node[_newBucket]();
  for (int i = 0; i < bucketSize; i++) {
    int temp01 = array_Double[i].GetID();
    if (temp01 != -1) {
      int newIndex = Hashfunction(temp01, _newBucket);
      if (temp[newIndex].GetID() == -1)
        temp[newIndex].SetID(temp01);
      else {
        for (int j = 1;; j++) {
          int Index = (newIndex + (j * (R - (temp01 % R)))) % _newBucket;
          if (temp[Index].GetID() == -1) {
            temp[Index].SetID(temp01);
            break;
          }
        }
      }
    }
  }
  Node *temp01 = array_Double;
  array_Double = temp;
  temp = nullptr;
  delete[] temp01;
}