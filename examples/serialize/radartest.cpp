
#include <iostream>
#include <vector>

#include "common/DataStream.h"
#include "dis7/OneByteChunk.h"
#include "dis7/RadarReflectivity.h"

int main () {
  DIS::DataStream ds(DIS::Endian::BIG);
  DIS::DataStream out(DIS::Endian::BIG);
  std::vector<DIS::OneByteChunk> chunks;

  DIS::RadarReflectivity tmp_data;
  DIS::RadarReflectivity tmp_data_2;
  tmp_data.setX(1.0);
  tmp_data.setY(5.0);
  tmp_data.setZ(13.0);
  tmp_data.setReflectivity(35.0);

  std::cout << tmp_data.getX() << " " << tmp_data.getY() << " " << tmp_data.getZ() << " " << tmp_data.getReflectivity() << std::endl;
  
  tmp_data.marshal(ds);
//   ds << int32; // Serialze int into DataStream
  while (ds.GetReadPos() < ds.size()) {
    DIS::OneByteChunk tmp;
    tmp.unmarshal(ds); // de-serialize Datastream into the OneByteChunk
    chunks.push_back(tmp);
  } 
  tmp_data.setX(2.0);
  tmp_data.setY(6.0);
  tmp_data.setZ(14.0);
  tmp_data.setReflectivity(42.0);
//   chunks.unmarshal(out);

  std::cout << "chunks (4 bytes): ";
  for (DIS::OneByteChunk chunk : chunks) {
    // Note '*' to dereference from char*
    std::cout << *(chunk.getOtherParameters());
    out << *(chunk.getOtherParameters());
  }
  std::cout << std::endl;

  tmp_data_2.unmarshal(out);
  std::cout << tmp_data.getX() << " " << tmp_data.getY() << " " << tmp_data.getZ() << " " << tmp_data.getReflectivity() << std::endl;
  std::cout << tmp_data_2.getX() << " " << tmp_data_2.getY() << " " << tmp_data_2.getZ() << " " << tmp_data_2.getReflectivity() << std::endl;
  
  return 0;
}