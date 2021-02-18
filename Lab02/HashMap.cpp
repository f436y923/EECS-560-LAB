#include "HashMap.h"
#include "LinkedList.h"
#include <cstddef>

int HashMap::Hashfunction(std::string firstname, int _bucketsize) {
  int ASCII = 0;
  int ascii = 0;
  int index = 0;
  int length = firstname.length();
  const char *read = firstname.c_str();
  for (int i = 0; i < length; i++) {
    ASCII = read[i];
    ascii += ASCII;
  }

  index = ascii % _bucketsize;
  return index;
}

void HashMap::AddStudent(std::string name, int id) {
  int index = Hashfunction(name);
  array[index].Insert(name, id);
}

bool HashMap::FindStudent(std::string name) {
  int index = Hashfunction(name);
  if (array[index].Find(name)) {
    return true;
  } else {
    return false;
  }
}

void HashMap::RemoveStudent(std::string name, int id) {
  int index = Hashfunction(name);
  if (FindStudent(name)) {
    if (array[index].Remove(name, id))
      std::cout << "Record has been removed from the hash table.\n";
    else {
      std::cout << "No Records found!\n";
    }
  } else {
    std::cout << "No Records found!\n";
  }
}

void HashMap::PrintStudentList() {

  for (int i = 0; i < FIXBUCKET; i++) {
    std::cout << "Bucket " << i << ": ";
    array[i].Print();
    std::cout << std::endl;
  }
}

HashMap::HashMap() { array = new LinkedList[FIXBUCKET]; }

HashMap::~HashMap() { delete[] array; }
