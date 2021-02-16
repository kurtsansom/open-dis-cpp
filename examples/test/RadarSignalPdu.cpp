#include "RadarSignalPdu.h"

using namespace DIS;


RadarSignalPdu::RadarSignalPdu() : SignalPdu(),
   _somevalue(0),
   _test_str("Hello")
{
    setPduType( 206 );
}

RadarSignalPdu::~RadarSignalPdu()
{
    _data.clear();
}

unsigned short RadarSignalPdu::getSomevalue() const
{
    return _somevalue;
}

void RadarSignalPdu::setSomevalue(unsigned char pX)
{
    _somevalue = pX;
}

std::string RadarSignalPdu::getString() const
{
    return _test_str;
}

void RadarSignalPdu::setString(std::string pX)
{
    _test_str = pX;
}

void RadarSignalPdu::marshal(DataStream& dataStream) const
{
    SignalPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _somevalue;
}

void RadarSignalPdu::unmarshal(DataStream& dataStream)
{
    SignalPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _somevalue;
}


bool RadarSignalPdu::operator ==(const RadarSignalPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SignalPdu::operator==(rhs);

     if( ! (_encodingScheme == rhs._encodingScheme) ) ivarsEqual = false;
     if( ! (_tdlType == rhs._tdlType) ) ivarsEqual = false;
     if( ! (_sampleRate == rhs._sampleRate) ) ivarsEqual = false;
     if( ! (_dataLength == rhs._dataLength) ) ivarsEqual = false;
     if( ! (_samples == rhs._samples) ) ivarsEqual = false;

     for(size_t idx = 0; idx < _dataLength; idx++)
     {
        if( ! ( _data[idx] == rhs._data[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int RadarSignalPdu::getMarshalledSize() const
{
    int marshalSize = 0;

    marshalSize = SignalPdu::getMarshalledSize();
    marshalSize = marshalSize + 1;  // _somevalue

    return marshalSize;
}

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.