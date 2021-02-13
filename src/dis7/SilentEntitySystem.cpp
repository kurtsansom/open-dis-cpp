#include <dis7/SilentEntitySystem.h>

using namespace DIS;


SilentEntitySystem::SilentEntitySystem():
   _numberOfEntities(0), 
   _numberOfAppearanceRecords(0), 
   _entityType(), 
   _appearanceRecordList()
{
}

SilentEntitySystem::~SilentEntitySystem()
{
}

unsigned short SilentEntitySystem::getNumberOfEntities() const
{
    return _numberOfEntities;
}

void SilentEntitySystem::setNumberOfEntities(unsigned short pX)
{
    _numberOfEntities = pX;
}

unsigned short SilentEntitySystem::getNumberOfAppearanceRecords() const
{
    return _numberOfAppearanceRecords;
}

void SilentEntitySystem::setNumberOfAppearanceRecords(unsigned short pX)
{
    _numberOfAppearanceRecords = pX;
}

EntityType& SilentEntitySystem::getEntityType() 
{
    return _entityType;
}

const EntityType& SilentEntitySystem::getEntityType() const
{
    return _entityType;
}

void SilentEntitySystem::setEntityType(const EntityType &pX)
{
    _entityType = pX;
}

FourByteChunk& SilentEntitySystem::getAppearanceRecordList() 
{
    return _appearanceRecordList;
}

const FourByteChunk& SilentEntitySystem::getAppearanceRecordList() const
{
    return _appearanceRecordList;
}

void SilentEntitySystem::setAppearanceRecordList(const FourByteChunk &pX)
{
    _appearanceRecordList = pX;
}

void SilentEntitySystem::marshal(DataStream& dataStream) const
{
    dataStream << _numberOfEntities;
    dataStream << _numberOfAppearanceRecords;
    _entityType.marshal(dataStream);
    _appearanceRecordList.marshal(dataStream);
}

void SilentEntitySystem::unmarshal(DataStream& dataStream)
{
    dataStream >> _numberOfEntities;
    dataStream >> _numberOfAppearanceRecords;
    _entityType.unmarshal(dataStream);
    _appearanceRecordList.unmarshal(dataStream);
}


bool SilentEntitySystem::operator ==(const SilentEntitySystem& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_numberOfEntities == rhs._numberOfEntities) ) ivarsEqual = false;
     if( ! (_numberOfAppearanceRecords == rhs._numberOfAppearanceRecords) ) ivarsEqual = false;
     if( ! (_entityType == rhs._entityType) ) ivarsEqual = false;
     if( ! (_appearanceRecordList == rhs._appearanceRecordList) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SilentEntitySystem::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // _numberOfEntities
   marshalSize = marshalSize + 2;  // _numberOfAppearanceRecords
   marshalSize = marshalSize + _entityType.getMarshalledSize();  // _entityType
   marshalSize = marshalSize + _appearanceRecordList.getMarshalledSize();  // _appearanceRecordList
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
