#ifndef SILENTENTITYSYSTEM_H
#define SILENTENTITYSYSTEM_H

#include <dis7/EntityType.h>
#include <dis7/FourByteChunk.h>
#include <common/DataStream.h>
#include <common/msLibMacro.h>


namespace DIS
{
// information abou an enitity not producing espdus. Section 6.2.79

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

class EXPORT_MACRO SilentEntitySystem
{
protected:
  /** number of the type specified by the entity type field */
  unsigned short _numberOfEntities;

  /** number of entity appearance records that follow */
  unsigned short _numberOfAppearanceRecords;

  /** Entity type */
  EntityType _entityType;

  /** Variable length list of appearance records */
  FourByteChunk _appearanceRecordList;


 public:
    SilentEntitySystem();
    virtual ~SilentEntitySystem();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getNumberOfEntities() const; 
    void setNumberOfEntities(unsigned short pX); 

    unsigned short getNumberOfAppearanceRecords() const; 
    void setNumberOfAppearanceRecords(unsigned short pX); 

    EntityType& getEntityType();
    const EntityType&  getEntityType() const;
    void setEntityType(const EntityType    &pX);

    FourByteChunk& getAppearanceRecordList();
    const FourByteChunk&  getAppearanceRecordList() const;
    void setAppearanceRecordList(const FourByteChunk    &pX);


     virtual int getMarshalledSize() const;

     bool operator ==(const SilentEntitySystem& rhs) const;
};
}

#endif
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
