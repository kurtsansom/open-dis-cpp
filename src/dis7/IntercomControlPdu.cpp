#include <dis7/IntercomControlPdu.h>

using namespace DIS;


IntercomControlPdu::IntercomControlPdu() : RadioCommunicationsFamilyPdu(),
   _controlType(0), 
   _communicationsChannelType(0), 
   _sourceEntityID(), 
   _sourceCommunicationsDeviceID(0), 
   _sourceLineID(0), 
   _transmitPriority(0), 
   _transmitLineState(0), 
   _command(0), 
   _masterEntityID(), 
   _masterCommunicationsDeviceID(0), 
   _intercomParametersLength(0), 
   _intercomParameters()
{
    setPduType( 32 );
}

IntercomControlPdu::~IntercomControlPdu()
{
}

unsigned char IntercomControlPdu::getControlType() const
{
    return _controlType;
}

void IntercomControlPdu::setControlType(unsigned char pX)
{
    _controlType = pX;
}

unsigned char IntercomControlPdu::getCommunicationsChannelType() const
{
    return _communicationsChannelType;
}

void IntercomControlPdu::setCommunicationsChannelType(unsigned char pX)
{
    _communicationsChannelType = pX;
}

EntityID& IntercomControlPdu::getSourceEntityID() 
{
    return _sourceEntityID;
}

const EntityID& IntercomControlPdu::getSourceEntityID() const
{
    return _sourceEntityID;
}

void IntercomControlPdu::setSourceEntityID(const EntityID &pX)
{
    _sourceEntityID = pX;
}

unsigned char IntercomControlPdu::getSourceCommunicationsDeviceID() const
{
    return _sourceCommunicationsDeviceID;
}

void IntercomControlPdu::setSourceCommunicationsDeviceID(unsigned char pX)
{
    _sourceCommunicationsDeviceID = pX;
}

unsigned char IntercomControlPdu::getSourceLineID() const
{
    return _sourceLineID;
}

void IntercomControlPdu::setSourceLineID(unsigned char pX)
{
    _sourceLineID = pX;
}

unsigned char IntercomControlPdu::getTransmitPriority() const
{
    return _transmitPriority;
}

void IntercomControlPdu::setTransmitPriority(unsigned char pX)
{
    _transmitPriority = pX;
}

unsigned char IntercomControlPdu::getTransmitLineState() const
{
    return _transmitLineState;
}

void IntercomControlPdu::setTransmitLineState(unsigned char pX)
{
    _transmitLineState = pX;
}

unsigned char IntercomControlPdu::getCommand() const
{
    return _command;
}

void IntercomControlPdu::setCommand(unsigned char pX)
{
    _command = pX;
}

EntityID& IntercomControlPdu::getMasterEntityID() 
{
    return _masterEntityID;
}

const EntityID& IntercomControlPdu::getMasterEntityID() const
{
    return _masterEntityID;
}

void IntercomControlPdu::setMasterEntityID(const EntityID &pX)
{
    _masterEntityID = pX;
}

unsigned short IntercomControlPdu::getMasterCommunicationsDeviceID() const
{
    return _masterCommunicationsDeviceID;
}

void IntercomControlPdu::setMasterCommunicationsDeviceID(unsigned short pX)
{
    _masterCommunicationsDeviceID = pX;
}

unsigned int IntercomControlPdu::getIntercomParametersLength() const
{
    return _intercomParametersLength;
}

void IntercomControlPdu::setIntercomParametersLength(unsigned int pX)
{
    _intercomParametersLength = pX;
}

IntercomCommunicationsParameters& IntercomControlPdu::getIntercomParameters() 
{
    return _intercomParameters;
}

const IntercomCommunicationsParameters& IntercomControlPdu::getIntercomParameters() const
{
    return _intercomParameters;
}

void IntercomControlPdu::setIntercomParameters(const IntercomCommunicationsParameters &pX)
{
    _intercomParameters = pX;
}

void IntercomControlPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _controlType;
    dataStream << _communicationsChannelType;
    _sourceEntityID.marshal(dataStream);
    dataStream << _sourceCommunicationsDeviceID;
    dataStream << _sourceLineID;
    dataStream << _transmitPriority;
    dataStream << _transmitLineState;
    dataStream << _command;
    _masterEntityID.marshal(dataStream);
    dataStream << _masterCommunicationsDeviceID;
    dataStream << _intercomParametersLength;
    _intercomParameters.marshal(dataStream);
}

void IntercomControlPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _controlType;
    dataStream >> _communicationsChannelType;
    _sourceEntityID.unmarshal(dataStream);
    dataStream >> _sourceCommunicationsDeviceID;
    dataStream >> _sourceLineID;
    dataStream >> _transmitPriority;
    dataStream >> _transmitLineState;
    dataStream >> _command;
    _masterEntityID.unmarshal(dataStream);
    dataStream >> _masterCommunicationsDeviceID;
    dataStream >> _intercomParametersLength;
    _intercomParameters.unmarshal(dataStream);
}


bool IntercomControlPdu::operator ==(const IntercomControlPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (_controlType == rhs._controlType) ) ivarsEqual = false;
     if( ! (_communicationsChannelType == rhs._communicationsChannelType) ) ivarsEqual = false;
     if( ! (_sourceEntityID == rhs._sourceEntityID) ) ivarsEqual = false;
     if( ! (_sourceCommunicationsDeviceID == rhs._sourceCommunicationsDeviceID) ) ivarsEqual = false;
     if( ! (_sourceLineID == rhs._sourceLineID) ) ivarsEqual = false;
     if( ! (_transmitPriority == rhs._transmitPriority) ) ivarsEqual = false;
     if( ! (_transmitLineState == rhs._transmitLineState) ) ivarsEqual = false;
     if( ! (_command == rhs._command) ) ivarsEqual = false;
     if( ! (_masterEntityID == rhs._masterEntityID) ) ivarsEqual = false;
     if( ! (_masterCommunicationsDeviceID == rhs._masterCommunicationsDeviceID) ) ivarsEqual = false;
     if( ! (_intercomParametersLength == rhs._intercomParametersLength) ) ivarsEqual = false;
     if( ! (_intercomParameters == rhs._intercomParameters) ) ivarsEqual = false;

    return ivarsEqual;
 }

int IntercomControlPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 1;  // _controlType
   marshalSize = marshalSize + 1;  // _communicationsChannelType
   marshalSize = marshalSize + _sourceEntityID.getMarshalledSize();  // _sourceEntityID
   marshalSize = marshalSize + 1;  // _sourceCommunicationsDeviceID
   marshalSize = marshalSize + 1;  // _sourceLineID
   marshalSize = marshalSize + 1;  // _transmitPriority
   marshalSize = marshalSize + 1;  // _transmitLineState
   marshalSize = marshalSize + 1;  // _command
   marshalSize = marshalSize + _masterEntityID.getMarshalledSize();  // _masterEntityID
   marshalSize = marshalSize + 2;  // _masterCommunicationsDeviceID
   marshalSize = marshalSize + 4;  // _intercomParametersLength
   marshalSize = marshalSize + _intercomParameters.getMarshalledSize();  // _intercomParameters
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
