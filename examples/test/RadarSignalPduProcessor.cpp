#include "RadarSignalPduProcessor.h"

#include <iostream>

using namespace Example;

void RadarSignalPduProcessor::Process(const DIS::Pdu& packet)
{
   const DIS::RadarSignalPdu& rspdu = static_cast<const DIS::RadarSignalPdu&>( packet );
   // if( rspdu.getTimestamp() % 2 )
   // {
      unsigned short encoding_scheme = rspdu.getEncodingScheme();
      unsigned short tdl_type = rspdu.getTdlType();
      unsigned short sample_rate = rspdu.getSampleRate();
      unsigned short data_length = rspdu.getDataLength();
      unsigned short samples = rspdu.getSamples();

      const std::vector<DIS::OneByteChunk>& data = rspdu.getData();

      std::cout << "encoding scheme: " << encoding_scheme
                << "\ttdl type: " << encoding_scheme
                << "\tsample rate: " << sample_rate
                << "\tdata length: " << data_length
                << "\tsamples: " << samples
                << std::endl;
   // }
}
