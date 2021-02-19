#include <dis7/RadarReflectivity.h>
#include <dis7/Vector3Float.h>

using namespace DIS;


RadarReflectivity::RadarReflectivity() : Vector3Float(),
   _reflectivity(0.0)
{
}

RadarReflectivity::~RadarReflectivity()
{
}

Vector3Float RadarReflectivity::getSampleLocation()
{
    Vector3Float _sampleLocation;
    _sampleLocation.setX(_x);
    _sampleLocation.setY(_y);
    _sampleLocation.setZ(_z);

    return _sampleLocation;
}

const Vector3Float RadarReflectivity::getSampleLocation() const
{
    Vector3Float _sampleLocation;
    _sampleLocation.setX(_x);
    _sampleLocation.setY(_y);
    _sampleLocation.setZ(_z);

    return _sampleLocation;
}

void RadarReflectivity::setSampleLocation(const Vector3Float &pX)
{
    _x = pX.getX();
    _y = pX.getY();
    _z = pX.getZ();
}

float RadarReflectivity::getReflectivity() const
{
    return _reflectivity;
}

void RadarReflectivity::setReflectivity(float pX)
{
    _reflectivity = pX;
}

void RadarReflectivity::marshal(DataStream& dataStream) const
{
    Vector3Float::marshal(dataStream); // Marshal information in superclass first
    dataStream << _reflectivity;
}

void RadarReflectivity::unmarshal(DataStream& dataStream)
{
    Vector3Float::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _reflectivity;
}


bool RadarReflectivity::operator ==(const RadarReflectivity& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = Vector3Float::operator==(rhs);

     if( ! (_reflectivity == rhs._reflectivity) ) ivarsEqual = false;

    return ivarsEqual;
 }

int RadarReflectivity::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = Vector3Float::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _reflectivity
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
