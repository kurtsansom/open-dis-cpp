#include <dis7/TransmitterPdu.h>

using namespace DIS;


TransmitterPdu::TransmitterPdu() : RadioCommunicationsFamilyPdu(),
   _radioReferenceID(), 
   _radioNumber(0), 
   _radioEntityType(), 
   _transmitState(0), 
   _inputSource(0), 
   _variableTransmitterParameterCount(0), 
   _antennaLocation(), 
   _relativeAntennaLocation(), 
   _antennaPatternType(0), 
   _antennaPatternCount(0), 
   _frequency(0), 
   _transmitFrequencyBandwidth(0.0), 
   _power(0.0), 
   _modulationType(), 
   _cryptoSystem(0), 
   _cryptoKeyId(0), 
   _modulationParameterCount(0), 
   _padding2(0), 
   _padding3(0), 
   _modulationParametersList(), 
   _antennaPatternList()
{
    setPduType( 25 );
}

TransmitterPdu::~TransmitterPdu()
{
}

EntityID& TransmitterPdu::getRadioReferenceID() 
{
    return _radioReferenceID;
}

const EntityID& TransmitterPdu::getRadioReferenceID() const
{
    return _radioReferenceID;
}

void TransmitterPdu::setRadioReferenceID(const EntityID &pX)
{
    _radioReferenceID = pX;
}

unsigned short TransmitterPdu::getRadioNumber() const
{
    return _radioNumber;
}

void TransmitterPdu::setRadioNumber(unsigned short pX)
{
    _radioNumber = pX;
}

EntityType& TransmitterPdu::getRadioEntityType() 
{
    return _radioEntityType;
}

const EntityType& TransmitterPdu::getRadioEntityType() const
{
    return _radioEntityType;
}

void TransmitterPdu::setRadioEntityType(const EntityType &pX)
{
    _radioEntityType = pX;
}

unsigned char TransmitterPdu::getTransmitState() const
{
    return _transmitState;
}

void TransmitterPdu::setTransmitState(unsigned char pX)
{
    _transmitState = pX;
}

unsigned char TransmitterPdu::getInputSource() const
{
    return _inputSource;
}

void TransmitterPdu::setInputSource(unsigned char pX)
{
    _inputSource = pX;
}

unsigned short TransmitterPdu::getVariableTransmitterParameterCount() const
{
    return _variableTransmitterParameterCount;
}

void TransmitterPdu::setVariableTransmitterParameterCount(unsigned short pX)
{
    _variableTransmitterParameterCount = pX;
}

Vector3Double& TransmitterPdu::getAntennaLocation() 
{
    return _antennaLocation;
}

const Vector3Double& TransmitterPdu::getAntennaLocation() const
{
    return _antennaLocation;
}

void TransmitterPdu::setAntennaLocation(const Vector3Double &pX)
{
    _antennaLocation = pX;
}

Vector3Float& TransmitterPdu::getRelativeAntennaLocation() 
{
    return _relativeAntennaLocation;
}

const Vector3Float& TransmitterPdu::getRelativeAntennaLocation() const
{
    return _relativeAntennaLocation;
}

void TransmitterPdu::setRelativeAntennaLocation(const Vector3Float &pX)
{
    _relativeAntennaLocation = pX;
}

unsigned short TransmitterPdu::getAntennaPatternType() const
{
    return _antennaPatternType;
}

void TransmitterPdu::setAntennaPatternType(unsigned short pX)
{
    _antennaPatternType = pX;
}

unsigned short TransmitterPdu::getAntennaPatternCount() const
{
    return _antennaPatternCount;
}

void TransmitterPdu::setAntennaPatternCount(unsigned short pX)
{
    _antennaPatternCount = pX;
}

long TransmitterPdu::getFrequency() const
{
    return _frequency;
}

void TransmitterPdu::setFrequency(long pX)
{
    _frequency = pX;
}

float TransmitterPdu::getTransmitFrequencyBandwidth() const
{
    return _transmitFrequencyBandwidth;
}

