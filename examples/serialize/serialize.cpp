
#include <iostream>
#include <vector>

#include "common/DataStream.h"
#include "dis7/OneByteChunk.h"
// using namespace DIS;


// using namespace std;

int main () {
  DIS::DataStream ds(DIS::Endian::BIG);
  std::vector<DIS::OneByteChunk> chunks;

  int int32 = 0x48692100; // 0x48 0x69 0x21 0x00 ("Hi!") 
  
  ds << int32;
  while (ds.GetReadPos() < ds.size()) {
    DIS::OneByteChunk tmp;
    tmp.unmarshal(ds);
    chunks.push_back(tmp);
  } 
  
  std::cout << "chunks (4 bytes): ";
  for (DIS::OneByteChunk chunk : chunks) {
    // Note '*' to dereference from char*
    std::cout << *(chunk.getOtherParameters());
  }
  std::cout << std::endl;
  
  return 0;
}