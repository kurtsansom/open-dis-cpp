#include <dis7/PduStream.h>

using namespace DIS;


PduStream::PduStream():
   _description(0), 
   _name(0), 
   _startTime(0), 
   _stopTime(0)
{
}

PduStream::~PduStream()
{
}

char PduStream::getDescription() const
{
    return _description;
}

void PduStream::setDescription(char pX)
{
    _description = pX;
}

char PduStream::getName() const
{
    return _name;
}

void PduStream::setName(char pX)
{
    _name = pX;
}

long PduStream::getStartTime() const
{
    return _startTime;
}

void PduStream::setStartTime(long pX)
{
    _startTime = pX;
}

long PduStream::getStopTime() const
{
    return _stopTime;
}

void PduStream::setStopTime(long pX)
{
    _stopTime = pX;
}

void PduStream::marshal(DataStream& dataStream) const
{
    dataStream << _description;
    dataStream << _name;
    dataStream << _startTime;
    dataStream << _stopTime;
}

void PduStream::unmarshal(DataStream& dataStream)
{
    dataStream >> _description;
    dataStream >> _name;
    dataStream >> _startTime;
    dataStream >> _stopTime;
}


bool PduStream::operator ==(const PduStream& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_description == rhs._description) ) ivarsEqual = false;
     if( ! (_name == rhs._name) ) ivarsEqual = false;
     if( ! (_startTime == rhs._startTime) ) ivarsEqual = false;
     if( ! (_stopTime == rhs._stopTime) ) ivarsEqual = false;

    return ivarsEqual;
 }

int PduStream::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _description
   marshalSize = marshalSize + 1;  // _name
   marshalSize = marshalSize + 8;  // _startTime
   marshalSize = marshalSize + 8;  // _stopTime
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