void TransmitterPdu::setTransmitFrequencyBandwidth(float pX)
{
    _transmitFrequencyBandwidth = pX;
}

float TransmitterPdu::getPower() const
{
    return _power;
}

void TransmitterPdu::setPower(float pX)
{
    _power = pX;
}

ModulationType& TransmitterPdu::getModulationType() 
{
    return _modulationType;
}

const ModulationType& TransmitterPdu::getModulationType() const
{
    return _modulationType;
}

void TransmitterPdu::setModulationType(const ModulationType &pX)
{
    _modulationType = pX;
}

unsigned short TransmitterPdu::getCryptoSystem() const
{
    return _cryptoSystem;
}

void TransmitterPdu::setCryptoSystem(unsigned short pX)
{
    _cryptoSystem = pX;
}

unsigned short TransmitterPdu::getCryptoKeyId() const
{
    return _cryptoKeyId;
}

void TransmitterPdu::setCryptoKeyId(unsigned short pX)
{
    _cryptoKeyId = pX;
}

unsigned char TransmitterPdu::getModulationParameterCount() const
{
    return _modulationParameterCount;
}

void TransmitterPdu::setModulationParameterCount(unsigned char pX)
{
    _modulationParameterCount = pX;
}

unsigned short TransmitterPdu::getPadding2() const
{
    return _padding2;
}

void TransmitterPdu::setPadding2(unsigned short pX)
{
    _padding2 = pX;
}

unsigned char TransmitterPdu::getPadding3() const
{
    return _padding3;
}

void TransmitterPdu::setPadding3(unsigned char pX)
{
    _padding3 = pX;
}

Vector3Float& TransmitterPdu::getModulationParametersList() 
{
    return _modulationParametersList;
}

const Vector3Float& TransmitterPdu::getModulationParametersList() const
{
    return _modulationParametersList;
}

void TransmitterPdu::setModulationParametersList(const Vector3Float &pX)
{
    _modulationParametersList = pX;
}

Vector3Float& TransmitterPdu::getAntennaPatternList() 
{
    return _antennaPatternList;
}

const Vector3Float& TransmitterPdu::getAntennaPatternList() const
{
    return _antennaPatternList;
}

void TransmitterPdu::setAntennaPatternList(const Vector3Float &pX)
{
    _antennaPatternList = pX;
}

void TransmitterPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _radioReferenceID.marshal(dataStream);
    dataStream << _radioNumber;
    _radioEntityType.marshal(dataStream);
    dataStream << _transmitState;
    dataStream << _inputSource;
    dataStream << _variableTransmitterParameterCount;
    _antennaLocation.marshal(dataStream);
    _relativeAntennaLocation.marshal(dataStream);
    dataStream << _antennaPatternType;
    dataStream << _antennaPatternCount;
    dataStream << _frequency;
    dataStream << _transmitFrequencyBandwidth;
    dataStream << _power;
    _modulationType.marshal(dataStream);
    dataStream << _cryptoSystem;
    dataStream << _cryptoKeyId;
    dataStream << _modulationParameterCount;
    dataStream << _padding2;
    dataStream << _padding3;
    _modulationParametersList.marshal(dataStream);
    _antennaPatternList.marshal(dataStream);
}

void TransmitterPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _radioReferenceID.unmarshal(dataStream);
    dataStream >> _radioNumber;
    _radioEntityType.unmarshal(dataStream);
    dataStream >> _transmitState;
    dataStream >> _inputSource;
    dataStream >> _variableTransmitterParameterCount;
    _antennaLocation.unmarshal(dataStream);
    _relativeAntennaLocation.unmarshal(dataStream);
    dataStream >> _antennaPatternType;
    dataStream >> _antennaPatternCount;
    dataStream >> _frequency;
    dataStream >> _transmitFrequencyBandwidth;
    dataStream >> _power;
    _modulationType.unmarshal(dataStream);
    dataStream >> _cryptoSystem;
    dataStream >> _cryptoKeyId;
    dataStream >> _modulationParameterCount;
    dataStream >> _padding2;
    dataStream >> _padding3;
    _modulationParametersList.unmarshal(dataStream);
    _antennaPatternList.unmarshal(dataStream);
}


