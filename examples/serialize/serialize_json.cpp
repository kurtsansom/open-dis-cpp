
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

#include "common/DataStream.h"
#include "dis7/OneByteChunk.h"
#include "dis7/RadarReflectivity.h"
// #include "dis7/Vector3Float.h"

namespace DIS {
    void to_json(nlohmann::json& j, const RadarReflectivity& p) {
        j = nlohmann::json{{"X", p.getX()},
                           {"Y", p.getY()},
                           {"Z", p.getZ()},
                           {"dBZ", p.getReflectivity()}
                          };
    }

    void from_json(const nlohmann::json& j, RadarReflectivity& p) {
        p.setX(j["X"].get<float>());
        p.setY(j["Y"].get<float>());
        p.setZ(j["Z"].get<float>());
        p.setReflectivity(j["dBZ"].get<float>());
    }
} // namespace DIS


int main () {

    DIS::RadarReflectivity tmp_data;
    tmp_data.setX(1.005);
    tmp_data.setY(5.0);
    tmp_data.setZ(13.0);
    tmp_data.setReflectivity(35.0);

    std::cout << tmp_data.getX() << " "
              << tmp_data.getY() << " "
              << tmp_data.getZ() << " " 
              << tmp_data.getReflectivity() << std::endl;

    // convert to JSON: copy each value into the JSON object
    nlohmann::json j;
    j["X"] = tmp_data.getX();
    j["Y"] = tmp_data.getY();
    j["Z"] = tmp_data.getZ();
    j["dBZ"] = tmp_data.getReflectivity();

    // convert from JSON: copy each value from the JSON object
    DIS::RadarReflectivity tmp_data2;
    tmp_data2.setX(j["X"].get<float>());
    tmp_data2.setY(j["Y"].get<float>());
    tmp_data2.setZ(j["Z"].get<float>());
    tmp_data2.setReflectivity(j["dBZ"].get<float>());

    std::cout << tmp_data2.getX() << " "
              << tmp_data2.getY() << " "
              << tmp_data2.getZ() << " " 
              << tmp_data2.getReflectivity() << std::endl;

    nlohmann::json j_test;

    // conversion: RadarReflectivity -> json
    j_test = tmp_data2;

    std::cout << j_test << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> RadarReflectivity
    auto tmp_data3 = j_test.get<DIS::RadarReflectivity>();

    // that's it
    assert(tmp_data2 == tmp_data3);

    DIS::DataStream ds(DIS::Endian::BIG);

    // try serializing to vector of chunks
    std::vector<DIS::OneByteChunk> chunks;

    // int int32 = 0x48692100; // 0x48 0x69 0x21 0x00 ("Hi!") 
  
    // dump the json to string
    std::string serialized_string = j_test.dump();
    // string iterator
    std::string::iterator it;

    // Traverse the string 
    for (it = serialized_string.begin(); 
         it != serialized_string.end(); 
         it++)
    {
        // de-serialize to datastream ( only handles basic datatypes)
        ds << *it;
        DIS::OneByteChunk chunk;
        chunk.unmarshal(ds);
        chunks.push_back(chunk);
        // Print current character 
        std::cout << *it; 
    }
    std::cout << std::endl;

    std::cout << "chunks : ";
    for (DIS::OneByteChunk byte : chunks) {
        // Note '*' to dereference from char*
        std::cout << *(byte.getOtherParameters());
    }
    std::cout << std::endl;

    return 0;

}