bool TransmitterPdu::operator ==(const TransmitterPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (_radioReferenceID == rhs._radioReferenceID) ) ivarsEqual = false;
     if( ! (_radioNumber == rhs._radioNumber) ) ivarsEqual = false;
     if( ! (_radioEntityType == rhs._radioEntityType) ) ivarsEqual = false;
     if( ! (_transmitState == rhs._transmitState) ) ivarsEqual = false;
     if( ! (_inputSource == rhs._inputSource) ) ivarsEqual = false;
     if( ! (_variableTransmitterParameterCount == rhs._variableTransmitterParameterCount) ) ivarsEqual = false;
     if( ! (_antennaLocation == rhs._antennaLocation) ) ivarsEqual = false;
     if( ! (_relativeAntennaLocation == rhs._relativeAntennaLocation) ) ivarsEqual = false;
     if( ! (_antennaPatternType == rhs._antennaPatternType) ) ivarsEqual = false;
     if( ! (_antennaPatternCount == rhs._antennaPatternCount) ) ivarsEqual = false;
     if( ! (_frequency == rhs._frequency) ) ivarsEqual = false;
     if( ! (_transmitFrequencyBandwidth == rhs._transmitFrequencyBandwidth) ) ivarsEqual = false;
     if( ! (_power == rhs._power) ) ivarsEqual = false;
     if( ! (_modulationType == rhs._modulationType) ) ivarsEqual = false;
     if( ! (_cryptoSystem == rhs._cryptoSystem) ) ivarsEqual = false;
     if( ! (_cryptoKeyId == rhs._cryptoKeyId) ) ivarsEqual = false;
     if( ! (_modulationParameterCount == rhs._modulationParameterCount) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_padding3 == rhs._padding3) ) ivarsEqual = false;
     if( ! (_modulationParametersList == rhs._modulationParametersList) ) ivarsEqual = false;
     if( ! (_antennaPatternList == rhs._antennaPatternList) ) ivarsEqual = false;

    return ivarsEqual;
 }

int TransmitterPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _radioReferenceID.getMarshalledSize();  // _radioReferenceID
   marshalSize = marshalSize + 2;  // _radioNumber
   marshalSize = marshalSize + _radioEntityType.getMarshalledSize();  // _radioEntityType
   marshalSize = marshalSize + 1;  // _transmitState
   marshalSize = marshalSize + 1;  // _inputSource
   marshalSize = marshalSize + 2;  // _variableTransmitterParameterCount
   marshalSize = marshalSize + _antennaLocation.getMarshalledSize();  // _antennaLocation
   marshalSize = marshalSize + _relativeAntennaLocation.getMarshalledSize();  // _relativeAntennaLocation
   marshalSize = marshalSize + 2;  // _antennaPatternType
   marshalSize = marshalSize + 2;  // _antennaPatternCount
   marshalSize = marshalSize + 8;  // _frequency
   marshalSize = marshalSize + 4;  // _transmitFrequencyBandwidth
   marshalSize = marshalSize + 4;  // _power
   marshalSize = marshalSize + _modulationType.getMarshalledSize();  // _modulationType
   marshalSize = marshalSize + 2;  // _cryptoSystem
   marshalSize = marshalSize + 2;  // _cryptoKeyId
   marshalSize = marshalSize + 1;  // _modulationParameterCount
   marshalSize = marshalSize + 2;  // _padding2
   marshalSize = marshalSize + 1;  // _padding3
   marshalSize = marshalSize + _modulationParametersList.getMarshalledSize();  // _modulationParametersList
   marshalSize = marshalSize + _antennaPatternList.getMarshalledSize();  // _antennaPatternList
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
